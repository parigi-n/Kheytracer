/*
** color.c for color in /home/vautie_a/rendu/MUL_2014_rtracer/src/raytracer
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sun Jun  7 20:08:01 2015 Jules Vautier
** Last update Sun Jun  7 20:46:55 2015 Jules Vautier
*/

#include "rt.h"
#include <stdio.h>

void		calc_color(t_object *obj, t_color lum,
			   double intensity, t_color *res)
{
  t_color	tmp;

  tmp.red = obj->color_int.red * (1.0 - obj->shine)
    + lum.red * obj->shine;
  tmp.red = tmp.red * intensity;
  tmp.green = obj->color_int.green * (1.0 - obj->shine)
    + lum.green * obj->shine;
  tmp.green = tmp.green * intensity;
  tmp.blue = obj->color_int.blue * (1.0 - obj->shine)
    + lum.blue * obj->shine;
  tmp.blue = tmp.blue * intensity;
  res->red = res->red + tmp.red;
  res->green = res->green + tmp.green;
  res->blue = res->blue + tmp.blue;
}
