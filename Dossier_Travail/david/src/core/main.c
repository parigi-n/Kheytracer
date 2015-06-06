/*
** main.c for  in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Thu May 28 18:11:18 2015 david sebaoun
** Last update Sat Jun  6 11:55:50 2015 david sebaoun
*/

#include <signal.h>
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
  else if (gere_key_lum(keycode, all) == 0)
    {
      if (gere_key_sphe(keycode, all) == 0)
	if (gere_key_plan(keycode, all) == 0)
	  gere_key_eye(keycode, all);
      /*raytrace(all, scene);*/
      gere_expose(all);
    }
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
  return (0);
}

int		main(int argc, char **argv)
{
  t_all		all;

  if (splash_screen() == ERROR)
    return (ERROR);
  if (command_line(&all) == ERROR)
    return (ERROR);
  return (0);
}
