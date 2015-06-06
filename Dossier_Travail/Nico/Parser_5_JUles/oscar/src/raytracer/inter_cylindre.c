/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
** Last update Wed May 27 15:51:54 2015 Jules Vautier
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

static int	end_calc(t_object *obj, t_coor *point,
			 double delta, t_vec *vec)
{
  double	tmp;

  obj->k = ((-point->y + sqrt(delta)) / (2 * point->x));
  tmp = ((-point->y - sqrt(delta)) / (2 * point->x));
  if (tmp < obj->k)
    obj->k = tmp;
  if (obj->k * vec->v.z + vec->pos.z > 0.0 &&
      obj->k * vec->v.z + vec->pos.z < obj->lim)
    return (obj->is_true = 1);
  else
    return (obj->is_true = 0);
}

int		inter_cylinder(t_all *all, t_vec *vec, t_object *obj)
{
  t_coor	point;
  double	delta;

  (void)all;
  do_calc(vec, &point, obj);
  delta = ((point.y * point.y) - (4 * point.x * point.z));
  if (delta >= 0.0)
    return (end_calc(obj, &point, delta, vec));
  else
    {
      obj->k = 0.0;
      return (obj->is_true = 0);
    }
}
