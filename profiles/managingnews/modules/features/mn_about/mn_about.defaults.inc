<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _mn_about_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'mn',
    'attribute' => 'section',
    'value' => 'about',
    'description' => '',
    'node' => array(
      '0' => 'book',
    ),
    'block' => array(
      'book_0' => array(
        'module' => 'book',
        'delta' => '0',
        'weight' => -21,
        'region' => 'left',
        'status' => '0',
        'label' => 'Book navigation',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}
