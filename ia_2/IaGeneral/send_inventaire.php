<?php

function        send_inventaire($player)
{
  $tinv = array();
  
  $msg = create_msg(&$player, INVENTORY .
                    " nourriture-" . $player["nourriture"] .
                    "-linemate-" .  $player["linemate"] .
                    "-deraumere-" .  $player["deraumere"] .
                    "-sibur-" .  $player["sibur"] .
                    "-mendiane-" .  $player["mendiane"] .
                    "-phiras-" .  $player["phiras"] .
                    "-thystame-" .  $player["thystame"]);
  array_push($player['taction'], $msg);
}

?>