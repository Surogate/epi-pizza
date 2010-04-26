B1;2202;0cB1;2202;0c<?php

$pfunc = array(
    'check_low_life',
    'check_stones',
    'seek_stones',
    'listen_to_player',
    'call_player',
    'check_life',
    'seek_food',
    'pl_fork',
    'go_near_player',
    'wait_for_player',
    'prepare_fork',
    'check_inv'
	       );

function		check_inv(&$player)
{
	routine(&$player);
}

function		check_low_life($play_info)
{
  echo "CHECK_LOW_LIFE\n";
  if ($player['food'] > 10)
    return (1);
  else
    return (6);
}

function		check_stones(&$player)
{
  echo "CHECK_STONES\n";
  if ($player['go_next_lvl'] == 1)
    return (3);
  else
    return (2);
}

function		seek_stones(&$player)
{
	to_search(&$player);
	get_there(&$player);
	fifo_in(&$player, "prend " . $player['objet'] . "\n");
	return (11);
}

function		listen_to_player(&$player)
{
	/*Broadcaster
  $play_info[0] -= 7;
  echo "LISTEN_TO_PLAYER\n";
  if (1)
    return (8);
  else
    return (4);
    * */
}

function		call_player(&$player)
{
  echo "CALL_PLAYER\n";
  $play_info[0] -= 7;
  if (rand(0, 4) == 1)
    return (10);
  else
    return (11);
}

function		check_life(&$player)
{
  echo "CHECK_LIFE\n";
  if ($player['food'] > 20)
    return (11);
  else
    return (6);
}

function		seek_food(&$player)
{
  search_food(&$player);	
  get_there(&$player);
  fifo_in(&$player, "prend " . $player['objet'] . "\n");
  echo "\033[31mSEEK_FOOD\033[m\n";
  return (5);
}

function		prepare_fork(&$player)
{
  echo "PREPARE_FORK\n";
  if ($play_info[0] > 200)
    return (7);
  else
    return (6);
}

function		pl_fork(&$player)
{
  $play_info[0] -= 42;
  echo "PL_FORK\n";
  return (11);
}

function		go_near_player(&$player)
{
  $play_info[0] -= 7;
  echo "GO_NEAR_PLAYER\n";
  return (11);
}

function		wait_for_player(&$player)
{
  $play_info[0] -= 7;
  echo "WAIT_FOR_PLAYER\n";
  return (11);
}

function		call_func($pfunc, &$player)
{
  $cycle = 0;
  $value = 0;
  do {
    $cycle++;
    echo "Vie du joueur -> " . $player['food'] . "\n";
    $value = $pfunc[$value](&$player);
    if ($player['food'] <= 0)
      break ;
  } while (1);
  echo "LE JOUEUR EST MORT au cycle -> " . $cycle . "\n";
}
?>
