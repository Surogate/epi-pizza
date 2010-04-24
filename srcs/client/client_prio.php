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

function		check_inv($play_info)
{
  echo "CHECK_INVENTORY\n";
  return (0);
}

function		check_low_life($play_info)
{
  echo "CHECK_LOW_LIFE\n";
  if ($play_info[0] > 300)
    return (1);
  else
    return (6);
}

function		check_stones($play_info)
{
  $play_info[0] -= 1;
  echo "CHECK_STONES\n";
  if ($play_info[1] == 1)
    return (3);
  else
    return (2);
}

function		seek_stones($play_info)
{
  if (rand(0, 50) == 1)
    $play_info[1] = 1;
  $play_info[0] -= 7;
  echo "SEEK_STONES\n";
  return (11);
}

function		listen_to_player($play_info)
{
  $play_info[0] -= 7;
  echo "LISTEN_TO_PLAYER\n";
  if (1)
    return (8);
  else
    return (4);
}

function		call_player($play_info)
{
  echo "CALL_PLAYER\n";
  $play_info[0] -= 7;
  if (rand(0, 4) == 1)
    return (10);
  else
    return (11);
}

function		check_life($play_info)
{
  echo "CHECK_LIFE\n";
  if ($play_info[0] > 600)
    return (11);
  else
    return (6);
}

function		seek_food($play_info)
{
  $play_info[0] -= 7;
  if (rand(0, 5) == 1)
    $play_info[0] += 126;
  echo "\033[31mSEEK_FOOD\033[m\n";
  return (5);
}

function		prepare_fork($play_info)
{
  echo "PREPARE_FORK\n";
  if ($play_info[0] > 200)
    return (7);
  else
    return (6);
}

function		pl_fork($play_info)
{
  $play_info[0] -= 42;
  echo "PL_FORK\n";
  return (11);
}

function		go_near_player($play_info)
{
  $play_info[0] -= 7;
  echo "GO_NEAR_PLAYER\n";
  return (11);
}

function		wait_for_player($play_info)
{
  $play_info[0] -= 7;
  echo "WAIT_FOR_PLAYER\n";
  return (11);
}

function		call_func($pfunc)
{
  $cycle = 0;
  $value = 11;
  $play_info[0] = 1260;
  $play_info[1] = 0;
  do {
    $cycle++;
    echo "Vie du joueur -> " . $play_info[0] . "\n";
    $value = $pfunc[$value](&$play_info);
    if ($play_info[0] <= 0)
      break ;
  } while (1);
  echo "LE JOUEUR EST MORT au cycle -> " . $cycle . "\n";
}

call_func($pfunc);

?>