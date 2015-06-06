/*
** init_light.c for init_light in /home/vautie_a/rendu/MUL_2014_rtv1/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Mar  4 16:39:00 2015 Jules Vautier
** Last update Sat Jun  6 12:22:38 2015 Jules Vautier
*/

#include "rt.h"
#include <stdio.h>

int		init_rotate(t_object **list)
{
  t_object	*obj;

  obj = *list;
  while (obj != NULL)
    {
      if (obj->a.x < 0.0)
	obj->a.x = -obj->a.x;
      if (obj->a.y < 0.0)
	obj->a.y = -obj->a.y;
      if (obj->a.z < 0.0)
	obj->a.z = -obj->a.z;
      obj->a.x = TORADIAN(obj->a.x);
      obj->a.y = TORADIAN(obj->a.y);
      obj->a.z = TORADIAN(obj->a.z);
      obj = obj->next;
    }
  return (0);
}
