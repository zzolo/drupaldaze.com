<?php

/**
 * Helper to implementation of hook_node_info().
 */
function _mn_channels_node_info() {
  $items = array(
    'channel' => array(
      'name' => t('Channel'),
      'module' => 'features',
      'description' => t('A channel is a collection of articles that the world can subscribe to.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Body'),
    ),
  );
  return $items;
}
