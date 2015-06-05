/*
** rotate.c for rotate.c in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Feb 11 16:09:14 2015 Jules Vautier
** Last update Tue May 26 19:12:54 2015 david sebaoun
*/

#include "struct.h"
#include "rt.h"

int		rotate_x(t_light *vec, double a)
{
  t_coor	tmp;

  tmp.x = vec->v.x;
  tmp.y = (vec->v.y * cos(a)) + (vec->v.z * -sin(a));
  tmp.z = (vec->v.y * sin(a)) + (vec->v.z * cos(a));
  vec->v.x = tmp.x;
  vec->v.y = tmp.y;
  vec->v.z = tmp.z;
  return (0);
}

int		rotate_y(t_light *vec, double a)
{
  t_coor	tmp;

  tmp.x = (vec->v.x * cos(a)) + (vec->v.z * sin(a));
  tmp.y = vec->v.y;
  tmp.z = (vec->v.x * -sin(a)) + (vec->v.z * cos(a));
  vec->v.x = tmp.x;
  vec->v.y = tmp.y;
  vec->v.z = tmp.z;
  return (0);
}

int		rotate_z(t_light *vec, double a)
{
  t_coor	tmp;

  tmp.x = (vec->v.x * cos(a)) + (vec->v.y * -sin(a));
  tmp.y = (vec->v.x * sin(a)) + (vec->v.y * cos(a));
  tmp.z = vec->v.z;
  vec->v.x = tmp.x;
  vec->v.y = tmp.y;
  vec->v.z = tmp.z;
  return (0);
}

int		rotate(t_light *vec, t_object *pos, int i)
{
  if (pos->a.x > 0.0)
    rotate_x(vec, pos->a.x * i);
  if (pos->a.y > 0.0)
    rotate_y(vec, pos->a.y * i);
  if (pos->a.z > 0.0)
    rotate_z(vec, pos->a.z * i);
  return (0);
}
