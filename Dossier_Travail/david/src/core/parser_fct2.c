/*
** parser_fct2.c for parser fct in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Jun  2 12:45:43 2015 Nicolas PARIGI
** Last update Sun Jun  7 19:40:21 2015 david sebaoun
*/

#include "rt.h"
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
  parsing->r = atoi(tab[1]);
  return (0);
}

int	parser_color(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "COLOR") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) > 6 || my_strlen(tab[1]) <= 0)
    return (puterr(ERROR_BAD_COLOR_LENGHT));
  parsing->color = strtol(tab[1], NULL, 16);
  hex_to_color(strtol(tab[1], NULL, 16), &parsing->color_int);
  return (0);
}

int	parser_shine(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "SHINE") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) <= 0)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  parsing->shine = atof(tab[1]);
  if (parsing->shine < 0.000000 || parsing->shine > 1.000000)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  return (0);
}

int	parser_limit(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "LIMIT") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) <= 0)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  parsing->lim = atoi(tab[1]);
  return (0);
}
