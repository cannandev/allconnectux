  <section class="hero-image hero-category">
    <div class="container">
      <header class="hero-image-header">
        <div class="hero-image-content">
          
          <div class="hero-image-headline hero-flex-item">
            <?php print render($title_prefix); ?>
            <h1 class="hero-image-headline__title" id="page-title"><?php print render($content['field_hero_title']); ?></h1>
            <?php print render($title_suffix); ?>
            <?php if ($content['field_hero_subtitle']) : ?>
            <p class="hero-image-headline__subhead"><?php print render($content['field_hero_subtitle']); ?></p>
            <?php endif; ?>              
          </div><!-- /.hero-image-headline -->
          
          <div class="hero-image-cta hero-flex-item">
              <div class="hero-image-cta__telgroup">
              <h4 class="hero-image-cta__title">Call to Order</h4><span class="flex-item"><a href="tel: +1-844-263-2443" class="acdc_provider_phone_no banner-phone">1-844-263-2443</a></span>
            </div>
            <p class="hero-image-cta__divider">OR</p>
            <button class="btn-view-offers btn btn-primary" data-toggle="modal" data-target="#address-capture" filterdata="category=<?php print $category_choice; ?>">
              <span class="btn-icon glyphicon glyphicon-map-marker"></span>Find Offers In Your Area</button>
          </div><!-- /.hero-image-cta -->
        
        </div><!-- /.hero-content -->
        
        <?php include_once path_to_theme() . '/templates/nodes/includes/heros/image.inc'; ?>

      </header><!-- /.hero-header with image -->
    </div>
  </section>
  <!-- filters -->
  <section class="hero">
    <div class="container hero-container">
      <?php include_once path_to_theme() . '/templates/nodes/includes/filters/filter.inc'; ?>
    </div>
  </section>
