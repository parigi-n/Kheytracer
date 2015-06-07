/*
** main.c for  in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Thu May 28 18:11:18 2015 david sebaoun
** Last update Sat Jun  6 18:20:10 2015 david sebaoun
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

int		gere_key(int keycode, t_all *all)
{
  t_object	*tmp_obj;
  t_light	*tmp_light;
  int		len;

  tmp_obj = all->scene.obj;
  tmp_light = all->scene.light;
  len = 0;
  if (keycode == MEGAUP && all->current_obj < all->scene.nb_obj)
    {
      all->current_obj = all->current_obj + 1;
    }
  if (keycode == MEGADOWN && all->current_obj > 0)
    {
      all->current_obj = all->current_obj - 1;
    }
  while (tmp_obj != NULL && len < all->current_obj && tmp_obj->next != NULL)
    {
      tmp_obj = tmp_obj->next;
      len++;
    }
  /*if (keycode == MEGAUP)
    {
      all->current_obj = all->current_obj + 1;
    }
  if (keycode == MEGADOWN)
    {
      all->current_obj = all->current_obj - 1;
      if (all->current_obj < 0)
      all->current_obj = all->scene.nb_obj - 1;
    }
    all->current_obj = all->current_obj % all->scene.nb_obj;
  while (tmp != NULL && len < all->current_obj && tmp_obj->next != NULL)
    {
      tmp_obj = tmp_obj->next;
      len++;
    }*/
  /*my_putstr("Light : ");
  my_putstr(tmp_light->name);
  my_putchar('\n');*/
  my_putstr("Object : ");
  my_putstr(tmp_obj->name);
  my_putchar('\n');
  if (keycode == ESC)
    exit(0);
  gere_key_lum(keycode, tmp_light);
  gere_key_sphe(keycode, tmp_obj);
  gere_key_plan(keycode, tmp_obj);
  gere_key_eye(keycode, &all->scene);
  /*all->scene.obj = tmp_obj;
  all->scene.light = tmp_light;*/
  raytrace(all, &all->scene);
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

int		main()
{
  t_all		all;

  if (splash_screen() == ERROR)
    return (ERROR);
  if (command_line(&all) == ERROR)
    return (ERROR);
  return (0);
}
