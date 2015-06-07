/*
** rtv1.c for rtv1.c in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Feb  4 08:58:47 2015 Jules Vautier
** Last update Sun Jun  7 13:13:03 2015 Jules Vautier
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

static void	do_shadow(t_all *all, t_object **list,
			  t_light *lum, t_scene *scene)
{
  t_object	*obj;
  double	k;

  obj = *list;
  all->calc.k = 99999.0;
  all->obj = NULL;
  while (obj != NULL)
    {
      calc_light(all->point, lum, obj);
      if (all->flag.rotate == 1)
	{
	  /*rotate(lum, all->calc.save->a, -1);*/
	  rotate(lum, obj->a, 1);
	}
      k = g_fonct[obj->type].ptr(all, lum, obj);
      if (k > 0.000001 && k < all->calc.k)
	{
	  /*if (all->flag.rotate == 1)
	    {
	      rotate(lum, all->calc.save->a, -1);
	      rotate(lum, obj->a, -1);
	      }*/
	  all->calc.k = k;
	  all->obj = obj;
	}
      obj = obj->next;
    }
}

int		shadow(t_all *all, t_light *lum, t_scene *scene)
{
  do_shadow(all, &scene->obj, lum, scene);
  if (all->obj == NULL)
    return (1);
  if (all->calc.k < 0.999999)
    {
      if (my_strcmp(all->calc.save->name, all->obj->name) == 0)
	return (1);
      return (0);
    }
  return (1);
}
