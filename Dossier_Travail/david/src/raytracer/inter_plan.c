/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
** Last update Thu May 28 12:01:35 2015 Jules Vautier
*/

#include "struct.h"
#include "rt.h"

int		inter_plan(t_all *all, t_vec *vec, t_object *obj)
{
  double	limite;

  (void)all;
  if (vec->v.z == 0.0)
    return (0);
  obj->k = - (vec->pos.z - obj->pos.z) / (vec->v.z);
  if (obj->k > 0.0000001)
    {
      limite =  (vec->v.y * obj->k + vec->pos.y);
      if (limite > (double)obj->r || limite < (double)-obj->r)
	  return (obj->is_true = 0);
      limite =  (vec->v.x * obj->k + vec->pos.x);
      if (limite > (double)obj->r || limite < (double)-obj->r)
      return (obj->is_true = 0);
      return (obj->is_true = 1);
    }
  else
    return (obj->is_true = 0);
}