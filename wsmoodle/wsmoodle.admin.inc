<?php

/*
 * @file Admin Settings for Moodle Webservices
 * 
 */


function wsmoodle_admin_settings() {

  $form = array();
  
  $form['wsmoodle_token'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('wsmoodle_token', ''),
    '#description' => 'Please Enter your Moodle token.',
    '#title' => 'Token',
    '#required' => TRUE,
  );
  
  $form['wsmoodle_fqdn'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('wsmoodle_fqdn', ''),
    '#description' => 'Fully qualified domain name. For example, ("https://moodle.com/").',
    '#title' => 'FQDN',
    '#required' => TRUE,
  );
  
  $form['wsmoodle_service_endpoint'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('wsmoodle_service_endpoint', 'webservice/rest/server.php'),
    '#description' => 'Please enter the service endpoint. For example, ("webservice/rest/server.php").',
    '#title' => 'Service Endpoint',
    '#required' => TRUE,
  );
  
  $form['wsmoodle_format'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('wsmoodle_format', 'json'),
    '#description' => 'Please enter the required response format. Either, ("json" or "xml").',
    '#title' => 'Respose Format',
    '#required' => TRUE,
  );

  $form['wsmoodle_authtype'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('wsmoodle_authtype', 'manual'),
    '#description' => 'Please enter the Moodle user authentication type.',
    '#title' => 'Moodle user auth type',
    '#required' => TRUE,
  );
  
  return system_settings_form($form);
}

function wsmoodle_tools_form($form, &$form_state) {
  $form['user_sync_button'] = array(
    '#type' => 'button',
    '#value' => t('Click to sync all Drupal users to moodle!'),

	'#ajax' => array(
      'callback'=>'user_sync_button',
      'wrapper'=>'progress-bar',
          'progress'=> array(
              'type'=> 'throbber', 
              'url'=>'',
              'message' => t("Please wait..."),
          ),
    ),
  );
  $form['cohort_sync_button'] = array(
    '#type' => 'button',
    '#value' => t('Click to sync all cohorts to moodle!'),
	'#ajax' => array(
      'callback'=>'cohort_sync_button',
      'wrapper'=>'progress-bar',
          'progress'=> array(
              'type'=> 'throbber', 
              'url'=>'',
              'message' => t("Please wait..."),
          ),
    ),
  );
  
  return $form;
}

function wsmoodle_cohorts_form($form, &$form_state) {
  $form = array();
  
  $form['wsmoodle_cohort_user_id'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('wsmoodle_cohort_user_id', ''),
    '#description' => 'Please enter the view field that contains the Drupal user ID.',
    '#title' => 'Drupal user ID',
    '#required' => TRUE,
  ); 
  $form['wsmoodle_cohort_name'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('wsmoodle_cohort_name', ''),
    '#description' => 'Please enter the view field that contains the cohort name.',
    '#title' => 'Cohort name',
    '#required' => TRUE,
  );
    $form['wsmoodle_cohort_id'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('wsmoodle_cohort_id', ''),
    '#description' => 'Please enter the view field that contains the cohort id.',
    '#title' => 'Cohort ID',
    '#required' => TRUE,
  );
    $form['wsmoodle_cohort_description'] = array(
    '#type' => 'textfield',
    '#default_value' => variable_get('wsmoodle_cohort_description', ''),
    '#description' => 'Please enter the view field that contains the cohort description.',
    '#title' => 'Cohort description',
    '#required' => TRUE,
  );
  
  return system_settings_form($form);
}