<?php 
$params = drupal_get_query_parameters();
?>

	<!-- Header content -->
  <div id="header-wrapper">

    <?php print render($page['header_codes']); ?>
    <?php include_once path_to_theme() . '/templates/pages/includes/header/modals/address.inc'; ?>
    <header class="site-header">
      <?php include_once path_to_theme() . '/templates/pages/includes/header/banners/cta-banner.inc'; ?>
      <?php include_once path_to_theme() . '/templates/pages/includes/header/menus/main-menu.inc'; ?>
    </header>

  </div>

  <?php print $messages; ?>
  
  <!-- Node content -->
  <?php print render($page['content']); ?>

  <!-- Page content -->
  <?php include_once 'includes/callback/checkout.inc' ?>
  
  <!-- Footer content -->
    
    <footer id="footer-wrapper" class="footer">
      <?php include_once path_to_theme() . '/templates/pages/includes/footer/banners/cta-banner.inc'; ?>
      <?php include_once path_to_theme() . '/templates/pages/includes/footer/menus/corporate-menu.inc'; ?>
    </footer>
  
