; $Id: managingnews.make,v 1.1.2.7 2009/11/19 15:04:58 alexb Exp $

core = 6.x

; Contrib projects
projects[ctools][subdir] = "contrib"
projects[data][subdir] = "contrib"
projects[devel][subdir] = "contrib"
projects[diff][subdir] = "contrib"
projects[drupal_queue][subdir] = "contrib"
projects[features][subdir] = "contrib"
projects[feeds][subdir] = "contrib"
projects[flot][subdir] = "contrib"
projects[geotaxonomy][subdir] = "contrib"
projects[imageapi][subdir] = "contrib"
projects[imagecache][subdir] = "contrib"
projects[libraries][subdir] = "contrib"
projects[openidadmin][subdir] = "contrib"
projects[openlayers][subdir] = "contrib"
projects[openlayers][version] = "0"
projects[porterstemmer][subdir] = "contrib"
projects[purl][subdir] = "contrib"
projects[schema][subdir] = "contrib"
projects[strongarm][subdir] = "contrib"
projects[views][subdir] = "contrib"
projects[views_rss][subdir] = "contrib"

; Patched.
; Explicit versions specified to ensure patches apply cleanly.
projects[context][subdir] = "contrib"
projects[context][version] = "2.0-beta7"
projects[context][patch][] = "http://drupal.org/files/issues/606816-1_node_form_context.patch"

; Custom modules
projects[extractor][subdir] = "custom"
projects[extractor][location] = "http://code.developmentseed.org/fserver"
projects[seed][subdir] = "custom"
projects[seed][location] = "http://code.developmentseed.org/fserver"
projects[stored_views][subdir] = "custom"
projects[stored_views][location] = "http://code.developmentseed.org/fserver"
projects[views_modes][subdir] = "custom"
projects[views_modes][location] = "http://code.developmentseed.org/fserver"

; Features
projects[mn_about][subdir] = "features"
projects[mn_about][location] = "http://code.developmentseed.org/fserver"
projects[mn_core][subdir] = "features"
projects[mn_core][location] = "http://code.developmentseed.org/fserver"
projects[mn_search][subdir] = "features"
projects[mn_search][location] = "http://code.developmentseed.org/fserver"
projects[mn_channels][subdir] = "features"
projects[mn_channels][location] = "http://code.developmentseed.org/fserver"
projects[mn_share][subdir] = "features"
projects[mn_share][location] = "http://code.developmentseed.org/fserver"
projects[mn_world][subdir] = "features"
projects[mn_world][location] = "http://code.developmentseed.org/fserver"

; Themes
projects[tao][location] = "http://code.developmentseed.org/fserver"
projects[jake][location] = "http://code.developmentseed.org/fserver"

; Libraries
libraries[simplepie][download][type] = "get"
libraries[simplepie][download][url] = "http://simplepie.org/downloads/simplepie_1.2.zip"
libraries[simplepie][directory_name] = "simplepie"
libraries[flot][download][type] = "get"
libraries[flot][download][url] = "http://flot.googlecode.com/files/flot-0.5.tar.gz"
libraries[flot][directory_name] = "flot"
libraries[openlayers][download][type] = "get"
libraries[openlayers][download][url] = "http://www.openlayers.org/download/OpenLayers-2.8.tar.gz"
libraries[openlayers][directory_name] = "openlayers"
