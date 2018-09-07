<?php

$hide_mobile = (isset($content['field_hide_mobile']) && $content['field_hide_mobile']['#items'][0]['value'] == 0) ? FALSE : 'hidden-xs';

?>
<?php if(isset($content['field_brand_feature']) && $content['field_brand_feature']['#items'][0]['value'] == 0): ?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <section class="section hero" <?php print $content_attributes; ?>>
    <div class="container">
      <header class="text-center">
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="headline-base hero-headline" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      </header>   
    </div>
  </section>
  <section class="node-content">
    <div class="container">
      <div class="row">
        <div class="col col-md-8 col-md-offset-2 col-xs-12">
          <?php print render($content); ?>
        </div>
      </div>
    </div>
    </div>
    <?php if(isset($content['field_hide_cta']) && $content['field_hide_cta']['#items'][0]['value'] == 0): ?>
    <div id="cta-footer" class="text-center">
      <button class="btn-view-offers btn btn-primary btn-lg" type="button" data-toggle="modal" data-target="#address-capture" filterdata="category=Bundles">
      </span>View All Plans</button>   
    </div>
    <?php endif; ?>
  </section>
</div>
<?php else: ?>
  <section id="node-<?php print $node->nid; ?>" class="section section-hr text-center <?php print render($hide_mobile); ?>"<?php print $attributes; ?>>
    <div class="container" <?php print $content_attributes; ?>>
      <?php print render($title_prefix); ?>    
      <h2 class="headline-base"><?php print $title; ?></h2>
      <?php print render($title_suffix); ?>
      <?php print render($content); ?>
      <?php print render($content['links']); ?>      
    </div>
  </section>
<?php endif; ?>

