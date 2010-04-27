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

function	seek_needs($lvl, $tab_inv, &$player)
{
  if (($lvl[$player['level'] + 1]['linemate'] - $tab_inv['linemate']) > 0)
    $need = 'linemate';
  else if (($lvl[$player['level'] + 1]['deraumere'] - $tab_inv['deraumere']) > 0)
    $need = 'deraumere';
  else if (($lvl[$player['level'] + 1]['sibur'] - $tab_inv['sibur']) > 0)
    $need = 'sibur';
  else if (($lvl[$player['level'] + 1]['mendiane'] - $tab_inv['mendiane']) > 0)
    $need = 'mendiane';
  else if (($lvl[$player['level'] + 1]['phiras'] - $tab_inv['phiras']) > 0)
    $need = 'phiras';
  else if (($lvl[$player['level'] + 1]['thystame'] - $tab_inv['thystame']) > 0)
    $need = 'thystame';
  else
    $need = -1;
  echo "VALEUR DE NEED -----> " . $need . "\n";
  return $need;
}

function	prepare_inv($inv_base)
{
  $inv = $inv_base;
  $inv = str_replace('{', '', $inv);
  $inv = str_replace('}', '', $inv);
  $inv = explode(",", $inv);
  return ($inv);
}

function	to_search(&$player)
{
  global $lvl;
  
  $rocks = fill_rocks();
  $inv = prepare_inv($player['inv']);
  $i = 0;
  while ($i < 7)
    {
      $tmp = explode(' ', $inv[$i]);
      $tab_inv[$tmp[0]] = $tmp[1];
      $i++;
    }  
  $need = seek_needs($lvl, $tab_inv, &$player);
  $view = $player['view'];
  $view = str_replace('{', '', $view);
  $view = str_replace('}', '', $view);
  $view = explode(",", $view);
  $i = 0;
  while (preg_match("/" . $need . "/i", $view[$i]) == 0 && $view[$i] != NULL)
    $i++;
  if ((preg_match("/" . $need . "/i", $view[$i]) == 1) || ($need == -1))
    {
      $player['reach'] = $i;
      $player['objet'] = $need;
    }
  else
    {
      $player['reach'] = 2 * $player['level'];
      $player['objet'] = NULL;
    }
}
?>
