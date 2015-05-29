/*
** scene_creator.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:38:32 2015 david sebaoun
** Last update Fri May 29 16:19:19 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"

int	create(t_all *all)
{
  if (all->tab[1] == NULL)
    {
      my_putstr("Usage: create file.khey\n");
      return (ERROR);
    }

  return (SUCCESS);
}
