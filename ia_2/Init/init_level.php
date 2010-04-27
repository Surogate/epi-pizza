<?php

function	generate_level($tlevel, $nlineate,
			   $nderaumere, $nsibur,
			   $nmendiane, $nphiras,
			   $nthystame, $njoueur)
{
  $tlevel["linemate"] = $nlineate;
  $tlevel["deraumere"] = $nderaumere;
  $tlevel["sibur"] = $nsibur;
  $tlevel["mendiane"] = $nmendiane;
  $tlevel["phiras"] = $nphiras;
  $tlevel["thystame"] = $nthystame;
  $tlevel["joueur"] = $njoueur;
}

function	init_level($player)
{
  $player['tlevel'] = array();
  $player['glevel'] = array();

  generate_level(&$player['tlevel'][0], 9999, 9999, 9999, 9999, 9999, 9999, 9999);
  generate_level(&$player['tlevel'][1], 1, 0, 0, 0, 0, 0, 1);
  generate_level(&$player['tlevel'][2], 1, 1, 1, 0, 0, 0, 2);
  generate_level(&$player['tlevel'][3], 2, 0, 1, 0, 2, 0, 2);
  generate_level(&$player['tlevel'][4], 1, 1, 2, 0, 1, 0, 4);
  generate_level(&$player['tlevel'][5], 1, 2, 1, 3, 0, 0, 4);
  generate_level(&$player['tlevel'][6], 1, 2, 3, 0, 1, 0, 6);
  generate_level(&$player['tlevel'][7], 2, 2, 2, 2, 2, 1, 6);

  generate_level(&$player['glevel'][0], 9999, 9999, 9999, 9999, 9999, 9999, 9999);
  generate_level(&$player['glevel'][1], 9, 8, 10, 5, 6, 1, 1);
  generate_level(&$player['glevel'][2], 8, 8, 10, 5, 6, 1, 2);
  generate_level(&$player['glevel'][3], 7, 7, 9, 5, 6, 1, 2);
  generate_level(&$player['glevel'][4], 5, 7, 8, 5, 4, 1, 4);
  generate_level(&$player['glevel'][5], 4, 6, 6, 5, 3, 1, 4);
  generate_level(&$player['glevel'][6], 3, 4, 5, 2, 3, 1, 6);
  generate_level(&$player['glevel'][7], 2, 2, 2, 2, 2, 1, 6);

  $player['level'] = 1;
}

?>