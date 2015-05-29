/*
** rtv1.c for rtv1.c in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Feb  4 08:58:47 2015 Jules Vautier
** Last update Fri May 29 11:23:12 2015 Jules Vautier
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
  double	tmpk;

  obj = *list;
  all->calc.k = 9999999.0;
  all->obj = NULL;
  while (obj != NULL)
    {
      calc_point_lum(&all->eye, lum, obj, k);
      /*if (all->flag.rotate == 1)
	{
	  rotate(&all->eye, &all->object[NB_OBJ], 1);
	  rotate(&all->eye, obj, 1);
	  }*/
      k = g_fonct[obj->type].ptr(all, lum, obj);
      if (k > 0.0 && k < all->calc.k)
	{
	  all->calc.k = k;
	  all->obj = obj;
	}
      obj = obj->next;
    }
 return (0);
}

int		shadow(t_all *all, double k,
		       t_vec *lum, t_object *save)
{
  t_coor	point_lum;
  t_coor	point_eye;

  find_point(&all->eye, &point_eye, k);
  do_shadow(all, &all->object, k, lum);
  find_point(lum, &point_lum, all->calc.k);
  /*if (all->obj == NULL)
    return (1);*/
  if (my_strcmp(save->name, all->obj->name) != 0)
    return (1);
  /*if (point_lum.x > point_eye.x + 100.00001 ||
      point_lum.y > point_eye.y + 100.00001 ||
      point_lum.z > point_eye.z + 100.00001 ||
      point_lum.x < point_eye.x - 100.00001 ||
      point_lum.y < point_eye.y - 100.00001 ||
      point_lum.z < point_eye.z - 100.00001 )
      return (0);*/
  /*if (my_strcmp(save->name, "plan") != 0)
    printf("%s %s\n", save->name, all->obj->name);*/
  return (1);
}
