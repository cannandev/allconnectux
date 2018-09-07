<?php
/**
 * @file
 * branded_products.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function branded_products_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function branded_products_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function branded_products_node_info() {
  $items = array(
    'category_page' => array(
      'name' => t('Category Page'),
      'base' => 'node_content',
      'description' => t('Build pages with customizable features. Use for <em>landing pages</em>.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('Limit title character count to 52.'),
    ),
    'error_page' => array(
      'name' => t('Error Page'),
      'base' => 'node_content',
      'description' => t('Template used for 403, 404 and no service pages.'),
      'has_title' => '1',
      'title_label' => t('Error Title'),
      'help' => '',
    ),
    'landing_page' => array(
      'name' => t('Landing Page with Featured Product'),
      'base' => 'node_content',
      'description' => t('Build pages with a featured product in the hero. Use for <em>landing pages</em>.'),
      'has_title' => '1',
      'title_label' => t('Drupal Page Name (used as meta title) '),
      'help' => '',
    ),
    'open_page' => array(
      'name' => t('Open page'),
      'base' => 'node_content',
      'description' => t('Used to create static pages'),
      'has_title' => '1',
      'title_label' => t('Drupal Title (Used in Meta tags)'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Basic page'),
      'base' => 'node_content',
      'description' => t('Use <em>basic pages</em> for your static content, such as an \'About us\' page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
