<?php
/**
 * @file
 * hours_of_operation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hours_of_operation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'hours';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Hours';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'field_hours_location_tid' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'bef_select_all_none' => FALSE,
        'bef_collapsible' => 0,
        'is_secondary' => 0,
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Time */
  $handler->display->display_options['fields']['field_hours_time']['id'] = 'field_hours_time';
  $handler->display->display_options['fields']['field_hours_time']['table'] = 'field_data_field_hours_time';
  $handler->display->display_options['fields']['field_hours_time']['field'] = 'field_hours_time';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hours_of_operation' => 'hours_of_operation',
  );
  /* Filter criterion: Content: Time -  start date (field_hours_time) */
  $handler->display->display_options['filters']['field_hours_time_value']['id'] = 'field_hours_time_value';
  $handler->display->display_options['filters']['field_hours_time_value']['table'] = 'field_data_field_hours_time';
  $handler->display->display_options['filters']['field_hours_time_value']['field'] = 'field_hours_time_value';
  /* Filter criterion: Content: Location (field_hours_location) */
  $handler->display->display_options['filters']['field_hours_location_tid']['id'] = 'field_hours_location_tid';
  $handler->display->display_options['filters']['field_hours_location_tid']['table'] = 'field_data_field_hours_location';
  $handler->display->display_options['filters']['field_hours_location_tid']['field'] = 'field_hours_location_tid';
  $handler->display->display_options['filters']['field_hours_location_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_hours_location_tid']['vocabulary'] = 'hours_sets';

  /* Display: Hours */
  $handler = $view->new_display('block', 'Hours', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Time */
  $handler->display->display_options['fields']['field_hours_time']['id'] = 'field_hours_time';
  $handler->display->display_options['fields']['field_hours_time']['table'] = 'field_data_field_hours_time';
  $handler->display->display_options['fields']['field_hours_time']['field'] = 'field_hours_time';
  $handler->display->display_options['fields']['field_hours_time']['label'] = '';
  $handler->display->display_options['fields']['field_hours_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_hours_time']['settings'] = array(
    'format_type' => 'hour',
    'fromto' => 'both',
    'multiple_number' => '1',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'hide',
  );
  $handler->display->display_options['fields']['field_hours_time']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_hours_time']['delta_first_last'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Priority (field_hours_priority) */
  $handler->display->display_options['sorts']['field_hours_priority_value']['id'] = 'field_hours_priority_value';
  $handler->display->display_options['sorts']['field_hours_priority_value']['table'] = 'field_data_field_hours_priority';
  $handler->display->display_options['sorts']['field_hours_priority_value']['field'] = 'field_hours_priority_value';
  $handler->display->display_options['sorts']['field_hours_priority_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hours_of_operation' => 'hours_of_operation',
  );
  /* Filter criterion: Content: Time -  start date (field_hours_time) */
  $handler->display->display_options['filters']['field_hours_time_value']['id'] = 'field_hours_time_value';
  $handler->display->display_options['filters']['field_hours_time_value']['table'] = 'field_data_field_hours_time';
  $handler->display->display_options['filters']['field_hours_time_value']['field'] = 'field_hours_time_value';
  $handler->display->display_options['filters']['field_hours_time_value']['default_date'] = 'today';
  /* Filter criterion: Content: Location (field_hours_location) */
  $handler->display->display_options['filters']['field_hours_location_tid']['id'] = 'field_hours_location_tid';
  $handler->display->display_options['filters']['field_hours_location_tid']['table'] = 'field_data_field_hours_location';
  $handler->display->display_options['filters']['field_hours_location_tid']['field'] = 'field_hours_location_tid';
  $handler->display->display_options['filters']['field_hours_location_tid']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['field_hours_location_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_hours_location_tid']['expose']['operator_id'] = 'field_hours_location_tid_op';
  $handler->display->display_options['filters']['field_hours_location_tid']['expose']['operator'] = 'field_hours_location_tid_op';
  $handler->display->display_options['filters']['field_hours_location_tid']['expose']['identifier'] = 'field_hours_location_tid';
  $handler->display->display_options['filters']['field_hours_location_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_hours_location_tid']['group_info']['label'] = 'Location (field_hours_location)';
  $handler->display->display_options['filters']['field_hours_location_tid']['group_info']['identifier'] = 'field_hours_location_tid';
  $handler->display->display_options['filters']['field_hours_location_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_hours_location_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_hours_location_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_hours_location_tid']['vocabulary'] = 'hours_sets';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_hours_time' => 'field_hours_time',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hours_time' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'hours_of_operation' => 'hours_of_operation',
  );
  /* Filter criterion: Content: Location (field_hours_location) */
  $handler->display->display_options['filters']['field_hours_location_tid']['id'] = 'field_hours_location_tid';
  $handler->display->display_options['filters']['field_hours_location_tid']['table'] = 'field_data_field_hours_location';
  $handler->display->display_options['filters']['field_hours_location_tid']['field'] = 'field_hours_location_tid';
  $handler->display->display_options['filters']['field_hours_location_tid']['value'] = array(
    2 => '2',
    1 => '1',
    3 => '3',
    5 => '5',
    4 => '4',
  );
  $handler->display->display_options['filters']['field_hours_location_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_hours_location_tid']['vocabulary'] = 'hours_sets';
  $handler->display->display_options['path'] = 'hours';
  $export['hours'] = $view;

  return $export;
}
