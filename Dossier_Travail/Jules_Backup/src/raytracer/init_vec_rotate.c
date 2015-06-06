/*
** init_light.c for init_light in /home/vautie_a/rendu/MUL_2014_rtv1/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Mar  4 16:39:00 2015 Jules Vautier
** Last update Fri Jun  5 17:49:51 2015 Jules Vautier
*/

#include "rt.h"

int		init_rotate(t_object **list)
{
  t_object	*obj;

  obj = *list;
  while (obj != NULL)
    {
      obj->a.x = (int)obj->a.x % 360;
      obj->a.y = (int)obj->a.y % 360;
      obj->a.z = (int)obj->a.z % 360;
      obj->a.x = TORADIAN(obj->a.x);
      obj->a.x = TORADIAN(obj->a.y);
      obj->a.x = TORADIAN(obj->a.z);
      obj->a.x = (double)obj->a.x;
      obj->a.y = (double)obj->a.y;
      obj->a.z = (double)obj->a.z;
      obj = obj->next;
    }
  return (0);
}
