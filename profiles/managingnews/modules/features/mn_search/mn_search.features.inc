<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function mn_search_context_default_contexts() {
  module_load_include('inc', 'mn_search', 'mn_search.defaults');
  $args = func_get_args();
  return call_user_func_array('_mn_search_context_default_contexts', $args);
}

/**
 * Implementation of hook_views_default_views().
 */
function mn_search_views_default_views() {
  module_load_include('inc', 'mn_search', 'mn_search.features.views');
  $args = func_get_args();
  return call_user_func_array('_mn_search_views_default_views', $args);
}
