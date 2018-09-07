<?php


/*
 *  Preprocess variables available to page.tpl.php.
 */
function electricitytexas_preprocess_page(&$vars, $hook) {

  //@todo: case statement
  if ((isset($vars['node']) && $vars['node']->type == 'results_page')) {
    // Make sure content type uses results tpl
    $vars['theme_hook_suggestions'][] = 'page__acdc_results';

    // Add custom JS to Search Results page
    drupal_add_js(drupal_get_path('theme','acbrand') . '/js/widgets/searchresults.js', array(
      'type' => 'file',
      'scope' => 'footer',
      'group' => 'acbrand',
      'weight' => 5
    ));     
  }

  if ((isset($vars['node']) && $vars['node']->type == 'category_page')) {
    // Lets us know if address capture was disabled by an admin.
    $ac_option = $vars['node']->field_address_capture;
    if (isset($ac_option) && $ac_option[LANGUAGE_NONE][0]['value'] == 1) {
      //Add as JS Drupal.settings global. 
      drupal_add_js(array('ET' => array('hideAddressCapture' => TRUE)), array(
      'type' => 'setting',
      'every_page' => FALSE,
      ));      
    }
  }

}

function electricitytexas_preprocess_entity(&$variables) {
  //dsm($variables, 'entity vars');
}
