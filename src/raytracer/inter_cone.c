/*
** inter_cone.c for inter_cone in /home/vautie_a/rendu/MUL_2014_rtracer/src/raytracer
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sun Jun  7 23:22:13 2015 Jules Vautier
** Last update Sun Jun  7 23:22:14 2015 Jules Vautier
*/

#include "struct.h"
#include "rt.h"

static int	do_calc(t_light *vec, t_coor *coor)
{
  coor->x = (vec->v.x * vec->v.x) + (vec->v.y * vec->v.y)
    - (vec->v.z * vec->v.z);
  coor->y = 2 * ((vec->tmp.x * vec->v.x) +
		 (vec->tmp.y * vec->v.y)
		- (vec->tmp.z * vec->v.z));
  coor->z = ((vec->tmp.x * vec->tmp.x) +
	     (vec->tmp.y * vec->tmp.y)
	    - (vec->tmp.z * vec->tmp.z));
  return (0);
}

static double	end_calc(t_object *obj, t_coor *coor,
			 double delta, t_light *vec)
{
  double	limite;
  double	k;

  k = ((-coor->y + sqrt(delta)) / (2 * coor->x));
  if (obj->lim == 0.0)
    return (k);
  limite =  (vec->v.z * k + vec->pos.z);
  if (limite > obj->pos.z || limite < obj->pos.z - obj->lim)
    return (0.0);
  return (k);
}

double		inter_cone(t_all *all, t_light *vec,
			   t_object *obj)
{
  t_coor	coor;
  double	delta;

  (void)all;
  do_calc(vec, &coor);
  delta = ((coor.y * coor.y) - (4 * coor.x * coor.z));
  if (delta >= 0.0)
    return (end_calc(obj, &coor, delta, vec));
  return (0.0);
}
