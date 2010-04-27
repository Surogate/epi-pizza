<?php

require_once 'check_onme.php';
require_once 'analyse.php';
require_once 'search_food.php';
require_once 'main_loop.php';
require_once 'routine.php';
require_once 'move.php';
require_once 'get_food.php';
require_once 'drop_stones.php';
require_once 'test_matches.php';


function		get_array()
{
  $pfunc = array(
		 'check_lowlife',
		 'exec_seeklife',
		 'check_listen',
		 'exec_join',
		 'check_stones',
		 'exec_seekstone',
		 'check_engplayer',
		 'exec_call',
		 'exec_fork',
		 'exec_incant'
		 );

  return ($pfunc);
}

function		check_lowlife(&$player)
{
  if ($player['food'] < 1)
    exit ("Plus de vie, vous etes mort\n");
  get_food(&$player);
  if ($player['food'] <= 30)/* || $player['seeking'] == 1)*/
    return (1);
  else
    return (2);
}

function		exec_seeklife(&$player)
{
  if ($player['food'] >= 30)
    return (4);
  search_food(&$player);
  get_there(&$player);
  if ($player['objet'] != NULL)
    fifo_in(&$player, "prend nourriture\n");
  return ('X');
}

function		check_listen(&$player)
{
  if ($player['broad'] == "<!--seek " . $player['level'] . "-->")
    return (3);
  else
    return (4);
}

function		exec_join(&$player)
{
  $player['reach'] = $player['CFbroad'];
  get_there(&$player);
  return ('X');
}

function		check_stones(&$player)
{
  to_search(&$player);
  if ($player['objet'] != -1)
    return (5);
  else
    return (6);
}

function		exec_seekstone(&$player)
{
  get_there(&$player);
  if ($player['objet'] != NULL)
    fifo_in(&$player, "prend " . $player['objet'] . "\n");
  return ('X');
}

function		check_engplayer(&$player)
{
  if ($player['connected'] == 0)
    {
      if (check_onme(&$player) == 1)
	return (9);
      else
	return (7);
    }
  return (8);
}

function		exec_call(&$player)
{
  routine(&$player);
  //ici on broadcast un message a la con style
  //"<!--seek " . $player['level'] . "-->"
  return ('X');
}

function		exec_fork(&$player)
{
  echo "EXEC_FORK\n";
  fifo_in(&$player, "fork\n");
  return ('X');
}

function		exec_incant(&$player)
{
  $player['reach'] = seek_empty(&$player);
  if ($player['reach'] == 0)
    {
      drop_stones(&$player);
      fifo_in(&$player, "incantation\n");
    }
  else
    get_there(&$player); 
  return ('X');
}

function		find_prio(&$player)
{
  $pfunc = get_array();
  $value = 0;
  do {
    $value = $pfunc[$value](&$player);
  } while ($value != 'X');
  routine(&$player);
}
?>
