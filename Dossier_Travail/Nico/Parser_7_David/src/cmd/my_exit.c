/*
** my_exit.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Fri May 29 10:41:35 2015 david sebaoun
** Last update Sun Jun  7 16:26:59 2015 david sebaoun
*/

#include "rt.h"
#include "cmd.h"
#include "struct.h"

int	my_exit(t_all *all, t_scene *scene)
{
  (void)all;
  (void)scene;
  free_scene(all, scene);
  return (EXIT);
}
