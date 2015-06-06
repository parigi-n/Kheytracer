/*
** parser_fct.c for parser_fct in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Jun  2 12:45:04 2015 Nicolas PARIGI
** Last update Fri Jun  5 17:47:48 2015 Nicolas PARIGI
*/

#include "shared.h"
#include "struct.h"
#include "string.h"
#include "parser.h"

int	parser_eye_origin(char **tab, t_scene *data)
{
  if (my_strcmp(tab[0], "ORIGIN") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_tablen(tab) != 4)
    return (puterr(ERROR_NBR_ARG));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[2]) <= 0 || my_strlen(tab[3]) <= 0)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  data->eye.pos.x = atof(tab[1]);
  data->eye.pos.y = atof(tab[2]);
  data->eye.pos.z = atof(tab[3]);
  return (0);
}

int	parser_eye_rotation(char **tab, t_scene *data)
{
  if (my_strcmp(tab[0], "ROTATION") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_tablen(tab) != 4)
    return (puterr(ERROR_NBR_ARG));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[2]) <= 0 || my_strlen(tab[3]) <= 0)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  data->eye.a.x = atof(tab[1]);
  data->eye.a.y = atof(tab[2]);
  data->eye.a.z = atof(tab[3]);
  if (data->eye.a.x > 360 || data->eye.a.x < -360 ||
    data->eye.a.y > 360 || data->eye.a.y < -360 ||
      data->eye.a.z > 360 || data->eye.a.z < -360)
    return (puterr(ERROR_BAD_ARG_LENGHT));
}
