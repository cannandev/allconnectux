  <?php print $messages; ?>
  <!-- Header content -->
  <?php print render($page['header_codes']); ?>
  <?php include_once path_to_theme() . '/templates/pages/includes/header/modals/address.inc'; ?>
  <header class="site-header">
    <?php include_once path_to_theme() . '/templates/pages/includes/header/banners/cta-banner.inc'; ?>
    <?php include_once path_to_theme() . '/templates/pages/includes/header/menus/main-menu.inc'; ?>
  </header>
