<?php

function        mode_manage_ponding($player, $pid)
{
  $tmp['tmode'] = array();
  $nally = count($player["tmsg"]) + 1;

  $total = (int)(($player["wmap"] + $player["hmap"]) / 2);
  $negg = $total - $nally - $player["nfork"];

  echo "[PONDEUSE = ".$player['pid']."] total = $total oeaf = " . $negg  ."\n";

  if ($negg > 0)
    {
      $tmp['tmode'][$pid] = PONDING;
      $tmp['tmode']['negg'] = $negg;
      unset($player['tmng'][$pid]);
      unset($player['tmode'][$pid]);
      $msg = create_msg(&$player, MANAGE_MODE . " ". serialize($tmp['tmode']));
      log_ia(&$player, NMANAGE, MMANAGE_PONDEUSE);
      array_unshift($player['taction'], $msg);
    }
  $player['negg'] = 1;
}

function	mode_manage($player)
{
  $tmp = $player['tmode'];
  $i = 0;  

  foreach ($player['tmode'] as $key => $val)
    {
      if ($i == 0 && $player["bpond"] = true
          && !$player['negg'] && $player['param']['fork'] != 'off')
	mode_manage_ponding(&$player, $key);
      if ($i < SEUIL_LEVELER)
	$player['tmode'][$key] = FEEDING;
      else if ($i < SEUIL_FARMER)
	{
	  unset($player['tmng'][$key]);
	  $player['tmode'][$key] = FARMING;
	}
      else if ($i < SEUIL_SPAMMEUR && $player['param']['mode'] != 'pve')
	{
	  unset($player['tmng'][$key]);
	  $player['tmode'][$key] = SPAMMING;
	}
      else if ($i < SEUIL_SINCRUSTE && $player['param']['mode'] != 'pve')
	{
	  unset($player['tmng'][$key]);
	  $player['tmode'][$key] = SINCRUSTING;
	}
      else
	$player['tmode'][$key] = SINCRUSTING;
      $i++;
    }

  if ($tmp != $player['tmode'])
    {
      log_ia(&$player, NMANAGE, MMANAGE_MODE);
      $msg = create_msg(&$player, MANAGE_MODE . " " . serialize($player['tmode']));
      array_unshift($player['taction'], $msg);
    }
}

?>