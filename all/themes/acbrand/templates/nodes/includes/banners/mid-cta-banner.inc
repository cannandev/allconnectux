<?php 
	$block = block_get_blocks_by_region('mid_banner');
	$mid_cta_block = drupal_render($block);
?>
    <?php if($mid_cta_block): ?>
    <div class="cta-banner" role="banner">
      <div class="container cta-banner__container">
        <div class="cta-banner__telgroup">
          <?php print $mid_cta_block; ?>
        </div>
      </div>
    </div><!-- /.cta-banner -->
  <?php endif; ?>