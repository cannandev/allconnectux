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
*
* @see node.tpl.php
*/

// hide node content fields before displaying them
hide($content['field_subtitle']);
hide($content['field_hero_image']);
hide($content['field_hero_title']);
hide($content['field_hero_subtitle']);
hide($content['field_filters_title']);

//@todo: move the field logic to template.php
$image_choice = isset($content['field_hero_image']['#items'][0]['value']) ? $content['field_hero_image']['#items'][0]['value'] : null;

if(render($content['field_category']) !== null){
  $category_choice = trim(render($content['field_category']));
  $page_type = strtolower($category_choice);
}
?>

<div id="node-<?php print $node->nid; ?>" class="main-wrapper page-type-<?php print $page_type; ?> <?php print $classes; ?>" <?php print $attributes; ?>>
  
  <!-- Hero -->
  <?php if (!$image_choice) : ?>
  <?php include_once path_to_theme() . '/templates/nodes/includes/heros/no-image.inc'; ?>
  <?php else: ?>
  <?php include_once path_to_theme() . '/templates/nodes/includes/heros/hero-category.inc'; ?>
  <?php endif; ?>    

  <!-- Mid CTA Banner -->
  <?php include_once path_to_theme() . '/templates/nodes/includes/banners/mid-cta-banner.inc'; ?>
  
  <!-- Category node content -->
  <?php print render($content); ?>
</div>