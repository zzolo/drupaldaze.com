<?php

/**
 * Helper to implementation of hook_context_default_contexts().
 */
function _mn_search_context_default_contexts() {
  $items = array();

  $items[] = array(
    'namespace' => 'mn',
    'attribute' => 'section',
    'value' => 'search',
    'description' => '',
    'path' => array(
      'search*' => 'search*',
      'stored-views*' => 'stored-views*',
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
      'views_-exp-mn_news-page_2' => array(
        'module' => 'views',
        'delta' => '-exp-mn_news-page_2',
        'weight' => 20,
        'region' => 'page_title',
        'status' => '0',
        'label' => 'Exposed form: mn_news-page_2',
        'type' => 'context_ui',
      ),
      'stored_views_save' => array(
        'module' => 'stored_views',
        'delta' => 'save',
        'weight' => 21,
        'region' => 'page_title',
        'status' => '0',
        'label' => 'Save current view block',
        'type' => 'context_ui',
      ),
      'views_mn_search_saved-block_2' => array(
        'module' => 'views',
        'delta' => 'mn_search_saved-block_2',
        'weight' => 21,
        'region' => 'left',
        'status' => '0',
        'label' => 'mn_search_saved: Highlighted searches',
        'type' => 'context_ui',
      ),
      'mn_search_status' => array(
        'module' => 'mn_search',
        'delta' => 'status',
        'weight' => 20,
        'region' => 'right',
        'status' => '0',
        'label' => 'Search index status',
        'type' => 'context_ui',
      ),
      'views_mn_news-block_1' => array(
        'module' => 'views',
        'delta' => 'mn_news-block_1',
        'weight' => 21,
        'region' => 'right',
        'status' => '0',
        'label' => 'mn_news: Block: Trend graph',
        'type' => 'context_ui',
      ),
      'views_mn_news-block_2' => array(
        'module' => 'views',
        'delta' => 'mn_news-block_2',
        'weight' => 22,
        'region' => 'right',
        'status' => '0',
        'label' => 'mn_news: Block: Map',
        'type' => 'context_ui',
      ),
    ),
  );
  return $items;
}
