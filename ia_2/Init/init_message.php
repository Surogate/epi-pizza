<?php

function	init_message($player)
{
  $player['pmsg'] = array();

  $player['pmsg'][NEW_PLAYER] = 'message_new_player';
  $player['pmsg'][TOTAL_PLAYER] = 'message_total_player';
  $player['pmsg'][LEVEL_CENSUS] = 'message_census_player';
  $player['pmsg'][OK_LEVELUP] = 'message_ok_levelup_player';
  $player['pmsg'][START_APPEAL] = 'message_start_appeal';
  $player['pmsg'][COME] = 'message_come';
  $player['pmsg'][START_INCANT] = 'message_start_incant';

  $player["tmsg"][$player["pid"]] = $player["nmsg"];
}

?>