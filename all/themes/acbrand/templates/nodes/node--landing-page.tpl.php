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
hide($content['field_hero_title_landing']);
hide($content['field_filters_title']);
hide($content['field_featured_name']);
hide($content['field_featured_price']);
hide($content['field_featured_label']);
hide($content['field_featured_terms']);
hide($content['field_featured_list']);
hide($content['field_hero_phone_cta']);
hide($content['field_hero_link_cta']);
hide($content['field_featured_promo_image']);
hide($content['field_featured_promo_text']);
hide($content['field_hero_image']);
hide($content['field_taxonomy']);


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
  <?php include_once path_to_theme() . '/templates/nodes/includes/heros/hero-featured.inc'; ?>
  <?php endif; ?>    

  <!-- Mid CTA Banner -->
  <?php include_once path_to_theme() . '/templates/nodes/includes/banners/mid-cta-banner.inc'; ?>
  
  <!-- Landing node content -->
  <?php print render($content); ?>
</div>