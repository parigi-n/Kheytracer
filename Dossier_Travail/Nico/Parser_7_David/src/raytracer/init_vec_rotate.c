/*
** init_vec_rotate.c for init_vec in /home/noswor_o/dim/MUL_2014_rtracer
** 
** Made by Oscar Nosworthy
** Login   <noswor_o@epitech.net>
** 
** Started on  Sun Jun  7 16:19:45 2015 Oscar Nosworthy
** Last update Sun Jun  7 16:21:52 2015 Oscar Nosworthy
*/

#include "rt.h"

static void	init_rotate_eye(t_light *eye)
{
  if (eye->a.x < 0.0)
    eye->a.x = -eye->a.x;
  if (eye->a.y < 0.0)
    eye->a.y = -eye->a.y;
  if (eye->a.z < 0.0)
    eye->a.z = -eye->a.z;
  eye->a.x = TORADIAN(eye->a.x);
  eye->a.y = TORADIAN(eye->a.y);
  eye->a.z = TORADIAN(eye->a.z);
}

void		init_rotate(t_object **list, t_light *eye)
{
  t_object	*obj;

  init_rotate_eye(eye);
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
}
