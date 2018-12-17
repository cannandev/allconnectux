<?php
/**
 * @file
 * Print all fields in the field_filters field collection with custom markup.
 * Also display filter icons as selected on a category page. Values are:
 *   0 = Internet
 *   1 = TV
 *   2 = Phone
 *
 * Available variables:
 * - $theme_path: The defined base path for images in the current theme.
 * - $items: An array of selected filter icons.
 * - $price: An array of the filter price value split by a decimal delimeter.
 *   [0] = dollars, [1] = cents
 *
 * @todo Move all logic to hook_preprocess_field in templates.php
 */

  $theme_path = drupal_get_path('theme', $GLOBALS['theme']);

  $price = NULL;

  if (!empty($content['field_filter_price'])) {
  $price = explode('.', $content['field_filter_price']['#items'][0]['safe_value']);
  }

  if (!empty($content['field_show_filter_icons']['#items'])) {
    $items = $content['field_show_filter_icons']['#items'];
  }

  $filter_value = isset($content['field_filter_value']) ? trim(render($content['field_filter_value'])) : '';

?>
              <div class="col-xs-12 col-sm-4 pd-t-lg pd-b-lg">
                <article class="filter">
                  <header class="filter-header">
                    <div class="filter-icons">
                    <?php if(isset($items)): ?>
                      <?php foreach($items as $options): ?>
                        <?php foreach($options as $value): ?>
                          <?php if($value == 0): ?>
                            <i class="filter-icon">
                              <img src="/<?php print $theme_path; ?>/img/icon_int.svg" alt="" class="filter-icon-img">
                            </i>
                          <?php endif; ?>
                          <?php if($value == 1): ?>
                            <i class="filter-icon">
                              <img src="/<?php print $theme_path; ?>/img/icon_tv.svg" alt="" class="filter-icon-img">
                            </i>
                          <?php endif; ?>
                          <?php if($value == 2): ?>
                            <i class="filter-icon">
                              <img src="/<?php print $theme_path; ?>/img/icon_voice.svg" alt="" class="filter-icon-img">
                            </i>
                          <?php endif; ?>
                        <?php endforeach; ?>
                      <?php endforeach; ?>
                    <?php endif; ?>
                    </div>
                    <h4 class="filter-title"><?php print render($content['field_filter_title']); ?></h4>
                     <?php if(!empty($content['field_filter_description'])): ?>
                      <p class="filter-desc"><?php print render($content['field_filter_description']); ?></p>
                      <?php endif; ?>                    
                  </header>
                  <?php if ($price != NULL) : ?>
                  <div class="filter-content">
                    <div class="filter-text">
                      <?php if(!empty($content['field_filter_label'])): ?>
                      <p class="filter-label"><?php print render($content['field_filter_label']); ?></p>
                      <?php endif; ?>  
                      <div class="filter-price-group">
                        <div class="filter-price-item">
                          <span class="filter-price">
                        <sup>$</sup><?php print $price[0]; ?>
                      </span>
                        </div>
                        <div class="filter-price-item">
                          <span class="filter-price">
                        <sup><?php print $price[1]; ?></sup>
                      </span>
                          <p class="filter-label-inline">/mo</p>
                        </div>
                      </div>
                      <!-- / .filter-price-group -->
                    </div>
                    <!-- /.filter-text -->
                  </div>
                  <? endif; ?>
                  <p class="filter-terms">
                  <?php if(!empty($content['field_filter_terms'])): ?>
                    <?php print render($content['field_filter_terms']); ?>
                  <?php endif; ?>
                  </p><!-- /.filter-terms -->
                  <?php if(!empty($content['field_filter_cta'])): ?>             
                  <footer class="filter-footer">
                    <button class="btn-view-offers btn btn-primary" type="button" data-toggle="modal" data-target="#address-capture" filterData="<?php print $filter_value; ?>"><?php print render($content['field_filter_cta']); ?></button>
                  </footer>
                  <?php endif; ?>
                </article>
                <!-- /.filter -->
              </div>
