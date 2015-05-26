/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
** Last update Tue May 26 15:11:27 2015 Jules Vautier
*/

#include "struct.h"
#include "rtv1.h"

static int	do_calc(t_vec *vec, t_coor *coor)
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

static int	end_calc(t_object *obj, t_coor *coor,
			 double delta, t_vec *vec)
{
  double	limite;
  double	tmp;

  obj->k = ((-coor->y + sqrt(delta)) / (2 * coor->x));
  tmp = ((- coor->y - sqrt(delta)) / (2 * coor->x));
  if (tmp < obj->k)
    obj->k = tmp;
  limite =  (vec->v.z * obj->k + vec->pos.z);
  if (limite > obj->pos.z || limite < obj->pos.z - obj->r)
    {
      obj->k = 999999.99999;
      return (obj->is_true = 0);
    }
  return (obj->is_true = 1);
}

int		inter_cone(t_all *all, t_vec *vec,
			   t_object *obj)
{
  t_coor	coor;
  double	delta;

  (void)all;
  do_calc(vec, &coor);
  delta = ((coor.y * coor.y) - (4 * coor.x * coor.z));
  if (delta >= 0.0)
    return (end_calc(obj, &coor, delta, vec));
  obj->k = 0.0;
  return (obj->is_true = 0);
}
