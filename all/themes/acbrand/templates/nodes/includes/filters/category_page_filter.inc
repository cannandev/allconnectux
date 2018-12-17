<?php
/**
* @see templates/fields/field-collection-item--field-filters.tpl.php
*/
?>
        <?php if (!empty(render($content['field_filters_title']))): ?>
        <h2 class="filters-wrapper__title">
          <?php print render($content['field_filters_title']); ?>
        </h2>
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
        <?php if (!empty(render($content['field_disclaimer']))): ?>
        <footer class="filters-disclaimer hidden text-center m-b-lg"><?php print render($content['field_disclaimer']); ?></footer>
        <?php endif; ?>