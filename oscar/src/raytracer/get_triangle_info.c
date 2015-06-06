/*
** get_triangle_info.c for tri in /home/noswor_o/MUL_2014_rtracer/oscar
** 
** Made by Oscar Nosworthy
** Login   <noswor_o@epitech.net>
** 
** Started on  Sat Jun  6 11:43:23 2015 Oscar Nosworthy
** Last update Sat Jun  6 11:44:23 2015 Oscar Nosworthy
*/

#include "struct.h"
#include "rt.h"

t_coor  create_tr1(t_coor tr1)
{
  tr1.x = -300;
  tr1.y = -400;
  tr1.z = 0;
  return (tr1);
}

t_coor  create_tr2(t_coor tr2)
{
  tr2.x = -300;
  tr2.y = 0;
  tr2.z = 0;
  return (tr2);
}

t_coor  create_tr3(t_coor tr3)
{
  tr3.x = -300;
  tr3.y = 0;
  tr3.z = -400;
  return (tr3);
}

t_tricor        create_triangle(t_tricor triangle)
{
  triangle.tr1 = create_tr1(triangle.tr1);
  triangle.tr2 = create_tr2(triangle.tr2);
  triangle.tr3 = create_tr3(triangle.tr3);
  return (triangle);
}

t_tricor        find_edges(t_tricor edges, t_tricor tri)
{
  edges.tr1 = minus(tri.tr1, tri.tr2);
  edges.tr2 = minus(tri.tr3, tri.tr1);
  edges.tr3 = minus(tri.tr2, tri.tr3);
  return (edges);
}
