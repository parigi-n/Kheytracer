/*
** find_baricenter.c for find in /home/noswor_o/MUL_2014_rtracer/oscar
** 
** Made by Oscar Nosworthy
** Login   <noswor_o@epitech.net>
** 
** Started on  Thu Jun  4 17:46:34 2015 Oscar Nosworthy
** Last update Sat Jun  6 16:38:57 2015 Oscar Nosworthy
*/

#include "struct.h"
#include "rt.h"

t_coor		find_intersection(t_coor inter, t_light *vec, double k)
{
  inter.x = vec->pos.x + k * vec->v.x;
  inter.y = vec->pos.y + k * vec->v.y;
  inter.z = vec->pos.z + k * vec->v.z;
  return (inter);
}

t_coor		find_coor(t_coor coor, t_light *vec, t_object *obj)
{
  coor.x = (vec->pos.x - obj->pos.x);
  coor.y = (vec->pos.y - obj->pos.y);
  coor.z = (vec->pos.z - obj->pos.z);
  return (coor);
}

double		inter_triangle(t_all *all, t_light *vec, t_object *obj)
{
  t_tri		triangle;
  t_tri		edges;
  t_tri		cross_edges;
  t_coor	inter;
  t_coor	normal;
  t_coor	coor;
  double	k;

  (void)all;
  triangle = create_triangle(triangle);
  edges = find_edges(edges, triangle);
  normal = cross_product(edges.tr1, edges.tr2);
  coor = find_coor(coor, vec, obj);
  k = - dot_product(coor, normal) / dot_product((vec->v), normal);
  inter = find_intersection(inter, vec, k);
  cross_edges.tr1 = minus(inter, triangle.tr2);
  cross_edges.tr2 = minus(inter, triangle.tr1);
  cross_edges.tr3 = minus(inter, triangle.tr3);

  if (k > 0.0000001)
    {
      if (dot_product(normal, cross_product(edges.tr1, cross_edges.tr1)) > 0 &&
	  dot_product(normal, cross_product(edges.tr2, cross_edges.tr2)) > 0 &&
	  dot_product(normal, cross_product(edges.tr3, cross_edges.tr3)) > 0)
	return (k);
    }
  return (0.0);
}
