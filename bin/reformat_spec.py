import os
import sys
import json
import yaml
from ruamel import yaml

#import pynwb

from datetime import datetime
from form.spec import Spec, AttributeSpec, LinkSpec, SpecNamespace, NamespaceBuilder
from pynwb.spec import NWBDatasetSpec, NWBGroupSpec, NWBNamespace

"""
    stuff to clean up

    - float('NaN') should be just 'NaN'
"""

CORE_NAMESPACE='core'

global tree
tree = list()
def monitor(func):
    def _func(name, d, **kwargs):

        nodename = name
        if '<' in nodename:
            end = nodename.rfind('>')
            nodename = nodename[1:end]
        elif '/' in nodename:
            nodename = nodename[0:-1]

        tree.append(nodename)
        ret = func(name, d, **kwargs)
        tree.pop()
        return ret
    return _func

def get_node():
    return '/'.join(tree)

ignore = {'electrode_group', 'electrode_map', 'filtering', 'impedance'}
metadata_ndts = list()

subspec_locations = {
    'ElectrodeGroup': 'ecephys',
    'IntracellularElectrode': 'icephys',
    'ImagingPlane': 'ophys',
    'OptogeneticStimulusSite': 'ogen',
    'Epoch': 'epoch',

}

device_spec = LinkSpec('the device that was used to record from this electrode group', 'Device', name='device', quantity='?')
alternate_defs = {
    'ElectrodeGroup': NWBGroupSpec('One of possibly many groups, one for each electrode group.',
            neurodata_type_def='ElectrodeGroup',
            namespace=CORE_NAMESPACE,
            datasets = [
                NWBDatasetSpec('array with description for each channel', 'text', name='channel_description', shape=(None,), dims=('num_channels',)),
                NWBDatasetSpec('array with location description for each channel e.g. "CA1"', 'text', name='channel_location',    shape=(None,), dims=('num_channels',)),
                NWBDatasetSpec('array with description of filtering applied to each channel', 'text', name='channel_filtering',   shape=(None,), dims=('num_channels',)),
                NWBDatasetSpec('xyz-coordinates for each channel. use NaN for unknown dimensions', 'text', name='channel_coordinates', shape=(None,3), dims=('num_channels', 'dimensions')),
                NWBDatasetSpec('float array with impedance used on each channel. Can be 2D matrix to store a range', 'text', name='channel_impedance', shape=(None,), dims=('num_channels',)),
                NWBDatasetSpec('description of this electrode group', 'text', name='description'),
                NWBDatasetSpec('description of location of this electrode group', 'text', name='location'),
            ],
            links = [
                device_spec
            ]
    )
}

NAME_WILDCARD = "*"

ndmap_to_group = {
    "<device_X>*": 'Device',
}

ndmap = {
    "<timeseries_X>": 'EpochTimeSeries',
    "<epoch_X>": 'Epoch',
    "<device_X>": 'Device',
    "<specification_file>": 'SpecFile',
    "<electrode_group_X>": 'ElectrodeGroup',
    "<electrode_X>": 'IntracellularElectrode',
    "<site_X>": 'OptogeneticStimulusSite',
    "<channel_X>": 'OpticalChannel',
    "<imaging_plane_X>": 'ImagingPlane',
    "<unit_N>": 'SpikeUnit',
    "<roi_name>": 'ROI',
    "<image_plane>": 'PlaneSegmentation',
    "<image stack name>": 'CorrectedImageStack',
}



#ImageSegmentation.image_plane.imaging_plane_name
metadata_links = {
    'electrode_idx': 'ElectrodeGroup',
    'imaging_plane': 'ImagingPlane',
    'site': 'OptogeneticStimulusSite',
    'imaging_plane_name': 'ImagingPlane',
    'electrode_name': 'IntracellularElectrode',
}

metadata_links_doc = {
    'electrode_idx': 'link to ElectrodeGroup group that generated this TimeSeries data',
    'imaging_plane': 'link to ImagingPlane group from which this TimeSeries data was generated',
    'site': 'link to OptogeneticStimulusSite group that describes the site to which this stimulus was applied',
    'electrode_name': 'link to IntracellularElectrode group that describes th electrode that was used to apply or record this data',
    'imaging_plane_name': 'link to ImagingPlane group from which this TimeSeries data was generated',

}
metadata_links_rename = {
    'electrode_idx': 'electrode_group',
    'electrode_name': 'electrode',
    'imaging_plane_name': 'imaging_plane'
}

all_specs = dict()


include_doc = {
    'presentation/': 'TimeSeries objects containing data of presented stimuli',
    'templates/': 'TimeSeries objects containing template data of presented stimuli',
    'timeseries/': 'TimeSeries object containing data generated during data acquisition',
    'FilteredEphys/': 'ElectricalSeries object containing filtered electrophysiology data',
    'PupilTracking/': 'TimeSeries object containing time series data on pupil size',
    'Position/': 'SpatialSeries object containing position data',
    'Fluorescence/': 'RoiResponseSeries object containing fluorescence data for a ROI',
    'Module': 'Interface objects containing data output from processing steps',

    'EventWaveform/': 'SpikeEventSeries object containing detected spike event waveforms',
    'EyeTracking/': 'SpatialSeries object containing data measuring direction of gaze',
    'BehavioralEpochs/': 'IntervalSeries object containing start and stop times of epochs',
    'DfOverF/': 'RoiResponseSeries object containing dF/F for a ROI',
    'LFP/': 'ElectricalSeries object containing LFP data for one or channels',
    'BehavioralTimeSeries/': 'TimeSeries object containing continuous behavioral data',
    'BehavioralEvents/': 'TimeSeries object containing irregular behavioral events',
    'CompassDirection/': 'SpatialSeries object containing direction of gaze travel',

}

def build_group_helper(**kwargs):
    myname = kwargs.pop('name', NAME_WILDCARD)
    doc = kwargs.pop('doc')
    ndt = kwargs.get('neurodata_type_def')
    if kwargs.get('neurodata_type_inc', None) is None:
        kwargs['neurodata_type_inc'] = 'NWBContainer'
    if ndt is not None:
        kwargs['namespace'] = 'core'
    if myname == NAME_WILDCARD:
        grp_spec = NWBGroupSpec(doc, **kwargs)
    else:
        if ndt is not None:
            kwargs['default_name'] = myname
            print('setting default_name for %s' % myname)
        else:
            kwargs['name'] = myname
            print('setting name for %s' % myname)
        grp_spec = NWBGroupSpec(doc, **kwargs)
    return grp_spec

@monitor
def build_group(name, d, ndtype=None):
    #required = True
    if name[0] == '<':
        name = NAME_WILDCARD
    myname = name
    quantity, myname = strip_characters(name)
    if myname[-1] == '/':
        myname = myname[:-1]
    extends = None
    if 'merge' in d:
        merge = d.pop('merge')
        base = merge[0]
        end = base.rfind('>')
        base = base[1:end] if end > 0 else base
        #extends = all_specs[base]
        extends = base

    if myname[0] == '<':
        neurodata_type = ndmap.get(myname, ndmap_to_group.get(myname))
        if neurodata_type is None:
            neurodata_type = ndtype
        else:
            myname = NAME_WILDCARD
    else:
        neurodata_type = ndtype

    desc = d.get('description', None)
    if isinstance(desc, dict) or desc is None:
        desc = d.pop('_description', None)
    else:
        d.pop('description', None)

    if 'attributes' in d:
        attributes = d.pop('attributes', None)
        if 'neurodata_type' in attributes:
            neurodata_type = attributes.pop('neurodata_type')['value']
        elif 'ancestry' in attributes:
            #neurodata_type = attributes['ancestry']['value'][-1]
            neurodata_type = attributes.pop('ancestry')['value'][-1]
        if extends is not None:
            if neurodata_type is None:
                neurodata_type = myname
        grp_spec = build_group_helper(name=myname, quantity=quantity, doc=desc, neurodata_type_def=neurodata_type, neurodata_type_inc=extends)
        add_attributes(grp_spec, attributes)
    elif neurodata_type is not None:
        grp_spec = build_group_helper(name=myname, quantity=quantity, doc=desc, neurodata_type_def=neurodata_type, neurodata_type_inc=extends)
    else:
        if myname == NAME_WILDCARD:
            grp_spec = build_group_helper(doc=desc, quantity=quantity, neurodata_type_inc=extends)
        else:
            grp_spec = build_group_helper(doc=desc, name=myname, quantity=quantity, neurodata_type_inc=extends)

    for key, value in d.items():
        tmp_name = key
        if tmp_name == 'autogen':
            continue
        if tmp_name[0] == '_':
            #TODO: figure out how to deal with these reserved keys
            print ('found leading underscore: key=%s, ndt=%s, name=%s' % (key, neurodata_type, myname), file=sys.stderr)
            continue
        if isinstance(value, str):
            continue
        if 'autogen' in value:
            if value['autogen']['type'] != 'create':
                print ('skipping autogen: %s/%s' % (get_node(), key))
                continue

        if tmp_name == 'include':
            ndt = next(iter(value.keys()))
            quantity = None
            if ndt[-1] != '/':
                quantity = ndt[-1]
                ndt = ndt[:-1]
            ndt = ndt[1:ndt.rfind('>')]
            doc = include_doc.get(name, include_doc.get(neurodata_type))
            vargs = {'neurodata_type_inc': ndt}
            if quantity is not None:
                vargs['quantity'] = quantity
            if ndt is not None:
                vargs['namespace'] = CORE_NAMESPACE
            grp_spec.add_group(doc, **vargs)
        elif 'link' in value:
            ndt = value['link']['target_type']
            doc = value.get('description', None)
            if ndt[0] == '<':
                ndt = ndt[1:ndt.rfind('>')]
            else:
                ndt = ndt[0:-1]
            link_name = key
            if link_name[-1] == '/':
                link_name = link_name[0:-1]
            #grp_spec.include_neurodata_link(ndt, name=link_name)
            grp_spec.add_link(doc, ndt, name=link_name)
        elif 'merge' in value:
            ndt = value['merge'][0]
            ndt = ndt[1:ndt.rfind('>')]
            doc = value['description']
            if key[0] == '<':
                #grp_spec.include_neurodata_group(ndt)
                grp_spec.add_group(doc, neurodata_type_inc=ndt, namespace=CORE_NAMESPACE)
            else:
                group_name = key
                if group_name[-1] == '/':
                    group_name = group_name[0:-1]
                vargs = {'neurodata_type_inc': ndt, name: group_name}
                if ndt is not None:
                    vargs['namespace'] = CORE_NAMESPACE
                grp_spec.add_group(doc, **vargs)
        elif tmp_name in metadata_links:
            ndt = metadata_links[tmp_name]
            doc = metadata_links_doc[tmp_name]
            grp_spec.add_link(doc, ndt, name=metadata_links_rename.get(tmp_name, tmp_name))
        else:
            if key.rfind('/') == -1: # forward-slash not found
                if key in ndmap_to_group:
                    grp_spec.set_group(build_group(tmp_name, value))
                else:
                    if tmp_name not in ignore:
                        grp_spec.set_dataset(build_dataset(tmp_name, value))
                    else:
                        print('skipping', tmp_name)
            else:
                subgrp = build_group(tmp_name, value)
                if subgrp.neurodata_type_def in subspec_locations:
                    if subgrp.neurodata_type_def in alternate_defs:
                        print('getting alternate_def for', subgrp.neurodata_type_def)
                        subgrp = alternate_defs[subgrp.neurodata_type_def]
                    #print('moving %s' % subgrp.neurodata_type_def)
                    vargs = {'neurodata_type_inc': subgrp.neurodata_type_def, 'namespace': CORE_NAMESPACE, 'quantity': '*'}
                    grp_spec.add_group(subgrp.doc, **vargs)
                    metadata_ndts.append(subgrp)
                else:
                    grp_spec.set_group(subgrp)

    if neurodata_type is not None:
        all_specs[neurodata_type] = grp_spec
    return grp_spec

dataset_ndt = { '<image_X>': 'Image' }
@monitor
def build_dataset(name, d):
    kwargs = remap_keys(name, d)
    if 'name' in kwargs:
        if kwargs['name'] in dataset_ndt:
            tmpname = kwargs.pop('name')
            kwargs['neurodata_type_def'] = dataset_ndt[tmpname]
    if 'neurodata_type_def' in kwargs or 'neurodata_type_inc' in kwargs:
        kwargs['namespace'] = CORE_NAMESPACE
    dset_spec = NWBDatasetSpec(kwargs.pop('doc'), kwargs.pop('dtype'), **kwargs)
    if 'attributes' in d:
        add_attributes(dset_spec, d['attributes'])
    return dset_spec

def add_attributes(parent_spec, attributes):
    for attr_name, attr_spec in attributes.items():
        if 'autogen' in attr_spec:
            print('skipping autogen attribute: %s.%s'  % (get_node(), attr_name))
            continue
        parent_spec.set_attribute(build_attribute(attr_name, attr_spec))

override_doc = {
    'conversion': "Scalar to multiply each element in data to convert it to the specified unit",
    'unit': "The base unit of measure used to store data. This should be in the SI unit. COMMENT: This is the SI unit (when appropriate) of the stored data, such as Volts. If the actual data is stored in millivolts, the field 'conversion' below describes how to convert the data to the specified SI unit.",
    'resolution': "Smallest meaningful difference between values in data, stored in the specified by unit. COMMENT: E.g., the change in value of the least significant bit, or a larger number if signal noise is known to be present. If unknown, use NaN",
    'help': 'A help statement',

}
def build_attribute(name, d):
    kwargs = remap_keys(name, d)
    myname = kwargs.pop('name')
    doc = kwargs.pop('doc')
    dtype = kwargs.pop('dtype')
    if 'value' in kwargs and isinstance(kwargs['value'], str):
        if 'NaN' in kwargs['value']:
            kwargs['value'] = 'NaN'
    attr_spec = AttributeSpec(myname, dtype, doc, **kwargs)
    return attr_spec

def strip_characters(name):
    flags = ('!', '?', '+', '*', '^')
    quantity = 1
    retname = name
    if retname != NAME_WILDCARD:
        if name[-1] == '!':
            retname = name[:-1]
            quantity = 1
        elif name[-1] == '?':
            retname = name[:-1]
            quantity = '?'
        elif name[-1] == '+':
            retname = name[:-1]
            quantity = '+'
        elif name[-1] == '*':
            retname = name[:-1]
            quantity = '*'
        elif name[-1] == '^':
            retname = name[:-1]
            quantity = '?'

    return (quantity, retname)


def remap_keys(name, d):
    # TODO: add parsing of +/* for 'num_args'
    # will move to quantity which takes on values *, +, ? , or an integer
    ret = dict()
    quantity, specname = strip_characters(name)
    if quantity != 1:
        ret['quantity'] = quantity

    if specname in ndmap:
        ret['neurodata_type_def'] = ndmap[specname]
    elif specname in ndmap_to_group:
        ret['neurodata_type_def'] = ndmap[specname]
    else:
        ret['name'] = specname
    #ret['name'] = name
    #if name[-1] == '?':
    #    ret['required'] = False
    #    ret['name'] = name[:-1]
    #elif name[-1] == '^':
    #    ret['name'] = name[:-1]
    ret['dtype'] = d.get('data_type', 'None')

    value = d.get('value', None)
    if isinstance(value, list) and len(value) == 1:
        value = value[0]

    const = d.pop('const', False)
    if value is not None:
        if const:
            ret['value'] = value
        else:
            ret['default_value'] = value
    def_doc = None
    ret['doc'] = d.get('description', def_doc)

    if 'value' in ret and ret['value'] is not None:
        ret['doc'] = "Value is '%s'" % str(ret['value'])
    elif ret['doc'] is None:
        ret['doc'] = override_doc.get(ret['name'])
    ret['dims'] = d.get('dimensions', None)
    ret['shape'] = make_shape(ret['dims'], d)
    ret['dims'] = get_dimensions(ret['dims'], d)
    return ret


def join_components(components):
    if isinstance(components[0], dict):
        return "|".join(x['alias'] for x in components)
    else:
        return [join_components(c) for c in components]

def get_dimensions(dims, d):
    if dims is None:
        return None
    if isinstance(dims, str):
        if dims in d and 'components' in d[dims]:
            return join_components(d[dims]['components'])
        return dims
    else:
        return [ get_dimensions(i, d) for i in dims ]

def make_shape(dims, d):
    if dims is None:
        return None
    if isinstance(dims, str):
        if dims in d and 'components' in d[dims]:
            return len(d[dims]['components'])
        return None
    else:
        return [ make_shape(i, d) for i in dims ]

def merge_spec(target, source):
    for grp_spec in source.groups:
        target.set_group(grp_spec)
    for dset_spec in source.datasets:
        target.set_dataset(dset_spec)
    for attr_spec in source.attributes:
        target.set_attribute(attr_spec)

def load_spec(spec):

    spec = spec['fs']['core']['schema']

    # load Module specs
    # load File spec
    # /
    # /acquisition/
    # /analysis/
    # /epochs/
    # /general/
    # /general/extracellular_ephys/?
    # /general/intracellular_ephys/?
    # /general/optogenetics/?
    # /general/optophysiology/?
    # /processing/
    # /stimulus/

    root = build_group('root', spec['/'], ndtype='NWBFile')


    tree.append('NWBFile')
    acquisition = build_group('acquisition', spec['/acquisition/'])
    root.set_group(acquisition)
    analysis = build_group('analysis', spec['/analysis/'])
    root.set_group(analysis)
    epochs = build_group('epochs', spec['/epochs/'])
    root.set_group(epochs)

    module_json =  spec['/processing/'].pop("<Module>/*")

    processing = build_group('processing', spec['/processing/'])
    processing.add_group('Intermediate analysis of acquired data', neurodata_type_inc='Module', quantity='*')
    root.set_group(processing)

    stimulus = build_group('stimulus', spec['/stimulus/'])
    root.set_group(stimulus)

    general = build_group('general', spec['/general/'])
    root.set_group(general)

    extracellular_ephys = build_group('extracellular_ephys?', spec['/general/extracellular_ephys/?'])
    general.set_group(extracellular_ephys)

    intracellular_ephys = build_group('intracellular_ephys?', spec['/general/intracellular_ephys/?'])
    general.set_group(intracellular_ephys)

    optogenetics = build_group('optogenetics?', spec['/general/optogenetics/?'])
    general.set_group(optogenetics)

    optophysiology = build_group('optophysiology?', spec['/general/optophysiology/?'])
    general.set_group(optophysiology)
    tree.pop()

    base = [
        #build_group("<Module>/*", module_json, ndtype='Module'),
        build_group("<TimeSeries>/", spec["<TimeSeries>/"], ndtype='TimeSeries'),
        build_group("<Interface>/", spec["<Interface>/"], ndtype='Interface'),
        build_group('<Module>/', module_json, ndtype='Module'),
    ]


    # load TimeSeries specs

    type_specs = dict()
    subspecs = [
        'epoch',
        'ecephys',
        'icephys',
        'image',
        'ophys',
        'ogen',
        'behavior',
        'misc',
        'retinotopy',
    ]
    type_specs['file'] = [root]

    type_specs['epoch'] = []

    type_specs['ecephys'] = [
        "<ElectricalSeries>/",
        "<SpikeEventSeries>/",
        "ClusterWaveforms/",
        "Clustering/",
        "FeatureExtraction/",
        "EventDetection/",
        "EventWaveform/",
        "FilteredEphys/",
        "LFP/",
    ]

    type_specs['icephys'] = [
        "<PatchClampSeries>/",
        "<CurrentClampSeries>/",
        "<IZeroClampSeries>/",
        "<CurrentClampStimulusSeries>/",
        "<VoltageClampSeries>/",
        "<VoltageClampStimulusSeries>/"
    ]

    type_specs['image'] = [
        "<ImageSeries>/",
        "<ImageMaskSeries>/",
        "<OpticalSeries>/",
        "<IndexSeries>/",
    ]

    type_specs['ophys'] = [
        "<TwoPhotonSeries>/",
        "<RoiResponseSeries>/",
        "DfOverF/",
        "Fluorescence/",
        "ImageSegmentation/",
    ]

    type_specs['ogen'] = [
        "<OptogeneticSeries>/",
    ]

    type_specs['behavior'] = [
        "<SpatialSeries>/",
        "BehavioralEpochs/",
        "BehavioralEvents/",
        "BehavioralTimeSeries/",
        "PupilTracking/",
        "EyeTracking/",
        "CompassDirection/",
        "Position/",
        "MotionCorrection/",
    ]

    type_specs['misc'] = [
        "<AbstractFeatureSeries>/",
        "<AnnotationSeries>/",
        "<IntervalSeries>/",
        "UnitTimes/",
    ]


    type_specs['retinotopy'] = [
        "ImagingRetinotopy/",
    ]

    def mapfunc(name):
        namearg = name
        ndt = None
        if name[0] == '<':
            namearg = name
            ndt = name[1:name.rfind('>')]
            #return build_group(NAME_WILDCARD, spec[name])
        else:
            ndt = name[0:name.rfind('/')]
            #return build_group(name, spec[name])

        return build_group(namearg, spec[name], ndtype=ndt)

    for key in subspecs:
        type_specs[key] = list(map(mapfunc, type_specs[key]))

    type_specs['base'] = base
    for subspec in metadata_ndts:
        loc = subspec_locations[subspec.neurodata_type_def]
        type_specs[loc].append(subspec)
    return { k: {'groups': v} for k, v in type_specs.items() }



spec_path = sys.argv[1]
outdir = sys.argv[2] if len(sys.argv) > 2 else "."
with open(spec_path) as spec_in:
    nwb_spec = load_spec(json.load(spec_in))
    #nwb_spec = load_iface(json.load(spec_in))


ns = dict()
ns['doc'] = 'NWB namespace'
ns['name'] = CORE_NAMESPACE
ns['full_name'] = 'NWB core'
ns['version'] = '1.2.0'
ns['date'] = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
ns['author'] = ['Keith Godfrey', 'Jeff Teeters', 'Oliver Ruebel', 'Andrew Tritt']
ns['contact'] = ['keithg@alleninstitute.org', 'jteeters@berkeley.edu', 'oruebel@lbl.gov', 'ajtritt@lbl.gov']
ns['namespace_cls'] = NWBNamespace
ns_builder = NamespaceBuilder(ns.pop('doc'), ns.pop('name'), **ns)

schema = list()

order = [
    'base',
    'epoch',
    'image',
    'file',
    'misc',
    'behavior',
    'ecephys',
    'icephys',
    'ogen',
    'ophys',
    'retinotopy',
]
for key  in order:
    value = nwb_spec[key]
    filename = 'nwb.%s.yaml' % key
    for spec in value['groups']:
        ns_builder.add_spec(filename, spec)
    #with open('%s/%s' % (outdir, filename), 'w') as out:
    #    yaml.dump(json.loads(json.dumps(value)), out, default_flow_style=False)
    #schema.append({'source': filename})

ns_file = 'nwb.namespace.yaml'
#ns['schema'] = schema
#ns = {'namespaces': [SpecNamespace.build_namespace(**ns)]}
#with open(ns_file, 'w') as out:
#    yaml.dump(json.loads(json.dumps(ns)), out, default_flow_style=False)

ns_builder.export(ns_file, outdir=outdir)


import tarfile
cwd = os.getcwd()
os.chdir(outdir)
tar = tarfile.open('nwb_core.tar', 'w')
for key in sorted(nwb_spec.keys()):
    specfile = 'nwb.%s.yaml' % (key)
    tar.add(specfile)
tar.add('nwb.namespace.yaml')
tar.close()
os.chdir(cwd)
