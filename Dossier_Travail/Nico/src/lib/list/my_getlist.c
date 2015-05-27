/*
** my_getstock.c for my_getstock in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Mar  2 16:02:58 2015 Jules Vautier
** Last update Tue May 26 15:17:33 2015 Jules Vautier
*/

#include "shared.h"
#include "struct.h"
#include "list.h"

t_object	*my_getlist(t_object **list, char *str)
{
  t_object	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (tmp->name != NULL && my_strcmp(tmp->name, str) == SUCCESS)
	return (tmp);
	tmp = tmp->next;
    }
  return (NULL);
}
