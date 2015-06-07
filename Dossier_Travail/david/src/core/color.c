/*
** shinny.c for shinny in /home/vautie_a/rendu/MUL_2014_rtracer/src/raytracer
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Jun  6 22:26:41 2015 Jules Vautier
** Last update Sun Jun  7 19:40:32 2015 david sebaoun
*/

#include "struct.h"

void		hex_to_color(int color, t_color *res)
{
  res->red = (color % 256);
  color = (color / 256);
  res->green = (color % 256);
  color = (color / 256);
  res->blue = (color % 256);
}
