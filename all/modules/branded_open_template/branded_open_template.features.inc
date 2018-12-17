<?php
/**
 * @file
 * branded_open_template.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function branded_open_template_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
