/*
** server_stt for project in /u/all/ancel_a/cu/travail/c/
**
** Made by francois1 ancel
** Login   <ancel_a@epitech.net>
**
** Started on  Tue Apr  6 17:58:29 2010 francois1 ancel
** Last update Tue Apr  6 17:58:29 2010 francois1 ancel
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int			init_svr(t_server *svr)
{
  struct sockaddr_in	sin;
  int			sock;

  sock = socket(PF_INET, SOCK_STREAM, 0);
  if (sock < 0)
    return (EXIT_FAILURE);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(svr->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  if (bind(sock, (struct sockaddr *)&sin, (socklen_t)sizeof(sin)) < 0)
    return (EXIT_FAILURE);
  if (listen(sock, 42) < 0)
    return (EXIT_FAILURE);
  return (sock);
}
