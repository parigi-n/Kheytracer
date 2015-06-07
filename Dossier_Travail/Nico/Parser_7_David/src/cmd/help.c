/*
** help.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Fri May 29 10:39:50 2015 david sebaoun
** Last update Sun Jun  7 12:34:23 2015 david sebaoun
*/

#include "shared.h"
#include "struct.h"
#include "printf.h"
#include "string.h"

int	help(t_all *all, t_scene *scene)
{
  (void)all;
  (void)scene;
  my_printf("%s%s%s%s%s%s%s%s%s%s%s", HELP_HELP, HELP_LS, HELP_ADD,
	      HELP_SHOW, HELP_LOAD, HELP_LOAD_EX, HELP_REND, HELP_REND_USE,
	    HELP_REND_USEN, HELP_WRITE, HELP_CLEAR, HELP_EXIT);
  return (SUCCESS);
}
