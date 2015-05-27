/*
** init_vec.c for init_vec in /home/vautie_a/rendu/MUL_2014_rtv1/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Mar  4 16:39:00 2015 Jules Vautier
** Last update Tue May 26 17:13:10 2015 Jules Vautier
*/

#include "rtv1.h"

int	init_lum(t_all *all)
{
  all->lum.pos.x = 1000.0;
  all->lum.pos.y = 3000.0;
  all->lum.pos.z = 400.0;
  all->lum.v.x = 0.0;
  all->lum.v.y = 0.0;
  all->lum.v.z = 0.0;
  /*all->object[NB_OBJ - 1].k = -99999.0;
    all->object[NB_OBJ - 1].type = TYPE_VIDE;*/
  /*all->object[NB_OBJ - 1].color[0] = 0;
  all->object[NB_OBJ - 1].color[1] = 0;
  all->object[NB_OBJ - 1].color[2] = 0;
  all->object[NB_OBJ - 1].color[3] = 0;
  all->object[NB_OBJ - 1].color[4] = 1000;*/
  /*all->object[NB_OBJ - 1].ax = 0.0;
  all->object[NB_OBJ - 1].ay = 0.0;
  all->object[NB_OBJ - 1].az = 0.0;*/
  return (0);
}

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
