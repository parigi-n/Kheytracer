/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
<<<<<<< HEAD
** Last update Fri May 29 11:28:50 2015 Jules Vautier
=======
** Last update Tue May 26 19:14:49 2015 david sebaoun
>>>>>>> 7b4f8b46492ef0dc1a0dac4d9277e1b011142ae6
*/

#include "struct.h"
#include "rt.h"
#include <stdio.h>

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

double		inter_sphere(t_all *all, t_vec *vec,
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
