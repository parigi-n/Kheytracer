/*
** init_light.c for init_light in /home/vautie_a/rendu/MUL_2014_rtv1/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Mar  4 16:39:00 2015 Jules Vautier
** Last update Fri Jun  5 17:04:49 2015 Jules Vautier
*/

#include "rt.h"

int		init_rotate(t_all *all, t_object **list)
{
  int		i;
  t_object	*obj;

  obj = *list;
  while (tmp != NULL)
    {
      obj->a.x = obj->a.x % 360.0;
      obj->a.y = obj->a.y % 360.0;
      obj->a.z = obj->a.z % 360.0;
      obj->a.x = TORADIAN(obj->a.x);
      obj->a.x = TORADIAN(obj->a.y);
      obj->a.x = TORADIAN(obj->a.z);
      tmp = tmp->next;
    }
  return (0);
}
