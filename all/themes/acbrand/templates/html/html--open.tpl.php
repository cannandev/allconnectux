<?php
/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 */
?>
<!DOCTYPE html>
<html lang="<?php print $language->language; ?>">
  <head profile="<?php print $grddl_profile; ?>">
    <script>    
      var gtmSessionId = new Date().getTime() + '.' + Math.random().toString(36).substring(5);
      var gtmDataLayer = [{
          'order_source': '<?php print $gtm_ord_src; ?>'
      }];    
    </script>
    <!-- Google Tag Manager -->
  <?php if (empty($GLOBALS['base_url'])): ?>
    <script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start': new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src='//www.googletagmanager.com/gtm.js?id='+i+dl;f.parentNode.insertBefore(j,f);})(window,document,'script','gtmDataLayer','GTM-5J2LKL');
    </script>
  <?php else: ?>
    <script>(function(w,d,s,l,i){w[l]=w[l]||[];w[l].push({'gtm.start':new Date().getTime(),event:'gtm.js'});var f=d.getElementsByTagName(s)[0],j=d.createElement(s),dl=l!='dataLayer'?'&l='+l:'';j.async=true;j.src='https://www.googletagmanager.com/gtm.js?id='+i+dl+'&gtm_auth=OUf8Z6B4Tplx9OT9hunXbQ&gtm_preview=env-5&gtm_cookies_win=x';f.parentNode.insertBefore(j,f);})(window,document,'script','gtmDataLayer','GTM-5J2LKL');
    </script>
  <?php endif; ?>
  <!-- End Google Tag Manager -->
    
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <link href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/css/bootstrap.min.css" rel="stylesheet">
    <?php print $styles; ?>
    <!--[if lte IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
    <![endif]-->
    <?php print $scripts; ?>
    <script>
      // Picture element HTML5 shiv
      document.createElement( "picture" );
    </script>
    <script src="//cdnjs.cloudflare.com/ajax/libs/picturefill/3.0.2/picturefill.min.js" async></script>
  </head>
  <body class="<?php print $classes; ?>" <?php print $attributes; ?>>
    <div id ="gtmBodySnippet"><!-- Google Tag Manager --><noscript><iframe src="//www.googletagmanager.com/ns.html?id=GTM-5J2LKL" height="0" width="0" style="display:none;visibility:hidden"></iframe></noscript><!-- End Google Tag Manager (noscript) -->
    </div>
    <?php print $page_top; ?>
    <?php print $page; ?>
    <?php print $page_bottom; ?>
  <script src="https://use.fontawesome.com/b25e7d562a.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
  </body>
</html>