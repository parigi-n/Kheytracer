/*
** parser.c for parser in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico/Parser_7_David
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sun Jun  7 21:52:21 2015 Nicolas PARIGI
** Last update Sun Jun  7 23:25:21 2015 Nicolas PARIGI
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "shared.h"
#include "wordtab.h"
#include "struct.h"
#include "string.h"
#include "parser.h"

static int	begin_parsing(char *line, t_scene *data)
{
  char		**tab;

  if ((tab = my_word_to_tab(line, " ")) == NULL)
    return (puterr(ERROR_MALLOC));
  if (my_tablen(tab) == 2 && my_strcmp(tab[0], "!NAME") == 0)
    {
      if (tab[1] == NULL || my_strlen(tab[1]) < 1 ||
	  my_strlen(tab[1]) > MAX_OBJ_NAME)
	return (puterr(ERROR_BAD_NAME_LENGHT));
      data->name = my_strcpy(tab[1]);
    }
  else
    return (puterr(ERROR_BAD_NAME_VAR));
  freetab(tab);
  return (1);
}

static char	*begin_parsing_check(char *line, int flag_begin)
{
  char		*epur_line;

  if ((epur_line = epur_str(line, 0)) == NULL)
    {
      puterr(ERROR_MALLOC);
      return (NULL);
    }
  if (my_strcmp(line, "<BEGIN>") == 0 && flag_begin == 1)
    {
      puterr(ERROR_TWICE_BEGIN);
      free(line);
      return (NULL);
    }
  free(line);
  return (epur_line);
}

static int	end_check_parser(t_scene *data, int flag_begin)
{
  if (flag_begin != 1)
    return (puterr(ERROR_NO_BEGIN));
  count_element(data);
  return (0);
}

int		parser(t_scene *data, int fd, int flag_stop)
{
  char		*line;
  int		flag_begin;

  flag_begin = 0;
  while ((line = get_next_line(fd)) != NULL && flag_stop != 2)
    {
      data->last_line = data->last_line + 1;
      if ((line = begin_parsing_check(line, flag_begin)) == NULL)
	return (ERROR);
      if (my_strcmp(line, "</END>") == 0)
	flag_stop = 2;
      else if (my_strcmp(line, "<BEGIN>") == 0)
	flag_begin = 2;
      else if (flag_begin == 2)
	{
	  if ((flag_begin = begin_parsing(line, data)) == ERROR)
	    return (ERROR);
	}
      else if (line[0] != '\0' && flag_begin == 1)
	  if ((flag_stop = check_element_type(data, line, fd)) == ERROR)
	    return (ERROR);
      free(line);
    }
  return (end_check_parser(data, flag_begin));
}
