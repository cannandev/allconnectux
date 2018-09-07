  <section class="hero">
    <div class="container hero-container">
      <header class="hero-header">
        <?php print render($title_prefix); ?>
        <h1 class="headline-base hero-headline" id="page-title"><?php print render($content['field_hero_title']); ?>
        </h1>
        <?php print render($title_suffix); ?>
        <?php if ($content['field_hero_subtitle']) : ?>
        <p class="hero-subhead"><?php print render($content['field_hero_subtitle']); ?></p>
        <?php endif; ?>
        <div class="hero-btn-block">
          <button class="btn-view-offers btn btn-primary" type="button" data-toggle="modal" data-target="#address-capture" filterdata="category=<?php print $category_choice; ?>">
            <span class="btn-icon glyphicon glyphicon-map-marker"></span>Find Offers In Your Area</button> 
        </div>
      </header><!-- /.hero-header no image -->
      <!-- filters -->
      <?php include_once path_to_theme() . '/templates/nodes/includes/products/filters.inc'; ?>
    </div>
  </section>
