/*
** add_object.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun Jun  7 12:29:25 2015 david sebaoun
** Last update Sun Jun  7 13:22:48 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"
#include "string.h"
#include "cmd.h"

int		add_object(t_scene *scene, char *name, const int type)
{
  t_object	*tmp_obj;

  if ((tmp_obj = malloc(sizeof(t_object))) == NULL)
    return (ERROR);
  tmp_obj->name = my_strcpy(name);
  tmp_obj->type = type;
  if (get_pos(&tmp_obj->pos, "Position") == ERROR)
    return (ERROR);
  if (get_pos(&tmp_obj->a, "Rotation") == ERROR)
    return (ERROR);
  if ((tmp_obj->r = get_radius()) == ERROR)
    return (ERROR);
  if ((tmp_obj->color = get_color()) == ERROR)
    return (ERROR);
  tmp_obj->next = scene->obj;
  scene->obj = tmp_obj;
  my_putstr(ADD_SUCCESS);
  return (SUCCESS);
}
