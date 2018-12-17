  <!-- Header content -->
	  <?php print render($page['header_codes']); ?>
	  <?php include_once drupal_get_path('theme', 'acbrand') . '/templates/pages/includes/header/modals/address.inc'; ?>
		
		<?php if (!$hide_header): ?>
	  <header class="site-header">
	    <?php include_once drupal_get_path('theme', 'acbrand') . '/templates/pages/includes/header/banners/cta-banner.inc'; ?>
	    <?php include_once drupal_get_path('theme', 'acbrand') . '/templates/pages/includes/header/menus/main-menu.inc'; ?>
	  </header>
	  <?php endif; ?>



  <?php if ($is_admin): ?>
    <?php print $messages; ?>
    <?php if ($tabs): ?><div class="tabs"><?php print render($tabs); ?></div><?php endif; ?>
    <?php print render($page['help']); ?>
    <?php if ($action_links): ?><ul class="action-links"><?php print render($action_links); ?></ul><?php endif; ?>
  <?php endif; ?> 
    
	<!-- Main content -->
	      
	<?php print render($page['content']); ?>

  <!-- Footer content -->
		
		<?php if (!$hide_footer): ?>
		<footer class="footer">
		  	<?php include_once drupal_get_path('theme', 'acbrand') . '/templates/pages/includes/footer/banners/cta-banner.inc'; ?>
		  	<?php include_once drupal_get_path('theme', 'acbrand') . '/templates/pages/includes/footer/menus/corporate-menu.inc'; ?>
		  	<script src="https://use.fontawesome.com/b25e7d562a.js"></script>
    		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
		</footer>
		<?php endif; ?>
	
