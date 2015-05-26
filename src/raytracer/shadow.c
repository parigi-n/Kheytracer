/*
** rtv1.c for rtv1.c in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Feb  4 08:58:47 2015 Jules Vautier
** Last update Tue May 26 16:37:59 2015 Jules Vautier
*/

#include "struct.h"
#include "shared.h"
#include "rtv1.h"

static const	t_fonct g_fonct[] =
  {
    {&inter_sphere, TYPE_SPHERE},
    {&inter_cone, TYPE_CONE},
    {&inter_cylinder, TYPE_CYLINDER},
    {&inter_plan, TYPE_PLAN},
    {NULL, -1}
  };

static int	do_shadow(t_all *all, t_object **list)
{
  t_object	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      calc_point_eye(&all->eye, all->pixel_nb);
      calc_vec(&all->eye, tmp);
      /*if (all->flag.rotate == 1)
	{
	  rotate(&all->eye, &all->object[NB_OBJ], 1);
	  rotate(&all->eye, tmp, 1);
	  }*/
      calc_point_lum(all, tmp, &all->lum);
      g_fonct[tmp->type].ptr(all, &all->lum, tmp);
    }
  return (0);
}

int		shadow(t_all *all)
{
  double	tmpk;
  t_object	*obj_nb;

  tmpk = all->calc.k;
  obj_nb = all->obj_nb;
  do_shadow(all, &all->object);
  do_k(all, &all->object);
  all->calc.k = tmpk;
  if (my_strcmp(all->obj_nb->name, obj_nb->name) == ERROR)
    return (900);
  return (0);
}
