<?php

function	std_manage($player, $msg)
{
  $string = strstr($msg[6], "<" . $player['pid'] . ">");
  $string = explode("-", $string);
  $len = count($string);
  for ($i = 1; $i < $len; $i++)
    {
      if ($string[$i][0] == "<")
	break;
      switch($string[$i])
	{
	case LEVELUP:
	  flush_action(&$player);
	  $player['ncoming'] = 0;
	  $player['mode'] = CALLING;
	  break ;
	case FOLLOW_STAY:
	  $i++;
	  flush_action(&$player);
	  $player['pid_follow'] = $string[$i];
	  $player["timer_follow"] = -1;
	  $player['mode'] = FOLLOWS;
	  break ;
	case FOLLOW_LEAVE:
	  $i++;
	  flush_action(&$player);
	  $player['pid_follow'] = $string[$i];
	  $player["timer_follow"] = -1;
	  $player['mode'] = FOLLOWL;
	  break ;
	case DROP:
	  $i++;
	  $player['tdrop'] = unserialize($string[$i]);
	  break ;
	case CALL:
	  $i++;
	  flush_action(&$player);
	  $player['ncoming'] = $string[$i];
	  $player['mode'] = CALLING;
	  break;
	}
    }
  if ($len)
    log_ia(&$player, NMODE, MMODE_CHANGE . $player['mode']);
}

?>