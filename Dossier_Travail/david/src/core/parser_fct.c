/*
** parser_fct.c for parser_fct in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Jun  2 12:45:04 2015 Nicolas PARIGI
** Last update Sat Jun  6 11:26:11 2015 Jules Vautier
*/

#include "shared.h"
#include "struct.h"
#include "string.h"
#include "parser.h"

int	parser_obj_name(char **tab, t_object *parsing)
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

int	parser_type(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "TYPE") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) <= 0)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  if (my_strcmp(tab[1], "SPHERE") == 0)
    parsing->type = 0;
  else if (my_strcmp(tab[1], "CONE") == 0)
    parsing->type = 1;
  else if (my_strcmp(tab[1], "CYLINDER") == 0)
    parsing->type = 2;
  else if (my_strcmp(tab[1], "PLAN") == 0)
    parsing->type = 3;
  else
    return (puterr(ERROR_UNKNOWN_OBJ_TYPE));
  return (0);
}

int	parser_origin(char **tab, t_object *parsing)
{
  if (my_strcmp(tab[0], "ORIGIN") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_tablen(tab) != 4)
    return (puterr(ERROR_NBR_ARG));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[2])
      <= 0 || my_strlen(tab[3]) <= 0)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  parsing->pos.x = atof(tab[1]);
  parsing->pos.y = atof(tab[2]);
  parsing->pos.z = atof(tab[3]);
  return (0);
}

int	parser_rotation(char **tab, t_object *parsing)
{
  if (my_strcmp(tab[0], "ROTATION") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_tablen(tab) != 4)
    return (puterr(ERROR_NBR_ARG));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[2])
      <= 0 || my_strlen(tab[3]) <= 0)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  parsing->a.x = atof(tab[1]);
  parsing->a.y = atof(tab[2]);
  parsing->a.z = atof(tab[3]);
  if (parsing->a.x > 360 || parsing->a.x < -360 ||
      parsing->a.y > 360 || parsing->a.y < -360 ||
      parsing->a.z > 360 || parsing->a.z < -360)
    return (puterr(ERROR_BAD_ARG_LENGHT));
}
