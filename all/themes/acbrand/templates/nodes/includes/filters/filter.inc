<?php
/**
* @see templates/fields/field-collection-item--field-filters.tpl.php
*/

  $price = explode('.', $content['field_featured_price']['#items'][0]['safe_value']);

  if(empty($price[1])) {
    $price[1] = '00';
  }

?>

        <?php if($image_choice): ?>
        <h2 class="hero-headline__filter headline-base"><?php print render($content['field_filters_title']); ?></h2>
        <?php endif; ?>
        <div class="row">
          <div class="col-xs-12 col-xs-offset-0">
            <div class="filters row">
              <?php print render($content['field_filters']); ?>
            </div>
            <!-- /.row -->
          </div>
          <!-- End nested grid -->
        </div>
        <!-- /.filters -->