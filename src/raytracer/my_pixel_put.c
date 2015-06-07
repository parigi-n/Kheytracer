/*
** my_pixel_put.c for loading in /home/parigi_n/Testrendu/MUL_2014_Raytracer/rtv1_src
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Apr 14 16:57:05 2015 Nicolas PARIGI
<<<<<<< HEAD
** Last update Sun Jun  7 20:46:06 2015 Jules Vautier
=======
** Last update Sun Jun  7 16:31:46 2015 Oscar Nosworthy
>>>>>>> 5da8d75c10bc34ba9e58f99d732e5a3075bb1bc4
** Last update Tue May 26 19:15:00 2015 david sebaoun
*/

#include "struct.h"
#include "rt.h"
#include <stdio.h>

static void	my_pixel_put(int nbr, char *img, t_color color)
{
  /*printf("%i %i %i\n", color.red, color.green, color.blue);*/
  img[nbr] = MAXCOLOR(color.red);
  img[nbr + 1] = MAXCOLOR(color.green);
  img[nbr + 2] = MAXCOLOR(color.blue);
}

static double	find_intensity(t_all *all, t_light *lum, t_scene *scene)
{
  double	inten;

  if (all->flag.intensity == 1)
    inten = prepare_intensity(all, lum, all->calc.save, scene);
  else
    inten = 1.0 / scene->nb_light;
  if (all->flag.shadow == 1 &&
      shadow(all, lum, scene) == 0)
    inten = inten / (scene->nb_light + 1);
  if (inten < 0)
    inten = 0;
  return (inten);
}

static void	find_color(t_all *all, t_light **list, t_scene *scene)
{
  t_light	*lum;
  double	intensity;
  t_color	res;

  res.red = 0;
  res.green = 0;
  res.blue = 0;
  lum = *list;
  intensity = 0.0;
  while (lum != NULL)
    {
      intensity = intensity + find_intensity(all, lum, scene);
      calc_color(all->calc.save, lum->color_int, intensity, &res);
      lum = lum->next;
    }
  my_pixel_put(all->pixel_nb, all->var.data, res);
}

int		creat_pixel(t_all *all, t_scene *scene)
{
  t_color	noir;

  noir.red = 0;
  noir.green = 0;
  noir.blue = 0;
  all->calc.tmpk = all->calc.k;
  all->calc.save = all->obj;
  if (all->calc.save == NULL)
    {
      my_pixel_put(all->pixel_nb, all->var.data, noir);
      return (0);
    }
  find_color(all, &scene->light, scene);
  return (0);
}
