/*
** rtv1.c for rtv1.c in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Feb  4 08:58:47 2015 Jules Vautier
** Last update Fri Jun  5 17:43:26 2015 Jules Vautier
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
			  t_light *lum)
{
  t_object	*obj;
  double	tmpk;

  obj = *list;
  all->calc.k = 99999.0;
  all->obj = NULL;
  while (obj != NULL)
    {
      calc_point_lum(&all->eye, lum, obj, all->calc.tmpk);
      /*if (all->flag.rotate == 1)
	{
	  rotate(&all->eye, &all->object[NB_OBJ], 1);
	  rotate(&all->eye, obj, 1);
	  }*/
      tmpk = g_fonct[obj->type].ptr(all, lum, obj);
      if (tmpk > 0.000001 && tmpk < all->calc.k)
	{
	  all->calc.k = tmpk;
	  all->obj = obj;
	}
      obj = obj->next;
    }
 return (0);
}

int		shadow(t_all *all, t_light *lum, t_scene *scene)
{
  /*t_coor	point_lum;
  t_coor	point_eye;*/

  /*find_point(lum, &point_lum, all->calc.k);*/
  do_shadow(all, &scene->obj, lum);
  if (all->obj == NULL)
    return (1);
  if (my_strcmp(all->calc.save->name, all->obj->name) == 0)
    return (1);
  return (0);
}
