/*
** scene_creator.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:38:32 2015 david sebaoun
** Last update Tue Jun  2 15:50:08 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"

int	create(t_all *all, t_scene *scene)
{
  if (all->tab[1] == NULL)
    {
      my_putstr("Usage: create file.khey\n");
      return (ERROR);
    }

  return (SUCCESS);
}
