
<?php

function	timer_trifeed($player, $socket, $string)
{
  timer_fork(&$player, &$socket, &$string);
  timer_manage(&$player, &$socket, &$string);
  timer_inventaire(&$player, &$socket, &$string);
}

function        timer_man($player, $socket, $string)
{
  timer_fork(&$player, &$socket, &$string);
}

function	init_mode($player)
{
  $player[PONDING]['pmsg'][NEW_PLAYER] = 'std_hi';
  $player[PONDING]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[PONDING]['pmsg'][SUICIDE] = 'std_suicide';
  $player[PONDING]['message'] = 'std_message';
  $player[PONDING]['response'] = 'std_response';
  $player[PONDING]['timer'] = 'timer_fork';
  $player[PONDING]['action'] = 'action_ponding';

  $player[SPAMMING]['pmsg'][MANAGE_MODE] = 'std_mmode';
  $player[SPAMMING]['pmsg'][NEW_PLAYER] = 'std_hi';
  $player[SPAMMING]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[SPAMMING]['pmsg'][SUICIDE] = 'std_suicide';
  $player[SPAMMING]['message'] = 'std_message';
  $player[SPAMMING]['response'] = 'std_response';
  $player[SPAMMING]['timer'] = 'timer_inventaire';
  $player[SPAMMING]['action'] = 'action_spamming';

  $player[SINCRUSTING]['pmsg'][SUICIDE] = 'std_suicide';
  $player[SINCRUSTING]['pmsg'][ENNEMY] = 'std_sincruste';
  $player[SINCRUSTING]['pmsg'][MANAGE_MODE] = 'std_mmode';
  $player[SINCRUSTING]['pmsg'][NEW_PLAYER] = 'std_hi';
  $player[SINCRUSTING]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[SINCRUSTING]['message'] = 'std_message';
  $player[SINCRUSTING]['response'] = 'std_response';
  $player[SINCRUSTING]['timer'] = 'timer_inventaire';
  $player[SINCRUSTING]['action'] = 'action_spamming';

  $player[FARMING]['pmsg'][SUICIDE] = 'std_suicide';
  $player[FARMING]['pmsg'][MANAGE_MODE] = 'std_mmode';
  $player[FARMING]['pmsg'][NEW_PLAYER] = 'std_hi';
  $player[FARMING]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[FARMING]['message'] = 'std_message';
  $player[FARMING]['response'] = 'std_response';
  $player[FARMING]['timer'] = 'timer_trifeed';
  $player[FARMING]['action'] = 'action_farming';

  $player[FEEDING]['pmsg'][SUICIDE] = 'std_suicide';
  $player[FEEDING]['pmsg'][MANAGE_MODE] = 'std_mmode';
  $player[FEEDING]['pmsg'][NEW_PLAYER] = 'std_hi';
  $player[FEEDING]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[FEEDING]['message'] = 'std_message';
  $player[FEEDING]['response'] = 'std_response';
  $player[FEEDING]['timer'] = 'timer_trifeed';
  $player[FEEDING]['action'] = 'action_feeding';

  $player[FEEDING_LEVELING]['pmsg'][SUICIDE] = 'std_suicide';
  $player[FEEDING_LEVELING]['pmsg'][MANAGE_MODE] = 'std_mmode';
  $player[FEEDING_LEVELING]['pmsg'][NEW_PLAYER] = 'std_hi';
  $player[FEEDING_LEVELING]['pmsg'][MANAGE] = 'std_manage';
  $player[FEEDING_LEVELING]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[FEEDING_LEVELING]['message'] = 'std_message';
  $player[FEEDING_LEVELING]['response'] = 'std_response';
  $player[FEEDING_LEVELING]['timer'] = 'timer_trifeed';
  $player[FEEDING_LEVELING]['action'] = 'action_feedingl';

  $player[LEVELING]['pmsg'][SUICIDE] = 'std_suicide';
  $player[LEVELING]['pmsg'][MANAGE_MODE] = 'std_mmode';
  $player[LEVELING]['pmsg'][MANAGE] = 'std_manage';
  $player[LEVELING]['pmsg'][NEW_PLAYER] = 'std_hi';
  $player[LEVELING]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[LEVELING]['message'] = 'std_message';
  $player[LEVELING]['response'] = 'std_response';
  $player[LEVELING]['timer'] = 'timer_trifeed';
  $player[LEVELING]['action'] = 'action_leveling';

  $player[MANAGING]['pmsg'][SUICIDE] = 'std_suicide';
  $player[MANAGING]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[MANAGING]['pmsg'][NEW_PLAYER] = 'std_hi';
  $player[MANAGING]['pmsg'][INVENTORY] = 'std_inventory';
  $player[MANAGING]['message'] = 'std_message';
  $player[MANAGING]['response'] = 'std_response';
  $player[MANAGING]['timer'] = 'timer_man';
  $player[MANAGING]['action'] = 'action_manage';

  $player[CALLING]['pmsg'][SUICIDE] = 'std_suicide';
  $player[CALLING]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[CALLING]['pmsg'][ARRIVE] = 'std_arrive';
  $player[CALLING]['message'] = 'std_message';
  $player[CALLING]['response'] = 'std_response';
  $player[CALLING]['timer'] = NULL;
  $player[CALLING]['action'] = 'action_calling';

  $player[CASTING]['pmsg'][SUICIDE] = 'std_suicide';
  $player[CASTING]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[CASTING]['message'] = 'std_message';
  $player[CASTING]['response'] = 'std_response';
  $player[CASTING]['timer'] = NULL;
  $player[CASTING]['action'] = 'action_casting';

  $player[FOLLOWS]['pmsg'][SUICIDE] = 'std_suicide';
  $player[FOLLOWS]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[FOLLOWS]['pmsg'][COME] = 'std_follows';
  $player[FOLLOWS]['message'] = 'std_message';
  $player[FOLLOWS]['response'] = 'std_response';
  $player[FOLLOWS]['timer'] = 'timer_follow';
  $player[FOLLOWS]['action'] = NULL;

  $player[FOLLOWL]['pmsg'][SUICIDE] = 'std_suicide';
  $player[FOLLOWL]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[FOLLOWL]['pmsg'][COME] = 'std_followl';
  $player[FOLLOWL]['message'] = 'std_message';
  $player[FOLLOWL]['response'] = 'std_response';
  $player[FOLLOWL]['timer'] = 'timer_follow';
  $player[FOLLOWL]['action'] = NULL;

  $player[WAITING]['pmsg'][SUICIDE] = 'std_suicide';
  $player[WAITING]['pmsg'][TOTAL_PLAYER] = 'std_tplayer';
  $player[WAITING]['pmsg'][START_INCANT] = 'std_sincant';
  $player[WAITING]['message'] = 'std_message';
  $player[WAITING]['response'] = 'std_response';
  $player[WAITING]['timer'] = 'timer_wait';
  $player[WAITING]['action'] = NULL;
}

?>