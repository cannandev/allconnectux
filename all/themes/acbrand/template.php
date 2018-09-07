<?php

/**
 * Override or insert variables into the html template.
 */
function acbrand_preprocess_html(&$vars) {
  if (module_exists('path') && (drupal_get_path_alias() == "acheader.html")) {
    $vars['theme_hook_suggestions'][] = 'html__acheader';
  }

  if (module_exists('path') && (drupal_get_path_alias() == "acfooter.html")) {
    $vars['theme_hook_suggestions'][] = 'html__acfooter';
  }

  $node = menu_get_object();

  if (isset($node) && $node->type == 'open_page') {
    $vars['theme_hook_suggestions'][] = 'html__open';
    $vars['gtm_ord_src'] = check_plain($node->field_gtm_order_src[LANGUAGE_NONE][0]['value']);
  }

}

/*
 *  Preprocess variables available to page.tpl.php.
 */
function acbrand_preprocess_page(&$vars, $hook) {

  $theme_path = drupal_get_path('theme', $GLOBALS['theme']);

  // General page template variables
  $vars['copyright_year'] = date('Y');
  $vars['site_phone'] = variable_get('site_phone', '1-844-263-2443');
  $vars['site_copyright'] = variable_get('site_copyright', 'BRAND. All rights reserved. All content on this Web site is proprietary.');
  $vars['site_callin'] = variable_get('site_callin', FALSE);
  $vars['theme_path'] = $theme_path;
  $vars['is_spanish'] = FALSE;

  // Add custom template names for ACDC header and footer.
  // @TODO: Make one check for module_exists and case statements for aliases.
  if (module_exists('path') && (drupal_get_path_alias() == "acheader.html")) {
    $vars['theme_hook_suggestions'][] = 'page__acdc_header';
  }

  if (module_exists('path') && (drupal_get_path_alias() == "acfooter.html")) {
    $vars['theme_hook_suggestions'][] = 'page__acdc_footer';
  }
  
  // Add custom JS to Search Results page
  if (module_exists('path') && (drupal_get_path_alias() == "ac-results.html")) {
    $vars['theme_hook_suggestions'][] = 'page__acdc_results';

    drupal_add_js(drupal_get_path('theme','acbrand') . '/js/widgets/searchresults.js', array(
      'type' => 'file',
      'scope' => 'footer',
      'group' => 'acbrand',
      'weight' => 5
    ));     
  }

  // Add custom template names for Callback Checkout pages
  if (module_exists('path') && (drupal_get_path_alias() == "cb-checkout/step-1")) {
    $vars['theme_hook_suggestions'][] = 'page__acdc_callback';

    drupal_add_js(drupal_get_path('theme','acbrand') . '/js/widgets/checkout.js', array(
      'type' => 'file',
      'scope' => 'footer',
      'group' => 'acbrand',
      'weight' => 5
    ));
  }

  if (module_exists('path') && (drupal_get_path_alias() == "cb-checkout/step-2")) {
    $vars['theme_hook_suggestions'][] = 'page__acdc_callback_2';    
  }    

  // Add custom template names for content types
  if (isset($vars['node'])) {
    $vars['theme_hook_suggestions'][] = 'page__'. $vars['node']->type;
  }

  // Add variables specific to Open Page content type
  if (isset($vars['node']) && $vars['node']->type == 'open_page') {
    $vars['hide_header'] = $vars['node']->field_open_header[LANGUAGE_NONE][0]['value'];
    $vars['hide_footer'] = $vars['node']->field_open_footer[LANGUAGE_NONE][0]['value'];

      // Loop through array of CSS files added through node field.
      if (isset($vars['node']->field_open_css)) {          
        // Create a path for each file and add to page head as external url.
        foreach ($vars['node']->field_open_css[LANGUAGE_NONE] as $css_file) {
          $field_css_uri = $css_file['safe_value'];
          $field_css = file_create_url($field_css_uri);
          drupal_add_css($field_css, array(
            'group' => CSS_THEME,
            'type' => 'external',
          ));
        }
      }

      // Get inline JS added through node field
      if (isset($vars['node']->field_open_js)) {
        $field_js = $vars['node']->field_open_js[LANGUAGE_NONE][0]['value'];
        drupal_add_js($field_js, array(
          'type' => 'inline', 
          'scope' => 'header', 
          'group' => JS_THEME,
        )
      );
    }  
  }

  // Add variables specific to Landing Page content type
  if (isset($vars['node']) && $vars['node']->type == 'landing_page') {
    if (!empty($vars['node']->field_taxonomy)) {
      $groups = field_get_items('node', $vars['node'], 'field_taxonomy');
      foreach($groups as $group) {
        if (taxonomy_term_load($group['tid'])->name == 'Spanish') {
          $vars['is_spanish'] = TRUE;
        }
      }
    }
  }
}

/*
 *  Preprocess variables available to node.tpl.php.
 */
 function acbrand_preprocess_node(&$vars) {
  $vars['site_name'] = variable_get('site_name');
  $vars['site_phone'] = variable_get('site_phone');
  $vars['theme_path'] =  drupal_get_path('theme', $GLOBALS['theme']);
 }


/**
 * Helper function to remove wrappers in a field collection field.
 */
function acbrand_field_collection_view($variables) {
  $element = $variables['element'];
  return $element['#children'];
}


/**
 *  Returns HTML wrapper for footer Brand Links menu, adding CSS classes.
 *  Implements theme_menu_tree__MENUNAME()
 */
function acbrand_menu_tree__menu_brand_links($variables) {
  return '<ul class="footer-nav footer-nav-primary">' . $variables['tree'] . '</ul>';
}

/**
 *  Returns HTML wrapper for footer Corporate Links menu, adding CSS classes.
 *  Implements theme_menu_tree__MENUNAME()
 */
function acbrand_menu_tree__menu_corporate_links($variables) {
  return '<ul class="footer-nav">' . $variables['tree'] . '</ul>';
}

/**
 *  Returns HTML wrapper for footer Spanish pages menu, adding CSS classes.
 *  Implements theme_menu_tree__MENUNAME()
 */
function acbrand_menu_tree__menu_spanish_pages($variables) {
  return '<ul class="footer-nav footer-nav-spanish">' . $variables['tree'] . '</ul>';
}

/**
 *  Returns HTML for primary local tasks. Add bootstrap classes to the wrapper.
 *  Implements theme_menu_local_tasks()
 */
function acbrand_menu_local_tasks($variables) {
  if(isset($variables['primary'])) {
    $variables['primary']['#prefix'] = '<ul class="tabs nav nav-tabs">';
    $variables['primary']['#suffix'] = '</ul>';

    return drupal_render($variables['primary']);
  }
}
