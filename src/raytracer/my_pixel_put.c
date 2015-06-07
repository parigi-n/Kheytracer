/*
** my_pixel_put.c for loading in /home/parigi_n/Testrendu/MUL_2014_Raytracer/rtv1_src
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Apr 14 16:57:05 2015 Nicolas PARIGI
<<<<<<< HEAD
** Last update Sun Jun  7 18:07:54 2015 Jules Vautier
=======
** Last update Sun Jun  7 16:31:46 2015 Oscar Nosworthy
>>>>>>> 5da8d75c10bc34ba9e58f99d732e5a3075bb1bc4
** Last update Tue May 26 19:15:00 2015 david sebaoun
*/

#include "struct.h"
#include "rt.h"
#include <stdio.h>

static void	my_pixel_put(int nbr, char *img,
			     unsigned int color,
			     double intensity)
{
  int		red;
  int		green;
  int		blue;

  red = (color % 256);
  color = (color / 256);
  green = (color % 256);
  color = (color / 256);
  blue = (color % 256);
  red = (red * intensity);
  img[nbr] = MAXCOLOR(red);
  green = (green * intensity);
  img[nbr + 1] = MAXCOLOR(green);
  blue = (blue * intensity);
  img[nbr + 2] = MAXCOLOR(blue);
}

static double	find_color(t_all *all, t_light **list,
			   t_object *save, t_scene *scene)
{
  t_light	*lum;
  double	ret;
  double	inten;

  lum = *list;
  ret = 0.0;
  while (lum != NULL)
    {
      if (all->flag.intensity == 1)
	inten = prepare_intensity(all, lum, save, scene);
      else
	inten = 1.0 / scene->nb_light;
      if (all->flag.shadow == 1 &&
	  shadow(all, lum, scene) == 0)
	inten = inten / (scene->nb_light + 1);
      if (inten < 0)
	inten = 0;
	ret = ret + inten;
      lum = lum->next;
    }
  return (ret);
}

int		creat_pixel(t_all *all, t_scene *scene)
{
  double	intensity;

  all->calc.tmpk = all->calc.k;
  all->calc.save = all->obj;
  if (all->calc.save == NULL)
    {
      my_pixel_put(all->pixel_nb, all->var.data, 0xFFFFFF, 0.0);
      return (0);
    }
  intensity = find_color(all, &scene->light,
			 all->calc.save, scene);
  /*printf("%f\n", intensity);*/
  if (all->calc.save != NULL)
    my_pixel_put(all->pixel_nb, all->var.data,
		 all->calc.save->color, intensity);
  return (0);
}
