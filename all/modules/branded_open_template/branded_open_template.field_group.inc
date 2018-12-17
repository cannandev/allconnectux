<?php
/**
 * @file
 * branded_open_template.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function branded_open_template_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fieldset|node|open_page|form';
  $field_group->group_name = 'group_fieldset';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'open_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'GTM',
    'weight' => '6',
    'children' => array(
      0 => 'field_gtm_id',
      1 => 'field_gtm_order_src',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'GTM',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-fieldset field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_fieldset|node|open_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_scripts|node|open_page|form';
  $field_group->group_name = 'group_scripts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'open_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Inline JS',
    'weight' => '5',
    'children' => array(
      0 => 'field_open_js',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Inline JS',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-scripts field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_scripts|node|open_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_styles|node|open_page|form';
  $field_group->group_name = 'group_styles';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'open_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CSS Files',
    'weight' => '4',
    'children' => array(
      0 => 'field_open_css',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-styles field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_styles|node|open_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('CSS Files');
  t('GTM');
  t('Inline JS');

  return $field_groups;
}
