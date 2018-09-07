<?php
/**
* @file
* Content page node template.
*
* Available variables:
* - $theme_path: Defined base path for images in the current theme.
* - $site_name: Setting variable as configured is Site Information.
*
* @see node.tpl.php
*/
?>
<!DOCTYPE html>
<html>
  <head>
    <title></title>
  </head>
  <body>
    <div class="main-wrapper &lt;?php print $classes; ?&gt;" id=
    "node-&lt;?php print $node-&gt;nid; ?&gt;">
      <section class="hero text-center">
        <div class="container">
          <?php print render($title_prefix); ?>
          <h1 class="headline-base hero-headline" id="page-title">
            <?php print $title; ?>
          </h1><?php print render($title_suffix); ?><?php if ($content['field_subtitle']) : ?>
          <p class="hero-subhead">
            <?php print render($content['field_subtitle']); ?>
          </p><?php endif; ?>
          <div class="hero-btn-block">
            <a class="btn btn-primary" data-target="#address-capture" data-toggle="modal" href=
            "#address-capture" type="button">
            <span class="btn-icon glyphicon glyphicon-map-marker"></span>Find Offers In Your Area</a>
          </div>
          <div class="filters">
            <div class="row">
              <div class="col-md-8 col-md-offset-2 col-sm-12 col-sm-offset-0">
                <article class="filter filter-promoted">
                  <header class="filter-header">
                    <h3 class="filter-title">
                      XFINITY Preferred Triple Play in<br>
                      <span class="fw-normal">Rancho Santa Margarita, CA</span>
                    </h3>
                  </header>
                  <div class="filter-content">
                    <div class="filter-text">
                      <p class="filter-label">
                        Starting at
                      </p>
                      <div class="filter-price-group">
                        <div class="filter-price-item">
                          <span class="filter-price"><sup>$</sup>109</span>
                        </div><!-- / .filter-price-item -->
                        <div class="filter-price-item">
                          <span class="filter-price"><sup>99</sup></span>
                          <p class="filter-label-inline">
                            /mo
                          </p>
                        </div><!-- / .filter-price-item -->
                      </div>
                      <p class="filter-term">
                        12 months.
                      </p>
                      <p class="filter-term">
                        No term agreement.
                      </p>
                    </div><!-- /.filter-text -->
                    <div class="filter-feature-group">
                      <div class="filter-feature">
                        <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                        "<?php print $theme_path; ?>/img/icon_tv.svg">
                        </i>
                        <p class="filter-feature-highlight">
                          140+
                        </p>
                        <p class="filter-term">
                          Channels
                        </p>
                      </div>
                      <div class="filter-feature">
                        <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                        "<?php print $theme_path; ?>/img/icon_int.svg">
                        </i>
                        <p class="filter-term">
                          Up to
                        </p>
                        <p class="filter-feature-highlight">
                          75
                        </p>
                        <p class="filter-term">
                          mpbs
                        </p>
                      </div>
                      <div class="filter-feature">
                        <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                        "<?php print $theme_path; ?>/img/icon_voice.svg">
                        </i>
                        <p class="filter-term">
                          Nationwide Calling
                        </p>
                      </div>
                    </div><!-- / .filter-feature-group -->
                  </div><!-- /.filter-content -->
                  <footer class="filter-footer">
                    <p>
                      <a class="btn btn-primary" data-target="#address-capture" data-toggle="modal"
                      href="#address-capture" type="button">Check Availability</a>
                    </p>
                    <p>
                      <a aria-controls="disclaimer-content" aria-expanded="false" class=
                      "btn btn-link" data-toggle="collapse" href="#disclaimer-content">Disclaimer</a>
                    </p>
                  </footer>
                </article><!-- /.filter filter-promoted -->
              </div>
            </div><!-- /.row -->
          </div>
        </div><!-- / .container -->
        <section class="section section-hr-white">
          <div class="container">
            <h2 class="headline-base">Featured XFINITY Plans in
            <br>
            <span class="fw-normal">Rancho Santa Margarita, California</span>
            </h2>
            <div class="filters">
              <div class="row">
                <div class="col-xs-12 col-xs-offset-0 col-md-12 col-md-offset-0">
                  <div class="row">
                    <div class="col-xs-12 col-sm-4">
                      <article class="filter">
                        <header class="filter-header">
                          <h4 class="filter-title">
                            X1 Starter Extreme Triple Play
                          </h4>
                        </header>
                        <div class="filter-content">
                          <div class="filter-text">
                            <p class="filter-label">
                              Starting at
                            </p>
                            <div class="filter-price-group">
                              <div class="filter-price-item">
                                <span class="filter-price"><sup>$</sup>109</span>
                              </div><!-- / .filter-price-item -->
                              <div class="filter-price-item">
                                <span class="filter-price"><sup>99</sup></span>
                                <p class="filter-label-inline">
                                  /mo
                                </p>
                              </div><!-- / .filter-price-item -->
                            </div>
                            <p class="filter-term">
                              12 months.
                            </p>
                            <p class="filter-term">
                              No contract.
                            </p>
                          </div><!-- /.filter-text -->
                          <div class="filter-feature-group">
                            <div class="filter-feature">
                              <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                              "<?php print $theme_path; ?>/img/icon_tv.svg">
                              </i>
                              <p class="filter-feature-highlight">
                                140+
                              </p>
                              <p class="filter-term">
                                Channels
                              </p>
                            </div>
                            <div class="filter-feature">
                              <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                              "<?php print $theme_path; ?>/img/icon_int.svg">
                              </i>
                              <p class="filter-term">
                                Up to
                              </p>
                              <p class="filter-feature-highlight">
                                75
                              </p>
                              <p class="filter-term">
                                mpbs
                              </p>
                            </div>
                            <div class="filter-feature">
                              <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                              "<?php print $theme_path; ?>/img/icon_voice.svg">
                              </i>
                              <p class="filter-term">
                                Nationwide Calling
                              </p>
                            </div>
                          </div><!-- / .filter-feature-group -->
                        </div><!-- /.filter-content -->
                        <footer class="filter-footer">
                          <p>
                            <a class="btn btn-primary" data-target="#address-capture" data-toggle=
                            "modal" href="#address-capture" type="button">Check Availability</a>
                          </p>
                          <p>
                            <a aria-controls="disclaimer-content" aria-expanded="false" class=
                            "btn btn-link" data-toggle="collapse" href=
                            "#disclaimer-content">Disclaimer</a>
                          </p>
                        </footer>
                      </article>
                    </div>
                    <div class="col-xs-12 col-sm-4">
                      <article class="filter">
                        <header class="filter-header">
                          <h4 class="filter-title">
                            X1 Starter Extreme Triple Play
                          </h4>
                        </header>
                        <div class="filter-content">
                          <div class="filter-text">
                            <p class="filter-label">
                              Starting at
                            </p>
                            <div class="filter-price-group">
                              <div class="filter-price-item">
                                <span class="filter-price"><sup>$</sup>109</span>
                              </div><!-- / .filter-price-item -->
                              <div class="filter-price-item">
                                <span class="filter-price"><sup>99</sup></span>
                                <p class="filter-label-inline">
                                  /mo
                                </p>
                              </div><!-- / .filter-price-item -->
                            </div>
                            <p class="filter-term">
                              12 months.
                            </p>
                            <p class="filter-term">
                              No contract.
                            </p>
                          </div><!-- /.filter-text -->
                          <div class="filter-feature-group">
                            <div class="filter-feature">
                              <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                              "<?php print $theme_path; ?>/img/icon_tv.svg">
                              </i>
                              <p class="filter-feature-highlight">
                                140+
                              </p>
                              <p class="filter-term">
                                Channels
                              </p>
                            </div>
                            <div class="filter-feature">
                              <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                              "<?php print $theme_path; ?>/img/icon_int.svg">
                              </i>
                              <p class="filter-term">
                                Up to
                              </p>
                              <p class="filter-feature-highlight">
                                75
                              </p>
                              <p class="filter-term">
                                mpbs
                              </p>
                            </div>
                            <div class="filter-feature">
                              <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                              "<?php print $theme_path; ?>/img/icon_voice.svg">
                              </i>
                              <p class="filter-term">
                                Nationwide Calling
                              </p>
                            </div>
                          </div><!-- / .filter-feature-group -->
                        </div><!-- /.filter-content -->
                        <footer class="filter-footer">
                          <p>
                            <a class="btn btn-primary" data-target="#address-capture" data-toggle=
                            "modal" href="#address-capture" type="button">Check Availability</a>
                          </p>
                          <p>
                            <a aria-controls="disclaimer-content" aria-expanded="false" class=
                            "btn btn-link" data-toggle="collapse" href=
                            "#disclaimer-content">Disclaimer</a>
                          </p>
                        </footer>
                      </article>
                    </div>
                    <div class="col-xs-12 col-sm-4">
                      <article class="filter">
                        <header class="filter-header">
                          <h4 class="filter-title">
                            X1 Starter Extreme Triple Play
                          </h4>
                        </header>
                        <div class="filter-content">
                          <div class="filter-text">
                            <p class="filter-label">
                              Starting at
                            </p>
                            <div class="filter-price-group">
                              <div class="filter-price-item">
                                <span class="filter-price"><sup>$</sup>109</span>
                              </div><!-- / .filter-price-item -->
                              <div class="filter-price-item">
                                <span class="filter-price"><sup>99</sup></span>
                                <p class="filter-label-inline">
                                  /mo
                                </p>
                              </div><!-- / .filter-price-item -->
                            </div>
                            <p class="filter-term">
                              12 months.
                            </p>
                            <p class="filter-term">
                              No contract.
                            </p>
                          </div><!-- /.filter-text -->
                          <div class="filter-feature-group">
                            <div class="filter-feature">
                              <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                              "<?php print $theme_path; ?>/img/icon_tv.svg">
                              </i>
                              <p class="filter-feature-highlight">
                                140+
                              </p>
                              <p class="filter-term">
                                Channels
                              </p>
                            </div>
                            <div class="filter-feature">
                              <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                              "<?php print $theme_path; ?>/img/icon_int.svg">
                              </i>
                              <p class="filter-term">
                                Up to
                              </p>
                              <p class="filter-feature-highlight">
                                75
                              </p>
                              <p class="filter-term">
                                mpbs
                              </p>
                            </div>
                            <div class="filter-feature">
                              <i class="filter-icon"><img alt="" class="filter-icon-img" src=
                              "<?php print $theme_path; ?>/img/icon_voice.svg">
                              </i>
                              <p class="filter-term">
                                Nationwide Calling
                              </p>
                            </div>
                          </div><!-- / .filter-feature-group -->
                        </div><!-- /.filter-content -->
                        <footer class="filter-footer">
                          <p>
                            <a class="btn btn-primary" data-target="#address-capture" data-toggle=
                            "modal" href="#address-capture" type="button">Check Availability</a>
                          </p>
                          <p>
                            <a aria-controls="disclaimer-content" aria-expanded="false" class=
                            "btn btn-link" data-toggle="collapse" href=
                            "#disclaimer-content">Disclaimer</a>
                          </p>
                        </footer>
                      </article>
                    </div>
                  </div>
                  <!-- / .row -->
                </div>
              </div><!-- /.row -->
            </div>
          </div><!-- /.container -->
        </section>
      </section>
      <div class="cta-banner" role="banner">
        <div class="container flex-container">
          <span class="flex-item"></span>
          <h4 class="banner-title">
            <span class="flex-item"><?php print t('Order ' . $site_name . ' Today'); ?></span>
          </h4><span class="flex-item"><a class="js-site-phone banner-phone dataTelephone" href=
          "tel:%20+%3C?php%20print%20$site_phone;%20?%3E"><?php print $site_phone; ?></a></span>
        </div>
      </div><!-- /.cta-banner -->
      <div class="container">
        <?php hide($content['field_products']); ?><?php print render($content); ?>
      </div>
    </div>
  </body>
</html>