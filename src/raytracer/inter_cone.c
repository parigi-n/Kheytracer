/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
<<<<<<< HEAD
** Last update Sun Jun  7 22:32:23 2015 Jules Vautier
=======
** Last update Tue May 26 19:14:20 2015 david sebaoun
>>>>>>> 7b4f8b46492ef0dc1a0dac4d9277e1b011142ae6
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
