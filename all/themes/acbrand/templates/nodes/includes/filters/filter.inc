<?php
/**
* @see templates/fields/field-collection-item--field-filters.tpl.php
*/

?>
        <h2 class="filters-wrapper__title section__title headline-base">
          <?php print render($content['field_filters_title']); ?>
        </h2>
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
        <?php if (!empty($content['field_disclaimer'])): ?>
        <footer class="filters-disclaimer text-center hidden"><?php print render($content['field_disclaimer']); ?></footer>
        <?php endif; ?>        