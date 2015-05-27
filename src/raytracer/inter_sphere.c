/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
** Last update Tue May 26 19:01:24 2015 Jules Vautier
*/

#include "struct.h"
#include "rtv1.h"

static int	do_calc(t_vec *vec, t_coor *coor, t_object *object)
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

int		inter_sphere(t_all *all, t_vec *vec,
			     t_object *object)
{
  t_coor	coor;
  double	delta;
  double	tmpk;

  (void)all;
  do_calc(vec, &coor, object);
  delta = ((coor.y * coor.y) - 4 * (coor.x * coor.z));
  if (delta > 0.0)
    {
      object->k = ((-coor.y + sqrt(delta)) / (2 * coor.x));
      tmpk = ((-coor.y - sqrt(delta)) / (2 * coor.x));
      if (tmpk < object->k)
	object->k = tmpk;
      return (object->is_true = 1);
    }
  object->k = 0.0;
  object->is_true = 0;
  return (0);
}
