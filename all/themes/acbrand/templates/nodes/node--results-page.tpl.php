<?php
/**
* @file
* Open page node template.
*
*
* @see node.tpl.php
*/

$template = isset($params['category']) ? $params['category'] : '';
$otherProvidersNeeded = isset($params['otherProvidersNeeded']) ? $params['otherProvidersNeeded'] : FALSE;
$providerName = isset($params['providerName']) ? $params['providerName'] : 'this provider';

  if(strpos($_SERVER['SERVER_NAME'], 'local.searchresults.com') !== false) {
    $env = "http://local.searchresults.com/";
    $trunk = "http://local.trunk.com/siteImages/";
  } else {
    $env = "/";
    $trunk = "/";
  }

// hide node content fields before displaying them
hide($content['field_hero_image']);
hide($content['field_category']);
hide($content['field_hero_link_cta']);
hide($content['field_disclaimer']);
hide($content['field_featured_id']);
hide($content['field_body_content']);
hide($content['field_shared_content']);
?>

<code>hero markup: render $content['fields']</code>
<h1><?php print render($title); ?></h1>
<?php print render($content); ?>

<code>acdc markup:</code>
<?php include_once 'includes/search/content.inc'; ?>

<code>body markup: render $content</code>
<?php print render($content['field_body_content']); ?>
<?php print render($content['field_shared_content']); ?>
