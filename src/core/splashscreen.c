/*
** wolf3d.c for wold3d in /home/parigi_n/Testrendu/MUL_2014_wolf3d
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sun Dec 28 17:13:35 2014 Nicolas PARIGI
** Last update Sat Jun  6 12:15:50 2015 david sebaoun
*/
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shared.h"
#include "rt.h"

static int	gere_key_splash(int keycode, t_img *var)
{
  (void)keycode;
  (void)var;
  exit(SUCCESS);
  return (SUCCESS);
}

static int	gere_mouse_splash(int button, int x, int y, t_img *var)
{
  (void)x;
  (void)y;
  (void)var;
  (void)button;
  exit(SUCCESS);
}

static int	gere_expose_splash(t_img *var)
{
  mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, var->img_ptr, 0, 0);
  return (SUCCESS);
}

static int	init(t_img *var)
{
  if ((var->mlx_ptr = mlx_init()) == 0)
    return (puterr("mlx_init error"));
  if ((var->img_ptr = mlx_xpm_file_to_image
       (var->mlx_ptr, "raytracer.xpm", &var->x_xpm, &var->y_xpm)) == 0)
    return (puterr("mlx xpm loading fail"));
  if (var->x_xpm > SPLASHSCREEN_X || var->y_xpm > SPLASHSCREEN_Y)
    return (puterr("mlx_new_window error"));
  if ((var->win_ptr = mlx_new_window
       (var->mlx_ptr, var->x_xpm, var->y_xpm, "Welcome to Kheytracer")) == 0)
    return (ERROR);
  var->data = mlx_get_data_addr
    (var->img_ptr, &var->bpp, &var->sizeline, &var->endian);
  return (SUCCESS);
}

int		splash_screen()
{
  int		status;
  pid_t		pid;
  t_img		var;

  if ((pid = fork()) == ERROR)
    return (ERROR);
  if (pid == 0)
    {
      if ((init(&var)) == ERROR)
	return (ERROR);
      mlx_mouse_hook(var.win_ptr, gere_mouse_splash, &var);
      mlx_hook(var.win_ptr, KeyPress, KeyRelease, gere_key_splash, &var);
      mlx_expose_hook(var.win_ptr, gere_expose_splash, &var);
      mlx_loop(var.mlx_ptr);
    }
  else
    wait(&status);
  return (SUCCESS);
}
