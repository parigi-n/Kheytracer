/*
** main.c for  in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Thu May 28 18:11:18 2015 david sebaoun
** Last update Sun Jun  7 22:02:11 2015 david sebaoun
*/

#include <signal.h>
#include "cmd.h"
#include "shared.h"
#include "keyboard.h"
#include "rt.h"
#include "printf.h"

int		gere_expose(t_all *all)
{
  mlx_put_image_to_window(all->var.mlx_ptr,
			  all->var.win_ptr, all->var.img_ptr, 0, 0);
  return (0);
}

int		gere_key(int keycode, t_all *all)
{
  t_object	*tmp_obj;
  t_light	*tmp_light;
  int		len;

  if (keycode == ESC)
    exit(0);
  tmp_obj = all->scene.obj;
  tmp_light = all->scene.light;
  len = 0;
  if (keycode == MEGAUP && all->current_obj + 1 < all->scene.nb_obj)
    all->current_obj = all->current_obj + 1;
  if (keycode == MEGADOWN && all->current_obj > 0)
    all->current_obj = all->current_obj - 1;
  while (tmp_obj != NULL && len < all->current_obj && tmp_obj->next != NULL)
    {
      tmp_obj = tmp_obj->next;
      len++;
    }
  if (keycode == MEGAUP || keycode == MEGAUP)
    my_printf("%s%s\n", "Selected object : ", tmp_obj->name);
  if (gere_key_lum(keycode, tmp_light) == 0)
    if (gere_key_sphe(keycode, tmp_obj) == 0)
      gere_key_eye(keycode, &all->scene);
  raytrace(all, &all->scene);
  return (0);
}

int		init_calc(t_all *all)
{
  all->calc.prea = 3.141592654 / 0.18;
  all->object = NULL;
  all->obj = NULL;
  all->lum = NULL;
  return (0);
}

int		main()
{
  t_all		all;

  if (splash_screen() == ERROR)
    return (ERROR);
  if (command_line(&all) == ERROR)
    return (ERROR);
  return (0);
}
