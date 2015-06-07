/*
** color.c for color in /home/vautie_a/rendu/MUL_2014_rtracer/src/raytracer
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sun Jun  7 20:08:01 2015 Jules Vautier
** Last update Sun Jun  7 21:25:55 2015 Jules Vautier
*/

#include "rt.h"
#include <stdio.h>

void		calc_color(t_object *obj, t_color lum,
			   double intensity, t_color *res)
{
  t_color	tmp;
  int		tmp_shine;
  int		tmp_inten;

  tmp_shine = obj->shine * 1000.0;
  tmp_inten = intensity * 1000.0;
  tmp.red = obj->color_int.red * (1000 - tmp_shine) / 1000
    + lum.red * tmp_shine / 1000;
  tmp.red = tmp.red * tmp_inten / 1000;
  tmp.green = obj->color_int.green * (1000 - tmp_shine) / 1000
    + lum.green * tmp_shine / 1000;
  tmp.green = tmp.green * tmp_inten / 1000;
  tmp.blue = obj->color_int.blue * (1000 - tmp_shine) / 1000
    + lum.blue * tmp_shine / 1000;
  tmp.blue = tmp.blue * tmp_inten / 1000;
  res->red = res->red + tmp.red;
  res->green = res->green + tmp.green;
  res->blue = res->blue + tmp.blue;

}
