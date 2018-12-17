<?php 
$params = drupal_get_query_parameters();
$template = isset($params['category']) ? strtoupper($params['category']) : 'BUNDLES';
$template_label = ucwords(strtolower($template));
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
    <?php print render($page['header_codes']); ?>
    <?php include_once drupal_get_path('theme', 'acbrand') . '/templates/pages/includes/header/modals/address.inc'; ?>
    <header class="site-header">
      <?php include_once path_to_theme() . '/templates/pages/includes/header/banners/cta-banner.inc'; ?>
      <?php include_once drupal_get_path('theme', 'acbrand') . '/templates/pages/includes/header/menus/main-menu.inc'; ?>
    </header>
  </div>

  <?php print $messages; ?>
  
  <!-- Main content -->
  <?php print render($page['content']); ?>
  
  <?php include_once 'includes/search/content.inc'; ?>

  <!-- Footer content -->

    <footer id="footer-wrapper" class="footer">
      <?php include_once drupal_get_path('theme', 'acbrand') . '/templates/pages/includes/footer/banners/cta-banner.inc'; ?>
      <?php include_once drupal_get_path('theme', 'acbrand') . '/templates/pages/includes/footer/menus/corporate-menu.inc'; ?>
      <script src="https://use.fontawesome.com/b25e7d562a.js"></script>
      <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
    </footer>
  