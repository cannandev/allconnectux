<?php
/**
 * @file
 * branded_products.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function branded_products_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-brand-links.
  $menus['menu-brand-links'] = array(
    'menu_name' => 'menu-brand-links',
    'title' => 'Brand Links',
    'description' => 'Brand specific links',
  );
  // Exported menu: menu-corporate-links.
  $menus['menu-corporate-links'] = array(
    'menu_name' => 'menu-corporate-links',
    'title' => 'Corporate Links',
    'description' => 'Corporate links for the site.',
  );
  // Exported menu: menu-spanish-pages.
  $menus['menu-spanish-pages'] = array(
    'menu_name' => 'menu-spanish-pages',
    'title' => 'Spanish pages',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Brand Links');
  t('Brand specific links');
  t('Corporate Links');
  t('Corporate links for the site.');
  t('Main menu');
  t('Spanish pages');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');

  return $menus;
}
