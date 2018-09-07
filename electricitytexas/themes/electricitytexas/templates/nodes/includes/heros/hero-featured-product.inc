<?php 
  //@TODO move logic to template.php hook
  $field_collection = entity_metadata_wrapper('node', $node);
  $desc = $field_collection->field_featured_hero->field_featured_description->value();
  $details = $field_collection->field_featured_hero->field_featured_details->value();
  $has_featured_product = ($content['field_featured_hero']) ? 'hero-w-featured-product' : '';
?>
  <section class="hero <?php print $has_featured_product; ?> hero-image-<?php print $image_choice; ?>">
    <div class="container">
      <div class="row">
        <div class="col col-sm-6 col-md-8 col-lg-5 col-lg-offset-3">
          <div class="hero__content">
            <img src="/<?php print $theme_path . '/img/txu-logo.png'; ?>" class="hero-provider-logo" alt="TXU logo">
            <h1><?php print render($title); ?></h1>
            <div class="hero__description">
              <?php if ($desc) : ?>
                <?php print render($desc['value']); ?>
              <?php endif; ?>
            </div>
          </div><!-- /.hero-content -->
        </div>
        <div class="col col-sm-6 col-md-4 col-lg-4">
          <?php if ($content['field_featured_hero']): ?>
          <article id="featured-product" class="hero__product">
            <?php print render($content['field_featured_hero']); ?>
            <footer>
              <div ng-if="productObject.providerPhoneOnly == true">
                <button class="btn btn-primary result__btn-call dataProductChoice hidden-sm hidden-md hidden-lg" id="phoneNumberForOrder_{{$index}}" ng-href="tel:{{productObject.callInOnlyNumber}}"><i class="fa fa-phone" aria-hidden="true"></i> Call to Order</button>
              </div>     
              <?php if ($content['field_hero_link_cta'] && $content['field_hero_link_cta']['#items']): ?>
              <button class="btn btn-primary" ng-if="productObject.providerPhoneOnly == false" ng-click="showAddressModel('choosethisplan',productObject,'mainPage')">
              <?php print render($content['field_hero_link_cta']); ?>
              </button>
              <?php endif; ?>
              <?php if ($details): ?>
              <a class="featured-product__more" data-toggle="modal" data-target="#modal-featured-details" href="#" title="More details">More Details</a>
              <?php endif; ?>
            </footer>
          </article><!-- /.hero-featured -->
          <?php endif; ?> 
        </div>
      </div><!-- /.row -->
    </div>
  </section>

  <div id="modal-featured-details" class="modal fade" tabindex="1" role="dialog">
    <div class="modal-dialog">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true"><i class="fa fa-times"></i></span></button>
      </div>
      <div class="modal-content">
        <?php if ($details) : ?>
          <?php print render($details['value']); ?>
        <?php endif; ?>
      </div>
    </div>
  </div>

