<?php

require_once("$CFG->libdir/externallib.php");
require_once($CFG->dirroot.'/local/droodle/webservice_class.php');
 
class droodle_helpers_external extends external_api {
 
	/* user_id */
    public static function user_id_parameters() {
        return new external_function_parameters(
                        array(
                            'username' => new external_value(PARAM_TEXT, 'multilang compatible name, course unique'),
                        )
        );
    }

    public static function user_id_returns() {
        return new  external_value(PARAM_INT, 'multilang compatible name, course unique');
    }

    public static function user_id($username) { //Don't forget to set it as static
        global $CFG, $DB;
 
        $params = self::validate_parameters(self::user_id_parameters(), array('username'=>$username));
 
		$webservice = new  droodle_webservice ();
		$id = $webservice->user_id ($username);

        return $id;
    }
	
	/* course_id */
    public static function course_id_parameters() {
        return new external_function_parameters(
                        array(
                            'idnumber' => new external_value(PARAM_TEXT, 'idnumber'),
                        )
        );
    }

    public static function course_id_returns() {
        return new  external_value(PARAM_INT, 'multilang compatible name, course unique');
    }

    public static function course_id($idnumber) { //Don't forget to set it as static
        global $CFG, $DB;
 
        $params = self::validate_parameters(self::course_id_parameters(), array('idnumber'=>$idnumber));
 
		$webservice = new  droodle_webservice ();
		$id = $webservice->course_id ($idnumber);

        return $id;
    }
	
	/* enrol_user */
    public static function enrol_user_parameters() {
        return new external_function_parameters(
                        array(
                            'username' => new external_value(PARAM_TEXT, 'username'),
                            'id' => new external_value(PARAM_INT, 'course id'),
                            'roleid' => new external_value(PARAM_INT, 'role id'),
                        )
        );
    }

    public static function enrol_user_returns() {
        return new  external_value(PARAM_INT, 'user created');
    }

    public static function enrol_user($username, $id, $roleid) { 
        global $CFG, $DB;
 
        $params = self::validate_parameters(self::enrol_user_parameters(), array('username'=>$username, 'id' => $id, 'roleid' => $roleid));
 
		$webservice = new  droodle_webservice ();
		$id = $webservice->enrol_user ($username, $id, $roleid);

        return $id;
    }

	/* create_user */
    public static function create_user_parameters() {
        return new external_function_parameters(
                        array(
                            'username' => new external_value(PARAM_TEXT, 'username'),
                            'firstname' => new external_value(PARAM_TEXT, 'firstname'),
                            'lastname' => new external_value(PARAM_TEXT, 'lastname'),
                            'email' => new external_value(PARAM_TEXT, 'email'),
							'auth' => new external_value(PARAM_TEXT, 'auth'),
                        )
        );
    }

    public static function create_user_returns() {
        return new  external_value(PARAM_INT, 'user created');
    }

    public static function create_user($username, $firstname, $lastname, $email, $auth) { 
        global $CFG, $DB;
 
        $params = self::validate_parameters(self::create_user_parameters(), array('username'=>$username, 'firstname'=>$firstname, 'lastname'=>$lastname, 'email'=>$email, 'auth'=>$auth));
 
		$webservice = new  droodle_webservice ();
		$id = $webservice->create_user ($username, $firstname, $lastname, $email, $auth);

        return $id;
    }
	
	/* delete_user */
    public static function delete_user_parameters() {
        return new external_function_parameters(
                        array(
                            'username' => new external_value(PARAM_TEXT, 'username'),
                        )
        );
    }

    public static function delete_user_returns() {
        return new  external_value(PARAM_BOOL, 'user deleted');
    }

    public static function delete_user($username) { 
        global $CFG, $DB;
 
        $params = self::validate_parameters(self::delete_user_parameters(), array('username'=>$username));
 
		$webservice = new  droodle_webservice ();
		$id = $webservice->delete_user ($username);

        return $id;
    }
}
?>