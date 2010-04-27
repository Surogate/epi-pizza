<?php

function	gere_voir($player, $socket, $string)
{
  $player['voir'] = true;
  $string =  trim(substr($string, 1, strlen($string)-2));
  $tstr = explode(",", $string);
  $size = sizeof($tstr);
  for ($i = 0; $i < $size; $i++)
    $player["map"][$i] = trim($tstr[$i]);
  array_shift($player["naction"]);
}

?>