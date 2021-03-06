/*
4coder_antonl.cpp - Anton Ljungdahl 4coder custom layer.
*/
// TOP

#if !defined(FCODER_DEFAULT_BINDINGS_CPP)
#define FCODER_DEFAULT_BINDINGS_CPP

#include "4coder_default_include.cpp"

// NOTE(allen): Users can declare their own managed IDs here.

#include "generated/managed_id_metadata.cpp"

// NOTE(antonl): Custom rendering based on github.com/Skytrias/4files
#include "antonl_render.cpp"

// NOTE(antonl): Anton's keybinds
#include "antonl_keybinds.cpp"

void
custom_layer_init(Application_Links *app){
    Thread_Context *tctx = get_thread_context(app);
    
    // NOTE(allen): setup for default framework
    default_framework_init(app);
    
    // NOTE(allen): default hooks and command maps
    set_all_default_hooks(app);
    set_custom_hook(app, HookID_RenderCaller, anton_render_caller);
    mapping_init(tctx, &framework_mapping);
    setup_anton_mapping(&framework_mapping, mapid_global, mapid_file, mapid_code);
}

#endif //FCODER_DEFAULT_BINDINGS

// BOTTOM
