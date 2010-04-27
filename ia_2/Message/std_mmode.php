<?php

function	std_mmode($player, $msg)
{
  $tmode = unserialize($msg[6]);

  if ($tmode[$player['pid']] == PONDING)
    {
      $player['negg'] = $tmode['negg'];
      echo "[PONDEUSE] le pondeu a recu le message " . $player['negg']."!\n";
      $player["mode"] = PONDING;
      return ;
    }

  if ($tmode[$player['pid']] == MANAGING)
    {
      $player['tmode'] = $tmode;
      return ;
    }  
  if (!$tmode[$player['pid']])
    return ;
  if ($tmode[$player['pid']] == FARMING)
    $player["level"] = 0;
  if (!(($player["mode"] == FEEDING ||
	 $player["mode"] == FEEDING_LEVELING ||
	 $player["mode"] == LEVELING) && $tmode[$player['pid']] == FEEDING))
    $player["mode"] = $tmode[$player['pid']];

  log_ia(&$player, NMODE, MMODE_CHANGE . $player['mode']);

}

?>