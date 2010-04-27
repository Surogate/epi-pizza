<?php

function	fill_tab_manage($player, $msg)
{
  $tmp = explode("-", $msg[6]);

  $len = count($tmp);
  for ($i = 0; $i < $len; $i += 2)
    $player['tmng'][$msg[2]][$tmp[$i]] = $tmp[$i+1];
  $player['tmng'][$msg[2]]['level'] = $msg[4];
  $player['tmng'][$msg[2]]['timer'] = $player['timer'];
  $player['ttempo'][$msg[2]] = $player['timer'];
  if (!$player['tmode'][$msg[2]])
    $player['tmode'][$msg[2]] = -1;
}

function	epur_tab_manage($player, $msg)
{
  $ftl = nb_food_to_level(&$player);

  foreach ($player['tmng'] as $key => $val)
    {
      $food = $val['nourriture'] - round(($player['timer'] - $val['timer']) / TIME_ONE_FOOD);
      if ($food < $ftl)
	unset($player['tmng'][$key]);
    }
}

function	exept_level1($player, $response)
{
  $max_level = 1;

  foreach ($player['tmng'] as $key => $val)
    {
      if ($val['level'] == 1 && $val['linemate'] > 0)
	{
	  $tdrop = $player['tlevel'][$val['level']];
	  unset($tdrop['joueur']);
	  $response .= "<" . $key .">-" . LEVELUP . "-" . DROP . "-" . serialize($tdrop) . "-";
	  unset($player['tmng'][$key]);
	}
      if ($val['level'] > $max_level)
	$max_level = $val['level'];
    }
  return ($max_level);
}

function	nb_joueur_requis($player, $lvl)
{
  $cpt = 0;
  foreach ($player['tmng'] as $key => $val)
    {
      if ($val['level'] == $lvl)
	$cpt++;
    }
  echo $cpt . "---> " . $player['tlevel'][$lvl]['joueur'] . "\n";

  if ($cpt >= $player['tlevel'][$lvl]['joueur'])
    return (true);
  return (false);
}

function	nb_ressource_requis($player, $lvl)
{
  $tneed = $player['tlevel'][$lvl];
  unset($tneed['joueur']);

  foreach ($player['tmng'] as $key => $val)
    {
      foreach ($val as $rsr => $nrsr)
	{
	  if ($tneed[$rsr] && $tneed[$rsr] > 0)
	    $tneed[$rsr] -= $nrsr;
	  if ($tneed[$rsr] <= 0)
	    unset($tneed[$rsr]);
	}
      if (!$tneed)
	return (true);
    }
  return (false);
}

function	manage_nextplayer($player, $lvl, $tneed)
{
  $bscore = 0;
  $pid = 0;

  foreach ($player['tmng'] as $key => $val)
    {
      $score = 0;
      if ($val['level'] == $lvl)
	$score += 10000;
      if ($val['level'] < $lvl)
	$score += 5000;
      foreach ($val as $rsr => $nrsr)
        {
	  if ($tneed[$rsr] && $tneed[$rsr] > 0)
	    {
	      if ($nrsr > $tneed[$rsr])
		$score += ($tneed[$rsr] * 10) - $val['level'];
	      else
		$score += ($nrsr * 10) - $val['level'];
	    }
	}
      if ($score > $bscore && $score != 5000)
	{
	  $pid = $key;
	  $bscore = $score;
	}
    }
  if ($pid == 0)
    return (false);
  $tplayer = $player['tmng'][$pid];
  $tplayer['pid'] = $pid;
  unset($player['tmng'][$pid]);
  return ($tplayer);
}

function	init_drop()
{
  $tdrop = array();

  $tdrop['linemate'] = 0;
  $tdrop['deraumere'] = 0;
  $tdrop['sibur'] = 0;
  $tdrop['mendiane'] = 0;
  $tdrop['phiras'] = 0;
  $tdrop['thystame'] = 0;
  return ($tdrop);
}

function	manage_action($player, $response, $lvl)
{
  $tneed = $player['tlevel'][$lvl];
  $nplayer = $player['tlevel'][$lvl]['joueur'];
  $cpt = 0;
  $nb_wait = 0;
  $caller['nb_wait'] = 0;

  while ($tplayer = manage_nextplayer(&$player, $lvl, $tneed))
    {
      $tdrop = init_drop();

      if (!$tneed && $cpt >= $nplayer)
	break ;
      if (!$tneed)
	{
	  if ($tplayer['level'] == $lvl)
	    $response .= "<" . $tplayer['pid'] . ">-" .
	      FOLLOW_STAY . "-" . $caller['pid'] . "-" .
	      DROP . "-" . serialize($tdrop) . "-";
	  $caller['nb_wait'] += 1;
	  $cpy++;
	  continue ;
	}

      foreach ($tplayer as $rsr => $nrsr)
        {
	  if ($tneed[$rsr] && $tneed[$rsr] > 0)
            {
	      if ($nrsr > $tneed[$rsr])
		{
		  $tdrop[$rsr] = $tneed[$rsr];
		  $tneed[$rsr] = 0;
		}
              else
		{
		  $tdrop[$rsr] = $nrsr;
		  $tneed[$rsr] -= $nrsr;
		}
	      if ($tneed[$rsr] <= 0)
		unset($tneed[$rsr]);
	    }
	}

      if ($tplayer['level'] == $lvl && $cpt < $nplayer)
	{
	  if ($cpt == 0)
	    {
	      $caller['pid'] = $tplayer['pid'];
	      $caller['drop'] = $tdrop;
	      $caller['nb_wait'] = 0;
	    }
	  else
	    {
	      $response .= "<" . $tplayer['pid'] . ">-" .
		FOLLOW_STAY . "-" . $caller['pid'] . "-" .
		DROP. "-" . serialize($tdrop) . "-";
	      $caller['nb_wait'] += 1;
	    }
	  $cpt++;
	}
      else
	{
	  $response .= "<" . $tplayer['pid'] . ">-" .
	    FOLLOW_LEAVE . "-" . $caller['pid'] . "-" .
	    DROP . "-" . serialize($tdrop) . "-";
	  $caller['nb_wait'] += 1;
	}
    }

  $response .= "<" . $caller['pid'] . ">-" .
    CALL . "-" . $caller['nb_wait'] . "-" .
    DROP . "-" . serialize($caller['drop']) . "-";
}

function	parse_tab_manage($player, $response)
{
  $max_level =  exept_level1(&$player, &$response);

  echo 'max level = ' . $max_level . "\n";

  /* for ($lvl = $max_level; $lvl > 1; $lvl--) */
  for ($lvl = 1; $lvl <= $max_level; $lvl++)
    {
      if (nb_joueur_requis(&$player, $lvl) == false)
	continue ;
      if (nb_ressource_requis(&$player, $lvl) == false)
	continue ;
      manage_action(&$player, &$response, $lvl);
    }
}

function	std_inventory($player, $msg)
{
  $response = create_msg(&$player, MANAGE);

  $response[strlen($response) - 1] = " ";
  $reponse_empty = $response;

  if ($player['ttempo'][$msg[2]] && 
      ($player['timer'] - $player['ttempo'][$msg[2]]) < DELAY_MANAGE_INV)
    return ;
  
  fill_tab_manage(&$player, &$msg);
  if ($player['nourriture'] < MIN_MANAGE_FOOD)
    return ;
  if ($player['param']['mode'] != 'pve')
    mode_manage(&$player);
  epur_tab_manage(&$player, &$msg);
  parse_tab_manage(&$player, &$response);

  print_r($player['tmng']);

  if (!($reponse_empty == $response))
    {
      $response .= "\n";
      log_ia(&$player, NMANAGE, MMANAGE_ORDER . $response);
      array_unshift($player['taction'], $response);
    }

}

?>