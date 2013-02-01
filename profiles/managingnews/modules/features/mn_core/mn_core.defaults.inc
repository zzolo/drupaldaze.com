<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _mn_core_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'mn',
    'attribute' => 'display_mode',
    'value' => 'list',
    'description' => '',
    'views_modes' => array(
      '0' => 'views-mode-list',
    ),
    'theme_section' => array(
      'class' => 'views-mode-list',
    ),
    'block' => array(),
  );
  $items[] = array(
    'namespace' => 'mn',
    'attribute' => 'display_mode',
    'value' => 'map',
    'description' => '',
    'views_modes' => array(
      '0' => 'views-mode-map',
    ),
    'theme_section' => array(
      'class' => 'views-mode-map',
    ),
    'theme_regiontoggle' => array(
      '0' => 'right',
    ),
    'block' => array(),
  );
  $items[] = array(
    'namespace' => 'mn',
    'attribute' => 'global',
    'value' => 'context',
    'description' => '',
    'sitewide' => '1',
    'block' => array(
      'mn_core_clock' => array(
        'module' => 'mn_core',
        'delta' => 'clock',
        'weight' => 20,
        'region' => 'palette',
        'status' => '0',
        'label' => 'MN: Clock',
        'type' => 'context_ui',
      ),
      'user_0' => array(
        'module' => 'user',
        'delta' => '0',
        'weight' => 21,
        'region' => 'palette',
        'status' => '0',
        'label' => 'User login',
        'type' => 'context_ui',
      ),
      'mn_core_user' => array(
        'module' => 'mn_core',
        'delta' => 'user',
        'weight' => 22,
        'region' => 'palette',
        'status' => '0',
        'label' => 'MN: User controls',
        'type' => 'context_ui',
      ),
    ),
  );
  $items[] = array(
    'namespace' => 'mn',
    'attribute' => 'section',
    'value' => 'admin',
    'description' => '',
    'path' => array(
      'admin' => 'admin',
      'admin/*' => 'admin/*',
      'import' => 'import',
      'import/*' => 'import/*',
    ),
    'block' => array(
      'mn_core_admin' => array(
        'module' => 'mn_core',
        'delta' => 'admin',
        'weight' => 21,
        'region' => 'left',
        'status' => '0',
        'label' => 'MN: Admin menu',
        'type' => 'context_ui',
      ),
    ),
  );
  $items[] = array(
    'namespace' => 'mn',
    'attribute' => 'section',
    'value' => 'news',
    'description' => '',
    'node' => array(
      '0' => 'feed',
    ),
    'views' => array(
      '0' => 'mn_news:page_1',
    ),
    'block' => array(
      'mn_core_print' => array(
        'module' => 'mn_core',
        'delta' => 'print',
        'weight' => 21,
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
      'views_mn_feeds-block_1' => array(
        'module' => 'views',
        'delta' => 'mn_feeds-block_1',
        'weight' => 21,
        'region' => 'left',
        'status' => '0',
        'label' => 'mn_feeds: Feeds block',
        'type' => 'context_ui',
      ),
      'views_mn_search_saved-block_1' => array(
        'module' => 'views',
        'delta' => 'mn_search_saved-block_1',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'mn_search_saved: Highlighted topics',
        'type' => 'context_ui',
      ),
    ),
  );
  $items[] = array(
    'namespace' => 'theme',
    'attribute' => 'layout',
    'value' => 'wide',
    'description' => '',
    'theme_regiontoggle' => array(
      '0' => 'right',
    ),
    'block' => array(),
  );
  return $items;
}

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _mn_core_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "data" && $api == "data_default") {
    return array("version" => 1);
  }
  else if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => 1);
  }
  else if ($module == "openlayers" && $api == "openlayers_styles") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_data_default().
 */
function _mn_core_data_default() {
  $export = array();
  $data_table = new stdClass;
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Syndication tags';
  $data_table->name = 'data_table_term';
  $data_table->table_schema = array(
    'fields' => array(
      'id' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
      ),
      'tid' => array(
        'type' => 'int',
        'size' => 'normal',
        'unsigned' => TRUE,
      ),
    ),
    'indexes' => array(
      'id' => array(
        '0' => 'id',
      ),
      'tid' => array(
        '0' => 'tid',
      ),
    ),
    'primary key' => array(
      '0' => 'id',
      '1' => 'tid',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'id' => array(
        'label' => '',
      ),
      'tid' => array(
        'label' => '',
      ),
    ),
    'join' => array(
      'feeds_data_syndication' => array(
        'left_field' => 'id',
        'field' => 'id',
        'inner_join' => '0',
      ),
      'term_data' => array(
        'left_field' => 'tid',
        'field' => 'tid',
        'inner_join' => '0',
      ),
    ),
  );

  $export['data_table_term'] = $data_table;
  $data_table = new stdClass;
  $data_table->disabled = FALSE; /* Edit this to true to make a default data_table disabled initially */
  $data_table->api_version = 1;
  $data_table->title = 'Syndication';
  $data_table->name = 'feeds_data_syndication';
  $data_table->table_schema = array(
    'fields' => array(
      'feed_nid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'id' => array(
        'type' => 'serial',
        'size' => 'normal',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'timestamp' => array(
        'description' => 'The Unix timestamp for the data.',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => FALSE,
      ),
      'title' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
      ),
      'description' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'guid' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
      'url' => array(
        'type' => 'text',
        'not null' => FALSE,
      ),
    ),
    'indexes' => array(
      'feed_nid' => array(
        '0' => 'feed_nid',
      ),
      'id' => array(
        '0' => 'id',
      ),
      'timestamp' => array(
        '0' => 'timestamp',
      ),
      'guid' => array(
        '0' => array(
          '0' => 'guid',
          '1' => 255,
        ),
      ),
      'url' => array(
        '0' => array(
          '0' => 'url',
          '1' => 255,
        ),
      ),
    ),
    'primary key' => array(
      '0' => 'id',
    ),
  );
  $data_table->meta = array(
    'fields' => array(
      'feed_nid' => array(
        'label' => '',
        'search' => 0,
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'id' => array(
        'label' => '',
        'search' => 0,
        'views_field_handler' => 'views_handler_field_numeric',
        'views_filter_handler' => 'views_handler_filter_numeric',
        'views_argument_handler' => 'views_handler_argument_numeric',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'timestamp' => array(
        'label' => '',
        'search' => 0,
        'views_field_handler' => 'views_handler_field_date',
        'views_filter_handler' => 'views_handler_filter_date',
        'views_argument_handler' => 'views_handler_argument_date',
        'views_sort_handler' => 'views_handler_sort_date',
      ),
      'title' => array(
        'label' => '',
        'search' => 1,
        'views_field_handler' => 'mn_core_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument_string',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'description' => array(
        'label' => '',
        'search' => 1,
        'views_field_handler' => 'mn_core_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'guid' => array(
        'label' => '',
        'search' => 0,
        'views_field_handler' => 'views_handler_field',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument',
        'views_sort_handler' => 'views_handler_sort',
      ),
      'url' => array(
        'label' => '',
        'search' => 0,
        'views_field_handler' => 'views_handler_field_url',
        'views_filter_handler' => 'views_handler_filter_string',
        'views_argument_handler' => 'views_handler_argument',
        'views_sort_handler' => 'views_handler_sort',
      ),
    ),
    'data_node' => array(
      'content_type' => 'channel',
      'id' => 'id',
    ),
    'join' => array(
      'node' => array(
        'left_field' => 'nid',
        'field' => 'feed_nid',
        'inner_join' => '1',
      ),
    ),
  );

  $export['feeds_data_syndication'] = $data_table;
  return $export;
}

/**
 * Helper to implementation of hook_feeds_importer_default().
 */
function _mn_core_feeds_importer_default() {
  $export = array();
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'locations';
  $feeds_importer->config = array(
    'name' => 'Locations',
    'description' => 'Imports locations into geotaxonomies',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsTermProcessor',
      'config' => array(
        'vocabulary' => '1',
        'update_existing' => 0,
        'mappings' => array(
          '0' => array(
            'source' => 'name',
            'target' => 'name',
            'unique' => 1,
          ),
          '1' => array(
            'source' => 'lat',
            'target' => 'lat',
            'unique' => FALSE,
          ),
          '2' => array(
            'source' => 'lon',
            'target' => 'lon',
            'unique' => FALSE,
          ),
          '3' => array(
            'source' => 'top',
            'target' => 'bound_top',
            'unique' => FALSE,
          ),
          '4' => array(
            'source' => 'right',
            'target' => 'bound_right',
            'unique' => FALSE,
          ),
          '5' => array(
            'source' => 'bottom',
            'target' => 'bound_bottom',
            'unique' => FALSE,
          ),
          '6' => array(
            'source' => 'left',
            'target' => 'bound_left',
            'unique' => FALSE,
          ),
          '7' => array(
            'source' => 'parent',
            'target' => 'parent_name',
            'unique' => FALSE,
          ),
          '8' => array(
            'source' => 'id',
            'target' => 'external_id',
            'unique' => FALSE,
          ),
          '9' => array(
            'source' => 'parent_id',
            'target' => 'parent_external_id',
            'unique' => FALSE,
          ),
        ),
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_on_create' => 1,
    'import_period' => '-1',
  );

  $export['locations'] = $feeds_importer;
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'opml';
  $feeds_importer->config = array(
    'name' => 'Import OPML',
    'description' => 'Import OPML files and create new feed subscriptions from it.',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsOPMLParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFeedNodeProcessor',
      'config' => array(
        'content_type' => 'feed',
        'update_existing' => 0,
        'mappings' => array(
          '0' => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          '1' => array(
            'source' => 'xmlurl',
            'target' => 'source',
            'unique' => 1,
          ),
        ),
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
  );

  $export['opml'] = $feeds_importer;
  $feeds_importer = new stdClass;
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'syndication';
  $feeds_importer->config = array(
    'name' => 'Syndication',
    'description' => 'Aggregates syndicated content.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 0,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'ExtractorSimplePieParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsDataProcessor',
      'config' => array(
        'update_existing' => 0,
        'mappings' => array(
          '0' => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          '1' => array(
            'source' => 'description',
            'target' => 'description',
            'unique' => 0,
          ),
          '2' => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          '3' => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 1,
          ),
          '4' => array(
            'source' => 'timestamp',
            'target' => 'timestamp',
            'unique' => FALSE,
          ),
          '5' => array(
            'source' => 'extracted_tids',
            'target' => 'data_table_term.tid',
            'unique' => FALSE,
          ),
        ),
        'expire' => '7257600',
      ),
    ),
    'content_type' => 'feed',
    'update' => 0,
    'import_on_create' => 1,
    'import_period' => '1800',
  );

  $export['syndication'] = $feeds_importer;
  return $export;
}

/**
 * Helper to implementation of hook_imagecache_default_presets().
 */
function _mn_core_imagecache_default_presets() {
  $items = array(
    'logo' => array(
      'presetname' => 'logo',
      'actions' => array(
        '0' => array(
          'actionid' => '2',
          'presetid' => '1',
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '100%',
            'height' => '50',
            'upscale' => 0,
          ),
        ),
      ),
    ),
    'logo_print' => array(
      'presetname' => 'logo_print',
      'actions' => array(
        '0' => array(
          'actionid' => '3',
          'presetid' => '2',
          'weight' => '0',
          'module' => 'imagecache',
          'action' => 'imagecache_scale',
          'data' => array(
            'width' => '100%',
            'height' => '150',
            'upscale' => 0,
          ),
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Helper to implementation of hook_openlayers_styles_info().
 */
function _mn_core_openlayers_styles_info() {
  $export = array();
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'mn_blue';
  $openlayers_styles->title = 'Blue';
  $openlayers_styles->description = 'Blue point.';
  $openlayers_styles->data = array(
    'pointRadius' => 5,
    'fillColor' => '#66eeff',
    'strokeColor' => '#33ccff',
    'strokeWidth' => 10,
    'strokeOpacity' => 0.35,
    'fillOpacity' => 0.75,
  );

  $export['mn_blue'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'mn_green';
  $openlayers_styles->title = 'Green';
  $openlayers_styles->description = 'Green point.';
  $openlayers_styles->data = array(
    'pointRadius' => 5,
    'fillColor' => '#33ff33',
    'strokeColor' => '#99ff33',
    'strokeWidth' => 10,
    'strokeOpacity' => 0.35,
    'fillOpacity' => 0.75,
  );

  $export['mn_green'] = $openlayers_styles;
  $openlayers_styles = new stdClass;
  $openlayers_styles->disabled = FALSE; /* Edit this to true to make a default openlayers_styles disabled initially */
  $openlayers_styles->api_version = 1;
  $openlayers_styles->name = 'mn_red';
  $openlayers_styles->title = 'Red';
  $openlayers_styles->description = 'Red point.';
  $openlayers_styles->data = array(
    'pointRadius' => 5,
    'fillColor' => '#ff4400',
    'strokeColor' => '#ff8844',
    'strokeWidth' => 10,
    'strokeOpacity' => 0.35,
    'fillOpacity' => 0.75,
  );

  $export['mn_red'] = $openlayers_styles;
  return $export;
}

/**
 * Helper to implementation of hook_user_default_permissions().
 */
function _mn_core_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer feeds
  $permissions[] = array(
    'name' => 'administer feeds',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer mn
  $permissions[] = array(
    'name' => 'administer mn',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer permissions
  $permissions[] = array(
    'name' => 'administer permissions',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: administer users
  $permissions[] = array(
    'name' => 'administer users',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: change own username
  $permissions[] = array(
    'name' => 'change own username',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: clear locations feeds
  $permissions[] = array(
    'name' => 'clear locations feeds',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: clear syndication feeds
  $permissions[] = array(
    'name' => 'clear syndication feeds',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: create book content
  $permissions[] = array(
    'name' => 'create book content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: create feed content
  $permissions[] = array(
    'name' => 'create feed content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: delete any book content
  $permissions[] = array(
    'name' => 'delete any book content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete any feed content
  $permissions[] = array(
    'name' => 'delete any feed content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own book content
  $permissions[] = array(
    'name' => 'delete own book content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: delete own feed content
  $permissions[] = array(
    'name' => 'delete own feed content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: edit any book content
  $permissions[] = array(
    'name' => 'edit any book content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit any feed content
  $permissions[] = array(
    'name' => 'edit any feed content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit own book content
  $permissions[] = array(
    'name' => 'edit own book content',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: edit own feed content
  $permissions[] = array(
    'name' => 'edit own feed content',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: import locations feeds
  $permissions[] = array(
    'name' => 'import locations feeds',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: import opml feeds
  $permissions[] = array(
    'name' => 'import opml feeds',
    'roles' => array(
      '0' => 'admin',
    ),
  );

  // Exported permission: import syndication feeds
  $permissions[] = array(
    'name' => 'import syndication feeds',
    'roles' => array(
      '0' => 'authenticated user',
    ),
  );

  // Exported permission: manage data relations
  $permissions[] = array(
    'name' => 'manage data relations',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: manage stored views
  $permissions[] = array(
    'name' => 'manage stored views',
    'roles' => array(
      '0' => 'admin',
      '1' => 'authenticated user',
    ),
  );

  // Exported permission: view uploaded files
  $permissions[] = array(
    'name' => 'view uploaded files',
    'roles' => array(
      '0' => 'anonymous user',
      '1' => 'authenticated user',
    ),
  );

  return $permissions;
}
