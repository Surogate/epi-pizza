<?php

function	find_coordonate($tfloor, $n)
{
  $t['y'] = $tfloor[$n];
  $t['x'] = -$t['y'] +
    ($n - ((($t['y']-1)*($t['y']-1) + 2*($t['y']-1) + 1)));
  return ($t);
}

function        create_way($player, $socket, $tneed)
{
  static	$fi = 0;

  $len = sizeof($player["tmap"]);
  $nlen = sizeof($tneed);
  $m = array();
  $flag = false;

  $m['x'] = 0;
  $m['y'] = 0;
  $bsl = NORD;
  for ($i = 0; $i < $len; $i++)
    {
      for ($j = 0; $j < $nlen; $j++)
	{
	  if ((strstr($player["tmap"][$i], $tneed[$j])
	      && !strstr($player["tmap"][$i], 'joueur')) ||
	      ($tneed[$j] == 'nourriture'
	       && strstr($player["tmap"][$i], $tneed[$j])))
	    {
	      $t = find_coordonate($player['tfloor'], $i);
	      trace_way(&$player, &$m, $t, &$bsl);
	      $nneed = count(explode($tneed[$j] , $player["tmap"][$i])) - 1;
	      if ($nneed > (nb_food_to_level(&$player) / 2))
		$nneed = nb_food_to_level(&$player) / 2;
	      for ($k = 0; $k < $nneed; $k++)
		array_push($player['taction'], PREND . " " . $tneed[$j] . "\n");
	      $flag = true;
	      $fi = 0;
	    }
	}
    }
  unset($player["tmap"]);
  if ($flag == false)
    {
      $fi++;
      if ($fi < (int)(($player["wmap"] + $player["hmap"]) / 2) - 1)
	array_push($player['taction'], AVANCE);
      else
	{
	  array_push($player['taction'], GAUCHE);
	  $fi = 0;
	}
    }
}

?>
