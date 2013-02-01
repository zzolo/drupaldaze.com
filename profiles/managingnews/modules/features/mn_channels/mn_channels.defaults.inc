<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _mn_channels_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'mn',
    'attribute' => 'channels',
    'value' => 'tools',
    'description' => '',
    'node' => array(
      '0' => 'channel',
    ),
    'path' => array(
      'feeds*' => 'feeds*',
      'search*' => 'search*',
      'stored-views*' => 'stored-views*',
    ),
    'views' => array(
      '0' => 'mn_channels',
      '1' => 'mn_channels_news',
    ),
    'block' => array(
      'data_node_feeds_data_syndication' => array(
        'module' => 'data_node',
        'delta' => 'feeds_data_syndication',
        'weight' => 18,
        'region' => 'palette',
        'status' => '0',
        'label' => 'Data node: Active node form for Syndication',
        'type' => 'context_ui',
      ),
    ),
  );
  $items[] = array(
    'namespace' => 'mn',
    'attribute' => 'section',
    'value' => 'channels',
    'description' => '',
    'node' => array(
      '0' => 'channel',
    ),
    'views' => array(
      '0' => 'mn_channels',
      '1' => 'mn_channels_news',
    ),
    'block' => array(
      'mn_core_print' => array(
        'module' => 'mn_core',
        'delta' => 'print',
        'weight' => 20,
        'region' => 'palette',
        'status' => '0',
        'label' => 'MN: Print controls',
        'type' => 'context_ui',
      ),
      'views_modes_modes' => array(
        'module' => 'views_modes',
        'delta' => 'modes',
        'weight' => 20,
        'region' => 'page_tools',
        'status' => '0',
        'label' => 'Views mode links',
        'type' => 'context_ui',
      ),
      'mn_core_formats' => array(
        'module' => 'mn_core',
        'delta' => 'formats',
        'weight' => 21,
        'region' => 'page_tools',
        'status' => '0',
        'label' => 'MN: Alternative formats',
        'type' => 'context_ui',
      ),
      'views_mn_channels-block_1' => array(
        'module' => 'views',
        'delta' => 'mn_channels-block_1',
        'weight' => -21,
        'region' => 'left',
        'status' => '0',
        'label' => 'mn_channels: Block: list of channels',
        'type' => 'context_ui',
      ),
      'views_mn_channels-block_2' => array(
        'module' => 'views',
        'delta' => 'mn_channels-block_2',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'mn_channels: Block: channel node',
        'type' => 'context_ui',
      ),
      'views_mn_channels_news-block_1' => array(
        'module' => 'views',
        'delta' => 'mn_channels_news-block_1',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'mn_channels_news: Block: Trend graph',
        'type' => 'context_ui',
      ),
      'views_mn_channels_news-block_2' => array(
        'module' => 'views',
        'delta' => 'mn_channels_news-block_2',
        'weight' => 22,
        'region' => 'right',
        'status' => '0',
        'label' => 'mn_channels_news: Block: Map',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_menu_default_items().
 */
function _mn_channels_menu_default_items() {
  $items = array();

  $items[] = array(
    'title' => 'Channels',
    'path' => 'channels',
    'weight' => '2',
    'description' => 'Channels contain news organized around topics. People can view, print and subscribe to the items in channels.',
  );
  // Translatables
  array(
    t('Channels'),
    t('Channels contain news organized around topics. People can view, print and subscribe to the items in channels.'),
  );


  return $items;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _mn_channels_user_default_permissions() {
  $permissions = array();

  // Exported permission: create channel content
  $permissions[] = array(
    'name' => 'create channel content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: delete any channel content
  $permissions[] = array(
    'name' => 'delete any channel content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own channel content
  $permissions[] = array(
    'name' => 'delete own channel content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: edit any channel content
  $permissions[] = array(
    'name' => 'edit any channel content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit own channel content
  $permissions[] = array(
    'name' => 'edit own channel content',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  return $permissions;
}
