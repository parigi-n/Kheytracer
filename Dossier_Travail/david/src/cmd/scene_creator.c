/*
** scene_creator.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:38:32 2015 david sebaoun
** Last update Sat Jun  6 16:26:43 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"
#include "printf.h"

/* static int		display(void *data) */
/* { */
/*   struct winsize	w; */

/*   if (file[0].state == ERROR) */
/*     return (SUCCESS); */
/*   ioctl(0, TIOCGWINSZ, &w); */
/*   my_printf("", ); */
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
  /* display(); */
  return (SUCCESS);
}
