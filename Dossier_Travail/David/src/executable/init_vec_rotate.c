/*
** init_vec.c for init_vec in /home/vautie_a/rendu/MUL_2014_rtv1/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Mar  4 16:39:00 2015 Jules Vautier
** Last update Wed May 27 18:22:31 2015 Jules Vautier
*/

#include "rt.h"

int	init_eye(t_all *all)
{
  /*all->object[NB_OBJ].x = -3000.0;
  all->object[NB_OBJ].y = 0.0;
  all->object[NB_OBJ].z = 300.0;
  all->object[NB_OBJ].ax = 0.0;
  all->object[NB_OBJ].ay = 0.0;
  all->object[NB_OBJ].az = 0.0;
  all->eye.posx = all->object[NB_OBJ].x;
  all->eye.posy = all->object[NB_OBJ].y;
  all->eye.posz = all->object[NB_OBJ].z;*/
  all->eye.pos.x = -3000.0;
  all->eye.pos.y = 0.0;
  all->eye.pos.z = 0.0;
  all->eye.v.x = 0.0;
  all->eye.v.y = 0.0;
  all->eye.v.z = 0.0;
  return (0);
}

int	init_rotate(t_all *all)
{
  /*int	i;

  i = 0;
  while (i <= NB_OBJ)
    {
      while (all->object[i].ax < 0.0)
	all->object[i].ax = all->object[i].ax + TORADIAN(360);
      while (all->object[i].ay < 0.0)
	all->object[i].ay = all->object[i].ay + TORADIAN(360);
      while (all->object[i].az < 0.0)
	all->object[i].az = all->object[i].az + TORADIAN(360);
      i++;
      }*/
  return (0);
}
