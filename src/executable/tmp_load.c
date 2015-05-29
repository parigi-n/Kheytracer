/*
** tmp_load.c for tmp_load in /home/vautie_a/rendu/MUL_2014_raytracer/src/lib/list
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue May 26 09:49:11 2015 Jules Vautier
<<<<<<< HEAD
** Last update Fri May 29 11:38:36 2015 Jules Vautier
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
  tmp->pos.x = 20.0;
  tmp->pos.y = 20.0;
  tmp->pos.z = 20.0;
  tmp->r = 200.0;
  tmp->lim = 400.0;
  tmp->a.y = 0.0;
  tmp->a.z = 0.0;

  /* 2 */
  my_put_in_list_object(&var->object, "sphere2");
  tmp = my_getlist_obj(&var->object, "sphere2");
  my_printf("%s ok\n", tmp->name);
  tmp->type = TYPE_SPHERE;
  tmp->color = 0x0000FF;
  tmp->pos.x = 0.0;
  tmp->pos.y = -200.0;
  tmp->pos.z = 50.0;
  tmp->r = 100.0;
  tmp->a.x = 0.0;
  tmp->a.y = 0.0;
  tmp->a.z = 0.0;

  /* 3 */
  my_put_in_list_object(&var->object, "plan");
  tmp = my_getlist_obj(&var->object, "plan");
  my_printf("%s ok\n", tmp->name);
  tmp->type = TYPE_PLAN;
  tmp->color = 0xC8C814;
  tmp->pos.x = 100.0;
  tmp->pos.y = -200.0;
  tmp->pos.z = -200.0;
  tmp->r = 2000.0;
  tmp->a.x = 0.0;
  tmp->a.y = 0.0;
  tmp->a.z = 0.0;

  /*Lum 1*/
  my_put_in_list_vec(&var->lum, "lum1");
  lum = my_getlist_vec(&var->lum, "lum1");
  my_printf("%s ok\n", lum->name);
  lum->pos.x = 1000.0;
  lum->pos.y = -1000.0;
  lum->pos.z = 600.0;

  /*Lum 2*/
  /*my_put_in_list_vec(&var->lum, "lum2");
  lum = my_getlist_vec(&var->lum, "lum2");
  my_printf("%s ok\n", lum->name);
  lum->pos.x = 1000.0;
  lum->pos.y = 3000.0;
  lum->pos.z = 400.0;*/
  return (0);
}
