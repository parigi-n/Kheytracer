/*
** clear.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:40:49 2015 david sebaoun
** Last update Sat Jun  6 12:18:19 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"

int	clear(t_all *all, t_scene *scene)
{
  (void)all;
  (void)scene;
  my_putstr("\x1b[2J\x1b[H");
  return (SUCCESS);
}
