<?php
/**
 * @file
 * branded_open_template.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function branded_open_template_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-open_page-field_gtm_id'.
  $field_instances['node-open_page-field_gtm_id'] = array(
    'bundle' => 'open_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'changes per environment',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gtm_id',
    'label' => 'ID',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 15,
      ),
      'type' => 'text_textfield',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-open_page-field_gtm_order_src'.
  $field_instances['node-open_page-field_gtm_order_src'] = array(
    'bundle' => 'open_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'same per site',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gtm_order_src',
    'label' => 'Order Source',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 15,
      ),
      'type' => 'text_textfield',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('ID');
  t('Order Source');
  t('changes per environment');
  t('same per site');

  return $field_instances;
}
