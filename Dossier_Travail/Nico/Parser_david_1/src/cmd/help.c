/*
** help.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Fri May 29 10:39:50 2015 david sebaoun
** Last update Tue Jun  2 15:44:20 2015 david sebaoun
*/

#include "shared.h"
#include "struct.h"

int	help(t_all *all, t_scene *scene)
{
  (void)all;
  (void)scene;
  my_putstr("help          show this help\nedit          start a scene editor");
  my_putstr("\nshow          show informations about loaded objects\n        ");
  my_putstr("      ex: show sphere1\nclear         clear the screen\nload    ");
  my_putstr("      load a scene from a configuration file\n              ex: ");
  my_putstr("load file.rt\nrender        render the loaded scene\ncreate_scen");
  my_putstr("e  start a scene configuration file tool\nexit          exit the");
  my_putstr(" program\n");
  return (SUCCESS);
}
