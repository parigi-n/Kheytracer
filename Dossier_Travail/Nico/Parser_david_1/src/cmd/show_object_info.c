/*
** show_object.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Fri May 29 10:40:46 2015 david sebaoun
** Last update Tue Jun  2 18:45:11 2015 david sebaoun
*/

#include "shared.h"
#include "struct.h"

int		show(t_all *all, t_scene *scene)
{
  t_object	*tmp;
  
  if (all->loaded == ERROR)
    return (puterr("Error: No scene loaded\n"));
  tmp = &scene->obj;
  while (tmp != NULL)
    {
      printf("name: %s\ntype: %d\nax: %f\nay: %f\naz: %f\nposx: %f\nposy: \
%f\nposz: %f\nr: %d\nlim: %f\ncolor: %d\n",
	     tmp->name, tmp->type, tmp->a.x, tmp->a.y, tmp->a.z, tmp->pos.x,
	     tmp->pos.y, tmp->pos.z, tmp->r, tmp->lim, tmp->color);
      tmp = tmp->next;
    }
  return (SUCCESS);
}