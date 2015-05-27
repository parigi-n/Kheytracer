/*
** wolf3d.c for wold3d in /home/parigi_n/Testrendu/MUL_2014_wolf3d
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sun Dec 28 17:13:35 2014 Nicolas PARIGI
** Last update Wed May 27 17:05:55 2015 Nicolas PARIGI
*/

#include "/usr/include/mlx.h"
#include <stdlib.h>
#include "X11/X.h"
#include "../include/struct.h"

# define MLX_KEY_ESC            65307
# define SCREEN_X 640
# define SCREEN_Y 300

int		gere_key(int keycode, t_img *var)
{
  (void)keycode;
  mlx_destroy_window(var->mlx_ptr, var->win_ptr);
  return (0);
}

int             gere_mouse(int button, int x, int y, t_img *var)
{
  (void)x;
  (void)y;
  (void)button;
  mlx_destroy_window(var->mlx_ptr, var->win_ptr);
  return (0);
}

int		gere_expose(t_img *var)
{
  mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr, 0, 0);
  return (0);
}

int		init_wolf3d(t_img *var)
{
  if ((var->mlx_ptr = mlx_init()) == 0)
    return (puterr("mlx_init error"));
  if ((var->img_ptr = mlx_xpm_file_to_image
       (var->mlx_ptr, "raytracer.xpm", &var->x_xpm, &var->y_xpm)) == 0)
    return (puterr("mlx xpm loading fail"));  
  if ((var->win_ptr = mlx_new_window
       (var->mlx_ptr, SCREEN_X, SCREEN_Y, "Welcome to Kheytracer")) == 0)
    return (puterr("mlx_new_window error"));
  var->data = mlx_get_data_addr
    (var->img_ptr, &var->bpp, &var->sizeline, &var->endian);
  return (0);
}

int		main()
{
  t_img	var;

  if ((init_wolf3d(&var)) == -1)
    return (-1);
  mlx_mouse_hook(var.win_ptr, gere_mouse, &var);
  mlx_hook(var.win_ptr, KeyPress, KeyRelease, gere_key, &var);
  mlx_expose_hook(var.win_ptr, gere_expose, &var);
  mlx_loop(var.mlx_ptr);
  return (0);
}
