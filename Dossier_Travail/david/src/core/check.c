/*
** check.c for check in /home/vautie_a/rendu/MUL_2014_fdf/igraph
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Dec  6 13:25:31 2014 Jules Vautier
<<<<<<< HEAD
** Last update Sat Jun  6 16:24:37 2015 david sebaoun
*/

#include "shared.h"
#include "rt.h"

int	check_error(t_all *all)
{
  if ((all->var.mlx_ptr = mlx_init()) == 0)
    {
      puterr("Error: mlx_init failed.\n");
      return (ERROR);
    }
  if ((all->var.win_ptr = mlx_new_window
       (all->var.mlx_ptr, SIZE_LARG, SIZE_LONG, all->name)) == 0)
    {
      puterr("Error: mlx_new_window failed.\n");
      return (ERROR);
    }
  if ((all->var.img_ptr = mlx_new_image
       (all->var.mlx_ptr, SIZE_LARG, SIZE_LONG)) == 0)
    return (ERROR);
  if ((all->var.data = mlx_get_data_addr
       (all->var.img_ptr, &all->var.bpp, &all->var.sizeline, &all->var.endian)) == NULL)
    return (ERROR);
  return (SUCCESS);
}
