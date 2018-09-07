<?php
/**
 * @file
 * branded_products.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function branded_products_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-corporate-links_about-us:node/2.
  $menu_links['menu-corporate-links_about-us:node/2'] = array(
    'menu_name' => 'menu-corporate-links',
    'link_path' => 'node/2',
    'router_path' => 'node/%',
    'link_title' => 'About Us',
    'options' => array(
      'attributes' => array(
        'title' => 'About Us',
      ),
      'identifier' => 'menu-corporate-links_about-us:node/2',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Exported menu link: menu-corporate-links_contact-us:<front>.
  $menu_links['menu-corporate-links_contact-us:<front>'] = array(
    'menu_name' => 'menu-corporate-links',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Contact Us',
    'options' => array(
      'attributes' => array(
        'title' => 'Contact Us',
      ),
      'identifier' => 'menu-corporate-links_contact-us:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 1,
    'customized' => 1,
  );
  // Exported menu link: menu-corporate-links_site-map:<front>.
  $menu_links['menu-corporate-links_site-map:<front>'] = array(
    'menu_name' => 'menu-corporate-links',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Site Map',
    'options' => array(
      'attributes' => array(
        'title' => 'Site Map',
      ),
      'identifier' => 'menu-corporate-links_site-map:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('About Us');
  t('Contact Us');
  t('Site Map');

  return $menu_links;
}
