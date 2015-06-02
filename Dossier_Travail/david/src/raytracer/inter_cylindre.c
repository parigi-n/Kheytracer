/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
** Last update Fri May 29 11:21:30 2015 Jules Vautier
*/

#include "struct.h"
#include "rt.h"

static int	do_calc(t_vec *vec, t_coor *point,
			t_object *obj)
{
  point->x = (vec->v.x * vec->v.x)
    + (vec->v.y * vec->v.y);
  point->y = 2 * ((vec->tmp.x * vec->v.x)
           + (vec->tmp.y * vec->v.y));
  point->z = ((vec->tmp.x * vec->tmp.x)
       + (vec->tmp.y * vec->tmp.y)
       - obj->r * obj->r * 2);
  return (0);
}

static double	end_calc(t_object *obj, t_coor *point,
			 double delta, t_vec *vec)
{
  double	k;

  k = ((-point->y - sqrt(delta)) / (2 * point->x));
  if (k * vec->v.z + vec->pos.z > 0.0 &&
      k * vec->v.z + vec->pos.z < obj->lim)
    return (k);
  return (0.0);
}

double		inter_cylinder(t_all *all,
			       t_vec *vec, t_object *obj)
{
  t_coor	point;
  double	delta;

  (void)all;
  do_calc(vec, &point, obj);
  delta = ((point.y * point.y) - (4 * point.x * point.z));
  if (delta >= 0.0)
    return (end_calc(obj, &point, delta, vec));
  return (0.0);
}
