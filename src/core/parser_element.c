/*
** parser_element.c for parser element in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico/Parser_7_David
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sun Jun  7 21:08:21 2015 Nicolas PARIGI
** Last update Sun Jun  7 21:37:24 2015 Nicolas PARIGI
*/

#include "shared.h"
#include "struct.h"
#include "parser.h"
#include "string.h"
#include "wordtab.h"

static int	launch_element_type(t_scene *data, char *cmd,
				    int flag_stop, int fd)
{
  if (my_strcmp(cmd, "OBJECT") == 0)
    {
      if ((flag_stop = content_parsing_obj
	   (&data->obj, fd, flag_stop, data)) == ERROR)
	return (ERROR);
    }
  else if (my_strcmp(cmd, "LIGHT") == 0)
    {
      if ((flag_stop = content_parsing_light
	   (&data->light, fd, flag_stop, data)) == ERROR)
	return (ERROR);
    }
  else if (my_strcmp(cmd, "EYE") == 0)
    {
      if ((flag_stop = content_parsing_eye
	   (data, fd, flag_stop)) == ERROR)
	return (ERROR);
    }
  else
    return (puterr(ERROR_UNKNOWN_E_TYPE));
  return (flag_stop);
}

int		check_element_type(t_scene *data, char *line, int fd)
{
  char		**tab;
  int		flag_stop;

  flag_stop = 0;
  if ((tab = my_word_to_tab(line, " ")) == NULL)
    return (-1);
  data->last_line++;
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "ELEMENT") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[1]) > MAX_OBJ_NAME)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  if ((flag_stop = launch_element_type(data, tab[1], flag_stop, fd)) == ERROR)
    return (ERROR);
  freetab(tab);
  return (flag_stop);
}
