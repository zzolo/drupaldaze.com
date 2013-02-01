// $Id: geotaxonomy.admin.js,v 1.1 2009/09/22 23:13:13 alexb Exp $

/**
 * Drupal behaviors for Geotaxonomy UI form.
 */
Drupal.behaviors.geotaxonomy = function(context) {  
 // Update map positioning when text fields are changed.
  $("#edit-lat:not(.geotaxonomy-ui-processed), $edit-lon:not(.geotaxonomy-ui-processed)").each(function() {
    $(this).addClass('geotaxonomy-ui-processed');
    $(this).change(function() {
      Drupal.geotaxonomy.updateMapCenter();
    });
  });

  // Run once on load.
  Drupal.geotaxonomy.updateMapCenter();
}

/**
 * Register form center value updating events.
 */
Drupal.behaviors.geotaxonomy_center = function(context) {
  var data = $(context).data('openlayers');
  if (data) {
    data.openlayers.events.register('moveend', data.map, function() { Drupal.geotaxonomy.updateCenterFormValues(data.openlayers) });
  }
}

/**
 * Helper functions.
 */
Drupal.geotaxonomy = {

  /**
   * Update the center of the helpmap using the values from the form
   *
   * Take the center lat, lon and zoom values from the form and update
   * the helper map.
   */
  'updateMapCenter': function() {
    var data = $('#geotaxonomy-latlon-helpmap').data('openlayers');
    if (data) {
      var lat = $('#geotaxonomy-form-lat').val();
      var lon = $('#geotaxonomy-form-lon').val();

      // Check for lat and lon
      if (lat != '' && lon != '') {
        // Create new center
        var center = new OpenLayers.LonLat(lon, lat);
        // Set center of map.
        data.openlayers.setCenter(center);
      }
    }
  },

  /**
   * Event callback for updating center form field values when map is dragged or zoomed.
   */
  'updateCenterFormValues': function() {
    var data = $('#geotaxonomy-latlon-helpmap').data('openlayers');
  
    if (data) {
      
      var helpmap = data.openlayers;
      var center = helpmap.getCenter();

      // Get new lat and lon
      var lat = center.lat;
      var lon = center.lon;
            
      // Set new values
      $('#edit-lat').val(lat);
      $('#edit-lon').val(lon);
    }
  }
}