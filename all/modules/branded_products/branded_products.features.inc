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
      'name' => t('Landing Page: Category'),
      'base' => 'node_content',
      'description' => t('Features a larger CTA button. Use for <em>landing pages</em> that direct users down the funnel (online checkout). '),
      'has_title' => '1',
      'title_label' => t('Hero Title (h1)'),
      'help' => '',
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
      'name' => t('Landing Page: Call-in'),
      'base' => 'node_content',
      'description' => t('Features a product in the hero and large phone number CTA. Use for <em>landing pages</em> that direct users to call-in.'),
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
