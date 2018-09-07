<div id="<?php print $block_html_id; ?>" class="<?php print $classes; ?> visible-lg-block"<?php print $attributes; ?>>
	<div class="block-content-wrap">
		
		<div class="block-content-area">  

		  <?php print render($title_prefix); ?>

			<header class="block-header">
				<h3<?php print $title_attributes; ?> class="block-header__title">
				<?php if ($block->subject): ?><?php print $block->subject; ?>
				<?php endif; ?>
				</h3>
				<div class="block-header__link" aria-role="button">
					<span>minimize</span> <i class="fa fa-minus-square" aria-hidden="true"></i>
				</div>
			</header>

		  <?php print render($title_suffix); ?>

			<div class="block-body">
				<div class="block-body__popup-wrap">
					<?php include_once 'includes/popup-icon.inc'; ?>
				</div>	
				<?php if ($block->callout): ?>
				  <h4 class="block-body__callout"><?php print $block->callout; ?></h4>
				<?php endif; ?>
				  <p class="block-body__content"<?php print $content_attributes; ?>><?php print $content; ?></p>	
			</div>

			<footer class="block-footer">
			<?php if ($block->phone_label): ?>
				<span class="block-footer__cta"><?php print $block->phone_label; ?></span>
			<?php endif; ?>
			<?php if ($block->phone): ?>
				<p class="block-footer__phone"><?php print $block->phone; ?></p>
			<?php endif; ?>
			</footer>

		</div>
		<div class="block-content-cover"></div>

	</div>
</div>
