<?php

/**
 * Implementation of hook_views_handlers()
 */
function mn_core_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'mn_core') . '/views',
    ),
    'handlers' => array(
      'mn_core_handler_field' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
