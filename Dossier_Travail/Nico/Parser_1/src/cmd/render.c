/*
** render.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 16:40:49 2015 david sebaoun
** Last update Thu May 28 07:57:26 2015 Jules Vautier
*/

#include "rt.h"
#include "cmd.h"

int	render(t_all *all)
{
  if (check_error(&all->var) == ERROR)
    {
      puterr("Error: error while opening window\n");
      return (ERROR);
    }
  init_calc(all);
  raytrace(all);
  mlx_expose_hook(all->var.win_ptr, gere_expose, all);
  mlx_hook(all->var.win_ptr, KeyPress, KeyRelease, &gere_key, all);
  mlx_loop(all->var.mlx_ptr);
  return (SUCCESS);
}
