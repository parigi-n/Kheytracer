/*
** render.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 16:40:49 2015 david sebaoun
** Last update Sun Jun  7 20:22:00 2015 Jules Vautier
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "rt.h"
#include "cmd.h"
#include "wordtab.h"

static int	init_render(t_all *all, t_scene *scene)
{
  all->scene = *scene;
  all->current_obj = 0;
  all->current_light = 0;
  if (check_error(all, &all->scene) == ERROR)
    {
      puterr("Error: error while opening window\n");
      exit(ERROR);
    }
  return (SUCCESS);
}

int	render(t_all *all, t_scene *scene)
{
  int		status;
  pid_t		pid;

  if (all->loaded != SUCCESS)
    return (puterr("Error: No scene loaded\n"));
  /* if (gere_flag(&all->flag, my_tablen(all->tab), all->tab) == ERROR) */
  /*   return (SUCCESS); */
  if ((pid = fork()) == ERROR)
    return (ERROR);
  if (pid == 0)
    {
      init_render(all, scene);
      init_calc(all);
      if (raytrace(all, &all->scene) == 1)
      	return (SUCCESS);
      mlx_expose_hook(all->var.win_ptr, gere_expose, all);
      mlx_hook(all->var.win_ptr, KeyPress, KeyRelease, &gere_key, all);
      mlx_loop(all->var.mlx_ptr);
    }
  else
    wait(&status);
  return (SUCCESS);
}
