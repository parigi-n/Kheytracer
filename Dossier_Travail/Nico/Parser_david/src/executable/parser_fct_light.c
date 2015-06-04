/*
** parser_fct.c for parser_fct in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Jun  2 12:45:04 2015 Nicolas PARIGI
** Last update Tue Jun  2 16:34:10 2015 Nicolas PARIGI
*/

#include "shared.h"
#include "struct.h"
#include "string.h"
#include "parser.h"

int	parser_light_name(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "NAME") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[1]) > MAX_OBJ_NAME)
    return (puterr(ERROR_BAD_ONAME_LENGHT));
  parsing->name = my_strcpy(tab[1]);
  return (0);
}

int	parser_light_origin(char **tab, t_object *parsing)
{
  if (my_strcmp(tab[0], "ORIGIN") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_tablen(tab) != 4)
    return (puterr(ERROR_NBR_ARG));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[2]) <= 0 || my_strlen(tab[3]) <= 0)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  parsing->pos.x = atof(tab[1]);
  parsing->pos.y = atof(tab[2]);
  parsing->pos.z = atof(tab[3]);
  return (0);
}

int	parser_light_color(char **tab, t_object *parsing)
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
