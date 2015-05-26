/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
** Last update Tue May 26 19:14:33 2015 david sebaoun
*/

#include "struct.h"
#include "rt.h"

/*static int	do_calc(t_vec *vec, t_calc *var, t_object *coor)
{
  var->a = (vec->vx * vec->vx)
    + (vec->vy * vec->vy);
  var->b = 2 * ((vec->tmobject * vec->vx)
           + (vec->tmpy * vec->vy));
  var->c = ((vec->tmobject * vec->tmobject)
       + (vec->tmpy * vec->tmpy)
       - coor->r * coor->r * 2);
  return (0);
}

static int	end_calc(t_object *coor, t_calc *var, double delta, t_vec *vec)
{
  double	tmp;

  coor->k = ((-var->b + sqrt(delta)) / (2 * var->a));
  tmp = ((-var->b - sqrt(delta)) / (2 * var->a));
  if (tmp < coor->k)
    coor->k = tmp;
  if (coor->k * vec->vz + vec->posz > 0.0 &&
      coor->k * vec->vz + vec->posz < 800.0)
    return (coor->is_true = 1);
  else
    return (coor->is_true = 0);
    }*/

int		inter_cylinder(t_all *all, t_vec *vec, t_object *coor)
{
  /*t_calc	var;
  double	delta;

  (void)all;
  do_calc(vec, &var, coor);
  delta = ((var.b * var.b) - (4 * var.a * var.c));
  if (delta >= 0.0)
    return (end_calc(coor, &var, delta, vec));
  else
    {
      coor->k = 0.0;
      return (coor->is_true = 0);
      }*/
}
