/*
** inter_sphere.c for sphere in /home/vautie_a/rendu/MUL_2014_rtracer/src/raytracer
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sun Jun  7 23:21:56 2015 Jules Vautier
** Last update Sun Jun  7 23:21:57 2015 Jules Vautier
*/

#include "struct.h"
#include "rt.h"

static int	do_calc(t_light *vec, t_coor *coor, t_object *object)
{
  coor->x = (vec->v.x * vec->v.x)
    + (vec->v.y * vec->v.y)
    + (vec->v.z * vec->v.z);
  coor->y = 2 * ((vec->tmp.x * vec->v.x)
		+ (vec->tmp.y * vec->v.y)
		+ (vec->tmp.z * vec->v.z));
  coor->z = ((vec->tmp.x * vec->tmp.x)
	    + (vec->tmp.y * vec->tmp.y)
	    + (vec->tmp.z * vec->tmp.z)
	    - object->r * object->r * 2);
  return (0);
}

double		inter_sphere(t_all *all, t_light *vec,
			     t_object *object)
{
  t_coor	coor;
  double	delta;
  double	k;

  (void)all;
  do_calc(vec, &coor, object);
  delta = ((coor.y * coor.y) - 4 * (coor.x * coor.z));
  if (delta > 0.0)
    {
      k = ((-coor.y - sqrt(delta)) / (2 * coor.x));
      return (k);
    }
  return (0.0);
}
