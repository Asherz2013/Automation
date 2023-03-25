import unreal

#instances of unreal classes
editor_level_lib = unreal.EditorLevelLibrary()
editor_filter_lib = unreal.EditorFilterLibrary()

# get all the actors and filter them down to specific elements
actors = editor_level_lib.get_all_level_actors()

static_meshs = editor_filter_lib.by_class(actors, unreal.StaticMeshActor)
reflection_cap = editor_filter_lib.by_class(actors, unreal.ReflectionCapture)
blueprints = editor_filter_lib.by_id_name(actors, "BP_")

moved = 0

# Create a mapping between folder names and arrays
mapping = {
    "StaticMeshActors": static_meshs,
    "ReflectionCaptures": reflection_cap,
    "Blueprints": blueprints
}

for folder_name in mapping:
    # for eavery list of actors
    unreal.log(folder_name)

    for actor in mapping[folder_name]:
        actor_name = actor.get_fname()
        actor.set_folder_path(folder_name)
        unreal.log("Moved {} into {}".format(actor_name, folder_name))

        moved += 1

unreal.log("Moved {} actors into respective dolfers".format(moved))