<?php
/**
 * @file views-views-json-style-simple.tpl.php
 * Default template for the Views JSON style plugin using the simple format
 *
 * Variables:
 * - $view: The View object.
 * - $rows: Hierachial array of key=>value pairs to convert to JSON
 * - $options: Array of options for this style
 *
 * @ingroup views_templates
 */

require DRUPAL_ROOT . '/sites/vendor/autoload.php';

use League\HTMLToMarkdown\HtmlConverter;

$converter = new HtmlConverter();
$converter->getConfig()->setOption('strip_tags', true);
$converter->getConfig()->setOption('header_style', 'atx');

$jsonp_prefix = $options['jsonp_prefix'];


$new_rows = array();

foreach ($rows['pages'] as $key => $value) {

  $bodyContent = ($rows['pages'][$key]['bodyContent']) ? $converter->convert($rows['pages'][$key]['bodyContent']) : $converter->convert($rows['pages'][$key]['body']);

  array_push($new_rows, array(
    'slug' => $rows['pages'][$key]['path'],
    'meta' => array(
      'title' => '',
      'robots' => '', 
      'keywords' => '',
      'attributes' => array(
        'id' => $rows['pages'][$key]['nid'],
        'pageCategory' => $rows['pages'][$key]['pageCategory'],
        'pageTemplate' => $rows['pages'][$key]['pageTemplate'],
        'providerLogo' => $rows['pages'][$key]['providerLogo'],
        'providerName' => $rows['pages'][$key]['providerName'],
        'tags' => explode(',', strtolower($rows['pages'][$key]['tags'])),
        'published' => $rows['pages'][$key]['published'],
        'postDate' => $rows['pages'][$key]['postDate'],
      ),
    ),
    'aliases' => array(), 
    'content' => array(
      array(
        'key' => 'heroId_' . $rows['pages'][$key]['nid'],
        'type' => 'section',
        'attributes' => array(
          'name' => 'hero'
        ),
        'content' => array(
          array(
            'attributes' => array(
              'name' => 'heroTitle',
            ),
            'type' => 'text',
            'text' => $rows['pages'][$key]['title'], 
          ),
          array(
            'attributes' => array(
              'name' => 'heroImage',
            ),
            'type' => 'image',
            'url' => '/sites/all/themes/allconnect/img/hero/' . $rows['pages'][$key]['heroImage'],
            'altText' => ''
          ),
        )
      ),
      array(
        'key' => 'productsId_' . $rows['pages'][$key]['nid'],
        'type' => 'section',
        'attributes' => array(
            'name' => 'products',
        ),
        'content' => array(
          array(
            'attributes' => 
              array(
                'name' => 'productsHeader',
              ),
            'type' => 'text',
            'text' => $rows['pages'][$key]['productsHeader'],
          ),
          array(
            'attributes' => null,
            'type' => 'selectables',
            'id' => $rows['pages'][$key]['uuid'], //  need other selectables
          ),      
        ),
      ),
      array(
        'key' => 'bodyId_' . $rows['pages'][$key]['nid'],
        'attributes' => 
          array(
            'name' => 'bodyContent',
          ),
        'type' => 'text',
        'text' => $bodyContent,
      ), 
    ),
    'author' => array(
      'email' => $rows['pages'][$key]['author'],
    )
  ));
}

if ($view->override_path) {
  // We're inside a live preview where the JSON is pretty-printed.
  $json = _views_json_encode_formatted($new_rows, $options);
  if ($jsonp_prefix) $json = "$jsonp_prefix($json)";
  print "<code>$json</code>";
}
else {
  $json = _views_json_json_encode($new_rows, $bitmask);
  if ($options['remove_newlines']) {
     $json = preg_replace(array('/\\\\n/'), '', $json);
  }

  if (isset($_GET[$jsonp_prefix]) && $jsonp_prefix) {
    $json = check_plain($_GET[$jsonp_prefix]) . '(' . $json . ')';
  }

  if ($options['using_views_api_mode']) {
    // We're in Views API mode.
    print $json;
  }
  else {
    // We want to send the JSON as a server response so switch the content
    // type and stop further processing of the page.
    $content_type = ($options['content_type'] == 'default') ? 'application/json' : $options['content_type'];
    drupal_add_http_header("Content-Type", "$content_type; charset=utf-8");
    print $json;
    drupal_page_footer();
    exit;
  }
}
