/*
** my_pixel_put.c for loading in /home/parigi_n/Testrendu/MUL_2014_Raytracer/rtv1_src
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Apr 14 16:57:05 2015 Nicolas PARIGI
** Last update Wed May 27 09:44:04 2015 Jules Vautier
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
  red = (red * intensity) / 1000;
  red = red + 20;
  img[nbr] = MAXCOLOR(red);
  green = (green * intensity) / 1000;
  green = green + 20;
  img[nbr + 1] = MAXCOLOR(green);
  blue = (blue * intensity) / 1000;
  blue = blue + 20;
  img[nbr + 2] = MAXCOLOR(blue);
}

int		creat_pixel(t_all *all)
{
  int		intensity;
  t_object	*save;
  double		k;

  save = all->obj_nb;
  if (save == NULL)
    {
      my_pixel_put(all->pixel_nb, all->var.data, 0, 0);
      return (0);
    }
  k = all->calc.k;
  intensity = 1000;
  if (all->flag.intensity == 1)
    intensity = intensity_main(all, all->obj_nb, intensity);
  if (all->flag.shadow == 1)
    intensity = intensity - shadow(all, k);
  if (intensity < 0)
    intensity = 0;
  if (save != NULL)
    my_pixel_put(all->pixel_nb, all->var.data,
	       save->color, intensity);
  return (0);
}
