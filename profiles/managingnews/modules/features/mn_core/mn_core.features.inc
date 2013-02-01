<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function mn_core_context_default_contexts() {
  module_load_include('inc', 'mn_core', 'mn_core.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_core_context_default_contexts', $args);
}

/**
 * Implementation of hook_ctools_plugin_api().
 */
function mn_core_ctools_plugin_api() {
  module_load_include('inc', 'mn_core', 'mn_core.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_core_ctools_plugin_api', $args);
}

/**
 * Implementation of hook_data_default().
 */
function mn_core_data_default() {
  module_load_include('inc', 'mn_core', 'mn_core.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_core_data_default', $args);
}

/**
 * Implementation of hook_feeds_importer_default().
 */
function mn_core_feeds_importer_default() {
  module_load_include('inc', 'mn_core', 'mn_core.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_core_feeds_importer_default', $args);
}

/**
 * Implementation of hook_imagecache_default_presets().
 */
function mn_core_imagecache_default_presets() {
  module_load_include('inc', 'mn_core', 'mn_core.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_core_imagecache_default_presets', $args);
}

/**
 * Implementation of hook_node_info().
 */
function mn_core_node_info() {
  module_load_include('inc', 'mn_core', 'mn_core.features.node');
  $args = func_get_args();
  return call_user_func_array('_mn_core_node_info', $args);
}

/**
 * Implementation of hook_openlayers_styles_info().
 */
function mn_core_openlayers_styles_info() {
  module_load_include('inc', 'mn_core', 'mn_core.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_core_openlayers_styles_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function mn_core_user_default_permissions() {
  module_load_include('inc', 'mn_core', 'mn_core.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_core_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function mn_core_views_default_views() {
  module_load_include('inc', 'mn_core', 'mn_core.features.views');
  $args = func_get_args();
  return call_user_func_array('_mn_core_views_default_views', $args);
}
