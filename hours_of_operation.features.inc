<?php
/**
 * @file
 * hours_of_operation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hours_of_operation_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hours_of_operation_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hours_of_operation_node_info() {
  $items = array(
    'hours_of_operation' => array(
      'name' => t('Hours of Operation'),
      'base' => 'node_content',
      'description' => t('for dynamically listing hours of operation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
