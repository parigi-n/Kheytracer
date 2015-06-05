/*
** my_pixel_put.c for loading in /home/parigi_n/Testrendu/MUL_2014_Raytracer/rtv1_src
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Apr 14 16:57:05 2015 Nicolas PARIGI
<<<<<<< HEAD
** Last update Mon Jun  1 11:36:37 2015 Jules Vautier
=======
** Last update Tue May 26 19:15:00 2015 david sebaoun
>>>>>>> 7b4f8b46492ef0dc1a0dac4d9277e1b011142ae6
*/

#include "struct.h"
#include "rt.h"
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

static int	find_color(t_all *all, t_vec **list, t_object *save)
{
  t_vec		*lum;
  int		ret;
  int		inten;
  int		check;
  double	k;

  k = all->calc.k;
  lum = *list;
  ret = 0;
  while (lum != NULL)
    {
      if (all->flag.intensity == 1)
	inten = prepare_intensity(all, lum, save, k);
      else
	inten = 1000;
      if (all->flag.shadow == 1)
	inten = inten * shadow(all, k, lum, save);
      if (inten < 0)
	inten = 0;
      ret = ret + inten;
      lum = lum->next;
    }
  return (ret);
}

int		creat_pixel(t_all *all)
{
  int		intensity;
  t_object	*save;

  intensity = 1000;
  save = all->obj;
  find_point(&all->eye, &all->point, all->calc.k);
  if (save == NULL)
    {
      my_pixel_put(all->pixel_nb, all->var.data, 0, 0);
      return (0);
    }
  intensity = find_color(all, &all->lum, save);
  if (save != NULL)
    my_pixel_put(all->pixel_nb, all->var.data,
	       save->color, intensity);
  return (0);
}
