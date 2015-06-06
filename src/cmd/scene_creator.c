/*
** scene_creator.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:38:32 2015 david sebaoun
** Last update Sat Jun  6 12:17:36 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"

/* static int		display(t_scene *scene) */
/* { */
/*   struct winsize	w; */

/*   data->i = 0; */
/*   data->x = 0; */
/*   data->z = 0; */
/*   if (file[0].state == ERROR) */
/*     return (SUCCESS); */
/*   ioctl(0, TIOCGWINSZ, &w); */
/*   /\* if (keycode == BACKSPACE || keycode == DELETE) *\/ */
/*   /\*   my_clear(data, 2); *\/ */
/*   /\* if (verif_size(file, data) == 0) *\/ */
/*   /\*   return (1); *\/ */
/*   while (file[data->i].name != NULL) */
/*     { */
/*       data->z = 0; */
/*       while (data->z < w.ws_row && file[data->i].name != NULL) */
/*         { */
/* 	  font(file[data->i].state); */
/* 	  my_putstr(tgoto(data->term_cm, data->x, data->z++), 2); */
/* 	  my_putstr(file[data->i++].name, 2); */
/*    	  my_putstr(DEF, 2); */
/* 	} */
/*       data->x += max_length(file, data->i, data->z) + 2; */
/*     } */
/*   return (SUCCESS); */
/* } */

int	create(t_all *all, t_scene *scene)
{
  if (all->tab[1] == NULL)
    {
      my_putstr("Usage: create file.khey\n");
      return (ERROR);
    }
  (void)scene;
  /* display(scene); */
  return (SUCCESS);
}
