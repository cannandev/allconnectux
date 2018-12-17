<?php 
  $price = explode('.', $content['field_featured_price']['#items'][0]['safe_value']);

  if(empty($price[1])) {
    $price[1] = '00';
  }

?>
  <section class="hero-image hero-featured">
    <div class="container">
      <header class="hero-image-header">
        <div class="hero-image-content">
          
          <?php print render($title_prefix); ?>
          <h1 class="hero-image-headline__title" id="page-title"><?php print render($content['field_hero_title_landing']); ?></h1>
          <?php print render($title_suffix); ?> 
          
          <div class="hero-product">
            <div class="hero-product__price">
              <div class="filter-content">
                <div class="filter-text">
                  <?php if(render($content['field_featured_label'])): ?>
                  <p class="filter-label">
                    <?php print render($content['field_featured_label']); ?>
                  </p>
                  <?php endif; ?>                      
                  <div class="filter-price-group">
                    <div class="filter-price-item">
                      <span class="filter-price"><sup>$</sup><?php print $price[0]; ?></span>
                    </div>
                    <div class="filter-price-item">
                      <span class="filter-price"><sup><?php print $price[1]; ?></sup></span>
                      <p class="filter-label-inline">/mo</p>
                    </div>
                  </div>
                  <?php if(render($content['field_featured_terms'])): ?>
                  <p class="filter-terms">
                    <?php print render($content['field_featured_terms']); ?>
                  </p>
                  <?php endif; ?>
                </div>
              </div>
            </div><!-- /.hero-product__price -->
            <div class="hero-product__features">
              <h4 class="filter-title"><?php if(render($content['field_featured_name'])): ?>
                    <?php print render($content['field_featured_name']); ?>
                  <?php endif; ?></h4>
              <?php if(render($content['field_featured_list'])): ?>
                <?php print render($content['field_featured_list']); ?>
              <?php endif; ?>              
            </div><!-- /.hero-product__features -->
          </div><!-- /.hero-product -->

          <?php if(render($content['field_featured_promo_text'])): ?>
          <div class="hero-promo">
              <?php if(render($content['field_featured_promo_image'])): ?>
              <img src="<?php print render($content['field_featured_promo_image']); ?>" alt="Featured Promotion">
              <?php endif; ?>
              <div class="hero-promo__text">
              <?php print render($content['field_featured_promo_text']); ?>
              </div>             
          </div><!-- /.hero-promo -->
          <?php endif; ?>

          <?php if(render($content['field_hero_phone_cta'])): ?>
          <div class="hero-cta">
            <div class="hero-cta__telgroup">
              <?php print render($content['field_hero_phone_cta']); ?>
            </div>
            <?php if(render($content['field_hero_link_cta'])): ?>
            <a class="hero-cta__link btn-view-offers" href="#" data-toggle="modal" data-target="#address-capture" filterData="category=<?php print $category_choice; ?>"><?php print render($content['field_hero_link_cta']); ?></a>              
            <?php endif; ?>
          </div><!-- /.hero-cta -->
          <?php endif; ?>          
          
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
