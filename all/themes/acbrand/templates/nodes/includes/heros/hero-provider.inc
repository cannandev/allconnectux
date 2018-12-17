  <section class="hero hero-provider hero-image-<?php print $image_choice; ?>">
    <div class="container center-v flex">
      <header class="hero__title">
        <?php print render($title_prefix); ?>
        <h1 id="page-title"><?php print $title; ?></h1>
        <?php print render($title_suffix); ?>
      </header><!-- /.hero-header with image -->
      <div class="hero__address">
        <div class="provider-logo">
          <img src="<?php print render($content['field_provider_logo']); ?>" alt="Provider logo">
        </div>
        <p>Enter your address to find plans and providers in your area</p>
        <form class="row">
          <div class="col col-sm-4 col-xs-12">
            <div class="form-group">
              <label for="street1" class="control-label hidden"></label>
              <input type="text" autocomplete="off" class="form-control" id="street1" placeholder="Street Address*">
            </div>
          </div>
          <div class="col col-sm-2 col-xs-5">
            <div class="form-group">
              <label for="aptCondo" class="control-label hidden"></label>
              <input type="text" autocomplete="off" class="form-control" id="aptCondo" placeholder="Apt #">
            </div>
          </div>
          <div class="col col-sm-3 col-xs-7">
            <div class="form-group">
              <label for="cityStateZip" class="control-label hidden"></label>
              <input type="text" autocomplete="off" class="form-control" id="cityStateZip" placeholder="Zip Code*">
            </div>
          </div>
          <div class="col col-sm-2 col-xs-12">
            <div class="form-group">
              <button type="button" class="btn btn-primary" id="SubmitAddress" filterData="category=<?php print $page_type; ?>">Search</button>
            </div>
          </div>        
        </form>
        <p>or set up all services with one phone call <a href="tel:+1-844-263-2443" data-fuse data-fuse-format="1-###-###-####" class="acdc_provider_phone_no">1-888-123-4567</a></p>
      </div>
    </div>
  </section>

  <!-- filters -->
  <?php if (isset($variables['field_category']) && $variables['field_category'][0]['value'] == 'Electricity') : ?>
    <section class="filters-wrapper" style="display: none;"></section>
  <?php elseif (count($content['field_filters']) > 0) : ?>
  <section class="filters-wrapper section">
    <div class="container">
      <?php include_once path_to_theme() . '/templates/nodes/includes/filters/category_page_filter.inc'; ?>
    </div>
  </section>
  <?php endif; ?>
  