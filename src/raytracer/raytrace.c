/*
** rtv1.c for rtv1.c in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Feb  4 08:58:47 2015 Jules Vautier
** Last update Thu Jun  4 19:55:37 2015 Jules Vautier
*/

#include "shared.h"
#include "struct.h"
#include "rt.h"
#include <stdio.h>

static const	t_fonct g_fonct[] =
  {
    {&inter_sphere, TYPE_SPHERE},
    {&inter_cone, TYPE_CONE},
    {&inter_cylinder, TYPE_CYLINDER},
    {&inter_plan, TYPE_PLAN},
    {&inter_disque, TYPE_DISQUE},
    {NULL, -1}
  };

static int	raycast(t_all *all, t_object **list)
{
  t_object	*tmp;
  double	k;

  tmp = *list;
  all->calc.k = 9999999.0;
  all->obj = NULL;
  while (tmp != NULL)
    {
      calc_vec(&all->eye, tmp);
      if (all->flag.rotate == 1)
	{
	  rotate(&all->eye, &all->object[NB_OBJ], 1);
	  rotate(&all->eye, tmp, 1);
	}
      k = g_fonct[tmp->type].ptr(all, &all->eye, tmp);
      if (k > 0.000001 && k < all->calc.k)
	{
	  all->calc.k = k;
	  all->obj = tmp;
	}
      tmp = tmp->next;
    }
  return (0);
}

int		raytrace(t_all *all)
{
  all->pixel_nb = 0;
  init_rotate(all);
  while (all->pixel_nb < SIZE_IMG)
    {
      calc_point_eye(&all->eye, all->pixel_nb);
      raycast(all, &all->object);
      all->pixel_nb = all->pixel_nb + 4;
      creat_pixel(all);
    }
  gere_expose(all);
  return (0);
}
