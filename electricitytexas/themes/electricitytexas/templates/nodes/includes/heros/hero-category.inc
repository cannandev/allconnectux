  <section class="hero hero-image hero-category">
    <div class="container">
      <header class="hero-image-header">
        <div class="hero-image-content">
          
          <div class="hero-image-headline hero-flex-item">
            <?php print render($title_prefix); ?>
            <h1 class="hero-image-headline__title" id="page-title"><?php print $title; ?></h1>
            <?php print render($title_suffix); ?>
            <?php if ($content['field_hero_subtitle']) : ?>
            <p class="hero-image-headline__title"><?php print render($content['field_hero_subtitle']); ?></p>
            <?php endif; ?>              
          </div><!-- /.hero-image-headline -->
          
          <?php if ($content['field_hero_link_cta']) : ?>
          <div class="hero-image-cta hero-flex-item">
            <button class="btn-view-offers btn btn-primary" data-toggle="modal" data-target="#address-capture" filterdata="category=<?php print $filter_value; ?>">
              <?php print render($content['field_hero_link_cta']); ?></button>
          </div><!-- /.hero-image-cta -->
          <?php endif; ?>
        
        </div><!-- /.hero-content -->
        
        <?php include_once $theme_path . '/templates/nodes/includes/heros/image.inc'; ?>

      </header><!-- /.hero-header with image -->
    </div>
  </section>
  <!-- filters -->
  <section class="hero">
    <div class="container hero-container">
      <?php include_once path_to_theme() . '/templates/nodes/includes/filters/filter.inc'; ?>
    </div>
  </section>
