<?php

/**
 * @author Antonio Duran
 * @license http://www.gnu.org/copyleft/gpl.html GNU Public License
 * @package moodle multiauth
 *
 * Authentication Plugin: droodle
 *
 * Checks against Joomla web services provided my droodle
 *
 * 2009-10-25  File created.
 */

if (!defined('MOODLE_INTERNAL')) {
    die('Direct access to this script is forbidden.');    ///  It must be included from a Moodle page
}

require_once($CFG->libdir.'/authlib.php');
require_once($CFG->dirroot.'/auth/manual/auth.php');
require_once($CFG->dirroot.'/enrol/locallib.php');
require_once($CFG->dirroot.'/course/lib.php');
require_once($CFG->dirroot.'/group/lib.php');
require_once($CFG->dirroot.'/lib/grouplib.php');
require_once($CFG->dirroot.'/cohort/lib.php');



/**
 * droodle
 */
class droodle_webservice {

    function test () {
	    return "Moodle web services are working!";
    }
	
    function user_id ($username)
    {
        global $DB;

        $username = utf8_decode ($username);
        $username = strtolower ($username);
        $conditions = array("username" => $username);
        $user = $DB->get_record("user", $conditions);

        if (!$user)
            return 0;

        return $user->id;
    }

    function course_id ($idnumber)
    {
        global $DB;

        $idnumber = utf8_decode ($idnumber);
        $idnumber = strtolower ($idnumber);
        $conditions = array("idnumber" => $idnumber);
        $course = $DB->get_record("course", $conditions);

        if (!$course)
            return 0;

        return $course->id;
    }

    function enrol_user ($username, $course_id, $roleid = 5)
    {
        global $CFG, $DB, $PAGE;

        $username = utf8_decode ($username);
        $username = strtolower ($username);
        /* Create the user before if it is not created yet */
        $conditions = array ('username' => $username);
        $user = $DB->get_record('user',$conditions);
        if (!$user)
            return 0;

        $user = $DB->get_record('user',$conditions);
        $conditions = array ('id' => $course_id);
        $course = $DB->get_record('course', $conditions);

        if (!$course)
            return 0;

        // Get enrol start and end dates of manual enrolment plugin
        if ($CFG->version >= 2011061700)
            $manager = new course_enrolment_manager($PAGE, $course);
        else
            $manager = new course_enrolment_manager($course);

        $instances = $manager->get_enrolment_instances();
        $plugins = $manager->get_enrolment_plugins();
        $enrolid = 1; //manual

        $today = time();
        $today = make_timestamp(date('Y', $today), date('m', $today), date('d', $today), date ('H', $today), date ('i', $today), date ('s', $today));
        $timestart = $today;
        $timeend = 0;

        $found = false;
        foreach ($instances as $instance)
        {
            if ($instance->enrol == 'manual')
            {
                $found = true;
                break;
            }
        }

        if (!$found)
            return 0;

        $plugin = $plugins['manual'];

        if ( $instance->enrolperiod)
            $timeend   = $timestart + $instance->enrolperiod;

        // First, check if user is already enroled but suspended, so we just need to enable it

        $conditions = array ('courseid' => $course_id, 'enrol' => 'manual');
        $enrol = $DB->get_record('enrol', $conditions);

        if (!$enrol)
            return 0;

        $conditions = array ('username' => $username);
        $user = $DB->get_record('user', $conditions);

        if (!$user)
            return 0;

        $conditions = array ('enrolid' => $enrol->id, 'userid' => $user->id);
        $ue = $DB->get_record('user_enrolments', $conditions);

        if ($ue)
        {
            // User already enroled
            // Can be suspended, or maybe enrol time passed
            // Just activate enrolment and set new dates
            $ue->status = 0; //active
            $ue->timestart = $timestart;
            $ue->timeend = $timeend;
            $ue->timemodified = $timestart;
            $DB->update_record('user_enrolments', $ue);
            return 1;
        }

        $plugin->enrol_user($instance, $user->id, $roleid, $timestart, $timeend);

        return 1;
    }

    function create_user ($username, $firstname, $lastname, $email, $auth) {

        global $CFG, $DB;

        $username = utf8_decode ($username);
        $username = strtolower ($username);

        $conditions = array ('username' => $username);
        $user = $DB->get_record('user',$conditions);

        if (!$user)
            $user = create_user_record($username, "");

        $conditions = array ('id' => $user->id);
        if ($firstname)
            $DB->set_field('user', 'firstname', $firstname, $conditions);
        if ($lastname)
            $DB->set_field('user', 'lastname', $lastname, $conditions);
        if ($email)
            $DB->set_field('user', 'email', $email, $conditions);
        if ($email)
            $DB->set_field('user', 'auth', $auth, $conditions);
            //$DB->set_field('user', 'firstaccess', time (), $conditions);
		
        return 1;
    }

    function delete_user ($username)
    {
        global $DB;

        $username = utf8_decode ($username);
        $username = strtolower ($username);
        $conditions = array("username" => $username);
        $user = $DB->get_record("user", $conditions);

        if ($user)
        {
            delete_user ($user);
            return 1;
        }
        return 0;
    }

} //class




?>