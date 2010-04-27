<?php

function		seek_empty(&$player)
{
  $view = str_replace('{', '', $player['view']);
  $view = str_replace('}', '', $view);
  $view = explode(',', $view);
  $i = 0;
  while ($view[$i] != NULL)
    {
      if (test_matches($view[$i]) == 0)
	return ($i);
      $i++;
    }
  if ($view[$player['reach']] == NULL)
    return ($i - 1);
}

function		test_matches($view)
{
  $flag = 0;
  if (preg_match("/linemate/i", $view) == 1)
    $flag = 1;
  if (preg_match("/deraumere/i", $view) == 1)
    $flag = 1;
  if (preg_match("/sibur/i", $view) == 1)
    $flag = 1;
  if (preg_match("/mendiane/i", $view) == 1)
    $flag = 1;
  if (preg_match("/phiras/i", $view) == 1)
    $flag = 1;
  if (preg_match("/thystame/i", $view) == 1)
    $flag = 1;

  return ($flag);
}

?>