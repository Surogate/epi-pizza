<?php

function	find_coordonate($tfloor, $n)
{
  $t['y'] = $tfloor[$n];
  $t['x'] = -$t['y'] +
    ($n - ((($t['y']-1)*($t['y']-1) + 2*($t['y']-1) + 1)));
  return ($t);
}

function	count_need($line, $need)
{
  $i = 0;
  $buffer = $need;
  while ($buffer = strstr($buffer, $need))
    {
      $buffer[0] = '0';
      $i++;
    }
  return ($i);
}

function        create_way($player, $socket, $tneed)
{
  $len = sizeof($player["map"]);
  $nlen = sizeof($tneed);
  $m = array();
  $flag = false;

  /*print_r($player["map"]);
  print_r($tneed);*/
  $m['x'] = 0;
  $m['y'] = 0;
  $bsl = NORD;
  for ($i = 0; $i < $len; $i++)
    {
      for ($j = 0; $j < $nlen; $j++)
	{
	  if (strstr($player["map"][$i], $tneed[$j]))
	    {
	      $t = find_coordonate($player['tfloor'], $i);
	      trace_way(&$player, &$m, $t, &$bsl);
	      $nneed = count_need($player["map"][$i], $tneed[$j]);
	      for ($k = 0; $k < $nneed; $k++)
		array_push($player['action'], PREND . " " . $tneed[$j] . "\n");
	      $player[$tneed[$j]] += 1;
	      $flag = true;
	    }
	}
    }
  $player['voir'] = false;
  unset($player["map"]);
  if ($flag == false)
    array_push($player['action'], AVANCE);
}


?>
