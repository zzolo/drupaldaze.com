<?php

/**
 * Helper to implementation of hook_ctools_plugin_api().
 */
function _mn_world_ctools_plugin_api() {
  $args = func_get_args();
  $module = array_shift($args);
  $api = array_shift($args);
  if ($module == "openlayers" && $api == "openlayers_layers") {
    return array("version" => 1);
  }
  else if ($module == "openlayers" && $api == "openlayers_presets") {
    return array("version" => 1);
  }
  else if ($module == "openlayers" && $api == "openlayers_styles") {
    return array("version" => 1);
  }
}

/**
 * Helper to implementation of hook_openlayers_layers_info().
 */
function _mn_world_openlayers_layers_info() {
  $export = array();
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'mn_channels_news_attachment_1';
  $openlayers_layers->title = 'Latest news';
  $openlayers_layers->description = 'MN > Channels > News view - Attachment';
  $openlayers_layers->data = array(
    'projection' => array(
      '0' => '4326',
      '1' => '900913',
      '2' => '4269',
    ),
    'baselayer' => FALSE,
    'type' => 'Vector',
    'url' => array(),
    'options' => array(),
    'events' => array(),
    'views' => array(
      'view' => 'mn_channels_news',
      'display' => 'attachment_1',
    ),
  );

  $export['mn_channels_news_attachment_1'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'mn_news_attachment_1';
  $openlayers_layers->title = 'Latest news';
  $openlayers_layers->description = 'MN > News view - OL Data View';
  $openlayers_layers->data = array(
    'projection' => array(
      '0' => '4326',
      '1' => '900913',
      '2' => '4269',
    ),
    'baselayer' => FALSE,
    'type' => 'Vector',
    'url' => array(),
    'options' => array(),
    'events' => array(),
    'views' => array(
      'view' => 'mn_news',
      'display' => 'attachment_1',
    ),
  );

  $export['mn_news_attachment_1'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'osmmapnik';
  $openlayers_layers->title = 'Open Street Map';
  $openlayers_layers->description = 'OSM Mapnik';
  $openlayers_layers->data = array(
    'projection' => array(
      '0' => '900913',
    ),
    'baselayer' => TRUE,
    'type' => 'OSM',
    'options' => array(
      'layername' => 'osmmapnik',
      'spherical_mercator' => TRUE,
      'maxExtent' => array(
        '0' => -20037508.34,
        '1' => -20037508.34,
        '2' => 20037508.34,
        '3' => 20037508.34,
      ),
      'type' => 'png',
    ),
    'events' => array(),
    'callback' => 'mn_core_process_layers',
  );

  $export['osmmapnik'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'world';
  $openlayers_layers->title = 'World Borders - Dark';
  $openlayers_layers->description = 'Version 1.0 World Borders';
  $openlayers_layers->data = array(
    'projection' => array(
      '0' => '900913',
    ),
    'baselayer' => TRUE,
    'type' => 'MapBox',
    'url' => array(
      '0' => 'http://a.tile.mapbox.com/',
      '1' => 'http://b.tile.mapbox.com/',
      '2' => 'http://c.tile.mapbox.com/',
      '3' => 'http://d.tile.mapbox.com/',
    ),
    'options' => array(
      'layername' => 'world2',
      'spherical_mercator' => TRUE,
      'resolutions' => array(
        '0' => 39135.758475,
        '1' => 19567.8792375,
        '2' => 9783.93961875,
        '3' => 4891.96980938,
        '4' => 2445.98490469,
        '5' => 1222.99245234,
      ),
      'serverResolutions' => array(
        156543.0339,
	      78271.51695,
	      39135.758475,
	      19567.8792375,
	      9783.93961875,
	      4891.969809375,
	      2445.9849046875,
	      1222.99245234375,
	      611.496226171875,
	      305.7481130859375,
	      152.87405654296876,
	      76.43702827148438,
	      38.21851413574219,
	      19.109257067871095,
	      9.554628533935547,
	      4.777314266967774,
	      2.388657133483887,
	      1.1943285667419434,
        0.5971642833709717
      ),
      'maxExtent' => array(
        '0' => -20037508.34,
        '1' => -20037508.34,
        '2' => 20037508.34,
        '3' => 20037508.34,
      ),
      'type' => 'png',
    ),
    'events' => array(),
    'callback' => 'mn_core_process_layers',
  );

  $export['world'] = $openlayers_layers;
  $openlayers_layers = new stdClass;
  $openlayers_layers->disabled = FALSE; /* Edit this to true to make a default openlayers_layers disabled initially */
  $openlayers_layers->api_version = 1;
  $openlayers_layers->name = 'world_light';
  $openlayers_layers->title = 'World Borders - Light';
  $openlayers_layers->description = 'Version 1.5 World Borders';
  $openlayers_layers->data = array(
    'projection' => array(
      '0' => '900913',
    ),
    'baselayer' => TRUE,
    'type' => 'MapBox',
    'url' => array(
      '0' => 'http://a.tile.mapbox.com/',
      '1' => 'http://b.tile.mapbox.com/',
      '2' => 'http://c.tile.mapbox.com/',
      '3' => 'http://d.tile.mapbox.com/',
    ),
    'options' => array(
      'layername' => 'world-light',
      'spherical_mercator' => TRUE,
      'resolutions' => array(
        '0' => 39135.758475,
        '1' => 19567.8792375,
        '2' => 9783.93961875,
        '3' => 4891.96980938,
        '4' => 2445.98490469,
        '5' => 1222.99245234,
        '6' => 611.496226172,
        '7' => 305.748113086,
      ),
      'serverResolutions' => array(
        156543.0339,
	      78271.51695,
	      39135.758475,
	      19567.8792375,
	      9783.93961875,
	      4891.969809375,
	      2445.9849046875,
	      1222.99245234375,
	      611.496226171875,
	      305.7481130859375,
	      152.87405654296876,
	      76.43702827148438,
	      38.21851413574219,
	      19.109257067871095,
	      9.554628533935547,
	      4.777314266967774,
	      2.388657133483887,
	      1.1943285667419434,
        0.5971642833709717
      ),
      'maxExtent' => array(
        '0' => -20037508.34,
        '1' => -20037508.34,
        '2' => 20037508.34,
        '3' => 20037508.34,
      ),
      'type' => 'png',
    ),
    'events' => array(),
    'callback' => 'mn_core_process_layers',
  );

  $export['world_light'] = $openlayers_layers;
  return $export;
}

/**
 * Helper to implementation of hook_openlayers_presets().
 */
function _mn_world_openlayers_presets() {
  $export = array();
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'mn';
  $openlayers_presets->title = 'MN map';
  $openlayers_presets->description = 'A simple basemap of the world.';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '200px',
    'image_path' => 'profiles/managingnews/themes/jake/openlayers',
    'center' => array(
      'initial' => array(
        'centerpoint' => '0, 20',
        'zoom' => '0',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '-20037508.34, -20037508.34, 20037508.34, 20037508.34',
      ),
    ),
    'behaviors' => array(
      'mn_core_behavior_popup' => array(),
      'mn_core_behavior_scalepoints' => array(
        'min' => array(
          'pointRadius' => '3',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'max' => array(
          'pointRadius' => '15',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'distinct' => '5',
      ),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'mn_news_attachment_1',
      ),
      'openlayers_behavior_navigation' => array(),
    ),
    'default_layer' => 'world_light',
    'layers' => array(
      'world_light' => 'world_light',
      'mn_news_attachment_1' => 'mn_news_attachment_1',
    ),
    'layer_styles' => array(
      'mn_news_attachment_1' => 'mn_blue',
    ),
    'layer_activated' => array(
      'mn_news_attachment_1' => 'mn_news_attachment_1',
    ),
    'projection' => '900913',
    'styles' => array(
      'default' => 'mn_blue',
      'select' => 'mn_blue',
      'temporary' => 'mn_blue',
    ),
    'options' => array(
      'displayProjection' => '4326',
      'maxResolution' => '156543.0339',
      'maxExtent' => array(
        'left' => '-20037508.34',
        'right' => '20037508.34',
        'top' => '20037508.34',
        'bottom' => '-20037508.34',
      ),
    ),
  );

  $export['mn'] = $openlayers_presets;
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'mn_channels';
  $openlayers_presets->title = 'MN channels';
  $openlayers_presets->description = 'A simple basemap of the world';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => '200px',
    'image_path' => 'profiles/managingnews/themes/jake/openlayers',
    'center' => array(
      'initial' => array(
        'centerpoint' => '0, 20',
        'zoom' => '0',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '-20037508.34, -20037508.34, 20037508.34, 20037508.34',
      ),
    ),
    'behaviors' => array(
      'mn_core_behavior_popup' => array(),
      'mn_core_behavior_scalepoints' => array(
        'min' => array(
          'pointRadius' => '3',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'max' => array(
          'pointRadius' => '15',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'distinct' => '5',
      ),
      'openlayers_behavior_zoomtolayer' => array(
        'zoomtolayer' => 'mn_channels_news_attachment_1',
      ),
      'openlayers_behavior_navigation' => array(),
    ),
    'default_layer' => 'world_light',
    'layers' => array(
      'world_light' => 'world_light',
      'mn_channels_news_attachment_1' => 'mn_channels_news_attachment_1',
    ),
    'layer_styles' => array(
      'mn_news_attachment_1' => 'mn_blue',
    ),
    'layer_activated' => array(
      'mn_channels_news_attachment_1' => 'mn_channels_news_attachment_1',
    ),
    'projection' => '900913',
    'styles' => array(
      'default' => 'mn_blue',
      'select' => 'mn_blue',
      'temporary' => 'mn_blue',
    ),
    'options' => array(
      'displayProjection' => '4326',
      'maxResolution' => '156543.0339',
      'maxExtent' => array(
        'left' => '-20037508.34',
        'right' => '20037508.34',
        'top' => '20037508.34',
        'bottom' => '-20037508.34',
      ),
    ),
  );

  $export['mn_channels'] = $openlayers_presets;
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'mn_fullscreen';
  $openlayers_presets->title = 'MN fullscreen';
  $openlayers_presets->description = 'A simple fullscreen map of the world.';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => 'auto',
    'image_path' => 'profiles/managingnews/themes/jake/openlayers',
    'css_path' => '',
    'center' => array(
      'initial' => array(
        'centerpoint' => '0, 20',
        'zoom' => '0',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '-20037508.34, -20037508.34, 20037508.34, 20037508.34',
      ),
    ),
    'behaviors' => array(
      'mn_core_behavior_layerswitcherplus' => array(),
      'mn_core_behavior_popup' => array(),
      'mn_core_behavior_scalepoints' => array(
        'min' => array(
          'pointRadius' => '3',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'max' => array(
          'pointRadius' => '15',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'distinct' => '5',
      ),
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_navigation' => array(),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_permalink' => array(),
    ),
    'default_layer' => 'world_light',
    'layers' => array(
      'world_light' => 'world_light',
      'world' => 'world',
      'osmmapnik' => 'osmmapnik',
      'mn_airports' => 'mn_airports',
      'mn_schools' => 'mn_schools',
      'mn_hospitals' => 'mn_hospitals',
      'mn_news_attachment_1' => 'mn_news_attachment_1',
    ),
    'layer_styles' => array(
      'mn_airports' => 'mn_airport',
      'mn_schools' => 'mn_school',
      'mn_hospitals' => 'mn_medical',
      'mn_news_attachment_1' => 'mn_blue',
    ),
    'layer_activated' => array(
      'mn_news_attachment_1' => 'mn_channels_news_attachment_1',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'mn_blue',
      'select' => 'mn_blue',
      'temporary' => 'mn_blue',
    ),
    'options' => NULL,
  );

  $export['mn_fullscreen'] = $openlayers_presets;
  $openlayers_presets = new stdClass;
  $openlayers_presets->disabled = FALSE; /* Edit this to true to make a default openlayers_presets disabled initially */
  $openlayers_presets->api_version = 1;
  $openlayers_presets->name = 'mn_fullscreen_channels';
  $openlayers_presets->title = 'MN fullscreen channels';
  $openlayers_presets->description = 'A simple fullscreen map of the world.';
  $openlayers_presets->data = array(
    'width' => 'auto',
    'height' => 'auto',
    'image_path' => 'profiles/managingnews/themes/jake/openlayers',
    'css_path' => '',
    'center' => array(
      'initial' => array(
        'centerpoint' => '0, 20',
        'zoom' => '0',
      ),
      'restrict' => array(
        'restrictextent' => 1,
        'restrictedExtent' => '-20037508.34, -20037508.34, 20037508.34, 20037508.34',
      ),
    ),
    'behaviors' => array(
      'mn_core_behavior_layerswitcherplus' => array(),
      'mn_core_behavior_popup' => array(),
      'mn_core_behavior_scalepoints' => array(
        'min' => array(
          'pointRadius' => '3',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'max' => array(
          'pointRadius' => '15',
          'fillOpacity' => '',
          'strokeWidth' => '',
        ),
        'distinct' => '5',
      ),
      'openlayers_behavior_attribution' => array(),
      'openlayers_behavior_navigation' => array(),
      'openlayers_behavior_panzoombar' => array(),
      'openlayers_behavior_permalink' => array(),
    ),
    'default_layer' => 'world_light',
    'layers' => array(
      'world_light' => 'world_light',
      'world' => 'world',
      'osmmapnik' => 'osmmapnik',
      'mn_airports' => 'mn_airports',
      'mn_schools' => 'mn_schools',
      'mn_hospitals' => 'mn_hospitals',
      'mn_channels_news_attachment_1' => 'mn_channels_news_attachment_1',
    ),
    'layer_styles' => array(
      'mn_airports' => 'mn_airport',
      'mn_schools' => 'mn_school',
      'mn_hospitals' => 'mn_medical',
      'mn_channels_news_attachment_1' => 'mn_blue',
    ),
    'layer_activated' => array(
      'mn_channels_news_attachment_1' => 'mn_channels_news_attachment_1',
    ),
    'projection' => '900913',
    'displayProjection' => '4326',
    'styles' => array(
      'default' => 'mn_blue',
      'select' => 'mn_blue',
      'temporary' => 'mn_blue',
    ),
    'options' => NULL,
  );

  $export['mn_fullscreen_channels'] = $openlayers_presets;
  return $export;
}
