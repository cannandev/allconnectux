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
hide($content['field_hero_image']);
hide($content['field_hero_title']);
hide($content['field_hero_subtitle']);
hide($content['field_filters_title']);
hide($content['field_filters']);
hide($content['field_category']);
hide($content['field_provider_name']);
hide($content['field_provider_logo']);

//@todo: move the field logic to template.php

//sidebar region
$side_blocks = block_get_blocks_by_region('sidebar_first');
$side = drupal_render($side_blocks);

$image_choice = isset($content['field_hero_image']['#items'][0]['value']) ? $content['field_hero_image']['#items'][0]['value'] : 0;

if(isset($content['field_category'])){
  $category_choice = trim(render($content['field_category']));
  $page_type = strtolower($category_choice);
}
?>

<div id="node-<?php print $node->nid; ?>" class="main-wrapper <?php print $classes; ?>" <?php print $attributes; ?>>
  
  <!-- Hero -->
  <?php include_once path_to_theme() . '/templates/nodes/includes/heros/hero-provider.inc'; ?>

  <!-- Mid CTA Banner -->
  <?php include_once path_to_theme() . '/templates/nodes/includes/banners/mid-cta-banner.inc'; ?>

  <!-- Brand Features -->
  <?php //if($content['field_shared_content']): ?>
  <?php //print render($content['field_shared_content']); ?> 
  <?php //endif; ?>
  
  <!-- Category node content -->
  <section class="body-content">
    <div class="container">
      <div class="row">
        <?php if ($side): ?>
        <div class="col col-sm-8">
          <?php print render($content); ?>
        </div>
        <div class="col col-sm-4 sidebar">
          <?php include_once path_to_theme() . "/templates/nodes/includes/sidebar/sub-category.inc"; ?>
          <?php print $side; ?>
        </div>
        <?php else: ?>
        <div class="col col-sm-12">
          <?php print render($content); ?>
        </div>
        <?php endif; ?>            
      </div>      
    </div>
  </section>
</div>
