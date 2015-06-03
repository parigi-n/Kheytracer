#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "shared.h"
#include "wordtab.h"
#include "struct.h"
#include "string.h"
#include "parser.h"

static int	check_element_type(t_object **obj, char *line, int fd)
{
  char		**tab;
  int		flag_stop;

  flag_stop = 0;
  tab = my_word_to_tab(line, " ");
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "ELEMENT") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[1]) > MAX_OBJ_NAME)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  if (my_strcmp(tab[1], "OBJECT") == 0)
    {
      if ((flag_stop = content_parsing(obj, fd, flag_stop)) == -1)
	return (-1);
    }
  else
    flag_stop = flag_stop;
  return (flag_stop);
}

static int	begin_parsing(char *line, t_scene *data)
{
  char		**tab;

  if ((tab = my_word_to_tab(line, " ")) == NULL)
    return (puterr(ERROR_MALLOC));
  if (my_tablen(tab) == 2 && my_strcmp(tab[0], "!NAME") == 0)
    {
      if (tab[1] == NULL || my_strlen(tab[1]) < 1 || my_strlen(tab[1]) > MAX_OBJ_NAME)
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

int		parser(t_scene *data, int fd)
{
  t_object	*obj;
  char		*line;
  int		flag_begin;
  int		flag_stop;

  obj = NULL;
  flag_begin = 0;
  flag_stop = 0;
  while ((line = get_next_line(fd)) != NULL && flag_stop != 2)
    {
      if ((line = begin_parsing_check(line, flag_begin)) == NULL)
	return (-1);
      if (my_strcmp(line, "<BEGIN>") == 0)
	flag_begin = 2;
      else if (flag_begin == 2)
	{
	  if ((flag_begin = begin_parsing(line, data)) == -1)
	    return (-1);
	}
      else if (flag_begin == 1)
	{
	  if ((flag_stop = check_element_type(&obj, line, fd)) == -1)
	    return (-1);
	}
    }
  if (flag_begin == 0)
    return (puterr(ERROR_NO_BEGIN));
  data->obj = *obj;
  return (0);
}
