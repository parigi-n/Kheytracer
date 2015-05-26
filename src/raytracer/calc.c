/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
** Last update Tue May 26 16:13:40 2015 Jules Vautier
*/

#include "struct.h"
#include "rtv1.h"

int		calc_point_eye(t_vec *eye, int i)
{
  i = i / 4;
  eye->new.x = 1000.0;
  eye->new.y = (i % SIZE_LARG);
  eye->new.z = (i / SIZE_LARG);
  return (0);
}

int		calc_point_lum(t_all *all, t_object *coor, t_vec *vec)
{
  all->calc.point.x = all->calc.k
    * all->eye.v.x + all->eye.pos.x;
  all->calc.point.y = all->calc.k
    * all->eye.v.y + all->eye.pos.y;
  all->calc.point.z = all->calc.k
    * all->eye.v.z + all->eye.pos.z;
  vec->tmp.x = vec->pos.x - coor->pos.x;
  vec->tmp.y = vec->pos.y - coor->pos.y;
  vec->tmp.z = vec->pos.z - coor->pos.z;
  vec->v.x = all->calc.point.x - vec->pos.x;
  vec->v.y = all->calc.point.y - vec->pos.y;
  vec->v.z = all->calc.point.z - vec->pos.z;
  return (0);
}

int	calc_vec(t_vec *vec, t_object *coor)
{
  vec->tmp.x = vec->pos.x - coor->pos.x;
  vec->tmp.y = vec->pos.y - coor->pos.y;
  vec->tmp.z = vec->pos.z - coor->pos.z;
  vec->v.x = vec->new.x;
  vec->v.y = (SIZE_LARG) / 2
    - vec->new.y;
  vec->v.z = (SIZE_LONG) / 2
  - vec->new.z;
  return (0);
}

int	find_point(t_all *all)
{
  all->calc.point.x = all->calc.k
    * all->eye.v.x + all->eye.pos.x;
  all->calc.point.y = all->calc.k
    * all->eye.v.y + all->eye.pos.y;
  all->calc.point.z = all->calc.k
    * all->eye.v.z + all->eye.pos.z;
  return (0);
}
