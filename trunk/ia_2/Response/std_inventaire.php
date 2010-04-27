<?php

function	std_inventaire($player, $socket, $string)
{
  array_shift($player["tresolve"]);
  log_ia(&$player, NACTION, MACTION_OK . "inventaire");
  $string =  trim(substr($string, 1, strlen($string)-2));
  $tmp = explode(",", $string);
  $len = count($tmp);
  for ($i = 0; $i < $len; $i++)
    {
      preg_match_all("#([a-z]+) +([0-9]+)#" , $tmp[$i], $reg);
      $player[$reg[1][0]] = $reg[2][0];
    }
  $player["inv"] = true;
}

?>