/*
** show_object.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Fri May 29 10:40:46 2015 david sebaoun
** Last update Sun Jun  7 23:06:32 2015 david sebaoun
*/

#include <stdio.h>
#include "shared.h"
#include "struct.h"
#include "string.h"
#include "printf.h"

static int	display_objects(t_scene *scene)
{
  t_object	*tmp;

  tmp = scene->obj;
  while (tmp != NULL)
    {
      my_putstr("\033[1m----------------------------------\033[0m\n");
      printf("name: %s\ntype: %d\nax: %f\nay: %f\naz: %f\nposx: \
%f\nposy: %f\nposz: %f\nr: %d\nlim: %d\ncolor: %d\n",
	     tmp->name, tmp->type, tmp->a.x, tmp->a.y, tmp->a.z, tmp->pos.x,
	     tmp->pos.y, tmp->pos.z, tmp->r, tmp->lim, tmp->color);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

static int	display_lights(t_scene *scene)
{
  t_light	*tmp;

  tmp = scene->light;
  while (tmp != NULL)
    {
      my_putstr("\033[1m----------------------------------\033[0m\n");
      printf("name: %s\nx: %f\ny: %f\nz: %f\ncolor: %d\n",
  	     tmp->name, tmp->pos.x, tmp->pos.y, tmp->pos.z, tmp->color);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

int		show(t_all *all, t_scene *scene)
{
  if (all->loaded == ERROR)
    return (puterr(ERROR_NO_SCENE));
  my_printf("\033[0;47m                                  \033[0m\n%s\n\033[0;47m\
                                  \033[0m\n", scene->name);
  display_objects(scene);
  display_lights(scene);
  return (SUCCESS);
}
