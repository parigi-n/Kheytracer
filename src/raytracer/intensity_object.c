/*
** rtv1.c for rtv1.c in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Feb  4 08:58:47 2015 Jules Vautier
** Last update Wed May 27 09:15:53 2015 Jules Vautier
*/

#include "struct.h"
#include "rtv1.h"
#include <stdio.h>

int		intensity_plan(t_all *all, t_vec *vec, t_object *obj)
{
  double	tmp;
  int		inte;
  t_vec		vec2;
  t_vec		vec1;
  t_coor	point;

  vec1.v.x = 0.0;
  vec1.v.y = 0.0;
  vec1.v.z = 1.0;
  find_point(&all->eye, &point, all->calc.k);
  vec2.v.x = vec->pos.x - point.x;
  vec2.v.y = vec->pos.y - point.y;
  vec2.v.z = vec->pos.z - point.z;
  /*if (all->flag.rotate == 1)
    rotate(vec1, obj, 1);*/
  inte = do_inten(&vec1, &vec2) * 1000.0;
  if (inte < 0)
    return (0);
  return (inte);
}

int		intensity_sphere(t_all *all, t_vec *vec, t_object *obj)
{
  int		inte;
  double	tmp;
  t_vec		vec1;
  t_vec		vec2;
  t_coor	point;

  find_point(&all->eye, &point, all->calc.k);
  vec1.v.x = point.x - obj->pos.x;
  vec1.v.y = point.y - obj->pos.y;
  vec1.v.z = point.z - obj->pos.z;
  vec2.v.x = vec->pos.x - obj->pos.x;
  vec2.v.y = vec->pos.y - obj->pos.y;
  vec2.v.z = vec->pos.z - obj->pos.z;
  inte = do_inten(&vec1, &vec2) * 1000.0;
  if (inte < 0)
    return (0);
  return (inte);
}

int		intensity_cone(t_all *all, t_vec *vec, t_object *obj)
{
  /*  int		inte;
  t_vec		vec2;
  t_vec		vec1;

  find_point(vec, &point, all->calc.k);
  vec1.v.x = point.x - vec->pos.x;
  vec1.v.y = point.y - vec->pos.y;
  vec1.v.z = point.z - vec->pos.z;
  vec2.v.x = point.x - obj->pos.x;
  vec2.v.y = point.y - obj->pos.y;
  vec2.v.z = point.z - obj->pos.z * 2.0;
  inte = do_inten(&vec1, &vec2) * 1000.0;
  if (inte < 0)
    inte = -inte;
  if (inte < 0)
    return (0);
    return (inte);*/
}

int		intensity_cylinder(t_all *all, t_vec *vec, t_object *obj)
{
  /*int		inte;
  t_vec		vec2;
  t_vec		vec1;

  find_point(vec, &point, all->calc.k);
  vec1.v.x = obj->pos.x - point.x;
  vec1.v.y = obj->pos.y - point.y;
  vec1.v.z = - point.z;
  vec2.v.x = obj->pos.x - vec->pos.x;
  vec2.v.y = obj->pos.y - vec->pos.y;
  vec2.v.z = obj->pos.z - vec->pos.z;
  inte = do_inten(&vec1, &vec2) * 1000.0;
  if (inte < 0)
    return (0);
    return (inte);*/
}
