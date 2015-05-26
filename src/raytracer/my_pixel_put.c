/*
** my_pixel_put.c for loading in /home/parigi_n/Testrendu/MUL_2014_Raytracer/rtv1_src
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Apr 14 16:57:05 2015 Nicolas PARIGI
** Last update Tue May 26 18:04:37 2015 Jules Vautier
*/

#include "struct.h"
#include "rtv1.h"
#include "printf.h"


static void	my_pixel_put(int nbr, char *img,
			     unsigned int color, int intensity)
{
  int		red;
  int		green;
  int		blue;

  red = (color % 256);
  color = (color / 256);
  green = (color % 256);
  color = (color / 256);
  blue = (color % 256);
  red = red * intensity / 1000;
  red = red + 20;
  img[nbr] = MAXCOLOR(red);
  green = green * intensity / 1000;
  green = green + 20;
  img[nbr + 1] = MAXCOLOR(green);
  blue = blue * intensity / 1000;
  blue = blue + 20;
  img[nbr + 2] = MAXCOLOR(blue);
}

int		creat_pixel(t_all *all)
{
  int		intensity;
  t_object	*save;

  save = all->obj_nb;
  intensity = 1000;
  if (all->flag.shadow == 1)
    intensity = 1000 - shadow(all);
  if (all->flag.intensity == 1)
    intensity = intensity_main(all, &all->object, all->obj_nb, intensity);
  if (save != NULL)
    my_pixel_put(all->pixel_nb, all->var.data,
	       save->color, intensity);
  else
    my_pixel_put(all->pixel_nb, all->var.data,
	       0, intensity);
  return (0);
}
