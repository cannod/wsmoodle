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

