/*
** parser_fct2.c for parser fct in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Jun  2 12:45:43 2015 Nicolas PARIGI
** Last update Tue Jun  2 15:28:51 2015 david sebaoun
*/

#include "shared.h"
#include "struct.h"
#include "string.h"
#include "parser.h"
#include "wordtab.h"

int	parser_radius(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "RADIUS") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) <= 0)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  parsing->r = atof(tab[1]);
  return (0);
}

int	parser_color(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "COLOR") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) != 6)
    return (puterr(ERROR_BAD_COLOR_LENGHT));
  parsing->color = strtol(tab[1], NULL, 16);
  return (0);
}
