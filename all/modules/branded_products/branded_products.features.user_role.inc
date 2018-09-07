<?php
/**
 * @file
 * branded_products.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function branded_products_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: block editor.
  $roles['block editor'] = array(
    'name' => 'block editor',
    'weight' => 6,
  );

  // Exported role: content admin.
  $roles['content admin'] = array(
    'name' => 'content admin',
    'weight' => 4,
  );

  // Exported role: pricing admin.
  $roles['pricing admin'] = array(
    'name' => 'pricing admin',
    'weight' => 3,
  );

  // Exported role: super user.
  $roles['super user'] = array(
    'name' => 'super user',
    'weight' => 5,
  );

  return $roles;
}
