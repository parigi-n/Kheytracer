/*
** init_obj.c for init_obj in /home/vautie_a/rendu/MUL_2014_rtv1/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Mar  4 16:35:12 2015 Jules Vautier
** Last update Wed Apr 22 11:03:48 2015 Jules Vautier
*/

#include "rtv1.h"

int	init_obj_un(t_all *all)
{
  all->object[0].type = TYPE_SPHERE;
  all->object[0].color = 0xFF0000;
  all->object[0].x = 0.0;
  all->object[0].y = 200.0;
  all->object[0].z = 50.0;
  all->object[0].r = 150;
  all->object[0].ax = 0.0;
  all->object[0].ay = 0.0;
  all->object[0].az = 0.0;
  return (0);
}

int	init_obj_deux(t_all *all)
{
  all->object[1].type = TYPE_CYLINDER;
  all->object[1].color = 0x00FF00; 
  all->object[1].x = 0.0;
  all->object[1].y = 600.0;
  all->object[1].z = 0.0;
  all->object[1].r = 150;
  all->object[1].ax = 0.0;
  all->object[1].ay = 0.0;
  all->object[1].az = 0.0;
  return (0);
}

int	init_obj_trois(t_all *all)
{
  all->object[2].type = TYPE_CYLINDER;
  all->object[2].color = 0x640ADC;
  all->object[2].x = 40.0;
  all->object[2].y = 700.0;
  all->object[2].z = 20.0;
  all->object[2].r = 0;
  all->object[2].ax = 0.2;
  all->object[2].ay = 0.0;
  all->object[2].az = 0.0;
  return (0);
}

int	init_obj_quatre(t_all *all)
{
  all->object[3].type = TYPE_PLAN;
  all->object[3].color = 0xC8C814;
  all->object[3].x = 100.0;
  all->object[3].y = -200.0;
  all->object[3].z = -200.0;
  all->object[3].r = 1000;
  all->object[3].ax = 0.0;
  all->object[3].ay = 0.0;
  all->object[3].az = 0.0;
  return (0);
}
