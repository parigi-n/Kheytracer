/*
** find_baricenter.c for find in /home/noswor_o/MUL_2014_rtracer/oscar
** 
** Made by Oscar Nosworthy
** Login   <noswor_o@epitech.net>
** 
** Started on  Thu Jun  4 17:46:34 2015 Oscar Nosworthy
** Last update Sat Jun  6 10:16:17 2015 Oscar Nosworthy
*/

#include "struct.h"
#include "rt.h"

t_coor	crossProduct(t_coor point1, t_coor point2)
{
  t_coor	product;
  product.x = (point1.y * point2.z) - (point1.z * point2.y);
  product.y = (point1.x * point2.z) - (point1.z * point2.x);
  product.z = (point1.y * point2.x) - (point1.x * point2.y);
  return (product);
}

double	dotProduct(t_coor point1, t_coor point2)
{
  double	dot;

  dot = point1.x * point2.x + point1.y * point2.y + point1.z * point2.z;
  return (dot);
}

t_coor		minus(t_coor point1, t_coor point2)
{
  t_coor	vector;

  vector.x = point1.x - point2.x;
  vector.y = point1.y - point2.y;
  vector.z = point1.z - point2.z;
  return (vector);
}

int	check_edge1(t_coor inter, t_coor edge1, t_coor normal)
{
  t_coor	C0;

  C0 = minus(inter, tr2);
  if (dotProduct(normal, crossProduct(edge1, C0)) > 0)
    return (1);
  return (0);
}

int	check_edge1(t_coor inter, t_coor edge1, t_coor normal)
{
  t_coor	C0;

  C0 = minus(inter, tr2);
  if (dotProduct(normal, crossProduct(edge1, C0)) > 0)
    return (1);
  return (0);
}

int	inter_triangle(t_all *all, t_vec *vec, t_object *obj)
{
  t_coor	tr1;
  t_coor	tr2;
  t_coor	tr3;
  t_coor	inter;
  t_coor	edge1;
  t_coor	edge2;
  t_coor	edge3;
  t_coor	edge4;
  t_coor	normal;
  
  t_coor	C1;
  t_coor	C2;
  t_coor	coor;

  tr1.x = -300;
  tr1.y = 0;
  tr1.z = -100;

  tr2.x = -300;
  tr2.y = -200;
  tr2.z = 0;

  tr3.x = -300;
  tr3.y = -200;
  tr3.z = -100;

  edge1 = minus(tr1, tr2);
  edge2 = minus(tr3, tr1);
  edge3 = minus(tr2, tr3);

  normal = crossProduct(edge1, edge2);
  coor.x = (vec->pos.x - obj->pos.x);
  coor.y = (vec->pos.y - obj->pos.y);
  coor.z = (vec->pos.z - obj->pos.z);

  obj->k = - dotProduct(coor, normal) / dotProduct((vec->v), normal);
  inter.x = vec->pos.x + obj->k * vec->v.x;
  inter.y = vec->pos.y + obj->k * vec->v.y;
  inter.z = vec->pos.z + obj->k * vec->v.z;
  
  C1 = minus(inter, tr1);
  C2 = minus(inter, tr3);

  if (obj->k > 0.0000001)
    {
      if (check_edge1(inter, edge1, normal) == 1 &&
	  dotProduct(normal, crossProduct(edge2, C1)) > 0 &&
	  dotProduct(normal, crossProduct(edge3, C2)) > 0)
	return (obj->is_true = 1);
    }
  return (obj->is_true = 0);
}
