/*
** parser_fct.c for parser_fct in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Jun  2 12:45:04 2015 Nicolas PARIGI
** Last update Sat Jun  6 20:21:30 2015 david sebaoun
*/

#include "shared.h"
#include "struct.h"
#include "string.h"
#include "parser.h"
#include "wordtab.h"
#include "rt.h"

static const	t_obj_type g_obj_type[] =
  {
    {"SPHERE", TYPE_SPHERE},
    {"CONE", TYPE_CONE},
    {"CYLINDER", TYPE_CYLINDER},
    {"PLAN", TYPE_PLAN},
    {"DISC", TYPE_DISC},
    {"TRIANGLE", TYPE_TRIANGLE},
    {"HYPERB", TYPE_HYPERB},
    {NULL, -1}
  };


int	parser_obj_name(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "NAME") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[1]) > MAX_OBJ_NAME)
    return (puterr(ERROR_BAD_ONAME_LENGHT));
  parsing->name = my_strcpy(tab[1]);
  return (SUCCESS);
}

int	parser_type(char **tab, t_object *parsing)
{
  int	i;

  i = 0;
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "TYPE") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) <= 0)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  while (g_obj_type[i].type != -1)
    {
      if (my_strcmp(tab[1], g_obj_type[i].name) == 0)
	{
	  parsing->type = g_obj_type[i].type;
	  return (SUCCESS);
	}
      i++;
    }
  return (puterr(ERROR_UNKNOWN_OBJ_TYPE));
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
  return (SUCCESS);
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
  return (SUCCESS);
}
