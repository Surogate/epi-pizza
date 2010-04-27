#!/usr/pkg/bin/php
<?php

require_once('Header/library.php');
require_once('Header/require.php');
require_once('Header/define.php');

$player = array();

$player['param'] = init_param($argc, $argv);

init_process($player['param']['n']);

$socket = init_connect(&$player);

init_player(&$player);

init_mode(&$player);

init_level(&$player);

init_ia(&$player, $socket);

loop_action(&$player, $socket);

?>