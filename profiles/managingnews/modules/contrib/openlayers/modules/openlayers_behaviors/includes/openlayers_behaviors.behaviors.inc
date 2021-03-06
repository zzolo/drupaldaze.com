<?php
// $Id: openlayers_behaviors.behaviors.inc,v 1.12 2009/09/24 17:40:47 tmcw Exp $

/**
 * @file
 * This file holds the main Drupal hook functions 
 * and private functions for the openlayers_behaviors module.
 *
 * @ingroup openlayers
 */

/**
 * Callback for OpenLayers Behaviors (Zoom to Layer)
 *
 * @param $behavoir
 *   Data about behavoir
 * @param $map
 *   Map array
 * @return
 *   Behavior array
 */
function openlayers_behaviors_process_zoom_to_layer($behavior, &$map) {
  // Check to make sure the layer attribute is properly set.
  if ($behavior['layer'] && $map['layers'][$behavior['layer']]) {
    return $behavior;
  }
}

/**
 * Callback for OpenLayers Behaviors (Tooltip)
 *
 * @param $behavoir
 *   Data about behavoir
 * @param $map
 *   Map array
 * @return
 *   Behavior array
 */
function openlayers_behaviors_process_tooltip($behavior, &$map) {
  // Check to make sure the layer attribute is properly set.
  if ($behavior['layer'] && $map['layers'][$behavior['layer']]) {
    drupal_add_css(drupal_get_path('module', 'openlayers_behaviors') . '/openlayers_behaviors.css', 'module');
    
    // Designate some default values
    $behavior['attribute'] = (!empty($behavior['attribute'])) ? $behavior['attribute'] : 'name';
    $behavior['attribute_id'] = (!empty($behavior['attribute_id'])) ? $behavior['attribute_id'] : $map['id'] . '-tooltip-text';
    $behavior['container_id'] = (!empty($behavior['container_id'])) ? $behavior['container_id'] : $map['id'] . '-tooltip';
    $behavior['offset_top'] = (!empty($behavior['offset_top'])) ? $behavior['offset_top'] : 30;
    $behavior['offset_left'] = (!empty($behavior['offset_left'])) ? $behavior['offset_left'] : 12;
    
    // Create container
    $behavior['container'] = theme('openlayers_behaviors_tooltip_container', $behavior, $map);
    
    return $behavior;
  }
}

/**
 * Callback for OpenLayers Behaviors (Popup)
 *
 * @param $behavoir
 *   Data about behavoir
 * @param $map
 *   Map array
 * @return
 *   Behavior array
 */
function openlayers_behaviors_process_popup($behavior, &$map) {
    // Assume we want to display the name attribute if no attribute is specified
    if (!$behavior['attribute']) {
      $behavior['attribute'] = 'name';
    }
    
    return $behavior;
}

/**
 * Callback for OpenLayers Behaviors (Draw Features)
 *
 * @param $behavoir
 *   Data about behavoir
 * @param $map
 *   Map array
 * @return
 *   Behavior array
 */
function openlayers_behaviors_process_draw_features($behavior, &$map) {
  // Check to make sure the layer attribute is properly set.
  if ($behavior['layer'] && $map['layers'][$behavior['layer']]) {
    // Add CSS
    drupal_add_css(drupal_get_path('module', 'openlayers_behaviors') . '/openlayers_behaviors.css', 'module');
    
    // Add mapReady Event
    $map['events'] = ($map['events']) ? $map['events'] : array();
    $map['events']['mapReady'] = ($map['events']['mapReady']) ? $map['events']['mapReady'] : array();
    $map['events']['mapReady'][] = 'drawFeaturesMapReady';
    
    return $behavior;
  }
}

/**
 * Callback for OpenLayers Behaviors (Fullscreen)
 *
 * @param $behavoir
 *   Data about behavoir
 * @param $map
 *   Map array
 * @return
 *   Behavior array
 */
function openlayers_behaviors_process_fullscreen($behavior, &$map) {
  drupal_add_css(drupal_get_path('module', 'openlayers_behaviors') .'/openlayers_behaviors.css', 'module');
  return $behavior;
}

/**
 * Callback for OpenLayers Behaviors (De-clutter)
 *
 * @param $behavoir
 *   Data about behavoir
 * @param $map
 *   Map array
 * @return
 *   Behavior array
 */
function openlayers_behaviors_process_declutter($behavior, &$map) {
  if ($behavior['layer'] && $map['layers'][$behavior['layer']]) {
    
    // Add Events to map
    $map['events'] = ($map['events']) ? $map['events'] : array();
    $map['events']['zoomend'] = ($map['events']['zoomend']) ? $map['events']['zoomend'] : array();
    $map['events']['zoomend'][] = 'declutterZoomEnd';
    
    // @@TODO: Add Events to layer (features added + removed)
    
    return $behavior;
  }
}
