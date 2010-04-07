/*
** server_stt for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr  6 17:58:29 2010 francois1 ancel
** Last update Tue Apr  6 17:58:29 2010 francois1 ancel
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int server_start(t_list **client)
{
  t_client *server;

  server = malloc(sizeof(*server));
  if (server)
    {
      return (EXIT_SUCCESS);
    }
  return (EXIT_FAILURE);
}
