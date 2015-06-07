/*
** triangle_tools.c for tools in /home/noswor_o/MUL_2014_rtracer/oscar
** 
** Made by Oscar Nosworthy
** Login   <noswor_o@epitech.net>
** 
** Started on  Sat Jun  6 11:25:32 2015 Oscar Nosworthy
** Last update Sun Jun  7 16:13:18 2015 Oscar Nosworthy
*/

#include "struct.h"
#include "rt.h"

t_coor		cross_product(t_coor point1, t_coor point2)
{
  t_coor	product;
  product.x = (point1.y * point2.z) - (point1.z * point2.y);
  product.y = (point1.x * point2.z) - (point1.z * point2.x);
  product.z = (point1.y * point2.x) - (point1.x * point2.y);
  return (product);
}

double		dot_product(t_coor point1, t_coor point2)
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
