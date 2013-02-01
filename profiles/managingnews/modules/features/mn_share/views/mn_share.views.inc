<?php

/**
 * Implementation of hook_views_handlers()
 */
function mn_share_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'mn_share') . '/views',
    ),
    'handlers' => array(
      'mn_share_handler_field_link' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}

/**
 * Implementation of hook_views_data_alter()
 */
function mn_share_views_data_alter(&$data) {
  $data['views']['mn_share_link'] = array(
    'title' => t('MN share link'),
    'help' => t('Link for sharing a particular item.'),
    'field' => array(
      'handler' => 'mn_share_handler_field_link',
    ),
  );
}
