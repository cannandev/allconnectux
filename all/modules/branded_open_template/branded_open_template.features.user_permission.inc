<?php
/**
 * @file
 * branded_open_template.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function branded_open_template_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create open_page content'.
  $permissions['create open_page content'] = array(
    'name' => 'create open_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content admin' => 'content admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any open_page content'.
  $permissions['delete any open_page content'] = array(
    'name' => 'delete any open_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content admin' => 'content admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own open_page content'.
  $permissions['delete own open_page content'] = array(
    'name' => 'delete own open_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content admin' => 'content admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any open_page content'.
  $permissions['edit any open_page content'] = array(
    'name' => 'edit any open_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content admin' => 'content admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own open_page content'.
  $permissions['edit own open_page content'] = array(
    'name' => 'edit own open_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'content admin' => 'content admin',
    ),
    'module' => 'node',
  );

  return $permissions;
}
