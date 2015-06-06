/*
** help.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Fri May 29 10:39:50 2015 david sebaoun
** Last update Wed Jun  3 16:38:37 2015 david sebaoun
*/

#include "shared.h"
#include "struct.h"

int	help(t_all *all, t_scene *scene)
{
  (void)all;
  (void)scene;
  my_putstr("help          show this help\nls            displays a list of .k");
  my_putstr("hey files\nedit          start a scene editor\nshow          show");
  my_putstr(" informations about loaded objects\n              ex: show sphere");
  my_putstr("1\nclear         clear the screen\nload          load a scene fro");
  my_putstr("m a configuration file\n              ex: load file.rt\nrender   ");
  my_putstr("     render the loaded scene\ncreate_scene  start a scene configu");
  my_putstr("ration file tool\nexit          exit the program\n");
  return (SUCCESS);
}
