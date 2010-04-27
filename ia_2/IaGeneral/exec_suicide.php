<?php

function	exec_suicide($player)
{
  static	$flag = true;
  $nfood = $player['nourriture'] + 10;
  
  if ($flag == false)
    return ;
  $flag = false;
  log_ia(&$player, NSUICIDE, MACTION_SUICIDE);

  flush_action(&$player);
  if ($player['mode'] == MANAGING)
    {
      foreach ($player['tmng'] as $key => $val);
      $player['tmode'][$key] = MANAGING;
      $msg = create_msg(&$player, MANAGE_MODE . " " . serialize($player['tmode']));
      array_push($player['taction'], $msg);
    }
  $msg = create_msg(&$player, SUICIDE);
  array_push($player['taction'], $msg);
  for ($i = 0; $i < $nfood; $i++)
    array_push($player['taction'], POSE . " nourriture\n");
}

?>