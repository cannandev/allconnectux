<?php
/**
* @file
* Open page node template.
*
*
* @see node.tpl.php
*/

$params = drupal_get_query_parameters();
$template = isset($params['category']) ? $params['category'] : '';
$otherProvidersNeeded = isset($params['otherProvidersNeeded']) ? $params['otherProvidersNeeded'] : FALSE;
$providerName = isset($params['providerName']) ? $params['providerName'] : 'this provider';

// hide node content fields before displaying them
hide($content['field_hero_image']);
hide($content['field_category']);
hide($content['field_hero_link_cta']);
hide($content['field_disclaimer']);
hide($content['field_featured_id']);
// hide($content['field_body_content']);
// hide($content['field_shared_content']);

//@todo: move the field logic to template.php
$image_choice = isset($content['field_hero_image']['#items'][0]['value']) ? $content['field_hero_image']['#items'][0]['value'] : null;

$filter_value = isset($content['field_filter_value']) ? trim(render($content['field_filter_value'])) : '';
?>

<div id="node-<?php print $node->nid; ?>" class="main-wrapper <?php print $classes; ?>" <?php print $attributes; ?>> 
  <!-- Hero -->
  <?php if ($image_choice) : ?>
  <?php include_once path_to_theme() . '/templates/nodes/includes/heros/hero-featured-product.inc'; ?>
  <?php endif; ?>   
</div>

<?php include_once 'includes/search/content.inc'; ?>

<?php print render($content); ?>
