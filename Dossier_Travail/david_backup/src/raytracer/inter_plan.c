/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
** Last update Fri May 29 11:22:03 2015 Jules Vautier
*/

#include "struct.h"
#include "rt.h"

double		inter_plan(t_all *all, t_vec *vec, t_object *obj)
{
  double	limite;
  double	k;

  (void)all;
  if (vec->v.z == 0.0)
    return (0.0);
  k = - (vec->pos.z - obj->pos.z) / (vec->v.z);
  if (k > 0.0000001)
    {
      limite = (vec->v.y * k + vec->pos.y);
      if (limite > obj->r || limite < -obj->r)
	return (0.0);
      limite = (vec->v.x * k + vec->pos.x);
      if (limite > obj->r || limite < -obj->r)
	return (0.0);
      return (k);
    }
  return (0.0);
}
