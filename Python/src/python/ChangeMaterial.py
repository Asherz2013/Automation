import unreal

# instances of unreal classes
editor_util = unreal.EditorUtilityLibrary()
layer_sys = unreal.LayersSubsystem()
editor_filter_lib = unreal.EditorFilterLibrary()

# get the selected material and selected static mesh actors
selected_actors = editor_util.get_selected_assets()
materials = editor_filter_lib.by_class(selected_actors, unreal.Material)

if len(materials) < 1:
    unreal.log_warning("Please select the to be assigned material")

else:
    material = materials[0]
    material_name = material.getfname()
    
    actors = layer_sys.get_selected_actors()
    static_mesh_actors = editor_filter_lib.by_class(actors, unreal.StaticMeshActors)

    for actor in static_mesh_actors:
        actor_name = actor.get_fname()
        unreal.log(actor_name)

        # get the static mesh component and assign the material
        actor_mesh_component = actor.static_mesh_component
        actor_mesh_component.set_material(0, material)

        unreal.log("Assigning mater '{}' to actor {}".format(material_name, actor_name))