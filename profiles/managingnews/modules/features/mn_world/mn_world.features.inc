<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mn_world_ctools_plugin_api() {
  module_load_include('inc', 'mn_world', 'mn_world.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_world_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_openlayers_layers_info().
 */
function mn_world_openlayers_layers_info() {
  module_load_include('inc', 'mn_world', 'mn_world.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_world_openlayers_layers_info', $args);
}

/**
 * Implementation of hook_openlayers_presets().
 */
function mn_world_openlayers_presets() {
  module_load_include('inc', 'mn_world', 'mn_world.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_world_openlayers_presets', $args);
}
