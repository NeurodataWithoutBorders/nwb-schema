"""
Module with classes for rendering specifications and object hierarchies
"""
from form.spec.spec import AttributeSpec, LinkSpec
from pynwb.spec import NWBGroupSpec as GroupSpec
from pynwb.spec import NWBDatasetSpec as DatasetSpec
from pynwb.spec import NWBNamespace as Namespace
from form.spec.catalog import SpecCatalog
from pynwb.core import docval, getargs
import warnings


class SpecFormatter(object):
    """
    Helper class for formatting spec documents to string
    """
    @staticmethod
    def spec_to_json(spec, pretty=False):
        """
        Convert a given specification to json.

        :param spec: Specification data structure
        :type spec: GroupSpec, DatasetSpec, AttributeSpec, LinkSpec

        :param pretty: Should a pretty formatting be used when encoding the JSON.

        :return: JSON string for the current specification
        """
        import json
        if pretty:
            return json.dumps(spec, sort_keys=True, indent=4, separators=(',', ': '))
        else:
            return json.dumps(spec)

    @staticmethod
    def spec_to_yaml(spec):
        """
        Convert a given specification to yaml.

        :param spec: Specification data structure
        :type spec: GroupSpec, DatasetSpec, AttributeSpec, LinkSpec

        :return: YAML string for the current specification
        """
        import json
        try:
            from ruamel import yaml
        except:
            import yaml
        clean_spec = json.loads(SpecFormatter.spec_to_json(spec, pretty=True))
        return yaml.dump(clean_spec, default_flow_style=False)

    @classmethod
    def spec_to_rst(cls, spec):
        """
        Create an RST document for the given spec

        :param spec: Specification data structure
        :type spec: GroupSpec, DatasetSpec, AttributeSpec, LinkSpec

        :return: RSTDocument for the given spec
        """
        rst_doc = RSTDocument()
        rst_doc.add_spec(spec)
        return rst_doc

    @staticmethod
    def spec_from_file(filenames, group_spec_cls=None):
        """
        Generate a SpecCatalog for the fiven list of spec files

        :param filenames: List of YAML/JSON specification files
        :type filenames: List of strings
        :param group_spec_cls: The GroupSpec class to be used for parsing specificationss
        :return: SpecCatalog
        """
        try:
            from ruamel import yaml
        except:
            import yaml
        group_spec_cls = GroupSpec if group_spec_cls is None else group_spec_cls
        spec_catalog = SpecCatalog()
        for path in filenames:
            with open(path, 'r') as stream:
                d = yaml.safe_load(stream)
                specs = d.get('groups')
                if specs is None:
                    if d.get('namespaces') is not None:
                        warnings.warn("%s is a namespace file" % path)
                    else:
                        warnings.warn("no 'specs' found in %s" % path)
                else:
                    for spec_dict in specs:
                        print(spec_dict['neurodata_type_def'])
                        spec_obj = GroupSpec.build_spec(spec_dict)
                        spec_catalog.auto_register(spec_obj)
        return spec_catalog


class HierarchyDescription(dict):
    """
    Dictionary data structure used to describe the contents of the specification or NWB file hierarchy.
    This simple helper datas structure was designed to ease rendering of object hierarchies but may
    be useful for other purposes as well.

    Ultimately, this is a flattened version of a spec or namespace where all datasets, groups, attributes,
    and links are sorted into flat lists of dicts. The nesting of the objects is then described via
    a list of relationships between the objects. Each object has a unique name that is determined
    by the full path to the object plus the actual name or type of the object.

    TODO Instead of using our own dict datastructures to describe datasets, groups etc. we should use
         the standard spec datastructures provided by PyNWB.
    """
    RELATIONSHIP_TYPES = {'managed_by': 'Object managed by',
                          'link': 'Object links to',
                          'attribute_of': 'Object is attribute of'}

    def __init__(self):
        super(HierarchyDescription, self).__init__()
        super(HierarchyDescription, self).__setitem__('datasets', [])
        super(HierarchyDescription, self).__setitem__('groups', [])
        super(HierarchyDescription, self).__setitem__('attributes', [])
        super(HierarchyDescription, self).__setitem__('relationships', [])
        super(HierarchyDescription, self).__setitem__('links', [])

    def __setitem__(self, key, value):
        raise ValueError("Explicit setting of objects not allowed. Use the add_* functions to add objects")

    def add_dataset(self, name, shape=None, dtype=None, neurodata_type=None):
        """
        Add a dataset to the description

        :param name: Name of the dataset (full path)
        :param shape: Shape of the dataset
        :param dtype: Data type of the data
        :param neurodata_type: NWB neurodata_type
        """
        self['datasets'].append({
            'name': name,
            'shape': shape,
            'dtype': dtype,
            'neurodata_type': neurodata_type

        })

    def add_group(self, name, neurodata_type=None):
        """
        Add a group to the description

        :param name: Name of the group (full path)
        :param neurodata_type: NWB neurodata type
        """
        self['groups'].append({
            'name': name,
            'neurodata_type': neurodata_type
        })

    def add_attribute(self,  name, value):
        """
        Add an attribute

        :param name: Name of the attribute (Full name, including the path of the parent object)
        :param value: Value of the attribute
        :return:
        """
        self['attributes'].append({
            'name': name,
            'value': value
        })

    def add_link(self, name, target_type):
        """
        Add a link

        :param name: Name of the link (full path)
        :param target_type: Type of object the link points to.
        """
        self['links'].append({'name': name,
                              'target_type': target_type})

    def add_relationship(self, source, target, name, rtype):
        """
        Add a relationship between two objects

        :param source: Name of the source object (full path)
        :param target: Name of the target object (full path)
        :param name: Name of the relationship
        :param rtype: Type of the relationship
        """
        self['relationships'].append({
            'source': source,
            'target': target,
            'name': name,
            'type': rtype
        })

    @classmethod
    def from_spec(cls, spec):
        """
        Traverse the spec to compute spec related hierarchy data.
        :param spec: The specification object
        :type spec: GroupSpec, AttributeSpec, DatasetSpec
        :return: Instance of HierarchyDescription with the hierarchy of the objects
        """
        import os

        specstats = cls()

        def update_stats(obj, parent_name):
            """
            Function used to recursively visit all items in a stat and update the specstats object
            :param obj: The spec for the object
            :param parent_name: String with the full path of the parent in the hierarchy
            """
            obj_main_name = obj.name \
                if obj.get('name', None) is not None \
                else obj.get('neurodata_type_def', None) \
                if obj.get('neurodata_type_def', None) is not None \
                else obj.get('neurodata_type_inc', None) \
                if obj.get('neurodata_type_inc', None) is not None \
                else obj['target_type']
            if obj.get('name', None) is None:
                obj_main_name = '<' + obj_main_name + '>'
            obj_name = os.path.join(parent_name, obj_main_name)

            if isinstance(obj, GroupSpec):
                if obj.get('neurodata_type_def', None) is not None:
                    nd = obj['neurodata_type_def']
                else:
                    nd = obj.neurodata_type_inc
                specstats.add_group(name=obj_name,
                                    neurodata_type=nd)
            elif isinstance(obj, DatasetSpec):
                if obj.get('neurodata_type_def', None) is not None:
                    nd = obj['neurodata_type_def']
                else:
                    nd = obj.neurodata_type_inc
                specstats.add_dataset(name=obj_name,
                                      shape=obj.shape,
                                      dtype=obj['type'] if hasattr(obj, 'type') else None,
                                      neurodata_type=nd)
            elif isinstance(obj, AttributeSpec):
                specstats.add_attribute(name=obj_name,
                                        value=obj.value)
            elif isinstance(obj, LinkSpec):
                specstats.add_link(name=obj_name,
                                   target_type=obj['target_type'])

            # Recursively add all groups and datasets
            if isinstance(obj, GroupSpec):
                for d in obj.datasets:
                    dn = update_stats(d, obj_name)
                    specstats.add_relationship(source=obj_name,
                                               target=dn,
                                               name=dn+"_managed_by_"+obj_name,
                                               rtype='managed_by')
                for g in obj.groups:
                    gn = update_stats(g, obj_name)
                    specstats.add_relationship(source=obj_name,
                                               target=gn,
                                               name=gn+"_managed_by_"+obj_name,
                                               rtype='managed_by')
                for l in obj.links:
                    ln = update_stats(l, obj_name)
                    specstats.add_relationship(source=obj_name,
                                               target=ln,
                                               name=ln+"_managed_by_"+obj_name,
                                               rtype='managed_by')
            if isinstance(obj, GroupSpec) or isinstance(obj, DatasetSpec):
                for a in obj.attributes:
                    an = update_stats(a, obj_name)
                    specstats.add_relationship(source=obj_name,
                                               target=an,
                                               name=an+"_attribute_of_"+obj_name,
                                               rtype='attribute_of')
            return obj_name

        update_stats(spec, parent_name='/')
        return specstats

    @classmethod
    def from_hdf5(cls, hdf_object, root='/'):
        """
        Traverse the file to compute file object hierarchy data.

        :param hdf_object: The h5py.Group or h5py.File object. If a string is given then the function assumes
                           that this is a path to and HDF5 file and will open the file.
        :param root: String indicating the root object starting from which we should compute the file statistics.
                     Default value is "/", i.e., starting from the root itself
        :type root: String

        :return: Instance of HierarchyDescription with the hierarchy of the objects

        """
        import h5py
        import os

        filestats = cls()

        def update_stats(name, obj):
            """
            Callback function used in conjunction with the visititems function to compile
            statistics for the file

            :param name: the name of the object in the file
            :param obj: the hdf5 object itself
            """
            obj_name = os.path.join(root, name)
            # Group and dataset metadata
            if isinstance(obj, h5py.Dataset):
                ntype=None
                if 'neurodata_type' in obj.attrs.keys():
                    ntype = obj.attrs['neurodata_type'][:]
                filestats.add_dataset(name=obj_name, shape=obj.shape, dtype=obj.dtype, neurodata_type=ntype)
            elif isinstance(obj, h5py.Group):
                ntype = None
                if 'neurodata_type' in obj.attrs.keys():
                    ntype = obj.attrs['neurodata_type'][:]
                filestats.add_group(name=obj_name, neurodata_type=ntype)
                # visititems does not visit any links. We need to add them here
                for objkey in obj.keys():
                    objval = obj.get(objkey, getlink=True)
                    if isinstance(objval, h5py.SoftLink) or isinstance(objval, h5py.ExternalLink):
                        linktarget = obj[objkey]
                        if 'neurodata_type' in linktarget.attrs.keys():
                            targettype = linktarget.attrs['neurodata_type'][:]
                        else:
                            targettype = str(type(linktarget))
                        linkname = os.path.join(obj_name, objkey)
                        filestats.add_link(linkname, target_type=targettype)
                        if isinstance(objval, h5py.SoftLink):
                            filestats.add_relationship(source=linkname,
                                                       target=objval.path,
                                                       name=linkname,
                                                       rtype='link')
            # Visit all attributes of the object
            for attr_name, attr_value in obj.attrs.items():
                attr_path = os.path.join(obj_name, attr_name)
                filestats.add_attribute(name=attr_path, value=attr_value)
                filestats.add_relationship(source=attr_path,
                                           target=obj_name,
                                           name=attr_name + '_attribute_of_' + obj_name,
                                           rtype='attribute_of')

            # Create the relationship for the object
            if obj_name != '/':
                filestats.add_relationship(source=os.path.dirname(obj_name),
                                           target=obj_name,
                                           name=obj_name + '_managed_by_' + root,
                                           rtype='managed_by')
        # Determine the main HDF5 object
        if isinstance(hdf_object, str):
            main_hdf_object = h5py.File(hdf_object, 'r')
            close_main_hdf_object = True
        else:
            main_hdf_object = hdf_object
            close_main_hdf_object = False

        # Visit all items in the hdf5 object to compile the object statistics
        main_hdf_object[root].visititems(update_stats)
        if root == '/':
            update_stats(name='/', obj=main_hdf_object['/'])

        # Close the hdf5 object if we opened it
        if close_main_hdf_object:
            main_hdf_object.close()
            del main_hdf_object

        # Return the results
        return filestats


class NXGraphHierarchyDescription(object):
    """
    Description of the object hierarchy as an nx graph
    """

    @docval({'name': 'data', 'type': HierarchyDescription, 'doc': 'Data of the hierarchy'},
            {'name': 'include_groups', 'type': bool,
             'doc': 'Bool indicating whether we should include groups in the hierarchy', 'default': True},
            {'name': 'include_datasets', 'type': bool,
             'doc': 'Bool indicating whether we should include datasets in the hierarchy', 'default': True},
            {'name': 'include_attributes', 'type': bool,
             'doc': 'Bool indicating whether we should include attributes in the hierarchy', 'default': True},
            {'name': 'include_links', 'type': bool,
             'doc': 'Bool indicating whether we should include links in the hierarchy', 'default': True},
            {'name': 'include_relationships', 'type': bool,
             'doc': 'Bool or list of strings indicating thh types of relationships to be included', 'default': True})
    def __init__(self, **kwargs):
        self.data, self.include_groups, self.include_datasets, self.include_attributes, \
            self.include_links, self.include_relationships = getargs('data', 'include_groups',
                                                                     'include_datasets', 'include_attributes',
                                                                     'include_links', 'include_relationships',
                                                                     kwargs)
        self.graph = self.nxgraph_from_data(self.data,
                                            self.include_groups,
                                            self.include_datasets,
                                            self.include_attributes,
                                            self.include_links,
                                            self.include_relationships)
        self.pos = self.create_hierarchical_graph_layout(self.graph)

    def draw(self, **kwargs):
        """
        Draw the graph using the draw_graph method
        :param kwargs: Additional keyword arguments to be passed to the static draw_graph method
        :return:
        """
        return self.draw_graph(graph=self.graph, pos=self.pos, data=self.data, **kwargs)

    @staticmethod
    def nxgraph_from_data(data,
                          include_groups=True,
                          include_datasets=True,
                          include_attributes=True,
                          include_links=True,
                          include_relationships=True):
        """
        Create a networkX representation of the objects in the HiearchyDescription stored in self.data

        :param data: Description of the object hierarchy
        :type data: HierarchyDescription
        :param include_groups: Bool indicating whether we should include groups in the hierarchy
        :param include_datasets: Bool indicating whether we should include datasets in the hierarchy
        :param include_attributes: Bool indicating whether we should include groups in the hierarchy
        :param include_links: Bool indicating whether we should include links in the hierarchy
        :param include_relationships: Bool or list of strings indicating which types of relationships should be included

        :return:  NXGraph from self.data
        """
        import networkx as nx

        graph = nx.Graph() # nx.MultiDiGraph()
        # Add all nodes
        if include_datasets:
            for d in data['datasets']:
                graph.add_node(d['name'])
        if include_groups:
            for g in data['groups']:
                graph.add_node(g['name'])
        if include_attributes:
            for g in data['attributes']:
                graph.add_node(g['name'])
        if include_links:
            for l in data['links']:
                graph.add_node(l['name'])

        # Create edges from relationships
        rel_list = include_relationships \
            if isinstance(include_relationships, list) \
            else data.RELATIONSHIP_TYPES \
            if include_relationships is True \
            else []
        all_nodes = graph.nodes(data=False)
        if len(rel_list) > 0:
            for r in data['relationships']:
                # Add only those relationships we were asked to include
                if r['type'] in rel_list:
                    # Add only relationships for which we have both the source and target in the graph
                    if r['source'] in all_nodes and r['target'] in all_nodes:
                        graph.add_edge(r['source'], r['target'])
        return graph

    @staticmethod
    def create_hierarchical_graph_layout(graph):
        """
        Given a networkX graph of file hierarchy, comput the positions of all nodes of the
        graph (i.e., groups and datasets) in a hierarchical layout

        :param graph: Network X graph of file objects

        :return: Dictionary where the keys are the names of the nodes in the graph and the values are
                 tuples with the floating point x and y coordinates for that node.
        """

        import numpy as np

        pos_hierarchy = {}
        allnodes = graph.nodes(data=False)
        nodes_at_level = {}
        for v in allnodes:
            xpos = len(v.split('/')) if v != '/' else 1
            try:
                nodes_at_level[xpos] += 1
            except KeyError:
                nodes_at_level[xpos] = 1

        curr_nodes_at_level = {i: 0 for i in nodes_at_level.keys()}
        for i, v in enumerate(np.sort(allnodes)):
            xpos = len(v.split('/')) if v != '/' else 1
            ypos = 1 - float(curr_nodes_at_level[xpos]) / nodes_at_level[xpos] * 1
            curr_nodes_at_level[xpos] += 1
            pos_hierarchy[v] = np.asarray([np.power(xpos, 2), ypos])

        return pos_hierarchy

    @staticmethod
    def create_warped_hierarchial_graph_layout(graph):
        """
        Given a networkX graph of file hierarchy, compute the positions of all nodes of the
        graph (i.e., groups and datasets) in a hierarchical layout where the levels of the
        hierarchy are warped to follow a semi-circle shape.

        :param graph: Network X graph of file objects

        :return: Dictionary where the keys are the names of the nodes in the graph and the values are
                 tuples with the floating point x and y coordinates for that node.
        """
        import numpy as np

        pos_hierarchy = {}
        allnodes = graph.nodes(data=False)
        nodes_at_level = {}
        for v in allnodes:
            xpos = len(v.split('/')) if v != '/' else 1
            try:
                nodes_at_level[xpos] += 1
            except KeyError:
                nodes_at_level[xpos] = 1

        curr_nodes_at_level = {i: 0 for i in range(7)}
        for i, v in enumerate(np.sort(allnodes)):
            xpos = len(v.split('/')) if v != '/' else 1
            ypos = float(curr_nodes_at_level[xpos]) / nodes_at_level[xpos]
            curr_nodes_at_level[xpos] += 1
            if xpos > 3:
                xpos += np.sin(ypos*np.pi)
            xpos = np.power(xpos, 2)
            pos_hierarchy[v] = np.asarray([xpos, -ypos])

        return pos_hierarchy

    @staticmethod
    def normalize_graph_layout(graph_layout):
        """
        Normalize the positions in the given graph layout so that the x and y
        values have a range of [0,1]
        :param graph_layout: Dict where the keys are the names of the nodes in the graph
               and the values are tuples with the (x,y) locations for the nodes
        :return: New graph layout with normalized coordinates
        """
        import numpy as np
        # Compute positions stats
        xpos = np.asarray([i[0] for i in graph_layout.values()])
        ypos = np.asarray([i[1] for i in graph_layout.values()])
        xmin = xpos.min()
        xmax = xpos.max()
        xr = xmax - xmin
        ymin = ypos.min()
        ymax = ypos.max()
        yr = ymax - ymin

        # Create the output layout
        normlized_layout = {k: np.asarray([(n[0] - xmin) / xr, (n[1] - xmin) / yr]) for k, n in graph_layout.items()}
        return normlized_layout

    def suggest_xlim(self):
        """
        Suggest xlimits for plotting
        :return: Tupple with min/max x values
        """
        import numpy as np
        xpos = np.asarray([i[0] for i in self.pos.values()])
        xmin = xpos.min()
        xmax = xpos.max()
        xrange = np.abs(xmax-xmin)
        xmin -= xrange*0.2
        xmax += xrange*0.2
        return (xmin, xmax)

    def suggest_ylim(self):
        """
        Suggest ylimits for plotting
        :return: Tupple with min/max x values
        """
        import numpy as np
        ypos = np.asarray([i[1] for i in self.pos.values()])
        ymin = ypos.min()
        ymax = ypos.max()
        yrange = np.abs(ymax-ymin)
        ymin -= yrange*0.1
        ymax += yrange*0.1
        return (ymin, ymax)


    def suggest_figure_size(self):
        """
        Suggest a figure size for a graph based on the number of rows and columns in the hierarchy
        :param graph: Network X graph of file objects
        :return: Tuple with the width and height for the figure
        """
        allnodes = self.graph.nodes(data=False)
        nodes_at_level = {}
        for v in allnodes:
            xpos = len(v.split('/')) if v != '/' else 1
            try:
                nodes_at_level[xpos] += 1
            except KeyError:
                nodes_at_level[xpos] = 1
        num_cols = len(nodes_at_level)
        num_rows = max([v for v in nodes_at_level.values()])
        w = 8 # num_cols + 1.5
        h = min(num_rows*0.75, 8)  #num_rows * 0.5 + 1.5
        return (w,h)

    @staticmethod
    def draw_graph(graph,
                   pos,
                   data,
                   show_labels=True,
                   relationship_types=None,
                   figsize=None,
                   label_offset=(0.0, 0.012),
                   label_font_size=8,
                   xlim=None,
                   ylim=None,
                   legend_location='lower left',
                   axis_on=False,
                   relationship_counts=True,
                   show_plot=True,
                   relationship_colors=None,
                   relationship_alpha=0.7,
                   node_colors=None,
                   node_alpha=1.0,
                   node_shape='o',
                   node_size=20):
        """
        Helper function used to render the file hierarchy and the inter-object relationships

        :param graph: The networkx graph
        :param pos: Dict with the position for each node generated, e.g., via nx.shell_layout(graph)
        :param data: Data about the hierarchy
        :type data: HierarchyDescription
        :param show_labels: Boolean indicating whether we should show the names of the nodes
        :param relationship_types: List of edge types that should be rendered. If None, then all edges will be rendered.
        :param figsize: The size of the matplotlib figure
        :param label_offset: Offsets for the node lables. This may be either: i) None (default),
                   ii) Tuple with constant (x,y) offset for the text labels, or
                   iii) Dict of tuples where the keys are the names of the nodes for which labels should be moved
                        and the values are the (x,y) offsets for the given nodes.
        :param label_font_size: Font size for the lables
        :param xlim: The x limits to be used for the plot
        :param ylim: The y limits to be used for the plot
        :param legend_location: The legend location (e.g., 'upper left' , 'lower right')
        :param axis_on: Boolean indicating whether the axes should be turned on or not.
        :param relationship_counts: Boolean indicating if edge/relationship counts should be shown.
        :param relationship_colors: Optional dict for changing the default colors used for drawing relationship edges.
            The keys of the dict are the type of relationship and the values are the names of the colors. This may
            also be a single color string in case that all relationships should be shown in the same color. Default
            behavior is:

               ```{'shared_encoding': 'magenta',
                  'indexes_values': 'cyan',
                  'equivalent': 'gray',
                  'indexes': 'orange',
                  'user': 'green',
                  'shared_ascending_encoding': 'blue',
                  'order': 'red',
                  'managed_by': 'steelblue',
                  'attribute_of': 'black'}```

        :param relationship_alpha: Float alpha value in the range of [0,1] with the alpha value to be used
            for relationship edges. This may also be a dict of per-relationship-typ alpha values, similar
            to relationship_colors.
        :param node_colors: Dict with the color strings of the different node types. This may also be a single
                string in case that the same color should be used for all node types. Defaul behavior is:

                ```{'typed_dataset': 'blue',
                    'untyped_dataset': 'lightblue',
                    'typed_group': 'red',
                    'untyped_group': 'orange',
                    'attribute': 'gray',
                    'link': 'white'}```

        :param node_shape: Dict indicating the shape string for each node type. This may also be a single string
               if the same shape should be used for all node types. Default='o'
        :param node_size:  Dict indicating the integer size for each node type. This may also be a single int
               if the same size should be used for all node types. Default='o'
        :param show_plot: If true call show to display the figure. If False return the matplotlib figure
                          without showing it.

        :return: Matplotlib figure of the data

        """
        from matplotlib import pyplot as plt
        import networkx as nx
        import os
        from copy import deepcopy
        from matplotlib.ticker import NullLocator

        fig = plt.figure(figsize=figsize)
        # List of object names
        all_nodes = graph.nodes(data=False)
        n_names = {'typed_dataset': [i['name'] for i in data['datasets'] if i['neurodata_type'] is not None and i['name'] in all_nodes],
                   'untyped_dataset': [i['name'] for i in data['datasets'] if i['neurodata_type'] is None and i['name'] in all_nodes],
                   'typed_group': [i['name'] for i in data['groups'] if i['neurodata_type'] is not None and i['name'] in all_nodes],
                   'untyped_group': [i['name'] for i in data['groups'] if i['neurodata_type'] is None and i['name'] in all_nodes],
                   'attribute': [i['name'] for i in data['attributes'] if i['name'] in all_nodes],
                   'link': [i['name'] for i in data['links'] if i['name'] in all_nodes]
                   }
        # Define the legend labels
        n_legend = {'typed_dataset': 'Typed Dataset (%i)' % len(n_names['typed_dataset']),
                    'untyped_dataset': 'Untyped Dataset (%i)' % len(n_names['untyped_dataset']),
                    'typed_group': 'Typed Group (%i)' % len(n_names['typed_group']),
                    'untyped_group': 'Untyped Group (%i)' % len(n_names['untyped_group']),
                    'attribute': 'Attributes (%i)' % len(n_names['attribute']),
                    'link': 'Links (%i)' % len(n_names['link'])
        }
        # Define the node colors
        n_colors = {'typed_dataset': 'blue',
                    'untyped_dataset': 'lightblue',
                    'typed_group': 'red',
                    'untyped_group': 'orange',
                    'attribute': 'gray',
                    'link': 'white'
        }
        if node_colors is not None:
            node_colors.update(node_colors)
        # Define the node alpha
        n_alpha_base = node_alpha if isinstance(node_alpha, float) else 1.0
        n_alpha = {k: n_alpha_base for k in n_colors}
        if isinstance(node_alpha, dict):
            n_alpha.update(node_alpha)
        # Define the shape of each node type
        n_shape_base = node_shape if isinstance(node_alpha, float) else 'o'
        n_shape = {k: n_shape_base for k in n_colors}
        if isinstance(node_shape, dict):
            n_shape.update(node_shape)
        # Define the size of each node type
        n_size_base = node_size if isinstance(node_size, float) or isinstance(node_size, int) else 20
        n_size = {k: n_size_base for k in n_colors}
        if isinstance(node_size, dict):
            n_size.update(node_size)

        # Draw all the nodes by type with the type-specific properties
        for ntype in n_names.keys():
            # Draw the typed dataset nodes of the network
            nx.draw_networkx_nodes(graph, pos,
                                   nodelist=n_names[ntype],
                                   node_color=n_colors[ntype],
                                   node_shape=n_shape[ntype],
                                   node_size=n_size[ntype],
                                   alpha=n_alpha[ntype],
                                   font_family='STIXGeneral',
                                   label=n_legend[ntype])

        # Define edge colors and alpha values
        rel_colors = {'shared_encoding': 'magenta',
                      'indexes_values': 'cyan',
                      'equivalent': 'gray',
                      'indexes': 'orange',
                      'user': 'green',
                      'shared_ascending_encoding': 'blue',
                      'order': 'lightblue',
                      'managed_by': 'steelblue',
                      'link': 'magenta',
                      'attribute_of': 'black'}
        if isinstance(relationship_colors, str):
            for k in rel_colors:
                rel_colors[k] = relationship_colors
        if relationship_colors is not None:
            rel_colors.update(relationship_colors)
        rel_base_alpha = 0.6 if not isinstance(relationship_alpha, float) else relationship_alpha
        rel_alpha = {k: rel_base_alpha for k in rel_colors}
        if isinstance(relationship_alpha, dict):
            rel_alpha.update(relationship_alpha)
        # Resort edges by type
        edge_by_type = {}
        for r in data['relationships']:
            if r['type'] in edge_by_type:
                edge_by_type[r['type']].append((r['source'], r['target']))
            else:
                edge_by_type[r['type']] = [(r['source'], r['target'])]
        # Determine the counts of relationships, i.e., how many relationships of each type do we have
        if relationship_counts:
            relationship_counts = {rt: len(rl) for rt, rl in edge_by_type.items()}
        else:
            relationship_counts = None
        # Draw the network edges
        for rt, rl in edge_by_type.items():
            if relationship_types is None or rt in relationship_types:
                try:
                    nx.draw_networkx_edges(graph,
                                           pos,
                                           edgelist=rl,
                                           width=1.0,
                                           alpha=rel_alpha[rt],
                                           edge_color=rel_colors[rt],
                                           arrows=False,
                                           style='solid' if rt != 'link' else 'dashed',
                                           label=rt if relationship_counts is None else (rt+' (%i)' % relationship_counts[rt])
                                           )
                except KeyError:
                    pass

        if show_labels:
            # Create node labels
            labels = {i: os.path.basename(i) if len(os.path.basename(i)) > 0 else i for i in graph.nodes(data=False)}
            # Determine label positions
            if label_offset is not None:
                # Move individual lables by the user-defined offsets
                if isinstance(label_offset, dict):
                    label_pos = deepcopy(pos)
                    for k, v in label_offset.items():
                        label_pos[k] += v
                # Move all labels by a single, user-defined offset
                else:
                    label_pos = {k: (v+label_offset) for k, v in pos.items()}
            else:
                # Use the node positions as label positions
                label_pos = pos
            # Draw the labels
            nx.draw_networkx_labels(graph, label_pos, labels, font_size=label_font_size)

        if axis_on:
            plt.axis('on')
        else:
            plt.axis('off')
            # Get rid of large whitespace around the figure
            plt.gca().xaxis.set_major_locator(NullLocator())
            plt.gca().yaxis.set_major_locator(NullLocator())
        plt.legend(prop={'size': label_font_size}, loc=legend_location)
        plt.autoscale(True)
        plt.tight_layout()
        if xlim:
            plt.xlim(xlim)
        if ylim:
            plt.ylim(ylim)
        if show_plot:
            plt.show()
        return fig


class RSTDocument(object):
    """
    Helper class for generating an reStructuredText (RST) document

    :ivar document: The string with the RST document
    :ivar newline: Newline string
    """
    ADMONITIONS = ['attention', 'caution', 'danger', 'error', 'hint', 'important', 'note', 'tip', 'warning']
    ALIGN = ['top', 'middle', 'bottom', 'left', 'center', 'right']

    def __init__(self):
        """Initalize empty RST document"""
        self.document = ""
        self.newline = "\n"
        self.default_indent = '    '

    def __get_headingline(self, title, heading_char):
        """Create a headingline for a given title"""
        heading = ""
        for i in range(len(title)):
            heading += heading_char
        return heading

    def add_text(self, text):
        """
        Add the given text to the document
        :param text: String with the text to be added
        """
        self.document += text

    def add_part(self, title):
        """
        Add a document part heading

        :param title: Title of the reading
        """
        heading = self.__get_headingline(title, '#')
        self.document += (heading + self.newline)
        self.document += (title + self.newline)
        self.document += (heading + self.newline)
        self.document += self.newline

    def add_chapter(self, title):
        """
        Add a document chapter heading

        :param title: Title of the reading
        """
        heading = self.__get_headingline(title, '*')
        self.document += (heading + self.newline)
        self.document += (title + self.newline)
        self.document += (heading + self.newline)
        self.document += self.newline

    def add_label(self, label):
        """
        Add a section lable
        :param label: name of the lable
        """
        self.document += ".. _%s:" % label
        self.document += self.newline + self.newline

    @staticmethod
    def get_reference(label, link_title=None):
        """
        Get RST text to create a reference to the given label
        :param label: Name of the lable to link to
        :param link_title: Text for the link
        :return: String with the inline reference text
        """
        if link_title is not None:
            return ":ref:`%s <%s>`" % (link_title, label)
        else:
            return ":ref:`%s`" % label

    def get_numbered_reference(self, label):
        return ":numref:`%s`" % label

    def add_section(self, title):
        """
        Add a document section heading

        :param title: Title of the reading
        """
        heading = self.__get_headingline(title, '=')
        self.document += (title + self.newline)
        self.document += (heading + self.newline)
        self.document += self.newline

    def add_subsection(self, title):
        """
        Add a document subsection heading

        :param title: Title of the reading
        """
        heading = self.__get_headingline(title, '-')
        self.document += (title + self.newline)
        self.document += (heading + self.newline)
        self.document += self.newline

    def add_subsubsection(self, title):
        """
        Add a document subsubsection heading

        :param title: Title of the reading
        """
        heading = self.__get_headingline(title, '^')
        self.document += (title + self.newline)
        self.document += (heading + self.newline)
        self.document += self.newline

    def add_paragraph(self, title):
        """
        Add a document paragraph heading

        :param title: Title of the reading
        """
        heading = self.__get_headingline(title, '"')
        self.document += (title + self.newline)
        self.document += (heading + self.newline)
        self.document += self.newline

    def add_code(self, code_block, code_type='python', show_line_numbers=True, emphasize_lines=None):
        """
        Add code block to the document
        :param code_block: String with the code block
        :param show_line_numbers: Bool indicating whether line number should be shown
        :param emphasize_lines: None or list of int with the line numbers to be highlighted
        :param code_type: The language type to be used for source code highlighting in the rst doc
        """
        self.document += ".. code-block:: %s%s" % (code_type, self.newline)
        if show_line_numbers:
            self.document += self.indent_text(':linenos:') + self.newline
        if emphasize_lines is not None:
            self.document += self.indent_text(':emphasize-lines: ')
            for i, j in enumerate(emphasize_lines):
                self.document += str(j)
                if i < len(emphasize_lines)-1:
                    self.document += ','
            self.document += self.newline
        self.document += self.newline
        self.document += self.indent_text(code_block)  # Indent text by 4 spaces
        self.document += self.newline
        self.document += self.newline

    def indent_text(self, text, indent=None):
        """
        Helper function used to indent a given text by a given prefix. Usually 4 spaces.

        :param text: String with the text to be indented
        :param indent: String with the prefix to be added to each line of the string. If None then self.default_indent
                       will be used.

        :return: New string with each line indented by the current indent
        """
        curr_indent = indent if indent is not None else self.default_indent
        return curr_indent + curr_indent.join(text.splitlines(True))

    def add_list(self, content, indent=None, item_symbol='*'):
        """
        Recursively add a list with possibly multiple levels to the document
        :param content: Nested list of strings with the content to be rendered
        :param indent: Indent to be used for the list. Required for recursive indentation of lists.
        """
        indent = '' if indent is None else indent
        for item in content:
            if isinstance(item, list) or isinstance(item, tuple):
                self.add_list(item,
                              indent=indent+self.default_indent,
                              item_symbol=item_symbol)
            else:
                self.document += ('%s%s %s%s' % (indent, item_symbol, item, self.newline))
        self.document += self.newline

    def add_admonitions(self, atype, text):
        """
        Add and admonition to the text. Admonitions are specially marked "topics"
        that can appear anywhere an ordinary body element can

        :param atype: One of RTDDocument.ADMONITIONS
        :param text: The RTD formatted text to be shown or the RTDDocument to be rendered as part of the admonition
        """
        curr_text = text if not isinstance(text, RSTDocument) else text.document
        self.document += self.newline
        self.document += ".. %s::" % atype
        self.document += self.newline
        self.document += self.indent_text(text)
        self.document += self.newline
        self.document += self.newline

    def add_include(self, filename):
        """
        Include the file with the given name as part of this RST document

        :param filename: Name of the file to be included
        :return:
        """
        self.document += ".. include:: %s" % filename
        self.document += self.newline

    def add_figure(self,
                   img,
                   caption=None,
                   legend=None,
                   alt=None,
                   height=None,
                   width=None,
                   scale=None,
                   align=None,
                   target=None):
        """

        :param img: Path to the image to be shown as part of the figure.
        :param caption: Optional caption for the figure
        :type caption: String or RSTDocument
        :param legend: Figure legend
        :type legend: String or RST Document
        :param alt: Alternate text.  A short description of the image used when the image cannot be displayed.
        :param height: Height of the figure in pixel
        :type height: Int
        :param width: Width of the figure in pixel
        :type width: Int
        :param scale: Uniform scaling of the figure in %. Default is 100.
        :type scale: Int
        :param align: Alignment of the figure. One of RTDDocument.ALIGN
        :param target: Hyperlink to be placed on the image.
        """
        self.document += self.newline
        self.document += ".. figure:: %s" % img
        self.document += self.newline
        if scale is not None:
            self.document += (self.indent_text(':scale: %i' % scale) + ' %' + self.newline)
        if alt is not None:
            self.document += (self.indent_text(':alt: %s' % alt) + self.newline)
        if height is not None:
            self.document += (self.indent_text(':height: %i px' % height) + self.newline)
        if width is not None:
            self.document += (self.indent_text(':width: %i px' % width) + self.newline)
        if align is not None:
            if align not in self.ALIGN:
                raise ValueError('align not valid. Found %s expected one of %s' % (str(align), str(self.ALIGN)))
            self.document += (self.indent_text(':align: %s' % align) + self.newline)
        if target is not None:
            self.document += (self.indent_text(':target: %s' % target) + self.newline)
        self.document += self.newline
        if caption is not None:
            curr_caption = caption if not isinstance(caption, RSTDocument) else caption.document
            self.document += (self.indent_text(curr_caption) + self.newline)
        if legend is not None:
            if caption is None:
                self.document += (self.indent_text('.. ') + self.newline + self.default_indent + self.newline)
            curr_legend = legend if not isinstance(legend, RSTDocument) else legend.document
            self.document += (self.indent_text(curr_legend) + self.newline)
        self.document += self.newline

    def add_sidebar(self, text, title, subtitle=None):
        """
        Add a sidebar. Sidebars are like miniature, parallel documents that occur inside other
        documents, providing related or reference material.

        :param text: The content of the sidebar
        :type text: String or RSTDocument
        :param title: Title of the sidebar
        :type title: String
        :param subtitle: Optional subtitel of the sidebar
        :type subtitle: String
        """
        self.document += self.newline
        self.document += '.. sidebar:: ' + title + self.newline
        if subtitle is not None:
            self.document += (self.indent_text(':subtitle: %s' % subtitle) + self.newline)
        self.document += self.newline
        curr_text = text if not isinstance(text, RSTDocument) else text.document
        self.document += (self.indent_text(curr_text)) + self.newline + self.newline

    def add_topic(self, text, title):
        """
        Add a topic. A topic is like a block quote with a title, or a self-contained section with no subsections.

        :param text: The content of the sidebar
        :type text: String or RSTDocument
        :param title: Title of the sidebar
        :type title: String
        """
        self.document += self.newline
        self.document += '.. sidebar:: ' + title + self.newline
        self.document += self.newline
        curr_text = text if not isinstance(text, RSTDocument) else text.document
        self.document += (self.indent_text(curr_text)) + self.newline + self.newline

    def add_spec(self, spec, show_json=False, show_yaml=False):
        """
        Convert the given spec to RST and add it to the document

        :param spec: Specification data structure
        :param show_json: Show JSON-based spec as part of the RST
        :param show_yaml: Show YAML-based spec as part of the RST
        :type spec: GroupSpec, DatasetSpec, AttributeSpec, LinkSpec
        """
        if show_json:
            self.add_code(SpecFormatter.spec_to_json(spec, True), code_type='json')
        if show_yaml:
            self.add_code(SpecFormatter.spec_to_yaml(spec), code_type='yaml')

    def add_latex_clearpage(self):
        self.document += self.newline
        self.document += ".. raw:: latex" + self.newline + self.newline
        self.document += self.default_indent + '\clearpage \\newpage' + self.newline + self.newline

    def add_table(self, rst_table, **kwargs):
        """
        Render an RSTtable in this document

        :param rst_table: RSTTable object to be rendered in this document
        :param kwargs: Arguments to be passed to the RSTTable.render
        """
        rst_table.render(self, **kwargs)

    def write(self, filename, mode='w'):
        """
        Write the document to file

        :param filename: Name of the output file
        :param mode: file open mode
        """
        outfile = open(filename, mode=mode)
        outfile.write(self.document)
        outfile.flush()
        outfile.close()


class  RSTTable(object):
    """
    Helper class to generate RST tables
    """
    def __init__(self, cols):
        """

        :param cols: List of strings with the column labels. Or int with the number of columns
        :return:
        """
        self.__table = []
        self.__cols = cols if not isinstance(cols, int) else ([''] * cols)
        self.newline = "\n"


    def set_cell(self, row, col, text):
        if col >= len(self.__cols):
            raise ValueError('Column index out of bounds: col=%i , max_index=%i' % (col, len(self.__cols)-1))
        if row >= len(self.__table):
            raise ValueError('Row index out of bounds: row=%i , max_index=%i' % (row, len(self.__table)-1))
        self.__table[row][col] = text

    def __len__(self):
        return self.num_rows()

    def num_rows(self):
        """
        :return: Number of rows in the table
        """
        return len(self.__table)

    def num_cols(self):
        """
        :return: Number of columns in the table
        """
        return len(self.__cols)

    def add_row(self, row_values=None, replace_none=None, convert_to_str=True):
        """
        Add a row of values to the table
        :param row_values: List of all values for the current row (or None if an empty row should be added).
                           If values in the list contain newline strings then this will result in the creation
                           of a multiline row with as many lines as the larges cell (i.e. the cell with the largest
                           number of newline symbols).
        :param replace_none:  String to be used to replace None values in the row data (default=None, i.e., do not
                              replace None values)
        :param convert_to_str: Boolean indicating whether all row values should be converted to strings. (default=True)
        """
        row_vals = row_values if row_values is not None else ([''] * len(self.__cols))
        if replace_none:
            for i, v in enumerate(row_values):
                if v is None:
                    row_vals[i] = replace_none
        if convert_to_str:
            row_vals = [str(v) for v in row_vals]
        self.__table.append(row_vals)

    def set_col(self, col, text):
        if col >= len(self.__cols):
            raise ValueError('Column index out of bounds: col=%i , max_index=%i' % (col, len(self.__cols)-1))
        self.__cols[col] = text

    def render(self,
               rst_doc=None,
               title=None,
               table_class='longtable',
               widths=None,
               ignore_empty=True,
               table_ref=None,
               latex_tablecolumns=None):
        """
        Render the table to an RSTDocument

        :param rst_doc: RSTDocument where the table should be rendered in or None if a new document should be created
        :param title: String with the optional title for the table
        :param table_class: Optional class for the table.  We here use 'longtable' as default. Set to None to use
                     the Sphinx default. Other table classes are: 'longtable', 'threeparttable', 'tabular', 'tabulary'
        :param widths: Optional list of width for the columns
        :param ignore_empty: Boolean indicating whether empty tables should be rendered (i.e., if False then
                    headings with no additional rows will be rendered) or if no table should be created
                    if no data rows exists (if set to True). (default=True)
        :param table_ref: Name of the reference to be used for the table
        :param latex_tablecolumns: Latex columns description to be rendered as part of the Sphinx tabularcolumns::
                    argument. E.g. '|p{3.5cm}|p{1cm}|p{10.5cm}|'
        """
        if len(self.__table) == 0 and ignore_empty:
            return rst_doc if rst_doc is not None else RSTDocument()

        def table_row_divider(col_widths, style='='):
            #out="" if not use_longtable else "    "
            out="    "
            for cw in col_widths:
                out += '+' +  (cw+2) * style
            out += "+\n"
            return out

        def normalize_cell(cell, col_width):
            return " " + cell + (col_width  - len(cell) + 1) * " "

        def render_row(col_widths, row, newline=self.newline):

            row_lines = [r.split(newline) for r in row]
            num_lines = max([len(r) for r in row_lines])
            for r in row:
                if newline in r:
                    max(num_lines, len(r.split(newline)))
            row_text = ''
            for l in range(num_lines):
                row_text += '    |'
                for ri in range(len(row)):
                    cell = row_lines[ri][l] if len(row_lines[ri]) > l else ''
                    row_text += normalize_cell(cell, col_width=col_widths[ri]) + '|'
                row_text += newline
            return row_text
            #for i, cell, in enumerate(row):
            #    row_text += normalize_cell(cell, col_width=col_widths[i]) + '|'
            #row_text += newline
            #return row_text

        def cell_len(cell, newline=self.newline):
            return max(len(r) for r in cell.split(newline))

        col_widths = [max(out)+2 for out in map(list, zip(*[[cell_len(item) for item in row] for row in ([self.__cols,] + self.__table)]))]
        rst_doc = rst_doc if rst_doc is not None else RSTDocument()
        rst_doc.add_text(rst_doc.newline)
        if latex_tablecolumns:
            rst_doc.add_text('.. tabularcolumns:: %s%s' % (latex_tablecolumns, rst_doc.newline))
        if table_ref is not None:
            rst_doc.add_label(table_ref)
        rst_doc.add_text('.. table::')
        if title:
            rst_doc.add_text(' ' + title)
        rst_doc.add_text(rst_doc.newline)
        if widths:
            rst_doc.add_text('    :widths:')
            for i in widths:
                rst_doc.add_text(' %i' %i)
            rst_doc.add_text(rst_doc.newline)
        if table_class is not None:
            rst_doc.add_text('    :class: ' + table_class + rst_doc.newline)
        rst_doc.add_text(rst_doc.newline)

        # Render the table header
        rst_doc.add_text(table_row_divider(col_widths=col_widths, style='-'))
        rst_doc.add_text(render_row(col_widths, self.__cols, rst_doc.newline))
        rst_doc.add_text(table_row_divider(col_widths=col_widths, style='='))

        # Render the main table contents
        for row in self.__table:
            rst_doc.add_text(render_row(col_widths, row, rst_doc.newline))
            rst_doc.add_text(table_row_divider(col_widths=col_widths, style='-'))
        rst_doc.add_text(rst_doc.newline)
        rst_doc.add_text(rst_doc.newline)


        # Return the table
        return rst_doc

