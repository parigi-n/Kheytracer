/*
** rtv1.c for rtv1.c in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Feb  4 08:58:47 2015 Jules Vautier
** Last update Thu May 28 09:17:36 2015 Jules Vautier
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

static int	do_shadow(t_all *all, t_object **list,
			  double k, t_vec *lum)
{
  t_object	*obj;

  obj = *list;
  calc_point_lum(&all->eye, lum, obj, k);
  while (obj != NULL)
    {
      /*if (all->flag.rotate == 1)
	{
	  rotate(&all->eye, &all->object[NB_OBJ], 1);
	  rotate(&all->eye, obj, 1);
	  }*/
      g_fonct[obj->type].ptr(all, lum, obj);
      obj = obj->next;
    }
 return (0);
}

int		shadow(t_all *all, double k,
		       t_vec *lum, t_object *save)
{
  t_coor	point;

  do_shadow(all, &all->object, k, lum);
  do_k(all, &all->object);
  /* find_point(lum, &point, all->calc.k); */
  if (all->obj_nb != NULL && save != NULL)
    if (&save != &all->obj_nb)
      return (1);
  return (0);
}
