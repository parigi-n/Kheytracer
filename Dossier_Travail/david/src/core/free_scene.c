/*
** free_scene.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun Jun  7 15:49:10 2015 david sebaoun
** Last update Sun Jun  7 15:56:40 2015 david sebaoun
*/

#include "struct.h"
#include "string.h"
#include "shared.h"
#include "wordtab.h"
#include "printf.h"
#include "parser.h"
#include "rt.h"
#include "cmd.h"

void		free_light(t_light *var)
{
  t_light	*tmp_light;
  t_light	*wait_light;

  tmp_light = var;
  while (tmp_light != NULL)
    {
      wait_light = tmp_light->next;
      free(tmp_light->name);
      free(tmp_light);
      tmp_light = wait_light;
    }
}
void		free_object(t_object *var)
{
  t_object	*tmp_obj;
  t_object	*wait_obj;

  tmp_obj = var;
  while (tmp_obj != NULL)
    {
      wait_obj = tmp_obj->next;
      free(tmp_obj->name);
      free(tmp_obj);
      tmp_obj = wait_obj;
    }
}

int		free_scene(t_all *all, t_scene *scene)
{
  free_object(scene->obj);
  free_light(scene->light);
  scene->light = NULL;
  scene->obj = NULL;
  scene->name = NULL;
  scene->last_line = 0;
  scene->nb_obj = 0;
  scene->nb_light = 0;
  all->loaded = ERROR;
  return (SUCCESS);
}
