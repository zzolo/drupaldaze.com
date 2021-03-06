<?php
// $Id: openlayers_behaviors.theme.inc,v 1.4 2009/09/24 17:40:47 tmcw Exp $

/**
 * @file
 * This file holds the theme functions for openlayers behaviors module
 *
 * @ingroup openlayers
 */

/**
 * Theme function for form description of layers
 *
 * @param $behavior
 *   Array of data about behavior
 * @param $map
 *   Array of map data
 * @return
 *   Themed output for tooltip container
 */
function theme_openlayers_behaviors_tooltip_container($behavior = array(), $map = array()) {
  $path_point_image = drupal_get_path('module', 'openlayers_behaviors') . '/images/pointy.png';
  $attr = array(
    'class' => 'openlayers-tooltip-point',
  );
  $point_image = theme('image', $path_point_image, t('Tooltip point'), '', $attr, FALSE);
  
  // Create output
  $output = '
    <div id="' . $behavior['container_id'] . '" class="openlayers-behaviors-tooltip">
      ' . $point_image . '
      <span id="' . $behavior['attribute_id'] . '"></span>
    </div>
  ';
  return $output;
}