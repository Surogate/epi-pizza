<?php

function	nb_food_to_level($player)
{
  static $min_food_to_level = 0;

  if ($min_food_to_level == 0)
    $min_food_to_level =
      ((($player["wmap"] * $player["hmap"] * 2) * 7) + TIME_INCANT + DELAY_INCANT) / TIME_ONE_FOOD;

  if ($min_food_to_level > MAX_FOOD)
    return (MAX_FOOD);
  return ((int)$min_food_to_level);
}

function        food_to_level($player)
{
  static $min_food_to_level = 0;

  if ($min_food_to_level == 0)
    $min_food_to_level =
      (($player["wmap"] * $player["hmap"] * 7) + TIME_INCANT + DELAY_INCANT) / TIME_ONE_FOOD;

  $nfood = $player["nourriture"];

  if ($nfood < MAX_FOOD && $nfood < (int)$min_food_to_level)
    return (false);
  return (true);
}


?>