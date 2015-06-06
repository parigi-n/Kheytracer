/*
** rotate.c for rotate.c in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Feb 11 16:09:14 2015 Jules Vautier
** Last update Sat Jun  6 10:03:13 2015 Jules Vautier
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

int		rotate(t_light *vec, t_coor a, int i)
{
  if (a.x > 0.0)
    rotate_x(vec, a.x * i);
  if (a.y > 0.0)
    rotate_y(vec, a.y * i);
  if (a.z > 0.0)
    rotate_z(vec, a.z * i);
  return (0);
}
