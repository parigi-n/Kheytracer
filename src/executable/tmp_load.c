/*
** tmp_load.c for tmp_load in /home/vautie_a/rendu/MUL_2014_raytracer/src/lib/list
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue May 26 09:49:11 2015 Jules Vautier
** Last update Wed May 27 08:31:52 2015 Jules Vautier
*/

#include "struct.h"
#include "list.h"
#include "printf.h"
#include "rtv1.h"

int		my_load(t_all *var)
{
  t_object	*tmp;

  /* 1 */
  my_put_in_list_object(&var->object, "sphere1");
  tmp = my_getlist(&var->object, "sphere1");
  my_printf("%s ok\n", tmp->name);
  tmp->type = TYPE_SPHERE;
  tmp->color = 0xFF0000;
  tmp->pos.x = 0.0;
  tmp->pos.y = 200.0;
  tmp->pos.z = -100.0;
  tmp->r = 150;
  tmp->a.x = 0.0;
  tmp->a.y = 0.0;
  tmp->a.z = 0.0;

  /* 2 */
  my_put_in_list_object(&var->object, "sphere2");
  tmp = my_getlist(&var->object, "sphere2");
  my_printf("%s ok\n", tmp->name);
  tmp->type = TYPE_SPHERE;
  tmp->color = 0xFF0000;
  tmp->pos.x = 0.0;
  tmp->pos.y = -200.0;
  tmp->pos.z = 50.0;
  tmp->r = 100;
  tmp->a.x = 0.0;
  tmp->a.y = 0.0;
  tmp->a.z = 0.0;

  /* 3 */
  my_put_in_list_object(&var->object, "plan");
  tmp = my_getlist(&var->object, "plan");
  my_printf("%s ok\n", tmp->name);
  tmp->type = TYPE_PLAN;
  tmp->color = 0xC8C814;
  tmp->pos.x = 100.0;
  tmp->pos.y = -200.0;
  tmp->pos.z = -200.0;
  tmp->r = 1000;
  tmp->a.x = 0.0;
  tmp->a.y = 0.0;
  tmp->a.z = 0.0;
  return (0);
}
