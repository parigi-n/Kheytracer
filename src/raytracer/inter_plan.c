/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
** Last update Sat Jun  6 15:35:56 2015 david sebaoun
*/

#include "struct.h"
#include "rt.h"

double		inter_plan(t_all *all, t_light *vec, t_object *obj)
{
  /* double	limite; */
  double	k;

  (void)all;
  if (vec->v.z == 0.0)
    return (0.0);
  k = - (vec->pos.z - obj->pos.z) / (vec->v.z);
  if (k > 0.0000001)
    {
      /*if (obj->lim > 0.0)
	{
	  limite = (vec->v.y * k + vec->pos.y + obj->pos.y);
	  if (limite > obj->lim ||
	      limite < -obj->lim)
	    return (0.0);
	  limite = (vec->v.x * k + vec->pos.x + obj->pos.x);
	  if (limite > obj->lim ||
	      limite < -obj->lim)
	    return (0.0);
	  return (k);
	}
	else*/
	return (k);
    }
  return (0.0);
}
