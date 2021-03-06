// $Id: openlayers_behaviors.behaviors.js,v 1.20 2009/09/24 17:40:47 tmcw Exp $

/**
 * @file
 * JS functions to handle different kinds of behaviors
 *
 * @ingroup openlayers
 */

/**
 * Global Object for Namespace
 */
var OL = OL || {};
OL.Behaviors = OL.Behaviors || {};


/**
 * OL Popup Behavior
 *
 * @param event
 *   Event Object
 */
OL.Behaviors.popup = function(event) {
  var mapDef = event.mapDef;
  var mapid = mapDef.id;
  var map = event.map;
  var behavior = event.behavior;
  var layers = Array();
  
  // Set up the hover triggers
  for (layer in OL.maps[mapid].map.layers) {
    if (OL.maps[mapid].map.layers[layer].drupalData.type == 'Vector') {
	    OL.maps[mapid].map.layers[layer].drupalData.popupAttribute = behavior.attribute;
      OL.maps[mapid].map.layers[layer].drupalData.popupId = behavior.id;
      // have to use push so it stores the reference instead of value
      layers.push(OL.maps[mapid].map.layers[layer]);
    }
  }

  var selectControlOptions = {
    onSelect: OL.Behaviors.popupFeatureSelected, 
    onUnselect: OL.Behaviors.popupFeatureUnselected
  };

  OL.maps[mapid].controls[behavior.id] = new OpenLayers.Control.SelectFeature(layers, selectControlOptions);
  // Add control
  map.addControl(OL.maps[mapid].controls[behavior.id]);
  OL.maps[mapid].controls[behavior.id].activate();
}

/**
 * OL Popup Behavior - Feature Clicked Handler
 *
 * @param feature
 *   Feature Object
 */
OL.Behaviors.popupFeatureSelected = function(feature) {
  popup = new OpenLayers.Popup.FramedCloud('popup', 
    feature.geometry.getBounds().getCenterLonLat(),
    null,
    "<div class='openlayers-popup'>"+ feature.attributes[feature.layer.drupalData.popupAttribute] +"</div>",
    null, true,
	  function () {
	    var mapid = feature.layer.map.mapid;
		  OL.maps[mapid].controls[feature.layer.drupalData.popupId].unselect(feature);
	  }
	);
  
  feature.popup = popup;
  feature.layer.map.addPopup(popup);
}

/**
 * OL Popup Behavior - Feature Unselected
 *
 * @param feature
 *   Feature Object
 */
OL.Behaviors.popupFeatureUnselected = function(feature) {
  feature.layer.map.removePopup(feature.popup);
  feature.popup.destroy();
  feature.popup = null;
}

/**
 * OL Tooltip Behavior
 *
 * @param event
 *   Event Object
 */
OL.Behaviors.tooltip = function(event) {
  var mapDef = event.mapDef;
  var mapid = mapDef.id;
  var map = event.map;
  var behavior = event.behavior;
  
  // Set up the hover triggers
  var layer = OL.maps[mapid].layers[behavior.layer];
  var options = {
    hover: true, 
    highlightOnly: true, 
    renderIntent: 'temporary', 
    eventListeners: {
      featurehighlighted: OL.Behaviors.tooltipOver, 
      featureunhighlighted: OL.Behaviors.tooltipOut
    }
  };
  layer.drupalData.tooltipData = behavior;
  OL.maps[mapid].controls[behavior.id] = new OpenLayers.Control.SelectFeature(layer, options);
  
  // Add control
  map.addControl(OL.maps[mapid].controls[behavior.id]);
  OL.maps[mapid].controls[behavior.id].activate();
  
  // Set up the HTML div from themed container
  $("#" + mapid).after(behavior.container);
}

/**
 * OL Tooltip Behavior - Hover Over Handler
 *
 * @param event
 *   Event Object
 */
OL.Behaviors.tooltipOver = function(event) {
  var feature = event.feature;
  var behavior = feature.layer.drupalData.tooltipData;
  var tooltipText = feature.attributes[behavior.attribute];
  var $textContainer = $('#' + behavior.attribute_id);
  
  // Put text into tooltip
  $textContainer.html(tooltipText);
  
  // Set the tooltip location
  // @@TODO: dynamically set offset based on height of tooltip...
  var $tooltipContainer = $('#' + behavior.container_id);
  var centroid = OL.Behaviors.tooltipGetCentroid(feature.geometry.clone());
  var centroidPixel = feature.layer.map.getPixelFromLonLat(centroid);
  var mapDivOffset = $('#' + feature.layer.map.mapid).offset();
  var scrollTop = $(window).scrollTop();
  var scrollLeft = $(window).scrollLeft();
  var containerHeight = $textContainer.height();
  var containterWidth = $textContainer.width();
  var absoluteTop = centroidPixel.y + mapDivOffset.top - scrollTop - behavior.offset_top;
  var absoluteLeft = centroidPixel.x + mapDivOffset.left - scrollLeft - behavior.offset_left;
  
  // Create offset
  $tooltipContainer
    .css('top', absoluteTop)
    .css('left', absoluteLeft)
    .css('display', 'block');
}

/**
 * OL Tooltip Behavior - Hover Out Handler
 *
 * @param event
 *   Event Object
 */
OL.Behaviors.tooltipOut = function(event) {
  var behavior = event.feature.layer.drupalData.tooltipData;
  $('#' + behavior.container_id).css('display','none');
}

/**
 * OL Tooltip Behavior - Get Centroid for Tooltip
 *
 * Help function to get Centroid
 *
 * @param event
 *   Event Object
 */
OL.Behaviors.tooltipGetCentroid = function(geometry) {
  if (geometry.CLASS_NAME == 'OpenLayers.Geometry.Polygon') {
    var firstCentroid = geometry.getCentroid();
    if (geometry.containsPoint(firstCentroid)) {
      // The polygon contains it's centroid, easy!
      var baseCentroid = firstCentroid;
    }
    else {    
      // The polygon is a funny shape and does not contain 
      // it's own centroid. Find the closest vertex to the centroid.
      var vertices = geometry.getVertices();
      var minDistance;
      for (var v in vertices){
        var distance = vertices[v].distanceTo(firstCentroid);
        if (distance < minDistance || v == 0){
          minDistance = distance;
          var closestVertices = vertices[v];
        }
      }
      var baseCentroid = closestVertices;
    }
  }
  else if (geometry.CLASS_NAME == 'OpenLayers.Geometry.LineString') {
    // Simply use the middle vertices as the centroid. One day 
    // we may want to take into account the lengths of the different segments
    var vertices = geometry.getVertices();
    var midVerticesIndex = Math.round((vertices.length -1) / 2);
    var baseCentroid = vertices[midVerticesIndex];
  }
  else if (geometry.CLASS_NAME == 'OpenLayers.Geometry.Point') {
    var baseCentroid = geometry.getCentroid();
  }
  return new OpenLayers.LonLat(baseCentroid.x, baseCentroid.y);
}

/**
 * OL Zoom to Layer Behavior
 *
 * @param event
 *   Event Object
 */
OL.Behaviors.zoomToLayer = function(event) {
  var mapDef = event.mapDef;
  var mapid = mapDef.id;
  var map = event.map;
  var behavior = event.behavior;
  var layer = OL.maps[mapid].layers[behavior.layer];
  if (layer.features.length != 0) {
    // Check to see if we are dealing with just a single point.
    if (layer.features.length == 1 && layer.features[0].geometry.getArea() == 0) {
      var center = new OpenLayers.LonLat(layer.features[0].geometry.x, layer.features[0].geometry.y);
      // If pointZoom has been set, then center and zoom, else just center and don't zoom
      if (OL.isSet(behavior.pointZoom)) {
        map.setCenter(center, mapDef.behaviors.pointZoom);
      }
      else {
        map.setCenter(center); 
      }
    }
    // Else we are dealing with either a polygon, a line, or 
    // multiple points, all of which have bounds to which we can zoom
    else {
      var extentToZoom = new OpenLayers.Bounds();
      // Go through the feautres of the layer, building out the bounds to which we wish to zoom.
      for (var f in layer.features) {
        extentToZoom.extend(layer.features[f].geometry.getBounds());
      }
      // Zoom the map to the bounds of the layer
      map.zoomToExtent(extentToZoom);
    }
  }
}

/**
 * Process Draw Features. 
 *
 * This is for marking vector layers as editable. It will add standard 
 * functionality for adding and editing features.  This function does 
 * not *do* anything with the features other than allow them to be 
 * drawn, edited and deleted by the interface.  Use featureadded_handler, 
 * featuremodified_handler and featureremoved_handler if you wish to 
 * do something with the drawn/edited/deleted features.
 *
 * @param event
 *   Event Object
 */
OL.Behaviors.drawFeatures = function(event) {
  var mapDef = event.mapDef;
  var mapid = mapDef.id;
  var behavior = event.behavior;  
  var layer = OL.maps[mapid].layers[behavior.layer];
    
  // Determine what handler we need to use.
  switch (behavior.feature_type) {
    case 'point':
      var handler = OpenLayers.Handler.Point;
      break;
      
    case 'path':
      var handler = OpenLayers.Handler.Path;
      break;
      
    case 'polygon':
      var handler = OpenLayers.Handler.Polygon;
      break;
      
  }
  
  // Create our conrols and attach them to our layer.
  var createControl = new OpenLayers.Control.DrawFeature(layer, handler);  
  var modifyControl = new OpenLayers.Control.ModifyFeature(layer, {deleteCodes:[68]});
  
  // Add control to map
  OL.maps[mapid].map.addControl(createControl);
  OL.maps[mapid].map.addControl(modifyControl);

  // Disable the active mode by default.  This could be 
  // changed if we wanted people to draw on the map immediately.
  createControl.activeByDefault = false;
  modifyControl.activeByDefault = false;
  
  // Create space for Drupal data and
  // mark on the control what it is for drawing (point, path, or polygon)
  createControl.Drupal = {};
  modifyControl.Drupal = {};
  createControl.Drupal.DrawType = behavior.feature_type;
  modifyControl.Drupal.DrawType = behavior.feature_type;
  
  // Add our create and modify controls to the controls object.
  // Use a # prefix since these are special controls created by drawFeatures.
  OL.maps[mapid].controls['#create-' + behavior.feature_type] = createControl;
  OL.maps[mapid].controls['#modify-' + behavior.feature_type] = modifyControl;
  
  // Add special event handlers to controls
  if (behavior.featureadded_handler) {
    for (var ev in behavior.featureadded_handler) {
      createControl.events.register('featureadded', createControl, OL.getObject(behavior.featureadded_handler[ev]));
    }
  }
  // Feature modified
  if (behavior.featuremodified_handler) {
    for (var ev in behavior.featuremodified_handler) { 
      layer.events.register('afterfeaturemodified', layer, OL.getObject(behavior.featuremodified_handler[ev]));
    }
  }
  // Feature moved
  if (behavior.featureremoved_handler) {
    for (var ev in behavior.featureremoved_handler) { 
      layer.events.register('beforefeatureremoved', layer, OL.getObject(behavior.featureremoved_handler[ev]));
    }
    
    // If a user presses the delete key, delete the currently selected polygon. 
    // This will in turn trigger the featureremoved_handler function. 
    $(document).keydown(function(event) {
      vKeyCode = event.keyCode;
      // If it is the Mac delete key (63272), or regular delete key (46) 
      // delete all selected features for the active map.
      if ((vKeyCode == 63272) || vKeyCode == 46) {
        for (var m in OL.maps){
          if (OL.maps[m].active == true){
            for (var b in OL.mapDefs[m].behaviors){
              var behavior = OL.mapDefs[m].behaviors[b];
              if (behavior.type == 'openlayers_behaviors_draw_features') {
                var featureToErase = OL.maps[m].layers[behavior.layer].selectedFeatures[0];
                OL.maps[m].layers[behavior.layer].destroyFeatures([featureToErase]);
                // Reload the modification control so we dont have ghost
                // control points from the recently deceased feature
                OL.maps[m].controls['#modify-' + behavior.feature_type].deactivate();
                OL.maps[m].controls['#modify-' + behavior.feature_type].activate();
              }
            }
          }
        }
      }
    });
  }
    
  // Add Base Pan button, if not already added
  if ($('#openlayers-controls-pan-' + mapid).length == 0) {
    $('<a href="#"></a>')
      .attr('id', 'openlayers-controls-pan-' + mapid)
      .attr('title', Drupal.t('Pan around map'))
      .addClass('openlayers-controls-draw-feature-link')
      .addClass('openlayers-controls-draw-feature-link-pan')
      .addClass('openlayers-controls-draw-feature-link-on')
      .data('type', 'pan')
      .data('mapid', mapid)
      .appendTo('#openlayers-controls-' + mapid);
  }
  
  // Add other control link (button)
  $('<a href="#"></a>')
    .attr('id', 'openlayers-controls-draw-' + behavior.feature_type + '-' + mapid)
    .attr('title', Drupal.t('Draw') + ' ' + behavior.feature_type)
    .addClass('openlayers-controls-draw-feature-link')
    .addClass('openlayers-controls-draw-feature-link-' + behavior.feature_type)
    .addClass('openlayers-controls-draw-feature-link-off')
    .data('type', behavior.feature_type)
    .data('mapid', mapid)
    .data('behaviorid', behavior.id)
    .appendTo('#openlayers-controls-' + mapid);
}

/**
 * Draw Features Map Ready Event
 *
 * @param event
 *   Event Object
 */
OL.EventHandlers.drawFeaturesMapReady = function(event) {
  // Add click event to the action link (button)
  $('.openlayers-controls-draw-feature-link').click(function() {
    var $thisLink = $(this);
    var $allControls = $('.openlayers-controls-draw-feature-link');
    var mapid = $thisLink.data('mapid');
    var controlType = $thisLink.data('type');
    var behaviorid = $thisLink.data('behaviorid');
    
    // Change the look of the action link
    $allControls.removeClass('openlayers-controls-draw-feature-link-on');
    $allControls.addClass('openlayers-controls-draw-feature-link-off');
    $thisLink.addClass('openlayers-controls-draw-feature-link-on');
    $thisLink.removeClass('openlayers-controls-draw-feature-link-off');
    
    // Cycle through the different possible types of controls (polygon, line, point, pan)
    for (var b in OL.mapDefs[mapid].behaviors){
      var behavior  = OL.mapDefs[mapid].behaviors[b];
      
      // Check behavior type
      if (behavior.type == 'openlayers_behaviors_draw_features') {
        var createControl = OL.maps[mapid].controls['#create-' + behavior.feature_type];
        var modifyControl = OL.maps[mapid].controls['#modify-' + behavior.feature_type];
        
        // Deactivate everything
        createControl.deactivate();
        modifyControl.deactivate();
          
        // Activate it if it matches
        if (controlType == behavior.feature_type) {
          createControl.activate();
          modifyControl.activate();
        }
      }
    }
    
    // Make sure the link doesn't go anywhere
    return false;
  });
}

/**
 * Fullsceen Behavoir
 *
 * @param event
 *   Event Object
 */
OL.Behaviors.fullscreen = function(event) {
  var mapDef = event.mapDef;
  var mapid = mapDef.id;
  var $map = $('#' + mapid);
  var $mapControls = $('#openlayers-controls-' + mapid);
  
  $('<a href="#"></a>')
    .attr('id', 'openlayers-controls-fullscreen-' + mapid)
    .addClass('openlayers-controls-fullscreen')
    .data('mapid', mapid)
    .appendTo('#openlayers-controls-' + mapid)
    .click(function() {
      var $thisElement = $(this);
    
      // Store data
      if (!OL.isSet(OL.Behaviors.fullscreenRegistry)) {
        OL.Behaviors.fullscreenRegistry = [];
      }
      if (!OL.isSet(OL.Behaviors.fullscreenRegistry[mapid])) {
        OL.Behaviors.fullscreenRegistry[mapid] = {};
        OL.Behaviors.fullscreenRegistry[mapid].fullscreen = false;
        OL.Behaviors.fullscreenRegistry[mapid].mapstyle = [];
        OL.Behaviors.fullscreenRegistry[mapid].controlsstyle = [];
      }
      
      // Check if fullscreen
      if (!OL.Behaviors.fullscreenRegistry[mapid].fullscreen) {
        OL.Behaviors.fullscreenRegistry[mapid].fullscreen = true;
      
        // Store old css values
        var mapStylesToStore = ['position','top','left','width','height','z-index'];
        var controlStylesToStore = ['position','top','right'];
        for (var ms in mapStylesToStore) {
          OL.Behaviors.fullscreenRegistry[mapid].mapstyle[mapStylesToStore[ms]] = $('#' + mapid).css(mapStylesToStore[ms]);
        }
        for (var cs in controlStylesToStore) {
          OL.Behaviors.fullscreenRegistry[mapid].controlsstyle[controlStylesToStore[cs]] = $('#openlayers-controls-' + mapid).css(controlStylesToStore[cs]);
        }
      
        // Resize the map.
        $map.css('position','fixed')
          .css('top','0px')
          .css('left','0px')
          .css('width','100%')
          .css('height','100%')
          .css('background','#fff')
          .css('z-index','999');
        // Change CSS on map controls
        $mapControls.css('position','fixed')
          .css('top','0px')
          .css('right','0px');
        // Update classes
        $thisElement.removeClass('openlayers-controls-fullscreen')
          .addClass('openlayers-controls-unfullscreen');
        
        // Update size of OpenLayers
        event.map.updateSize();
      }
      else {
        // Restore styles, resizing the map.
        for (var ms in OL.Behaviors.fullscreenRegistry[mapid].mapstyle) {
          $('#' + mapid).css(ms,OL.Behaviors.fullscreenRegistry[mapid].mapstyle[ms]);
        };
        for (var cs in OL.Behaviors.fullscreenRegistry[mapid].controlsstyle) {
          $('#openlayers-controls-' + mapid).css(cs,OL.Behaviors.fullscreenRegistry[mapid].controlsstyle[cs]);
        };
        
        // Update classes
        $thisElement.removeClass('openlayers-controls-unfullscreen')
          .addClass('openlayers-controls-fullscreen');
          
        // Update stored registry and OpenLayers map size
        OL.Behaviors.fullscreenRegistry[mapid].fullscreen = false;
        event.map.updateSize();
      }
    });
}



/**
 * De-clutter Behavoir
 * 
 * This function sets up the behavior - making a copy of the original geometry,
 * and calling the first SortAndMove
 *
 * @param event
 *   Event Object
 */
OL.Behaviors.declutter = function(event) {
  for (var l in event.map.layers) {
    if (event.map.layers[l].drupalId == event.behavior.layer) var layer = event.map.layers[l];
  }
  for (var f in layer.features) {
    if (layer.features[f].geometry.CLASS_NAME == 'OpenLayers.Geometry.Point'){
      layer.features[f].originalGeometry = layer.features[f].geometry.clone();
    }
  }
  OL.Behaviors.declutterSortAndMove(layer,event.behavior);
}


/**
 * De-Clutter Sort and Move
 * 
 * Given a layer, find all the points and move them so they are not overlapping.
 * 
 * @param layer
 *   Layer Object
 * @param behavior
 *   Behavior Definition Object
 */

OL.Behaviors.declutterSortAndMove = function(layer,behavior) {
  // Set up our variables.
  var points = [];

  if (OL.isSet(behavior.adjustment)){
    var pixelAdjustment = parseInt(behavior.adjustment);
  }
  else {
    var pixelAdjustment = 0;
  }
  
  if (OL.isSet(behavior.limit)){
    var recursionLimit = parseInt(behavior.limit);
  }
  else {
    var recursionLimit = 50;
  }

  // Gather up our points. declutter currently only works with points.
  for (var f in layer.features){
    if (layer.features[f].geometry.CLASS_NAME == 'OpenLayers.Geometry.Point'){
      points.push(layer.features[f]);
    }
  }
  
  // Get the max pixel size of the icon or the vector representation
  for (var p in points){
    if (points[p].style){
      var pointRadius     = parseInt(points[p].style.pointRadius);
      var strokeWidth     = parseInt(points[p].style.strokeWidth);
      var externalGraphic = points[p].style.externalGraphic;
      var graphicWidth    = parseInt(points[p].style.graphicWidth);
      var graphicHeight   = parseInt(points[p].style.graphicHeight);
    }
    else {
    // We are using the default layer style
      var pointRadius     = parseInt(layer.styleMap.styles['default'].defaultStyle.pointRadius);
      var strokeWidth     = parseInt(layer.styleMap.styles['default'].defaultStyle.strokeWidth);
      var externalGraphic = layer.styleMap.styles['default'].defaultStyle.externalGraphic;
      var graphicWidth    = parseInt(layer.styleMap.styles['default'].defaultStyle.graphicWidth);
      var graphicHeight   = parseInt(layer.styleMap.styles['default'].defaultStyle.graphicHeight);
    }
    
    if (OL.isSet(externalGraphic)){
      // We are using a graphic
      if (graphicWidth < graphicHeight){
        points[p].pixelSize = intvalgraphicHeight -2 + pixelAdjustment;
      }
      else {
        points[p].pixelSize = graphicWidth -2 + pixelAdjustment;
      }
    }
    else {
      // We are using a vector style
      points[p].pixelSize = (strokeWidth * 2) + pointRadius + 2 + pixelAdjustment;
    }

  }
  
  // Get the pixel coordinates of the points
  for (var p in points) {
    var centroidPixel = layer.map.getPixelFromLonLat(new OpenLayers.LonLat(points[p].geometry.x, points[p].geometry.y));
    points[p].pixelX = centroidPixel.x;
    points[p].pixelY = centroidPixel.y;
  }
  
  // Check to see if there is a collision, and if there is then 'move' the point by adjusting the pixel
  for (var p in points) {
    if (OL.EventHandlers.declutterCollision(points[p], points) == true){
      // We have a collision. Try moving the point.
      var testPoint = { 'pixelX': points[p].pixelX, 'pixelY': points[p].pixelY, 'pixelSize': points[p].pixelSize, 'id': points[p].id };
      var emptyPlace = OL.EventHandlers.declutterFindFreeSpace(testPoint, points, 0, 1, recursionLimit);
      points[p].pixelX = emptyPlace.pixelX;
      points[p].pixelY = emptyPlace.pixelY;
      var newPixelCoord = new OpenLayers.Pixel(points[p].pixelX, points[p].pixelY);
      var newLonLat = layer.map.getLonLatFromPixel(newPixelCoord);
      // We've found an empty spot, move the point to it!
      points[p].geometry.x = newLonLat.lon;
      points[p].geometry.y = newLonLat.lat;
      points[p].geometry.calculateBounds();
    }
  }
  layer.redraw();
}

/**
 * De-Clutter Find Free Space
 * 
 * Given a point, and a array of points, find the closet place that is has
 * enough free space to fit the point. It does this by recursively calling
 * itself, spiralling out to find a free spot.
 * 
 * @param testPoint
 *   Point we should find a free space for
 * @param points
 *   Array of points that the TetPoint should not overlap with.
 * @param direction
 *   Direction (1 - 8) to try to find a free space at.
 * @param distance
 *   Distance to try to find a free space at
 */
OL.EventHandlers.declutterFindFreeSpace = function(testPoint, points, direction, distance, distanceLimit){
  var tempPoint = testPoint;
  //@@TODO: Fix the use of direction instead of using math.random
  //var angle = (direction/8) * 2 * 3.1415;
  var angle = (Math.random()) * 2 * 3.141569;
  tempPoint.pixelY = tempPoint.pixelY + (((distance * tempPoint.pixelSize) + 4) * (Math.sin(angle)));
  tempPoint.pixelX = tempPoint.pixelX + (((distance * tempPoint.pixelSize) + 4) * (Math.cos(angle)));
  
  if (OL.EventHandlers.declutterCollision(tempPoint, points) == true){
    // We didn't find a free spot, adjust direction (and possibly distance) and try again.
    if (direction == 9) {
      // We have exausted all directions. Try furthur a-field.
      direction = 1;
      distance = distance + 1;
    }
    else {
      direction = direction + 1; 
    }
    
    // Try again recursively.
    if (OL.isSet(distanceLimit)){
      if (distance == distanceLimit) return false;
    }
    return OL.EventHandlers.declutterFindFreeSpace(testPoint, points, direction, distance);
  }
  else {
    return tempPoint;
  }
}

/**
 * De-Clutter Collision
 * 
 * Determine whether a given point collides with an array of points
 * 
 * @param testPoint
 *   Point we should find a free space for
 * @param points
 *   Array of points that the TetPoint should not overlap with.
 */
OL.EventHandlers.declutterCollision = function(testPoint, points){
  // Go through points and see if there is a collision with this point.
  for (var p in points){
    if (points[p].id != testPoint.id){
      // Distance as per Pythagorean theorem
      var distance = Math.sqrt(Math.pow((testPoint.pixelX - points[p].pixelX),2) + Math.pow((testPoint.pixelY - points[p].pixelY),2));
      if (distance < testPoint.pixelSize) return true;
    }
  }
  return false;
}

/**
 * De-Clutter Zoom End
 * 
 * Event Handler for when the user zooms. We reset all the points to their original location,
 * then call declutterSortAndMove to seperate them out again.
 * 
 * @param event
 *   Event Object
 */
OL.EventHandlers.declutterZoomEnd = function(event) {
  mapid = event.object.mapid;
  // Go through all declutter behaviors and trigger declutterSortAndMove
  for (var b in OL.mapDefs[mapid].behaviors){
    var behavior = OL.mapDefs[mapid].behaviors[b];
    if (behavior.type == 'openlayers_behaviors_declutter'){
      for (var l in event.object.layers) {
        if (event.object.layers[l].drupalId == behavior.layer) var layer = event.object.layers[l];
      }
      
        // Go through features and put them back to their original place, so that we can shuffle them again for the next zoom.
      for (var f in layer.features) {
        if (layer.features[f].geometry.CLASS_NAME == 'OpenLayers.Geometry.Point'){
          layer.features[f].geometry.x = layer.features[f].originalGeometry.x;
          layer.features[f].geometry.y = layer.features[f].originalGeometry.y;
        }
      }
      OL.Behaviors.declutterSortAndMove(layer,behavior);
    }
  }
}
