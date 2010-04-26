<?php

require_once 'search_food.php';
require_once 'main_loop.php';
require_once 'routine.php';
require_once 'move.php';

function	get_pfunc()
{
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
return ($pfunc);
}

function		check_inv(&$player)  /*11*/
{
	routine(&$player);
}

function		check_low_life($play_info) /*0*/
{
  echo "CHECK_LOW_LIFE\n";
  if ($player['food'] > 10)
    return (1);
  else
    return (6);
}

function		check_stones(&$player) /*1*/
{
  echo "CHECK_STONES\n";
  if ($player['go_next_lvl'] == 1)
    return (3);
  else
    return (2);
}

function		seek_stones(&$player)  /*2*/
{
	to_search(&$player);
	get_there(&$player);
	fifo_in(&$player, "prend " . $player['objet']);
	echo "\033[31mSEEK_STONE\033[m\n";
	main_loop(&$player);
	return (11);
}

function		listen_to_player(&$player) /*3*/
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

function		call_player(&$player) /*4*/
{
  echo "CALL_PLAYER\n";
  $play_info[0] -= 7;
  if (rand(0, 4) == 1)
    return (10);
  else
    return (11);
}

function		check_life(&$player) /*5*/
{
  echo "CHECK_LIFE: food = " . $player['food'] . "\n";
  if ($player['food'] > 20)
    while(1);/*return (11);*/
  else
	{
		routine(&$player);
		$player['next_func'] = 6;
		main_loop(&$player);
	}
    /*return (6);*/
}

function		seek_food(&$player) /*6*/
{
  search_food(&$player);
  get_there(&$player);
  if ($player['objet'] != NULL)
	fifo_in(&$player, "prend " . $player['objet']);
  echo "\033[31mSEEK_FOOD\033[m\n";
  $player['next_func'] = 5;
  echo "GO main_loop\n";
  echo "smg to send = " . $player['send'][0] . "\n";
  main_loop(&$player);
  /*return (5);*/
}

function		prepare_fork(&$player) /*10*/
{
  echo "PREPARE_FORK\n";
  if ($play_info[0] > 200)
    return (7);
  else
    return (6);
}

function		pl_fork(&$player) /*7*/
{
  $play_info[0] -= 42;
  echo "PL_FORK\n";
  return (11);
}

function		go_near_player(&$player) /*8*/
{
  $play_info[0] -= 7;
  echo "GO_NEAR_PLAYER\n";
  return (11);
}

function		wait_for_player(&$player) /*9*/
{
  $play_info[0] -= 7;
  echo "WAIT_FOR_PLAYER\n";
  return (11);
}

function		call_func($value, &$player)
{
  $cycle = 0;
  $pfunc = get_pfunc();
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
