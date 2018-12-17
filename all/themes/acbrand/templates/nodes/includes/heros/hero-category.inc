  <section class="hero hero-category hero-image-<?php print $image_choice; ?>">
    <div class="container center-v flex">
      <header class="hero__title">
        <?php print render($title_prefix); ?>
        <h1 id="page-title"><?php print $title; ?></h1>
        <?php print render($title_suffix); ?>
      </header><!-- /.hero-header with image -->
      <div class="hero__address">
        
        
        <?php if (isset($variables['field_category']) && $variables['field_category'][0]['value'] == 'Electricity') : ?>
            <p>Enter your zip code to find plans and providers in your area</p>
            <form class="row" id="electricity_zip">
              <div class="col col-sm-5 col-xs-12">
                <div class="form-group">
                  <label for="cityStateZip" class="control-label hidden"></label>
                  <input type="text" class="form-control" id="zipcode" placeholder="Zip Code*" maxlength="5" onkeypress='return event.charCode >= 48 && event.charCode <= 57'>
                </div>
              </div>
              <div class="col col-sm-2 col-xs-12">
                <div class="form-group">
                  <button type="button" class="btn btn-primary" id="SubmitZip" filterData="category=<?php print $page_type; ?>">Search</button>
                </div>
              </div>        
            </form>
        <?php else : ?>
            <p>Enter your address to find plans and providers in your area</p>
            <form class="row">
              <div id="address_field" class="col col-sm-9 col-xs-12">
                <div class="form-group">
                  <label for="street1" class="control-label hidden"></label>
                  <input type="text" autocomplete="off" class="form-control" id="fullAddress" placeholder="Address*">
                </div>
              </div>
              <div id="unit_field" class="col col-sm-2 col-xs-5 hidden">
              	 <input id="unit_num" class="form-control" placeholder="Unit"/>
              </div>
              <!-- <div class="col col-sm-2 col-xs-5">
                <div class="form-group">
                  <label for="aptCondo" class="control-label hidden"></label>
                  <input type="text" class="form-control" id="aptCondo" placeholder="Apt #">
                </div>
              </div>
              <div class="col col-sm-3 col-xs-7">
                <div class="form-group">
                  <label for="cityStateZip" class="control-label hidden"></label>
                  <input type="text" class="form-control" id="cityStateZip" placeholder="Zip Code*" pattern="\d{5}-?(\d{4})?" title="Enter Zip Code in xxxxx or xxxxx-xxxx format only.">
                </div>
              </div> -->
              <div class="col col-sm-2 col-xs-12">
                <div class="form-group">
                  <button type="button" class="btn btn-primary" id="SubmitAddress" filterData="category=<?php print $page_type; ?>">Search</button>
                </div>
              </div>        
            </form>
        <?php endif ?>

        
        <span class="phone-message">or set up all services with one phone call </span>
        <span class="flex-item"><a href="tel:+1-844-263-2443" data-fuse="" data-fuse-format="1-###-###-####" class="acdc_provider_phone_no jsHeroPhoneNumber">1-888-123-4567</a></span>
      </div>
    </div>
  </section>

  <!-- filters -->
  <?php if (isset($variables['field_category']) && $variables['field_category'][0]['value'] == 'Electricity') : ?>
    <section class="filters-wrapper" style="display: none;"></section>
  <?php elseif (count($content['field_filters']) > 0) : ?>
    <section class="filters-wrapper">
      <div class="container">
        <?php include_once path_to_theme() . '/templates/nodes/includes/filters/category_page_filter.inc'; ?>
      </div>
    </section>
  <?php endif; ?>