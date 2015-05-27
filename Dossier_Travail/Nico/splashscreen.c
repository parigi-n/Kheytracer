/*
** wolf3d.c for wold3d in /home/parigi_n/Testrendu/MUL_2014_wolf3d
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sun Dec 28 17:13:35 2014 Nicolas PARIGI
** Last update Tue May 26 18:14:02 2015 Nicolas PARIGI
*/

#include <usr/minilibx/mlx.h>
#include <stdlib.h>
#include "X11/X.h"
#include "minilibx.h"

typedef struct  s_data
{
  void          *mlx_ptr;
  void          *win_ptr;
  void          *img_ptr;
  void          *img_interface;
  char          *img_data;
  int           bpp;
  int           sizeline;
  int           endian;
  int           x_xpm;
  int           y_xpm;
}               t_data;

# define MLX_KEY_ESC            65307


int		gere_key(int keycode, t_data *data)
{
  if (keycode == MLX_KEY_ESC)
    {
      exit(0);
    }
  gere_expose(data);
  return (0);
}

int		gere_expose(t_data *data)
{
  mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
  return (0);
}

int		init_wolf3d(t_data *data)
{
  if ((data->mlx_ptr = mlx_init()) == 0)
    return (puterr("mlx_init error"));
  if ((data->win_ptr = mlx_new_window
       (data->mlx_ptr, SCREEN_X, SCREEN_Y, "Wold 3D !")) == 0)
    return (puterr("mlx_new_window error"));
  if ((data->img_interface = mlx_xpm_file_to_image
       (data->mlx_ptr, "raytracer.xpm", &data->x_xpm, &data->y_xpm)) == 0)
    return (puterr("mlx xpm loading fail"));
  data->img_data = mlx_get_data_addr
    (data->img_ptr, &data->bpp, &data->sizeline, &data->endian);
  return (0);
}

int		main()
{
  t_data	data;

  if ((init_wolf3d(&data)) == -1)
    return (-1);
  mlx_hook(data.win_ptr, KeyPress, KeyRelease, gere_key, &data);
  mlx_expose_hook(data.win_ptr, gere_expose, &data);
  mlx_loop(data.mlx_ptr);
  return (0);

}
