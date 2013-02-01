<?php
// $Id: openlayers_views.views.theme.inc,v 1.5 2009/09/24 17:40:48 tmcw Exp $

/**
 * @file
 * This file holds views theme function for style plugin.
 *
 * @ingroup openlayers
 */

/**
 * Implementation of theme function
 */
function theme_openlayers_views_map($view, $options, $map, $title) {
  $title = ($title) ? '<h3>'. $title .'</h3>' : '';
  $output = '
    '. $title .'
    <div class="openlayers-views-map">
      '. $map['themed'] .'
    </div>
  ';
  
  return $output;
}