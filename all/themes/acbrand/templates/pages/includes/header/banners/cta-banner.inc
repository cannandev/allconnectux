<div class="header-cta-banner brand" id="status" data-spy="affix" data-offset-top="60" data-offset-bottom="10">
  <div class="container cta-banner__container">
    <?php print render($page['header_banner']); ?>
    <div class="cta-banner__telgroup">
      <div class="agent m-r-sm">
        <p class="agent-text">Agents Available</p>
      </div>
      <!-- / .agent -->
      <h3 class="header-cta-banner__phone">
      <a href="tel:+<?php print $site_phone; ?>" data-fuse="" data-fuse-format="1-###-###-####" class="acdc_provider_phone_no jsCTAPhoneNumber"><?php print $site_phone; ?></a>
      </h3>
    </div>
    <!-- / .agent-telgroup -->
  </div>
</div>