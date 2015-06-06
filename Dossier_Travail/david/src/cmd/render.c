/*
** render.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 16:40:49 2015 david sebaoun
** Last update Sat Jun  6 18:23:48 2015 david sebaoun
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "rt.h"
#include "cmd.h"
#include "wordtab.h"

int	render(t_all *all, t_scene *scene)
{
  int	status;
  pid_t	pid;

  if (all->loaded != SUCCESS)
    return (puterr("Error: No scene loaded\n"));
  if (gere_flag(&all->flag, my_tablen(all->tab), all->tab) == ERROR)
    return (SUCCESS);
  if ((pid = fork()) == ERROR)
    return (ERROR);
  if (pid == 0)
    {
      if (check_error(all, scene) == ERROR)
	{
	  puterr("Error: error while opening window\n");
	  exit(ERROR);
	}
      init_calc(all);
      if (raytrace(all, scene) == 1)
      	return (SUCCESS);
      mlx_expose_hook(all->var.win_ptr, gere_expose, all);
      mlx_hook(all->var.win_ptr, KeyPress, KeyRelease, &gere_key, all);
      mlx_loop(all->var.mlx_ptr);
    }
  else
    wait(&status);
  return (SUCCESS);
}
