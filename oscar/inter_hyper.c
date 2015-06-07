/*
** inter_hyper.c for ray in /home/noswor_o/dim/MUL_2014_rtracer
** 
** Made by Oscar Nosworthy
** Login   <noswor_o@epitech.net>
** 
** Started on  Sun Jun  7 16:06:38 2015 Oscar Nosworthy
** Last update Sun Jun  7 16:54:16 2015 Oscar Nosworthy
*/

#include "rt.h"
#include "struct.h"

int		delta_hyper(double a, double b, double d, double k)
{
  double	r1;
  double	r2;

  if (d >= 0.0)
    {
      r1 = (-b - sqrt(d)) / (2 * a);
      r2 = (-b + sqrt(d)) / (2 * a);
      if (r1 < 0.0 && r2 < 0.0)
	return (0.0);
      else if (r2 < r1 && r2 >= 0.0)
	k = r2;
      else
	k = r1;
    }
  return (k);
}

double		inter_hyper(t_all *all, t_light *vec, t_object *object)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	limite;
  double	k;

  (void)all;
  (void)object;
  c = pow(vec->tmp.z, 2) + (8000) - pow(vec->tmp.x, 2) - pow(vec->tmp.y, 2);
  b = 2.0*(vec->tmp.z * vec->v.z - vec->tmp.x * vec->v.x
	   - vec->tmp.y * vec->v.y);
  a = pow(vec->v.z, 2) - pow(vec->v.x, 2)
    - pow(vec->v.y, 2);
  delta = (b * b) - (4 * (a * c));
  if ((k = delta_hyper(a, b, delta, k)) == 0.0)
    return (0.0);
  limite =  (vec->v.z * k + vec->pos.z);
  if (limite > 100 || limite < -500)
    return (0.0);
  return (k);
}

double		inter_hyper2(t_all *all, t_light *vec, t_object *object)
{
  double	a;
  double	b;
  double	c;
  double	delta;
  double	limite;
  double	k;

  (void)all;
  (void)object;
  c = pow(vec->tmp.z, 2) + (-8000) - pow(vec->tmp.x, 2) - pow(vec->tmp.y, 2);
  b = 2.0*(vec->tmp.z * vec->v.z - vec->tmp.x * vec->v.x
	   - vec->tmp.y * vec->v.y);
  a = pow(vec->v.z, 2)-pow(vec->v.x, 2) - pow(vec->v.y, 2);
  delta = (b * b) - (4 * (a * c));
  if ((k = delta_hyper(a, b, delta, k)) == 0.0)
    return (0.0);
  limite =  (vec->v.z * k + vec->pos.z);
  if (limite > 100 || limite < -500)
    return (0.0);
  return (k);
}
