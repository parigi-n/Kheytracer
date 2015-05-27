/*
** test.c for env in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb 26 17:20:30 2015 Jules Vautier
** Last update Tue May 26 15:19:23 2015 Jules Vautier
*/

#include "struct.h"
#include "list.h"
#include "shared.h"

int		erase_list_object(t_object **list, char *str)
{
  t_object	*wait;

  if ((wait = my_getlist(list, str)) == NULL)
    return (ERROR);
  free(wait->name);
  free(wait);
  *list = wait;
  return (SUCCESS);
}

int		listlen(t_object **list)
{
  int		len;
  t_object	*tmp;

  tmp = *list;
  len = 0;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      len++;
    }
  return (len);
}
