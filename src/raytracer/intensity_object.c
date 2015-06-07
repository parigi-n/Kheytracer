/*
** intensity_object.c for raytracer in /home/vautie_a/rendu/MUL_2014_rtracer/src/raytracer
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Jun  6 15:37:59 2015 Jules Vautier
<<<<<<< HEAD
** Last update Sun Jun  7 21:31:46 2015 Jules Vautier
=======
** Last update Sun Jun  7 16:55:53 2015 Oscar Nosworthy
>>>>>>> 5da8d75c10bc34ba9e58f99d732e5a3075bb1bc4
*/

#include "rt.h"

double		intensity_plan(t_all *all, t_light *vec,
			       t_object *obj)
{
  double	inte;
  t_light	vec2;
  t_light	vec1;
  t_coor	point;

  vec1.v.x = 0.0;
  vec1.v.y = 0.0;
  vec1.v.z = 1.0;
  point = all->point;
  vec2.v.x = vec->pos.x - point.x;
  vec2.v.y = vec->pos.y - point.y;
  vec2.v.z = vec->pos.z - point.z;
  if (all->flag.rotate == 1)
    rotate(&vec1, obj->a, -1);
  inte = do_inten(&vec1, &vec2);
  if (inte < 0.0)
    return (0.0);
  return (inte);
}

double		intensity_sphere(t_all *all, t_light *vec,
				 t_object *obj)
{
  double	inte;
  t_light	vec1;
  t_light	vec2;
  t_coor	point;

  point = all->point;
  vec1.v.x = point.x - obj->pos.x;
  vec1.v.y = point.y - obj->pos.y;
  vec1.v.z = point.z - obj->pos.z;
  vec2.v.x = vec->pos.x - obj->pos.x;
  vec2.v.y = vec->pos.y - obj->pos.y;
  vec2.v.z = vec->pos.z - obj->pos.z;
  if (all->flag.rotate == 1)
    rotate(&vec1, obj->a, -1);
  inte = do_inten(&vec1, &vec2);
  if (inte < 0.0)
    inte = 0.0;
  return (inte);
}

double		intensity_cone(t_all *all, t_light *vec,
			       t_object *obj)
{
  double	inte;
  t_light	vec2;
  t_light	vec1;
  t_coor	point;

  point = all->point;
  vec1.v.x = point.x - vec->pos.x;
  vec1.v.y = point.y - vec->pos.y;
  vec1.v.z = point.z - vec->pos.z;
  vec2.v.x = point.x - obj->pos.x;
  vec2.v.y = point.y - obj->pos.y;
  vec2.v.z = point.z - obj->pos.z * 2.0;
  if (all->flag.rotate == 1)
    rotate(&vec1, obj->a, -1);
  inte = do_inten(&vec1, &vec2);
  if (inte < 0.0)
    inte = - inte;
  if (inte < 0.0)
    return (0.0);
  return (inte);
}

double		intensity_cylinder(t_all *all, t_light *vec,
				   t_object *obj)
{
  double	inte;
  t_light	vec2;
  t_light	vec1;
  t_coor	point;

  point = all->point;
  vec1.v.x = obj->pos.x - point.x;
  vec1.v.y = obj->pos.y - point.y;
  vec1.v.z = - point.z;
  vec2.v.x = obj->pos.x - vec->pos.x;
  vec2.v.y = obj->pos.y - vec->pos.y;
  vec2.v.z = obj->pos.z - vec->pos.z;
  if (all->flag.rotate == 1)
    rotate(&vec1, obj->a, -1);
  inte = do_inten(&vec1, &vec2);
  if (inte < 0.0)
    return (0.0);
  return (inte);
}
