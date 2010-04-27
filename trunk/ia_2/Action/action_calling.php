<?php

function	clean_case($player)
{
  if ($player['tmap'][0])
    {
      $rsr = explode(" ", $player['tmap'][0]);
      $tlen = count($rsr);
      for ($j = 0; $j < $tlen; $j++)
	{
	  if ($rsr[$j] != "joueur"/* && $rsr[$j] != "nourriture"*/)
	    array_push($player['taction'], PREND . " " . $rsr[$j] . "\n");
	}
    }
}

function	drop_rsr($player)
{
  foreach($player['tdrop'] as $key => $val)
    {
      while ($val > 0)
	{
	  array_push($player['taction'], POSE . " $key\n");
	  $val--;
	}
    }
}

function        action_calling($player, $socket, $string)
{
  static $bfirst = true;

  if ($bfirst == true)
    {
      if (!$player['tmap'])
	array_push($player['taction'], VOIR);
      else
	{
	  array_push($player['taction'], EXPULSE);
	  clean_case(&$player);
	  unset($player['tmap']);
	  $bfirst = false;
	}
    }
  else
    {
      if ($player['ncoming'] != 0)
	{
	  $msg = create_msg(&$player, COME);
	  array_push(&$player['taction'], $msg);
	  array_push(&$player['taction'], VOIR);
	  array_push(&$player['taction'], VOIR);
	  log_ia(&$player, NNOTICE, MNOTICE_APPEAL);
	}
      else
	{
	  unset($player['tmap']);
	  $bfirst = true;
	  drop_rsr(&$player);
	  log_ia(&$player, NMODE, MMODE_CHANGE . CASTING);
	  $player['mode'] = CASTING;
	}
    }
}

?>