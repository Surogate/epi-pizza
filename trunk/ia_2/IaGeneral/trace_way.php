<?php

function	change_dir($player, $act, $tar)
{
  if ($act == NORD && $tar == OUEST)
    {
      array_push($player['taction'], GAUCHE);
      $act = OUEST;
    }
  if ($act == OUEST && $tar == NORD)
    {
      array_push($player['taction'], DROITE);
      $act = NORD;
    }
  else
    {
      if ($act > $tar)
	{
	  while ($act != $tar)
	    {
	      array_push($player['taction'], GAUCHE);
	      $act--;
	    }
	}
      else if ($act < $tar)
	{
	  while ($act != $tar)
	    {
	      array_push($player['taction'], DROITE);
	      $act++;
	    }
	}
    }
}

function        align_x($player, $m, $t, $bsl)
{
  while ($m['x'] != $t['x'])
    {
      if ($m['x'] > $t['x'])
        {
          change_dir(&$player, &$bsl, OUEST);
          $m['x'] -= 1;
        }
      else if ($m['x'] < $t['x'])
        {
          change_dir(&$player, &$bsl, EST);
          $m['x'] += 1;
        }
      array_push($player['taction'], AVANCE);
    }
}

function        align_y($player, $m, $t, $bsl)
{
  while ($m['y'] != $t['y'])
    {
      if ($m['y'] > $t['y'])
        { 
          change_dir(&$player, &$bsl, SUD);
          $m['y'] -= 1;
        }
      else if ($m['y'] < $t['y'])
        {
          change_dir(&$player, &$bsl, NORD);
          $m['y'] += 1;
        }
      array_push($player['taction'], AVANCE);
    }
}

function        trace_way($player, $m, $t, $bsl)
{
  align_x(&$player, &$m, $t, &$bsl);
  align_y(&$player, &$m, $t, &$bsl);
}

?>