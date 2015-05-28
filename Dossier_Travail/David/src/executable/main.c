/*
** main.c for main in /home/vautie_a/rendu/MUL_2014_rtracer/src/executable
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Wed May 27 18:52:22 2015 Jules Vautier
** Last update Thu May 28 10:53:07 2015 david sebaoun
*/

#include "shared.h"
#include "keyboard.h"
#include "rt.h"

int		gere_expose(t_all *all)
{
  mlx_put_image_to_window(all->var.mlx_ptr,
			  all->var.win_ptr, all->var.img_ptr, 0, 0);
  return (0);
}

int		gere_key(int keycode, void *param)
{
  t_all		*all;

  all = (t_all*)param;
  if (keycode == ESC)
    exit(0);
  if (gere_key_lum(keycode, all) == 0)
    if (gere_key_sphe(keycode, all) == 0)
      if (gere_key_plan(keycode, all) == 0)
	gere_key_eye(keycode, all);
  raytrace(all);
  gere_expose(all);
  return (0);
}

int		init_calc(t_all *all)
{
  all->calc.prea = 3.141592654 / 0.18;
  all->object = NULL;
  all->obj_nb = NULL;
  all->lum = NULL;
  /*init_obj_un(all);
  init_obj_deux(all);
  init_obj_trois(all);
  init_obj_quatre(all);*/
  init_eye(all);
  my_load(all);
  return (0);
}

int		main(int argc, char **argv)
{
  t_all		all;

  if (command_line(&all) == ERROR)
    return (ERROR);
  if (gere_flag(&all.flag, argc, argv) == -1)
    return (0);
  if (check_error(&all.var) == -1)
    {
      puterr("fail in check_error\n");
      return (-1);
    }
  init_calc(&all);
  raytrace(&all);
  mlx_expose_hook(all.var.win_ptr, gere_expose, &all);
  mlx_hook(all.var.win_ptr, KeyPress, KeyRelease, &gere_key, &all);
  mlx_loop(all.var.mlx_ptr);
  return (0);
}
