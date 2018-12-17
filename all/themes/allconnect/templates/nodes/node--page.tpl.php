<?php

$hide_mobile = (isset($content['field_hide_mobile']) && $content['field_hide_mobile']['#items'][0]['value'] == 0) ? FALSE : 'hidden-xs';

//sidebar region
$side_blocks = block_get_blocks_by_region('sidebar_first');
$side = drupal_render($side_blocks);

?>
<?php if(isset($content['field_brand_feature']) && $content['field_brand_feature']['#items'][0]['value'] == 0): ?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  

    <section class="page-title" <?php print $content_attributes; ?>>
      <div class="container">
        <header class="text-center">
        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="hero-headline" id="page-title"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        </header>   
      </div>
    </section>  


  <div class="body-content">
    <div class="container">
      <div class="row">
        <?php if ($side): ?>
        <div class="col col-sm-8 article field-collection-item">
          <?php print render($content); ?>
        </div>
        <div class="col col-sm-4 sidebar">
          <?php print render($side); ?>
        </div>
        <?php else: ?>
        <div class="col col-md-8 col-md-offset-2 col-xs-12 article field-collection-item">
          <?php print render($content); ?>
        </div>
        <?php endif; ?>            
      </div>
    </div>
  </div>
</div>
<?php else: ?>
  <section class="shared-content section section-hr text-center <?php print render($hide_mobile); ?>" id="node-<?php print $node->nid; ?>" <?php print $attributes; ?>>
    <div class="container" <?php print $content_attributes; ?>>
      <?php print render($title_prefix); ?>    
      <h2 class="headline-base"><?php print $title; ?></h2>
      <?php print render($title_suffix); ?>
      <?php print render($content); ?>
      <?php print render($content['links']); ?>      
    </div>
  </section>
<?php endif; ?>

