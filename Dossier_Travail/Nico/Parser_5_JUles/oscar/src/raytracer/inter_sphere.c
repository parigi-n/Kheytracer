/*
** inter.c for inter in /home/vautie_a/rendu/MUL_2014_rtv1/TP/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb  5 08:38:05 2015 Jules Vautier
<<<<<<< HEAD
** Last update Wed Jun  3 16:08:50 2015 Oscar Nosworthy
=======
** Last update Tue May 26 19:14:49 2015 david sebaoun
>>>>>>> 7b4f8b46492ef0dc1a0dac4d9277e1b011142ae6
*/

#include "struct.h"
#include "rt.h"

#define	M_PI 3.14159265358979323846

static int	do_calc(t_vec *vec, t_coor *coor, t_object *object)
{
  coor->x = (vec->v.x * vec->v.x)
    + (vec->v.y * vec->v.y)
    + (vec->v.z * vec->v.z);
  coor->y = 2 * ((vec->tmp.x * vec->v.x)
		+ (vec->tmp.y * vec->v.y)
		+ (vec->tmp.z * vec->v.z));
  coor->z = ((vec->tmp.x * vec->tmp.x)
	    + (vec->tmp.y * vec->tmp.y)
	    + (vec->tmp.z * vec->tmp.z)
	    - object->r * object->r * 2);
  return (0);
}

int		inter_sphere(t_all *all, t_vec *vec,
			     t_object *object)
{
  t_coor	coor;
  double	delta;
  double	tmpk;

  (void)all;
  do_calc(vec, &coor, object);
  delta = ((coor.y * coor.y) - 4 * (coor.x * coor.z));
  if (delta > 0.0)
    {
      object->k = ((-coor.y + sqrt(delta)) / (2 * coor.x));
      tmpk = ((-coor.y - sqrt(delta)) / (2 * coor.x));
      if (tmpk < object->k)
	object->k = tmpk;
      return (object->is_true = 1);
    }
  object->k = 0.0;
  object->is_true = 0;
  return (0);
}

int	delta_hyper(double a, double b, double d, t_object *object)
{
  double	res1;
  double	res2;

  if (d >= 0.0)
    {
      res1 = (-b - sqrt(d)) / (2 * a);
      res2 = (-b + sqrt(d)) / (2 * a);
      if (res1 < 0.0 && res2 < 0.0)
	return (-1.0);
      else if (res2 < res1 && res2 >= 0.0)
	object->k = res2;
      else
	object->k = res1;
    }
  else
    return (-1);
}

int		inter_hyper(t_all *all, t_vec *vec,
			     t_object *object)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	r;
  double	rayon;
  double	limite;

  (void)all;
  r = object->r * (double)M_PI / 180.000;
  a = pow(vec->v.x, 2) + pow(vec->v.y, 2) - (pow(vec->v.z, 2)*pow(tan(r), 2));
  b = 2 * ((vec->tmp.x * vec->v.x) + (vec->tmp.y * vec->v.y))
    - ((2 * vec->tmp.z * vec->v.z) * (pow(tan(r), 2)));
  c = pow(vec->tmp.x, 2) + pow(vec->tmp.y, 2)
    - (pow(vec->tmp.z, 2) * pow(tan(r), 2)) + (-8000);
  delta = (b * b) - (4 * (a * c));
  if (delta_hyper(a, b, delta, object) == -1)
    return (object->is_true = 0);
  limite =  (vec->v.z * object->k + vec->pos.z);
  if (limite > 100 || limite < -500)
    return (object->is_true = 0);
  return (object->is_true = 1);
}
