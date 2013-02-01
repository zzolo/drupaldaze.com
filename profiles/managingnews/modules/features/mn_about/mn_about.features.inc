<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function mn_about_context_default_contexts() {
  module_load_include('inc', 'mn_about', 'mn_about.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_about_context_default_contexts', $args);
}

/**
 * Implementation of hook_node_info().
 */
function mn_about_node_info() {
  module_load_include('inc', 'mn_about', 'mn_about.features.node');
  $args = func_get_args();
  return call_user_func_array('_mn_about_node_info', $args);
}
