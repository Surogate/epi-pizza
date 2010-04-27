<?php

function	mode_appeal($player, $socket)
{
  if ($player['voir'] == true)
    check_appeal(&$player, &$socket);
  else
    {
    array_push($player["action"], VOIR);
    }
}

?>