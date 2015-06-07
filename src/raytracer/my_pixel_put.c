/*
** my_pixel_put.c for loading in /home/parigi_n/Testrendu/MUL_2014_Raytracer/rtv1_src
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Apr 14 16:57:05 2015 Nicolas PARIGI
** Last update Sun Jun  7 11:53:03 2015 Jules Vautier
** Last update Tue May 26 19:15:00 2015 david sebaoun
*/

#include "struct.h"
#include "rt.h"
#include "printf.h"


static void	my_pixel_put(int nbr, char *img,
			     unsigned int color,
			     int intensity)
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
  img[nbr] = MAXCOLOR(red);
  green = (green * intensity) / 1000;
  img[nbr + 1] = MAXCOLOR(green);
  blue = (blue * intensity) / 1000;
  img[nbr + 2] = MAXCOLOR(blue);
}

static int	find_color(t_all *all, t_light **list,
			   t_object *save, t_scene *scene)
{
  t_light	*lum;
  int		ret;
  int		inten;

  lum = *list;
  ret = 0;
  while (lum != NULL)
    {
      if (all->flag.intensity == 1)
	inten = prepare_intensity(all, lum, save, scene);
      else
	inten = 1000 / scene->nb_light;
      if (all->flag.shadow == 1 &&
	  shadow(all, lum, scene) == 0)
	inten = 0;
      if (inten < 0)
	inten = 0;
	ret = ret + inten;
      lum = lum->next;
    }
  return (ret);
}

static void	init_coor_pixel(t_all *all,
				t_scene *scene, t_object *save)
{
  calc_point_eye(&scene->eye, all->pixel_nb);
  calc_vec(&scene->eye, save);
  if (all->flag.rotate == 1)
    {
      rotate(&scene->eye, scene->eye.a, 1);
      rotate(&scene->eye, save->a, 1);
    }
  /*find_point(&scene->eye, &all->point, all->calc.tmpk);*/
}

int		creat_pixel(t_all *all, t_scene *scene)
{
  int		intensity;

  intensity = 1000;
  all->calc.tmpk = all->calc.k;
  all->calc.save = all->obj;
  if (all->calc.save == NULL)
    {
      my_pixel_put(all->pixel_nb, all->var.data, 0xFFFFFF, 500);
      return (0);
    }
  intensity = find_color(all, &scene->light,
			 all->calc.save, scene);
  if (all->calc.save != NULL)
    my_pixel_put(all->pixel_nb, all->var.data,
		 all->calc.save->color, intensity);
  return (0);
}
