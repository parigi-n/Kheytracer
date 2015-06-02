/*
** show_object.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Fri May 29 10:40:46 2015 david sebaoun
** Last update Tue Jun  2 15:50:39 2015 david sebaoun
*/

#include "shared.h"
#include "struct.h"

int	show(t_all *all, t_scene *scene)
{
  if (all->tab[1] == NULL)
    {
      my_show_list(all->object);
      my_show_list_vec(all->lum);
    }
  return (SUCCESS);
}
