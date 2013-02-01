<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _mn_core_node_info() {
  $items = array(
    'feed' => array(
      'name' => t('Feed'),
      'module' => 'features',
      'description' => t('A feed for aggregating RSS/Atom sources.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '0',
      'body_label' => t(''),
    ),
  );
  return $items;
}
