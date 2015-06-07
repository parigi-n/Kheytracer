/*
** add_light.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun Jun  7 12:28:32 2015 david sebaoun
** Last update Sun Jun  7 23:02:28 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"
#include "string.h"
#include "cmd.h"

int		add_light(t_scene *scene, char *name)
{
  t_light	*tmp_light;

  if ((tmp_light = malloc(sizeof(t_light))) == NULL)
    return (ERROR);
  tmp_light->name = my_strcpy(name);
  if ((tmp_light->color = get_color()) == ERROR)
    return (ERROR);
  if (get_pos(&tmp_light->pos, "Position") == ERROR)
    return (ERROR);
  tmp_light->next = scene->light;
  scene->light = tmp_light;
  my_putstr(ADD_SUCCESS);
  return (SUCCESS);
}
