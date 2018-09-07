
  <header>
    <?php if ($content['field_featured_name']) : ?>
      <h3><?php print render($content['field_featured_name']); ?></h3>
    <?php endif; ?>
    <?php if ($content['field_featured_label']) : ?>
      <h4><?php print render($content['field_featured_label']); ?></h4>
    <?php endif; ?>
    <?php if ($content['field_price']) : ?>
      <span class="featured-product__price"><?php print render($content['field_price']); ?></span>
    <?php endif; ?>
    <?php if ($content['field_featured_terms']) : ?>
      <p class="featured-product__terms"><?php print render($content['field_featured_terms']); ?></p>
    <?php endif; ?>      
  </header>
  <div class="featured-product__list">
  <?php if ($content['field_featured_list']) : ?>
    <?php print render($content['field_featured_list']); ?>
  <?php endif; ?>
  </div>
