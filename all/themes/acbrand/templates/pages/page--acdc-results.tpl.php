<?php 
$params = drupal_get_query_parameters();
$is_acdc = isset($params['isACDC']) ? TRUE : FALSE;
$template = isset($params['category']) ? $params['category'] : 'bundles';
$otherProvidersNeeded = isset($params['otherProvidersNeeded']) ? $params['otherProvidersNeeded'] : FALSE;
$providerName = isset($params['providerName']) ? $params['providerName'] : 'this provider';

  if(strpos($_SERVER['SERVER_NAME'], 'local.searchresults.com') !== false) {
    $env = "http://local.searchresults.com/";
    $trunk = "http://local.trunk.com/siteImages/";
  } else {
    $env = "/";
    $trunk = "/";
  }
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
  
  <!-- Main content -->
        
  <?php print render($page['content']); ?>
  
  <?php include_once 'includes/search/content.inc'; ?>

  <!-- Footer content -->

  <?php if (!$is_acdc): ?>    
    <footer id="footer-wrapper" class="site-footer">
      <?php include_once path_to_theme() . '/templates/pages/includes/footer/menus/brand-menu.inc'; ?>
      <?php include_once path_to_theme() . '/templates/pages/includes/footer/banners/cta-banner.inc'; ?>
      <?php include_once path_to_theme() . '/templates/pages/includes/footer/menus/logos.inc'; ?>
      <?php include_once path_to_theme() . '/templates/pages/includes/footer/menus/corporate-menu.inc'; ?>
    </footer>
  
  <?php endif; ?>
