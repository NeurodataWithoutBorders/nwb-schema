import os
import sys
import json
#import yaml
from ruamel import yaml

import pynwb
from pynwb.io.spec import Spec, AttributeSpec, BaseStorageSpec, DatasetSpec, GroupSpec, SpecCatalog


ndmap = {
    "<timeseries_X>/*": 'EpochTimeSeries',
    "<epoch_X>/*": 'Epoch',
    "<device_X>*": 'Device',
    "<specification_file>*": 'SpecFile',
    "<electrode_group_X>": 'ElectrodeGroup',
    "<electrode_X>": 'IntracellularElectrode',
    "<site_X>/*": 'OptogeneticStimulusSite',
    "<channel_X>": 'OpticalChannel',
    "<imaging_plane_X>/*": 'ImagingPlane',
    "<unit_N>/+": 'SpikeUnit',
    #"<image_name>/+": , # TODO: Figure out how to move this to a link to an ImagingPlane neurodata_type
    "<roi_name>/*": 'ROI',
    "<image_plane>/*": 'PlaneSegmentation',
}

metadata_links = {
    'electrode_idx': 'ElectrodeGroup',
    'imaging_plane': 'ImagingPlane',
    'site': 'OptogeneticStimulusSite',
    'electrode_name': 'IntracellularElectrode',
}

metadata_links_doc = {
    'electrode_idx': 'link to ElectrodeGroup group that generated this TimeSeries data',
    'imaging_plane': 'link to ImagingPlane group from which this TimeSeries data was generated',
    'site': 'link to OptogeneticStimulusSite group that describes the site to which this stimulus was applied',
    'electrode_name': 'link to IntracellularElectrode group that describes th electrode that was used to apply or record this data',
}
metadata_links_rename = {
    'electrode_idx': 'electrode_group',
    'electrode_name': 'electrode',
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
    '<Module>/*': 'Interface objects containing data output from processing steps',

    #TODO: finish documenting these guys
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
    myname = kwargs.pop('name', '*')
    doc = kwargs.pop('doc')
    if doc is None:
        print('no doc for name %s, ndt %s' % (myname, kwargs.get('neurodata_type_def', kwargs.get('neurodata_type'))), file=sys.stderr)
    if myname == '*':
        grp_spec = GroupSpec(doc, **kwargs)
    else:
        grp_spec = GroupSpec(doc, name=myname, **kwargs)
    return grp_spec

def build_group(name, d, ndtype=None):
    #print('building %s' % name, file=sys.stderr)
    required = True
    myname = name
    if myname[-1] == '?':
        required = False
        myname = myname[:-1]
    if myname[-1] == '^':
        required = False
        myname = myname[:-1]
    if myname[-1] == '/':
        myname = myname[:-1]
    if myname == '*':
        required = False
    extends = None
    if 'merge' in d:
        merge = d.pop('merge')
        print('Found merge directive for %s' % name, file=sys.stderr)
        base = merge[0]
        end = base.rfind('>')
        base = base[1:end] if end > 0 else base
        #extends = all_specs[base]
        extends = base
        if len(d) == 0:
            print('%s - spec empty after popping merge' %  name, file=sys.stderr)

    if myname[0] == '<':
        neurodata_type = ndmap.get(myname)
        #print('found neurodata_type %s' % neurodata_type, file=sys.stderr)
        if neurodata_type is None:
            neurodata_type = ndtype
        else:
            myname = '*'
        #print('neurodata_type=%s, myname=%s' % (neurodata_type, myname), file=sys.stderr)
    else:
        neurodata_type = ndtype

    desc = d.get('description', None)
    if isinstance(desc, dict) or desc is None:
        print('popping _description ndt=%s, desc=%s' % (neurodata_type, desc), file=sys.stderr)
        desc = d.pop('_description', None)
        print('after popping ndt=%s, desc=%s' % (neurodata_type, desc), file=sys.stderr)
    else:
        print('popping description ndt=%s, desc=%s' % (neurodata_type, desc), file=sys.stderr)
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
        grp_spec = build_group_helper(name=myname, required=required, doc=desc, neurodata_type_def=neurodata_type, neurodata_type=extends)
        add_attributes(grp_spec, attributes)
    elif neurodata_type is not None:
        grp_spec = build_group_helper(name=myname, required=required, doc=desc, neurodata_type_def=neurodata_type, neurodata_type=extends)
    else:
        if myname == '*':
            grp_spec = build_group_helper(doc=desc, required=required, neurodata_type=extends)
        else:
            grp_spec = build_group_helper(doc=desc, name=myname, required=required, neurodata_type=extends)

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

        if tmp_name == 'include':
            ndt = next(iter(value.keys()))
            ndt = ndt[1:ndt.rfind('>')]
            #grp_spec.include_neurodata_group(ndt)
            doc = include_doc.get(name, include_doc.get(neurodata_type))
            grp_spec.add_group(doc, neurodata_type=ndt)
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
                grp_spec.add_group(doc, neurodata_type=ndt)
            else:
                group_name = key
                if group_name[-1] == '/':
                    group_name = group_name[0:-1]
                grp_spec.add_group(doc, neurodata_type=ndt, name=group_name)
        elif tmp_name in metadata_links:
            ndt = metadata_links[tmp_name]
            doc = metadata_links_doc[tmp_name]
            grp_spec.add_link(doc, ndt, name=metadata_links_rename.get(tmp_name, tmp_name))
        else:
            if key.rfind('/') == -1: # forward-slash not found
                grp_spec.set_dataset(build_dataset(tmp_name, value))
            else:
                grp_spec.set_group(build_group(tmp_name, value))

    if neurodata_type is not None:
        #print('adding %s to all_specs' % neurodata_type, file=sys.stderr)
        all_specs[neurodata_type] = grp_spec
    #else:
    #    print('no neurodata_type found for %s' % myname, file=sys.stderr)
    return grp_spec

def build_dataset(name, d):
    kwargs = remap_keys(name, d)
    #dset_spec = DatasetSpec(kwargs.pop('dtype'), name=myname, **kwargs)
    dset_spec = DatasetSpec(kwargs.pop('doc'), kwargs.pop('dtype'), **kwargs)
    if 'attributes' in d:
        add_attributes(dset_spec, d['attributes'])
    return dset_spec

def add_attributes(parent_spec, attributes):
    for attr_name, attr_spec in attributes.items():
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
    attr_spec = AttributeSpec(myname, dtype, doc, **kwargs)
    return attr_spec

def remap_keys(name, d):
    ret = dict()
    ret['required'] = True
    ret['name'] = name
    if name[-1] == '?':
        ret['required'] = False
        ret['name'] = name[:-1]
    elif name[-1] == '^':
        ret['name'] = name[:-1]
    ret['const'] = d.get('const', None)
    ret['dtype'] = d.get('data_type', 'None')

    ret['value'] = d.get('value', None)
    if isinstance(ret['value'], list) and len(ret['value']) == 1:
        ret['value'] = ret['value'][0]
    def_doc = None
    ret['doc'] = d.get('description', def_doc)

    if ret['doc'] is None:
        ret['doc'] = override_doc.get(ret['name'])

    ret['dim'] = d.get('dimensions', None)

    return ret



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

    #root = GroupSpec(neurodata_type='NWBFile')
    root = build_group('root', spec['/'], 'NWBFile')


    acquisition = build_group('acquisition', spec['/acquisition/'])
    root.set_group(acquisition)
    analysis = build_group('analysis', spec['/analysis/'])
    root.set_group(analysis)
    epochs = build_group('epochs', spec['/epochs/'])
    root.set_group(epochs)

    module_json =  spec['/processing/'].pop("<Module>/*")

    processing = build_group('processing', spec['/processing/'])
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

    base = [
        "<TimeSeries>/", #
        "<Interface>/",
        "<Module>/",
    ]
    base = [
        root,
        build_group("<Module>/*", module_json, ndtype='Module'),
        build_group('*', spec["<TimeSeries>/"], ndtype='TimeSeries'),
        build_group('*', spec["<Interface>/"], ndtype='Interface')
    ]


    # load TimeSeries specs

    type_specs = dict()
    subspecs = [
        'ec_ephys',
        'ic_ephys',
        'image',
        'ophys',
        'ogen',
        'behavior',
        'misc',
        'retinotopy',
    ]

    type_specs['ec_ephys'] = [
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

    type_specs['ic_ephys'] = [
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
        "<RoiResponseSeries>/",
        "<IndexSeries>/",
    ]

    type_specs['ophys'] = [
        "<TwoPhotonSeries>/",
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
            namearg = '*'
            ndt = name[1:name.rfind('>')]
            #return build_group('*', spec[name])
        else:
            ndt = name[0:name.rfind('/')]
            #return build_group(name, spec[name])
            
        return build_group(namearg, spec[name], ndtype=ndt)

    #for key in type_specs.keys():
    for key in subspecs:
        type_specs[key] = list(map(mapfunc, type_specs[key]))

    type_specs['base'] = base
    return type_specs

"""
    mod_types = [
        "BehavioralEpochs/",
        "BehavioralEvents/",
        "BehavioralTimeSeries/",
        "ClusterWaveforms/",
        "Clustering/",
        "CompassDirection/",
        "DfOverF/",
        "EventDetection/",
        "EventWaveform/",
        "EyeTracking/",
        "FeatureExtraction/",
        "FilteredEphys/",
        "Fluorescence/",
        "ImageSegmentation/",
        "ImagingRetinotopy/",
        "LFP/",
        "MotionCorrection/",
        "Position/",
        "PupilTracking/",
        "UnitTimes/",
    ]

    ts_types = [
        "<TimeSeries>/", #
        "<PatchClampSeries>/",
        "<CurrentClampSeries>/", #
        "<IZeroClampSeries>/", #
        "<CurrentClampStimulusSeries>/", #
        "<VoltageClampSeries>/", #
        "<VoltageClampStimulusSeries>/", #
        "<ElectricalSeries>/", #
        "<SpikeEventSeries>/", #
        "<ImageSeries>/", #
        "<ImageMaskSeries>/", #
        "<IndexSeries>/", #
        "<OpticalSeries>/", #
        "<OptogeneticSeries>/", #
        "<RoiResponseSeries>/", #
        "<SpatialSeries>/", #
        "<TwoPhotonSeries>/", #
    ]
    ts_specs = dict()
    while ts_types:
        ts_type = ts_types.pop(0)
        ts_dict = spec[ts_type]
        merge = list()
        all_bases = True
        for merge_type in ts_dict.pop('merge', list()):
            tmp = ts_specs.get(merge_type, None)
            if tmp:
                merge.append(tmp)
            else:
                ts_types.append(ts_type)
                all_bases = False
                break
        if not all_bases:
            continue

        ts_spec = build_group('*', ts_dict)
        #for m in merge:
        #    merge_spec(m, ts_spec)
        ts_specs[ts_type] = ts_spec

    #print ('created specs for all TimeSeries', file=sys.stderr)

    iface = build_group('*', spec['<Interface>/'])
    #print ('created specs for <Interface>', file=sys.stderr)


    mod_specs = dict()

    mod_types = [
        "BehavioralEpochs/",
        "BehavioralEvents/",
        "BehavioralTimeSeries/",
        "ClusterWaveforms/",
        "Clustering/",
        "CompassDirection/",
        "DfOverF/",
        "EventDetection/",
        "EventWaveform/",
        "EyeTracking/",
        "FeatureExtraction/",
        "FilteredEphys/",
        "Fluorescence/",
        "ImageSegmentation/",
        "ImagingRetinotopy/",
        "LFP/",
        "MotionCorrection/",
        "Position/",
        "PupilTracking/",
        "UnitTimes/",
    ]
    #print ('creating specs for Modules', file=sys.stderr)
    for mod in mod_types:
        mod_spec = spec[mod]
        #merge = mod_spec.pop('merge')
        mod_specs[mod] = build_group(mod, mod_spec)
        #merge_spec(mod_specs[mod], iface)
    #print ('created specs for all Modules', file=sys.stderr)

    #register with SpecMap
    #SpecCatalog.register_spec('NWB', root)
    #SpecCatalog.register_spec('Interface', iface)
    #for ts_type, ts_spec in ts_specs.items():
    #    tmp = ts_type[1:len(ts_type)-2]
    #    SpecCatalog.register_spec(tmp, ts_spec)
    #for mod_type, mod_spec in mod_specs.items():
    #    tmp = mod_type[1:len(mod_type)-1]
    #    SpecCatalog.register_spec(tmp, mod_spec)
    #    pass

    ret = [root, iface]
    ret.extend(ts_specs.values())
    ret.extend(mod_specs.values())
    ret = {'root': list(root.values()), 'Interface': list(iface.values()), 'modules': list(mod_specs.values()), 'timeseries': list(ts_specs.values())}
    return ret



def load_iface(spec):
    spec = spec['fs']['core']['schema']
    iface = build_group('*', spec['<Interface>/'])
    return iface
"""

def represent_str(self, data):
    s = data.replace('"', '\\"')
    return s
    #return self.represent_scalar("", '"%s"' % s)

spec_path = sys.argv[1]
with open(spec_path) as spec_in:
    nwb_spec = load_spec(json.load(spec_in))
    #nwb_spec = load_iface(json.load(spec_in))




for key, value  in nwb_spec.items():
    with open('nwb.%s.yaml' % key, 'w') as out:
        yaml.dump(json.loads(json.dumps(value)), out, default_flow_style=False)

#def quoted_presenter(dumper, data):
#    return dumper.represent_scalar('tag:yaml.org,2002:str', data, style='"')

#yaml.add_representer(str, quoted_presenter)
#yaml.add_representer(str, represent_str)
##print(json.dumps(nwb_spec, indent=4))
#print(yaml.dump(json.loads(json.dumps(nwb_spec)), default_flow_style=False, default_style='"'))
#print(yaml.dump(json.loads(json.dumps(nwb_spec)), default_flow_style=False))

