<?php

require_once('Init/init_param.php');
require_once('Init/init_process.php');
require_once('Init/init_connect.php');
require_once('Init/init_player.php');
require_once('Init/init_level.php');
require_once('Init/init_ia.php');
require_once('Init/init_mode.php');

require_once('IaGeneral/loop_action.php');
require_once('IaGeneral/mode.php');
require_once('IaGeneral/apply_ia.php');
require_once('IaGeneral/create_msg.php');
require_once('IaGeneral/new_action.php');
require_once('IaGeneral/time_action.php');
require_once('IaGeneral/flush_action.php');
require_once('IaGeneral/create_way.php');
require_once('IaGeneral/trace_way.php');
require_once('IaGeneral/food.php');
require_once('IaGeneral/log_ia.php');
require_once('IaGeneral/exec_suicide.php');
require_once('IaGeneral/send_inventaire.php');

require_once('Response/std_response.php');
require_once("Response/std_ok.php");
require_once("Response/std_ko.php");
require_once("Response/std_deplacement.php");
require_once("Response/std_mort.php");
require_once("Response/std_voir.php");
require_once("Response/std_inventaire.php");
require_once("Response/std_fork.php");
require_once("Response/std_incant.php");
require_once("Response/std_actuallevel.php");

require_once("Timer/timer_fork.php");
require_once("Timer/timer_inventaire.php");
require_once("Timer/timer_manage.php");
require_once("Timer/timer_wait.php");
require_once("Timer/timer_follow.php");

require_once("Message/std_suicide.php");
require_once("Message/std_message.php");
require_once("Message/std_hi.php");
require_once("Message/std_inventory.php");
require_once("Message/std_manage.php");
require_once("Message/std_follows.php");
require_once("Message/std_followl.php");
require_once("Message/std_sincant.php");
require_once("Message/std_arrive.php");
require_once("Message/std_tplayer.php");
require_once("Message/std_mmode.php");
require_once("Message/std_sincruste.php");

require_once("Action/action_feeding.php");
require_once("Action/action_feedingl.php");
require_once("Action/action_leveling.php");
require_once("Action/action_manage.php");
require_once("Action/action_calling.php");
require_once("Action/action_casting.php");
require_once("Action/action_farming.php");
require_once("Action/action_spamming.php");
require_once("Action/action_ponding.php");

?>