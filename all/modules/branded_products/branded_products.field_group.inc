<?php
/**
 * @file
 * branded_products.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function branded_products_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|category_page|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'category_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '3',
    'children' => array(
      0 => 'group_body_content',
      1 => 'group_manage_filters',
      2 => 'group_share_content',
      3 => 'group_hero',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-accordion field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_accordion|node|category_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion|node|landing_page|form';
  $field_group->group_name = 'group_accordion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '2',
    'children' => array(
      0 => 'group_body_content',
      1 => 'group_manage_filters',
      2 => 'group_page_hero',
      3 => 'group_shared_content',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => 'group-accordion field-group-accordion',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_accordion|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_body_content|node|category_page|form';
  $field_group->group_name = 'group_body_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'category_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page Content	',
    'weight' => '29',
    'children' => array(
      0 => 'field_body_content',
      1 => 'field_disclaimer',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page Content	',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-body-content field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_body_content|node|category_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_body_content|node|landing_page|form';
  $field_group->group_name = 'group_body_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page Content',
    'weight' => '8',
    'children' => array(
      0 => 'field_body_content',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Page Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-body-content field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_body_content|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_choose_hero|node|category_page|form';
  $field_group->group_name = 'group_choose_hero';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'category_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page Hero',
    'weight' => '35',
    'children' => array(
      0 => 'field_hero_image',
      1 => 'field_hero_link_cta',
      2 => 'field_hero_subtitle',
      3 => 'title',
      4 => 'group_fieldset',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_choose_hero|node|category_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cta_fieldset|node|landing_page|form';
  $field_group->group_name = 'group_cta_fieldset';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_hero';
  $field_group->data = array(
    'label' => 'Call to Action',
    'weight' => '9',
    'children' => array(
      0 => 'field_hero_link_cta',
      1 => 'field_hero_phone_cta',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Call to Action',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-cta-fieldset field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_cta_fieldset|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_featured_product|node|landing_page|form';
  $field_group->group_name = 'group_featured_product';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_hero';
  $field_group->data = array(
    'label' => 'Featured Product',
    'weight' => '8',
    'children' => array(
      0 => 'field_featured_label',
      1 => 'field_featured_list',
      2 => 'field_featured_name',
      3 => 'field_featured_price',
      4 => 'field_featured_terms',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Featured Product',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_featured_product|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fieldset|node|category_page|form';
  $field_group->group_name = 'group_fieldset';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'category_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_choose_hero';
  $field_group->data = array(
    'label' => 'Featured Product',
    'weight' => '32',
    'children' => array(
      0 => 'field_featured_hero',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Featured Product',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-fieldset field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_fieldset|node|category_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fieldset|node|landing_page|form';
  $field_group->group_name = 'group_fieldset';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_hero';
  $field_group->data = array(
    'label' => 'Promotions',
    'weight' => '10',
    'children' => array(
      0 => 'field_featured_promo_text',
      1 => 'field_featured_promo_img',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Promotions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_fieldset|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hero|node|category_page|form';
  $field_group->group_name = 'group_hero';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'category_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page Hero',
    'weight' => '27',
    'children' => array(
      0 => 'field_hero_image',
      1 => 'title',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-hero field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_hero|node|category_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_manage_filters|node|category_page|form';
  $field_group->group_name = 'group_manage_filters';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'category_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Products and Filters',
    'weight' => '28',
    'children' => array(
      0 => 'field_filters',
      1 => 'field_filters_title',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Products and Filters',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_manage_filters|node|category_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_manage_filters|node|landing_page|form';
  $field_group->group_name = 'group_manage_filters';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Products and Filters',
    'weight' => '7',
    'children' => array(
      0 => 'field_filters',
      1 => 'field_filters_title',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-manage-filters field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_manage_filters|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_hero|node|landing_page|form';
  $field_group->group_name = 'group_page_hero';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Page Hero',
    'weight' => '4',
    'children' => array(
      0 => 'field_category',
      1 => 'field_hero_image',
      2 => 'field_hero_title_landing',
      3 => 'group_featured_product',
      4 => 'group_fieldset',
      5 => 'group_cta_fieldset',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-hero field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page_hero|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_share_content|node|category_page|form';
  $field_group->group_name = 'group_share_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'category_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Shared Content',
    'weight' => '30',
    'children' => array(
      0 => 'field_shared_content',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Shared Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-share-content field-group-accordion-item',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_share_content|node|category_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shared_content|node|landing_page|form';
  $field_group->group_name = 'group_shared_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_accordion';
  $field_group->data = array(
    'label' => 'Shared Content',
    'weight' => '9',
    'children' => array(
      0 => 'field_shared_content',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-shared-content field-group-accordion-item',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_shared_content|node|landing_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Call to Action');
  t('Featured Product');
  t('Page Content');
  t('Page Content	');
  t('Page Hero');
  t('Products and Filters');
  t('Promotions');
  t('Shared Content');

  return $field_groups;
}
