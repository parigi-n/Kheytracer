/*
** ss.c for ss.c in /home/vautie_a/rendu/CPE_2014_Pushswap/push_swap_src
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Dec  8 11:30:18 2014 jules vautier
** Last update Tue Jun  2 16:12:05 2015 david sebaoun
*/

#include "struct.h"
#include "printf.h"
#include "shared.h"

void		free_list_light(t_light **list)
{
  t_light		*tmp;
  t_light		*wait;

  tmp = *list;
  while (tmp != NULL)
    {
      wait = tmp->next;
      free(tmp->name);
      free(tmp);
      tmp = wait;
    }
}

int		my_put_in_list_light(t_light **list, char *name)
{
  t_light		*l_a;

  if ((l_a = malloc(sizeof(*l_a))) == NULL)
    return (ERROR);
  if ((l_a->name = my_strcpy(name)) == NULL)
    return (ERROR);
  l_a->next = *list;
  *list = l_a;
  return (SUCCESS);
}

void		my_show_list_light(t_light *list)
{
  t_light		*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_printf("object: %s\n", tmp->name);
      tmp = tmp->next;
    }
}
