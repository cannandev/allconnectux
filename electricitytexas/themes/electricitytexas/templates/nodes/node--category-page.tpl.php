<?php
/**
* @file
* Content page node template.
*
* Available variables:
* - $block: Single block in Mid Banner region.
* - $mid_cta_block: Rendered block.
* - $image_choice: Selected hero image value.
* - $category_choice: Rendered page category value. Used for results page.
* - $launch_address_capture: Boolean value adds data-attribute to CTA buttons.
*
* @see node.tpl.php
*/

// hide node content fields before displaying them
hide($content['field_taxonomy']);
hide($content['field_hero_subtitle']);
hide($content['field_hero_image']);
hide($content['field_hero_phone_cta']);
hide($content['field_hero_link_cta']);
hide($content['field_filters_title']);
hide($content['field_featured_hero']);
hide($content['field_address_capture']);


//@todo: move the field logic to template.php
$image_choice = isset($content['field_hero_image']['#items'][0]['value']) ? $content['field_hero_image']['#items'][0]['value'] : null;

$filter_value = isset($content['field_filter_value']) ? trim(render($content['field_filter_value'])) : '';
?>

<div id="node-<?php print $node->nid; ?>" class="main-wrapper <?php print $classes; ?>" <?php print $attributes; ?>>
  
  <!-- Hero -->
  <?php if (!$image_choice) : ?>
  <?php include_once drupal_get_path('theme', 'acbrand') . '/templates/nodes/includes/heros/no-image.inc'; ?>
  <?php else: ?>
  <?php include_once path_to_theme() . '/templates/nodes/includes/heros/hero-category.inc'; ?>
  <?php endif; ?>    

  <!-- Mid CTA Banner -->
  <?php include_once drupal_get_path('theme', 'acbrand') . '/templates/nodes/includes/banners/mid-cta-banner.inc'; ?>

  <!-- Category node content -->
  <?php print render($content); ?>
</div>