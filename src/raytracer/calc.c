/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
<<<<<<< HEAD
** Last update Wed May 27 10:03:26 2015 Jules Vautier
=======
** Last update Tue May 26 19:13:18 2015 david sebaoun
>>>>>>> 7b4f8b46492ef0dc1a0dac4d9277e1b011142ae6
*/

#include "struct.h"
#include "rt.h"

int		calc_point_eye(t_vec *eye, int i)
{
  i = i / 4;
  eye->new.x = 1000.0;
  eye->new.y = (i % SIZE_LARG);
  eye->new.z = (i / SIZE_LARG);
  return (0);
}

int		calc_point_lum(t_vec *eye, t_vec *vec,
			       t_object *obj, double k)
{
  t_coor	point;

  find_point(eye, &point, k);
  vec->tmp.x = vec->pos.x - obj->pos.x;
  vec->tmp.y = vec->pos.y - obj->pos.y;
  vec->tmp.z = vec->pos.z - obj->pos.z;
  vec->v.x = point.x - vec->pos.x;
  vec->v.y = point.y - vec->pos.y;
  vec->v.z = point.z - vec->pos.z;
  return (0);
}

int		calc_vec(t_vec *vec, t_object *obj)
{
  vec->tmp.x = vec->pos.x - obj->pos.x;
  vec->tmp.y = vec->pos.y - obj->pos.y;
  vec->tmp.z = vec->pos.z - obj->pos.z;
  vec->v.x = vec->new.x;
  vec->v.y = (SIZE_LARG) / 2
    - vec->new.y;
  vec->v.z = (SIZE_LONG) / 2
  - vec->new.z;
  return (0);
}

int		find_point(t_vec *vec, t_coor *coor, double k)
{
  coor->x = k * vec->v.x + vec->pos.x;
  coor->y = k * vec->v.y + vec->pos.y;
  coor->z = k * vec->v.z + vec->pos.z;
  return (0);
}
