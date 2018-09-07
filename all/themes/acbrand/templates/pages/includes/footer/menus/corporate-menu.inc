  <nav class="footer-navbar footer-navbar-dark" role="navigation">
    <div class="container">
      <?php if ($page['footer_corporate']): ?>
        <?php print render($page['footer_corporate']); ?>
      <?php endif; ?>
      <p class="footer-copyright">Copyright &copy; <?php print $copyright_year; ?> <?php print $site_copyright; ?></p>
    </div>
  </nav>