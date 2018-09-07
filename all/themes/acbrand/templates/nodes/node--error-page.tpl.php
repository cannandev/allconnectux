<?php

/**
 * @file
 * Content page node template.
 *
 * @see node.tpl.php
 */
?>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <section class="section hero" <?php print $content_attributes; ?>>
    <div class="container">
      <header class="text-center">
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="headline-base hero-headline" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php if (!empty($content['field_subtitle'])): ?>
        <p class="lead"><?php print render($content['field_subtitle']); ?></p>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      </header>   
    </div>
  </section>
  <section>
    <div class="container">
      <div class="row">
          <?php print render($content); ?>
      </div>
    </div>
  </section>
</div>
