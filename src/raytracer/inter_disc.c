/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
** Last update Sun Jun  7 16:54:51 2015 Oscar Nosworthy
*/

#include "struct.h"
#include "rt.h"

double		inter_disc(t_all *all, t_light *vec, t_object *obj)
{
  double	limite;
  double	k;

  (void)all;
  if (vec->v.z == 0.0)
    return (0.0);
  k = - (vec->pos.z - obj->pos.z) / (vec->v.z);
  if (k > 0.0000001)
    {
      limite = (pow(k * vec->v.x + vec->pos.x, 2)
		+ pow(k * vec->v.y
		      + vec->pos.y, 2));
      if (limite > pow((double)obj->r, 2))
	return (0.0);
      return (k);
    }
  return (0.0);
}
