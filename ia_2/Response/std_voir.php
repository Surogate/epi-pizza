<?php

function	std_voir($player, $socket, $string)
{
  array_shift($player["tresolve"]);

  log_ia(&$player, NACTION, MACTION_OK . "voir");
  $string =  trim(substr($string, 1, strlen($string)-2));
  $tstr = explode(",", $string);
  $size = sizeof($tstr);
  for ($i = 0; $i < $size; $i++)
    $player["tmap"][$i] = trim($tstr[$i]);
}

?>