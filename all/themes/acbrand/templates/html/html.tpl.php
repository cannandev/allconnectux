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
    <?php print $page_top; ?>
    <?php print $page; ?>
    <?php print $page_bottom; ?>
  <!-- <script src="https://use.fontawesome.com/b25e7d562a.js"></script>
  <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.6/js/bootstrap.min.js"></script> -->
<!--  <script id="__bs_script__">//<![CDATA[
  document.write("<script async src='http://HOST:3000/browser-sync/browser-sync-client.2.13.0.js'><\/script>".replace("HOST", location.hostname));
//]]></script>  -->
  </body>
</html>