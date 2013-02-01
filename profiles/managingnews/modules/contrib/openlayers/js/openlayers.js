// $Id: openlayers.js,v 1.55 2009/11/13 19:50:35 tmcw Exp $
/*jslint white: false */
/*global OpenLayers Drupal $ document jQuery */

/**
 * @file
 * This file holds the main javascript API for OpenLayers. It is 
 * responsable for loading and displaying the map.
 *
 * @ingroup openlayers
 */

/**
 * This is a workaround for a bug involving IE and VML support.
 * See the Drupal Book page describing this problem:
 * http://drupal.org/node/613002
 */

document.namespaces;

/**
 * Minimal OpenLayers map bootstrap.
 * All additional operations occur in additional Drupal behaviors.
 */
Drupal.behaviors.openlayers = function(context) {
  if (typeof(Drupal.settings.openlayers) === 'object' && Drupal.settings.openlayers.maps && !$(context).data('openlayers')) {
    $('.openlayers-map:not(.openlayers-processed)').each(function() {
      $(this).addClass('openlayers-processed');

      var map_id = $(this).attr('id');

      if (Drupal.settings.openlayers.maps[map_id]) {
        var map = Drupal.settings.openlayers.maps[map_id];
        
        $(this)
          // @TODO: move this into markup in theme function, doing this dynamically is a waste.
          .css('width', map.width)
          .css('height', map.height);

        // Process map option settings and prepare params for OpenLayers.
        if (map.options) {
          var options = map.options;
          options.projection = new OpenLayers.Projection('EPSG:' + map.projection);          
          options.displayProjection = new OpenLayers.Projection('EPSG:' + map.displayProjection);
          options.controls = [];
        }
        else {
          var options = {};
          options.projection = new OpenLayers.Projection('EPSG:' + map.projection);
          options.displayProjection = new OpenLayers.Projection('EPSG:' + map.displayProjection);
          if (map.projection === '900913') {
            options.maxExtent = new OpenLayers.Bounds(-20037508.34, -20037508.34, 20037508.34, 20037508.34);
          }
          if (map.projection === '4326') {
            options.maxExtent = new OpenLayers.Bounds(-180, -90, 180, 90);
          }
          options.maxResolution = 1.40625;
          options.controls = [];
        }

        // Change image path if specified
        if (map.image_path) {
          if (map.image_path.substr(map.image_path.length - 1) !== '/') {
            map.image_path = map.image_path + '/';
          }
          if (map.image_path.indexOf('://') >= 0) {
            OpenLayers.ImgPath = map.image_path;
          }
          else {
            OpenLayers.ImgPath = Drupal.settings.basePath + map.image_path;
          }
        }

        // Change css path if specified
        if (map.css_path) {
          if (map.css_path.indexOf('://') >= 0) {
            options.theme = map.css_path;
          }
          else {
            options.theme = Drupal.settings.basePath + map.css_path;
          }
        }

        // Initialize openlayers map
        var openlayers = new OpenLayers.Map(map.id, options);

        // Run the layer addition first
        Drupal.openlayers.addLayers(map, openlayers);

        // Attach data to map DOM object
        $(this).data('openlayers', {'map': map, 'openlayers': openlayers});

        // Finally, attach behaviors
        Drupal.attachBehaviors(this);

        if($.browser.msie) {
          Drupal.openlayers.redrawVectors();
        }
      }
    });
  }
};

/**
 * Collection of helper methods.
 */
Drupal.openlayers = {
  /**
   * Redraw Vectors.
   * This is necessary because various version of IE cannot draw vectors on
   * $(document).ready()
   */
  'redrawVectors': function() {
    $(window).load(
      function() {
        for(map in Drupal.settings.openlayers.maps) {
          $.each($('#'+map).data('openlayers').openlayers.getLayersByClass('OpenLayers.Layer.Vector'), 
            function(i, layer) {
              layer.redraw();
            }
          );
        }
      }
    );
  },
  'addLayers': function(map, openlayers) {
    for (var name in map.layers) {
      var layer;      
      var options = map['layers'][name];
      if (Drupal.openlayers.layer[options['layer_handler']] !== undefined) {
        var layer = Drupal.openlayers.layer[options['layer_handler']](name, map, options);

        layer.visibility = (!map['layer_activated'] || map['layer_activated'][name]);

        if (map.center.wrapdateline === '1') {
          // TODO: move into layer specific settings
          layer.wrapDateLine = true;
        }
        openlayers.addLayer(layer);
      }
    }
    
    // Set our default base layer
    for (var layer in openlayers.layers) {      
      if (openlayers.layers[layer].name === map.layers[map.default_layer].name) {
        openlayers.setBaseLayer(openlayers.layers[layer]); 
      }
    }
    
    // Zoom & center
    if (map.center.initial) {
      var center = new OpenLayers.LonLat.fromString(map.center.initial.centerpoint).transform(new OpenLayers.Projection('EPSG:4326'), new OpenLayers.Projection('EPSG:' + map.projection));
      var zoom = parseInt(map.center.initial.zoom, 10);
      openlayers.setCenter(center, zoom, false, false);
    }

    // Set the restricted extent if wanted.
    // Prevents the map from being panned outside of a specfic bounding box.
    // TODO: needs to be aware of projection: currently the restrictedExtent string is always latlon
    if (typeof map.center.restrict !== 'undefined') {
      openlayers.restrictedExtent = new OpenLayers.Bounds.fromString(map.center.restrict.restrictedExtent);
    }
  },
  /**
   * Abstraction of OpenLayer's feature adding syntax to work with Drupal output.
   * Ideally this should be rolled into the PHP code, because we don't want to manually
   * parse WKT
   */
  'addFeatures': function(map, layer, features) {
    var wktFormat = new OpenLayers.Format.WKT();
    var newFeatures = [];

    // Go through features
    for (var key in features) {
      var feature = features[key];

      // Extract geometry either from wkt property or lon/lat properties
      if (feature.wkt) {
        // Check to see if it is a string of wkt, or an array for a multipart feature.
        if (typeof(feature.wkt) === "string") {
          var wkt = feature.wkt;
        }
        else if (typeof(feature.wkt) == "object" && feature.wkt !== null && feature.wkt.length !== 0) {
          var wkt = "GEOMETRYCOLLECTION(" + feature.wkt.join(',') + ")";
        }
        var newFeatureObject = wktFormat.read(wkt);
      }
      else if (feature.lon) {
        var newFeatureObject = wktFormat.read("POINT(" + feature.lon + " " + feature.lat + ")");
      }

      // If we have successfully extracted geometry add additional
      // properties and queue it for addition to the layer
      if (newFeatureObject) {
        var newFeatureSet = [];

        // Check to see if it is a new feature, or an array of new features.
        if (typeof(newFeatureObject[0]) === 'undefined'){
          newFeatureSet[0] = newFeatureObject;
        }
        else{
          newFeatureSet = newFeatureObject;
        }

        // Go through new features
        for (var i in newFeatureSet) {
          var newFeature = newFeatureSet[i];

          // Transform the geometry if the 'projection' property is different from the map projection
          if (feature.projection) {
            if (feature.projection !== map.projection){
              var featureProjection = new OpenLayers.Projection("EPSG:" + feature.projection);
              var mapProjection = new OpenLayers.Projection("EPSG:" + map.projection);
              newFeature.geometry.transform(featureProjection, mapProjection);
            }
          }

          // Add attribute data
          if (feature.attributes){
            newFeature.attributes = feature.attributes;
            newFeature.data = feature.attributes;
          }

          // Add style information
          if (feature.style) {
            newFeature.style = jQuery.extend({}, OpenLayers.Feature.Vector.style['default'], feature.style);
          }

          // Push new features
          newFeatures.push(newFeature);
        }
      }
    }

    // Add new features if there are any
    if (newFeatures.length !== 0){
      layer.addFeatures(newFeatures);
    }
  },
  /**
   * getStyleMap
   */
  'getStyleMap': function(map, layername) {
    if (map.styles) {
      var stylesAdded = {};
      // Grab and map base styles.
      for (var style in map.styles) {
        stylesAdded[style] = new OpenLayers.Style(map.styles[style]);
      }
      // Implement layer-specific styles.
      if (map.layer_styles[layername]) {
        var style = map.layer_styles[layername];
        stylesAdded['default'] = new OpenLayers.Style(map.styles[style]);
      }
      return new OpenLayers.StyleMap(stylesAdded);
    }
    // Default styles
    return new OpenLayers.StyleMap({
      'default': new OpenLayers.Style({
        pointRadius: 5,
        fillColor: "#ffcc66",
        strokeColor: "#ff9933",
        strokeWidth: 4,
        fillOpacity:0.5
      }),
      'select': new OpenLayers.Style({
        fillColor: "#66ccff",
        strokeColor: "#3399ff"
      })
    });
  }
};
