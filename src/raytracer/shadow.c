/*
** rtv1.c for rtv1.c in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Feb  4 08:58:47 2015 Jules Vautier
** Last update Wed May 27 10:40:42 2015 Jules Vautier
*/

#include "struct.h"
#include "shared.h"
#include "rt.h"

static const	t_fonct g_fonct[] =
  {
    {&inter_sphere, TYPE_SPHERE},
    {&inter_cone, TYPE_CONE},
    {&inter_cylinder, TYPE_CYLINDER},
    {&inter_plan, TYPE_PLAN},
    {NULL, -1}
  };

static int	do_shadow(t_all *all, t_object **list, double k)
{
  t_object	*tmp;

  tmp = *list;
  /*calc_point_eye(&all->eye, all->pixel_nb);*/
  while (tmp != NULL)
    {
      /*calc_vec(&all->lum, tmp);*/
      /*if (all->flag.rotate == 1)
	{
	  rotate(&all->eye, &all->object[NB_OBJ], 1);
	  rotate(&all->eye, tmp, 1);
	  }*/
      calc_point_lum(&all->eye, &all->lum, tmp, k);
      g_fonct[tmp->type].ptr(all, &all->lum, tmp);
      tmp = tmp->next;
     }
 return (0);
}

int		shadow(t_all *all, double k)
{
  t_object	*obj_nb;
  t_coor	lum;
  t_coor	eye;

  obj_nb = all->obj_nb;
  do_shadow(all, &all->object, k);

  if (all->obj_nb != NULL && obj_nb != NULL)
    if (all->obj_nb->k != obj_nb->k)
      return (900);
  return (0);
}
