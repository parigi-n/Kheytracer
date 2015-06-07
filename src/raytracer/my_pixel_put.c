/*
** my_pixel_put.c for pixel in /home/vautie_a/rendu/MUL_2014_rtracer/src/raytracer
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sun Jun  7 23:21:41 2015 Jules Vautier
** Last update Sun Jun  7 23:21:43 2015 Jules Vautier
*/

#include "struct.h"
#include "rt.h"

static void	my_pixel_put(int nbr, char *img, t_color color)
{
  img[nbr] = MAXCOLOR(color.blue);
  img[nbr + 1] = MAXCOLOR(color.green);
  img[nbr + 2] = MAXCOLOR(color.red);
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
    inten = 0.0;
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
      intensity = find_intensity(all, lum, scene);
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
