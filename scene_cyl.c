/*
** tmp_load.c for tmp_load in /home/vautie_a/rendu/MUL_2014_raytracer/src/lib/list
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue May 26 09:49:11 2015 Jules Vautier
<<<<<<< HEAD
** Last update Thu Jun  4 20:13:59 2015 Jules Vautier
*/

#include "struct.h"
#include "list.h"
#include "printf.h"
#include "rt.h"

int		my_load(t_all *var)
{
  t_object	*tmp;
  t_vec		*lum;

  /* 1 */
  my_put_in_list_object(&var->object, "cyl1");
  tmp = my_getlist_obj(&var->object, "cyl1");
  my_printf("%s ok\n", tmp->name);
  tmp->type = TYPE_CYLINDER;
  tmp->color = 0xFF0000;
  tmp->pos.x = 3000.0;
  tmp->pos.y = 500.0;
  tmp->pos.z = 20.0;
  tmp->r = 100.0;
  tmp->lim = 0.0;
  tmp->a.y = 0.0;
  tmp->a.z = 0.0;

  my_put_in_list_object(&var->object, "cyl2");
  tmp = my_getlist_obj(&var->object, "cyl2");
  my_printf("%s ok\n", tmp->name);
  tmp->type = TYPE_CYLINDER;
  tmp->color = 0xFF0000;
  tmp->pos.x = 200.0;
  tmp->pos.y = 800.0;
  tmp->pos.z = 20.0;
  tmp->r = 100.0;
  tmp->lim = 0.0;
  tmp->a.y = 0.0;
  tmp->a.z = 0.0;

  my_put_in_list_object(&var->object, "cyl3");
  tmp = my_getlist_obj(&var->object, "cyl3");
  my_printf("%s ok\n", tmp->name);
  tmp->type = TYPE_CYLINDER;
  tmp->color = 0xFF0000;
  tmp->pos.x = 3000.0;
  tmp->pos.y = -500.0;
  tmp->pos.z = 20.0;
  tmp->r = 100.0;
  tmp->lim = 00.0;
  tmp->a.y = 0.0;
  tmp->a.z = 0.0;

  my_put_in_list_object(&var->object, "cyl4");
  tmp = my_getlist_obj(&var->object, "cyl4");
  my_printf("%s ok\n", tmp->name);
  tmp->type = TYPE_CYLINDER;
  tmp->color = 0xFF0000;
  tmp->pos.x = 200.0;
  tmp->pos.y = -800.0;
  tmp->pos.z = 20.0;
  tmp->r = 100.0;
  tmp->lim = 0.0;
  tmp->a.y = 0.0;
  tmp->a.z = 0.0;

  my_put_in_list_object(&var->object, "plan1");
  tmp = my_getlist_obj(&var->object, "plan1");
  my_printf("%s ok\n", tmp->name);
  tmp->type = TYPE_PLAN;
  tmp->color = 0xC8C814;
  tmp->pos.x = 100.0;
  tmp->pos.y = -200.0;
  tmp->pos.z = -200.0;
  tmp->r = 0.0;
  tmp->lim = 0.0;
  tmp->a.x = 0.0;
  tmp->a.y = 0.0;
  tmp->a.z = 0.0;

  my_put_in_list_object(&var->object, "plan2");
  tmp = my_getlist_obj(&var->object, "plan2");
  my_printf("%s ok\n", tmp->name);
  tmp->type = TYPE_PLAN;
  tmp->color = 0x00FF00;
  tmp->pos.x = -4000.0;
  tmp->pos.y = 0.0;
  tmp->pos.z = -6300.0;
  tmp->r = 0.0;
  tmp->lim = 0.0;
  tmp->a.x = 0.0;
  tmp->a.y = 0.90;
  tmp->a.z = 0.0;

  /*Lum 1*/
  my_put_in_list_vec(&var->lum, "lum1");
  lum = my_getlist_vec(&var->lum, "lum1");
  my_printf("%s ok\n", lum->name);
  lum->pos.x = 2000.0;
  lum->pos.y = 1000.0;
  lum->pos.z = 100.0;

  my_put_in_list_vec(&var->lum, "lum2");
  lum = my_getlist_vec(&var->lum, "lum2");
  my_printf("%s ok\n", lum->name);
  lum->pos.x = 1000.0;
  lum->pos.y = -1000.0;
  lum->pos.z = 600.0;

  /*Lum 2*/
  return (0);
}
