/*
** intensity_object.c for raytracer in /home/vautie_a/rendu/MUL_2014_rtracer/src/raytracer
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Jun  6 15:37:59 2015 Jules Vautier
** Last update Sun Jun  7 09:05:32 2015 Jules Vautier
*/

#include "rt.h"
#include <stdio.h>

int		intensity_plan(t_all *all, t_light *vec,
			       t_object *obj, t_light eye)
{
  int		inte;
  t_light	vec2;
  t_light	vec1;
  t_coor	point;

  vec1.v.x = 0.0;
  vec1.v.y = 0.0;
  vec1.v.z = 1.0;
  find_point(&eye, &point, all->calc.k);
  point = all->point;
  vec2.v.x = vec->pos.x - point.x;
  vec2.v.y = vec->pos.y - point.y;
  vec2.v.z = vec->pos.z - point.z;
  if (all->flag.rotate == 1)
    rotate(&vec1, obj->a, -1);
  inte = do_inten(&vec1, &vec2) * 1000.0;
  if (inte < 0)
    return (0);
  return (inte);
}

int		intensity_sphere(t_all *all, t_light *vec,
				 t_object *obj, t_light eye)
{
  int		inte;
  t_light	vec1;
  t_light	vec2;
  t_coor	point;

  find_point(&eye, &point, all->calc.k);
  vec1.v.x = point.x - obj->pos.x;
  vec1.v.y = point.y - obj->pos.y;
  vec1.v.z = point.z - obj->pos.z;
  vec2.v.x = vec->pos.x - obj->pos.x;
  vec2.v.y = vec->pos.y - obj->pos.y;
  vec2.v.z = vec->pos.z - obj->pos.z;
  inte = do_inten(&vec1, &vec2) * 1000.0;
  if (inte < 0)
    inte = 0;
  return (inte);
}

int		intensity_cone(t_all *all, t_light *vec,
			       t_object *obj, t_light eye)
{
  int		inte;
  t_light		vec2;
  t_light		vec1;
  t_coor	point;

  find_point(&eye, &point, all->calc.k);
  vec1.v.x = point.x - vec->pos.x;
  vec1.v.y = point.y - vec->pos.y;
  vec1.v.z = point.z - vec->pos.z;
  vec2.v.x = point.x - obj->pos.x;
  vec2.v.y = point.y - obj->pos.y;
  vec2.v.z = point.z - obj->pos.z * 2.0;
  inte = do_inten(&vec1, &vec2) * 1000.0;
  if (inte < 0)
    inte = - inte;
  if (inte < 0)
    return (0);
  return (inte);
}

int		intensity_cylinder(t_all *all, t_light *vec,
				   t_object *obj, t_light eye)
{
  int		inte;
  t_light	vec2;
  t_light	vec1;
  t_coor	point;

  find_point(&eye, &point, all->calc.k);
  vec1.v.x = obj->pos.x - point.x;
  vec1.v.y = obj->pos.y - point.y;
  vec1.v.z = - point.z;
  vec2.v.x = obj->pos.x - vec->pos.x;
  vec2.v.y = obj->pos.y - vec->pos.y;
  vec2.v.z = obj->pos.z - vec->pos.z;
  inte = do_inten(&vec1, &vec2) * 1000.0;
  if (inte < 0)
    return (0);
  return (inte);
}
