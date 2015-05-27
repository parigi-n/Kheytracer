/*
** check.c for check in /home/vautie_a/rendu/MUL_2014_fdf/igraph
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sat Dec  6 13:25:31 2014 Jules Vautier
** Last update Thu Mar  5 10:28:08 2015 Jules Vautier
*/

#include "rtv1.h"

int	check_error(t_img *var)
{
  if ((var->mlx_ptr = mlx_init()) == 0)
    {
      puterr("Error: mlx_init failed.\n");
      return (-1);
    }
  if ((var->win_ptr = mlx_new_window
       (var->mlx_ptr, SIZE_LARG, SIZE_LONG, "RTV1")) == 0)
    {
      puterr("Error: mlx_new_window failed.\n");
      return (-1);
    }
  if ((var->img_ptr = mlx_new_image
       (var->mlx_ptr, SIZE_LARG, SIZE_LONG)) == 0)
    return (-1);
  if ((var->data = mlx_get_data_addr
       (var->img_ptr, &var->bpp, &var->sizeline, &var->endian)) == NULL)
    return (-1);
  return (0);
}
