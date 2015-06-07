/*
** calc.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun Jun  7 21:39:43 2015 david sebaoun
** Last update Sun Jun  7 21:39:49 2015 david sebaoun
*/

#include "struct.h"
#include "rt.h"

int		calc_point_lum(t_light *eye, t_light *vec,
			       t_object *obj, double k)
{
  t_coor	point;

  (void)obj;
  (void)eye;
  vec->v.x = point.x - vec->pos.x;
  vec->v.y = point.y - vec->pos.y;
  vec->v.z = point.z - vec->pos.z;
  vec->tmp.x = point.x - k * vec->v.x;
  vec->tmp.y = point.y - k * vec->v.y;
  vec->tmp.z = point.z - k * vec->v.z;
  return (0);
}

int		calc_light(t_coor point, t_light *vec,
			   t_object *obj)
{
  vec->tmp.x = vec->pos.x - obj->pos.x;
  vec->tmp.y = vec->pos.y - obj->pos.y;
  vec->tmp.z = vec->pos.z - obj->pos.z;
  vec->v.x = point.x - vec->pos.x;
  vec->v.y = point.y - vec->pos.y;
  vec->v.z = point.z - vec->pos.z;
  return (0);
}

int		calc_point_eye(t_light *eye, int i)
{
  i = i / 4;
  eye->new.x = 1000.0;
  eye->new.y = (i % SIZE_LARG);
  eye->new.z = (i / SIZE_LARG);
  return (0);
}

int		calc_vec(t_light *vec, t_object *obj)
{
  vec->tmp.x = vec->pos.x - obj->pos.x;
  vec->tmp.y = vec->pos.y - obj->pos.y;
  vec->tmp.z = vec->pos.z - obj->pos.z;
  vec->v.x = vec->new.x;
  vec->v.y = (SIZE_LARG) / 2 - vec->new.y;
  vec->v.z = (SIZE_LONG) / 2 - vec->new.z;
  return (0);
}

int		find_point(t_light *vec, t_coor *coor, double k)
{
  coor->x = k * vec->v.x + vec->pos.x;
  coor->y = k * vec->v.y + vec->pos.y;
  coor->z = k * vec->v.z + vec->pos.z;
  return (0);
}
