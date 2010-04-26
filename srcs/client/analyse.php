<?php
require_once 'elevation.php';

function	fill_rocks()
{
  $rocks[0] = 'linemate';
  $rocks[1] = 'deraumere';
  $rocks[2] = 'sibur';
  $rocks[3] = 'mendiane';
  $rocks[4] = 'phiras';
  $rocks[5] = 'thystame';
  
  return ($rocks);
}

function	seek_needs($lvl, $tab_inv)
{
  if ($tab_inv['nourriture'] < 600)
    $need = 'nourriture';
  else if ($lvl[$pers_skill + 1]['linemate'] - $tab_inv['linemate'] > 0)
    $need = 'linemate';
  else if ($lvl[$pers_skill + 1]['deraumere'] - $tab_inv['deraumere'] > 0)
    $need = 'deraumere';
  else if ($lvl[$pers_skill + 1]['sibur'] - $tab_inv['sibur'] > 0)
    $need = 'sibur';
  else if ($lvl[$pers_skill + 1]['mendiane'] - $tab_inv['mendiane'] > 0)
    $need = 'mendiane';
  else if ($lvl[$pers_skill + 1]['phiras'] - $tab_inv['phiras'] > 0)
    $need = 'phiras';
  else if ($lvl[$pers_skill + 1]['thystame'] - $tab_inv['thystame'] > 0)
    $need = 'thystame';
  else
    $need = 'elevation';

  return $need;
}

function	prepare_inv($inv_base)
{
  $inv = $inv_base;
  $inv = str_replace('{', '', $inv);
  $inv = str_replace('}', '', $inv);
  $inv = explode(", ", $inv);

  return ($inv);
}

function	to_search(&$player)
{
  global $lvl;
  
  $rocks = fill_rocks();
  $pers_skill = $player['level'];
  $inv = prepare_inv($player['inv']);
  $i = 0;
  while ($i < 7)
    {
      $tmp = explode(' ', $inv[$i]);
      $tab_inv[$tmp[0]] = $tmp[1];
      $i++;
    }  
  $need = seek_needs($lvl, $tab_inv);
  $view = $player['view'];
  $view = str_replace('{', '', $view);
  $view = str_replace('}', '', $view);
  $view = explode(", ", $view);
  $i = 0;
  while (preg_match("/" . $need . "/i", $view[$i]) == 0 && $view[$i] != NULL)
    $i++;
  $player['reach'] = $i;
  $player['objet'] = $need;
}
?>
