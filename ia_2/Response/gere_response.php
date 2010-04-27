<?php

require_once("gere_ok.php");
require_once("gere_ko.php");
require_once("gere_message.php");
require_once("gere_deplacement.php");
require_once("gere_mort.php");
require_once("gere_voir.php");
require_once("gere_inventaire.php");
require_once("gere_fork.php");

function	gere_response($player, $socket, $string)
{
  $tstr = explode(" ", $string);

  /*echo "string = [$string]\n";*/

  if ($tstr[0] == OK)
    gere_ok(&$player, $socket, $string);
  else if ($tstr[0] == KO)
    gere_ko(&$player, $socket, $string);
  else if ($tstr[0] == MESSAGE)
    gere_message(&$player, $socket, $string);
  else if ($tstr[0] == DEPLACEMENT)
    gere_deplacement(&$player, $socket, $string);
  else if ($tstr[0] == MORT)
    gere_mort(&$player, $socket, $string);
  else if (ereg(PATTERN_VOIR, $string))
    gere_voir(&$player, $socket, $string);
  else if (ereg(PATTERN_INVENTAIRE, $string))
    gere_inventaire(&$player, $socket, $string);
  else if (is_numeric($string) == true)
    gere_fork(&$player, &$socket, $string);
  else
    echo "message unknown\n";
}

?>