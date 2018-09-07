<?php 
$params = drupal_get_query_parameters();
$is_acdc = isset($params['isACDC']) ? TRUE : FALSE;
?>

	<!-- Header content -->
  <div id="header-wrapper">
  <?php if (!$is_acdc): ?>

    <?php print render($page['header_codes']); ?>
    <?php include_once path_to_theme() . '/templates/pages/includes/header/modals/address.inc'; ?>
    <header class="site-header">
      <?php include_once path_to_theme() . '/templates/pages/includes/header/banners/cta-banner.inc'; ?>
      <?php include_once path_to_theme() . '/templates/pages/includes/header/menus/main-menu.inc'; ?>
    </header>

  <?php endif; ?>
  </div>

  <?php print $messages; ?>
  
  <!-- Node content -->
  <?php print render($page['content']); ?>

  <!-- Page content -->
  <?php include_once 'includes/callback/checkout.inc' ?>
  
  <!-- Footer content -->
  <?php if (!$is_acdc): ?>
    
    <footer id="footer-wrapper" class="site-footer">
      <?php include_once path_to_theme() . '/templates/pages/includes/footer/menus/brand-menu.inc'; ?>
      <?php include_once path_to_theme() . '/templates/pages/includes/footer/banners/cta-banner.inc'; ?>
      <?php include_once path_to_theme() . '/templates/pages/includes/footer/menus/logos.inc'; ?>
      <?php include_once path_to_theme() . '/templates/pages/includes/footer/menus/corporate-menu.inc'; ?>
    </footer>
  
  <?php endif; ?>
