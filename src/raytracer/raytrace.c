/*
** rtv1.c for rtv1.c in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed Feb  4 08:58:47 2015 Jules Vautier
** Last update Tue May 26 16:28:15 2015 Jules Vautier
*/

#include "shared.h"
#include "struct.h"
#include "rtv1.h"
#include <stdio.h>

static const	t_fonct g_fonct[] =
  {
    {&inter_sphere, TYPE_SPHERE},
    {&inter_cone, TYPE_CONE},
    {&inter_cylinder, TYPE_CYLINDER},
    {&inter_plan, TYPE_PLAN},
    {NULL, -1}
  };

static int	end_k(t_all *all, t_object *obj_nb)
{
  if (obj_nb == NULL)
    all->calc.k = 0.0;
  else
      all->calc.k = obj_nb->k;
  all->obj_nb = obj_nb;
  return (0);
}

int		do_k(t_all *all, t_object **obj)
{
  double	tmpk;
  t_object	*tmp;
  t_object	*obj_nb;

  tmp = *obj;
  tmpk = 999999.0000;
  obj_nb = NULL;
  while (tmp != NULL)
    {
      if (tmp->is_true == 1)
	if (tmp->k < tmpk)
	  {
	    tmpk = tmp->k;
	    obj_nb = tmp;
	  }
      tmp = tmp->next;
    }
  end_k(all, obj_nb);
  return (0);
}

static int	raycast(t_all *all, t_object **list)
{
  t_object	*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      tmp->is_true = 0;
      calc_vec(&all->eye, tmp);
      /*if (all->flag.rotate == 1)
	{
	  rotate(&all->eye, &all->object[NB_OBJ], 1);
	  rotate(&all->eye, tmp, 1);
	}*/
      g_fonct[tmp->type].ptr(all, &all->eye, tmp);
      tmp = tmp->next;
    }
  return (0);
}

int		raytrace(t_all *all)
{
  all->pixel_nb = 0;
  init_rotate(all);
  my_putstr("Loading, please wait ...\n");
  while (all->pixel_nb < SIZE_IMG)
    {
      calc_point_eye(&all->eye, all->pixel_nb);
      raycast(all, &all->object);
      do_k(all, &all->object);
      all->pixel_nb = all->pixel_nb + 4;
      creat_pixel(all);
      /*if (all->pixel_nb % (SIZE_LARG * 2) == 0)
	gere_expose(all);
      if (all->pixel_nb % ((SIZE_IMG) / 10) == 0)
      my_loading(all->pixel_nb, SIZE_IMG);*/
    }
  gere_expose(all);
  my_putstr("\nDone !\n------------------------\n");
  return (0);
}
