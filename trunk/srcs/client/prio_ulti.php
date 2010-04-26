<?php
require_once 'check_onme.php';
require_once 'analyse.php';

function		get_array()
{
  $pfunc = array(
		 'check_lowlife',
		 'exec_seeklife',
		 'check_listen',
		 'exec_join',
		 'check_stone',
		 'exec_seekstone',
		 'check_engplayer',
		 'exec_call',
		 'exec_fork'
		 );

  return ($pfunc);
}

function		check_lowlife(&$player)
{
  if ($player['food'] < 10 || $player['seeking'] == 1)
    return (1);
  else
    return (2);
}

function		exec_seeklife(&$player)
{
  echo "EXEC_SEEKLIFE\n";
  $player['seeking'] = 1;
  if ($player['food'] >= 20)
    $player['seeking'] = 0;
  search_food(&$player);
  get_there(&$player);
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
  echo "EXEC_JOIN\n";
  $player['reach'] = $player['CFbroad'];
  get_there(&$player);
  return ('X');
}

function		check_stone(&$player)
{
  $player['object'] = NULL;
  to_search(&$player);
  if ($player['object'] != NULL)
    return (5);
  else
    return (6);
}

function		exec_seekstone(&$player)
{
  echo "EXEC_SEEKSTONE\n";
  get_there(&$player);
  return ('X');
}

function		check_engplayer(&$player)
{
  if ($player['connected'] == 0)
    {
      if (check_onme(&$player) == 1)
	return (7);
    }
  return (8);
}

function		exec_call(&$player)
{
  echo "EXEC_CALL\n";
  /*ici on broadcast un message a la con style*/
  /*"<!--seek " . $player['level'] . "-->"*/
  return ('X');
}

function		exec_fork(&$player)
{
  echo "EXEC_FORK\n";
  /*aller on fork mes cocos*/
  return ('X');
}

function		find_prio(&$player)
{
  $pfunc = get_array();
  $value = 0;
  do {
    $value = $pfunc[$value](&$player);
  } while ($value != 'X');
  echo "\n*****END FIND PRIO*****\n";
}
?>