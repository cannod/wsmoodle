<?php

function wsmoodle_rules_action_info() {
  $actions = array(
    // The base-level keys in the array are the machine names for the actions,
    // and by default also the function name for the action callback. Prefix
    // with your module name to avoid name conflicts.

    'wsmoodle_action_hello_user' => array(
      'label' => t('Say hello to a selected user'),
      'group' => t('Rules examples'),
      // When declaring parameters, site builders will by default get a form to
      // select fitting data. In this case, we require the site builder to
      // select a user object. The 'type' could be any data type known to Rules,
      // which means any entity type known to Entity API or any additional data
      // type declared by hook_rules_data_info – by default including things
      // like 'integer', 'text' and more. See
      'parameter' => array(
        // Each parameter is keyed with an internally used machine name.
        'account' => array(
          'type' => 'user',
          'label' => t('User to say hello to'),
          // If we were to make changes to the parameter object, whe should set
          // the 'save' property to TRUE. This makes Rules handle the saving in
          // a more optimized way than if each action saved the objects.
          // 'save' => TRUE,
        ),
      ),
    ),
	'wsmoodle_action_create_update_user' => array(
      'label' => t('Create a Moodle user'),
      'group' => t('Droodle'),
      // When declaring parameters, site builders will by default get a form to
      // select fitting data. In this case, we require the site builder to
      // select a user object. The 'type' could be any data type known to Rules,
      // which means any entity type known to Entity API or any additional data
      // type declared by hook_rules_data_info – by default including things
      // like 'integer', 'text' and more. See
      'parameter' => array(
        // Each parameter is keyed with an internally used machine name.
        'account' => array(
          'type' => 'user',
          'label' => t('The user to create'),
          // If we were to make changes to the parameter object, whe should set
          // the 'save' property to TRUE. This makes Rules handle the saving in
          // a more optimized way than if each action saved the objects.
          // 'save' => TRUE,
        ),
      ),
    ),
	'wsmoodle_action_sync_cohorts' => array(
      'label' => t('Sync Moodle cohorts'),
      'group' => t('Droodle'),
      // When declaring parameters, site builders will by default get a form to
      // select fitting data. In this case, we require the site builder to
      // select a user object. The 'type' could be any data type known to Rules,
      // which means any entity type known to Entity API or any additional data
      // type declared by hook_rules_data_info – by default including things
      // like 'integer', 'text' and more. See
      'parameter' => array(
        // Each parameter is keyed with an internally used machine name.
        'account' => array(
          'type' => 'user',
          'label' => t('The user to be synced'),
          // If we were to make changes to the parameter object, whe should set
          // the 'save' property to TRUE. This makes Rules handle the saving in
          // a more optimized way than if each action saved the objects.
          // 'save' => TRUE,
        ),
      ),
    ),
  );

  return $actions;
}

/**
 * The action function for the 'rules_example_action_hello_user'.
 *
 * The $accout parameter is the user object sent into this action, selected in
 * the Rules configuration interface.
 * @param <object> $account
 *   The user object to work with. Selected by the site administrator when the
 *   action is configured.
 */
function wsmoodle_action_hello_user($account) {
  drupal_set_message(t('Hello @username!',
    array('@username' => $account->name)));
}
/**
 * The action function for the 'wsmoodle_action_create_update_user'.
 *
 * The $account parameter is the user object sent into this action, selected in
 * the Rules configuration interface.
 * @param <object> $account
 *   The user object to work with. Selected by the site administrator when the
 *   action is configured.
 */
function wsmoodle_action_create_update_user($account) {

	wsmoodle_create_update_user($account);
}

/**
 * The action function for the 'wsmoodle_action_sync_cohorts'.
 *
 * The $account parameter is the user object sent into this action, selected in
 * the Rules configuration interface.
 * @param <object> $account
 *   The user object to work with. Selected by the site administrator when the
 *   action is configured.
 */
function wsmoodle_action_sync_cohorts($account) {

  wsmoodle_sync_cohorts($account);

}