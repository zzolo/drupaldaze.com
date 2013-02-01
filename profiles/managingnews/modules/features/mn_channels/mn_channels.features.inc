<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function mn_channels_context_default_contexts() {
  module_load_include('inc', 'mn_channels', 'mn_channels.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_channels_context_default_contexts', $args);
}

/**
 * Implementation of hook_menu_default_items().
 */
function mn_channels_menu_default_items() {
  module_load_include('inc', 'mn_channels', 'mn_channels.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_channels_menu_default_items', $args);
}

/**
 * Implementation of hook_node_info().
 */
function mn_channels_node_info() {
  module_load_include('inc', 'mn_channels', 'mn_channels.features.node');
  $args = func_get_args();
  return call_user_func_array('_mn_channels_node_info', $args);
}

/**
 * Implementation of hook_user_default_permissions().
 */
function mn_channels_user_default_permissions() {
  module_load_include('inc', 'mn_channels', 'mn_channels.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_channels_user_default_permissions', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function mn_channels_views_default_views() {
  module_load_include('inc', 'mn_channels', 'mn_channels.features.views');
  $args = func_get_args();
  return call_user_func_array('_mn_channels_views_default_views', $args);
}
