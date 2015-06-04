/*
** main.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Thu May 28 18:11:41 2015 david sebaoun
** Last update Tue Jun  2 12:35:53 2015 Nicolas PARIGI
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
  all->obj = NULL;
  all->lum = NULL;
  /*init_obj_un(all);
  init_obj_deux(all);
  init_obj_trois(all);
  init_obj_quatre(all);*/
  init_eye(all);
  my_load(all);
  return (0);
}

int		salutation(int argc, char **argv)
{
  t_all		all;

  /*if (command_line(&all) == ERROR)
    return (ERROR);*/
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
