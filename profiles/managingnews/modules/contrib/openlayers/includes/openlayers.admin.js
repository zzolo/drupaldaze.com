// $Id: openlayers.admin.js,v 1.1 2009/09/24 17:40:46 tmcw Exp $

/**
 * @file
 * This file holds the javascript functions for the preset UI
 *
 * @ingroup openlayers
 */

/**
 * Drupal behaviors for OpenLayers UI form.
 */
Drupal.behaviors.openlayers_ui = function(context) {
  // Panels
  $("ul#openlayers-panel-links li a:not(.openlayers-ui-processed)").each(function() {
    $(this).addClass('openlayers-ui-processed');
    $(this).click(function() {
      $(".openlayers-panel-active").removeClass('openlayers-panel-active');
      var panel = $(this).attr('href').split('#')[1];
      $("div." + panel).addClass('openlayers-panel-active');
      $(this).addClass('openlayers-panel-active');
      return false;
    });
  });

  // Automatic options.  We do it here, instead of in Form API because
  // Form API enforces the disabled
  $("#edit-options-automatic-options:not(.openlayers-ui-processed)").each(function() {
    $(this).addClass('openlayers-ui-processed');
    $(this).change(function() {
      var $thisCheck = $(this);
      var $autoOptions = $thisCheck.parent().parent().parent().find('input:not("#edit-options-automatic-options")');
      if ($thisCheck.is(':checked')) {
        $autoOptions.attr('disabled', 'disabled');
      }
      else {
        $autoOptions.removeAttr('disabled');
      }
    });

    // When form is submitted, if disabled, FAPI does not read values   
    $(this).parents('form').submit(function() {
      $("#edit-options-automatic-options").attr('checked', false).trigger('change');
    });
    $(this).trigger('change');
  });

  // Update map positioning when text fields are changed.
  $("#edit-center-lat:not(.openlayers-ui-processed), #edit-center-lon:not(.openlayers-ui-processed), #edit-center-zoom:not(.openlayers-ui-processed)").each(function() {
    $(this).addClass('openlayers-ui-processed');
    $(this).change(function() {
      Drupal.openlayers_ui.updateMapCenter();
    });
  });

  // Run once on load.
  Drupal.openlayers_ui.updateMapCenter();
}

/**
 * Register form center value updating events.
 */
Drupal.behaviors.openlayers_ui_center = function(context) {
  var data = $(context).data('openlayers');
  if (data) {
    data.openlayers.events.register('moveend', data.map, function() { Drupal.openlayers_ui.updateCenterFormValues() });
    data.openlayers.events.register('zoomend', data.map, function() { Drupal.openlayers_ui.updateCenterFormValues() });
  }
}

/**
 * Helper functions.
 */
Drupal.openlayers_ui = {

  /**
   * Update the center of the helpmap using the values from the form
   *
   * Take the center lat, lon and zoom values from the form and update
   * the helper map.
   */
  'updateMapCenter': function() {
    var data = $('#openlayers-center-helpmap').data('openlayers');
    if (data) {
      var projection = $('#edit-projections-projection').val();
      var zoom = $('#edit-center-zoom').val();
      var lat = $('#edit-center-lat').val();
      var lon = $('#edit-center-lon').val();

      // Check for lat and lon
      if (lat != '' && lon != '') {
        // Create new center
        var center = new OpenLayers.LonLat(lon, lat);
        // Transform for projection
        center.transform(new OpenLayers.Projection('EPSG:' + projection), new OpenLayers.Projection('EPSG:4326'));
        // Set center of map.
        data.openlayers.setCenter(center, zoom);
      }
    }
  },

  /**
   * Event callback for updating center form field values when map is dragged or zoomed.
   */
  'updateCenterFormValues': function() {
    var data = $('#openlayers-center-helpmap').data('openlayers');
    if (data) {
      var helpmap = data.openlayers;
      var projection = $('#edit-projections-projection').val();
      var zoom = helpmap.getZoom();
      var center = helpmap.getCenter();

      // Transform center
      center.transform(new OpenLayers.Projection('EPSG:4326'), new OpenLayers.Projection('EPSG:' + projection));

      // Get new lat and lon
      var lat = center.lat;
      var lon = center.lon;

      // Set new values
      $('#edit-center-zoom').val(zoom);
      $('#edit-center-lat').val(lat);
      $('#edit-center-lon').val(lon);
    }
  }
}
