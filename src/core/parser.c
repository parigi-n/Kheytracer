#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "shared.h"
#include "wordtab.h"
#include "struct.h"
#include "string.h"
#include "parser.h"

static int	check_element_type(t_scene *data, char *line, int fd)
{
  char		**tab;
  int		flag_stop;

  flag_stop = 0;
  if ((tab = my_word_to_tab(line, " ")) == NULL)
    return (-1);;
  data->last_line++;
  if (my_tablen(tab) != 2)
    return (puterr(ERROR_NBR_ARG));
  if (my_strcmp(tab[0], "ELEMENT") != 0)
    return (puterr(ERROR_BAD_ORDER));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[1]) > MAX_OBJ_NAME)
    return (puterr(ERROR_BAD_ARG_LENGHT));
  if (my_strcmp(tab[1], "OBJECT") == 0)
    {
      if ((flag_stop = content_parsing_obj(&data->obj, fd, flag_stop, data)) == ERROR)
	return (ERROR);
    }
  else if (my_strcmp(tab[1], "LIGHT") == 0)
    {
      if ((flag_stop = content_parsing_light(&data->light, fd, flag_stop, data)) == ERROR)
	return (ERROR);
    }
  else if (my_strcmp(tab[1], "EYE") == 0)
    {
      if ((flag_stop = content_parsing_eye(data, fd, flag_stop)) == ERROR)
	return (ERROR);
    }
  else
    return (puterr("Error : Unknown ELEMENT type found.\n"));
  freetab(tab);
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

static void	count_element(t_scene *data)
{
  int		nb_obj;
  int		nb_light;
  t_object	*tmp_obj;
  t_light	*tmp_light;

  nb_obj = 0;
  nb_light = 0;
  tmp_obj = data->obj;
  tmp_light = data->light;
  while (tmp_obj != NULL)
    {
      tmp_obj = tmp_obj->next;
      nb_obj++;
    }
  while (tmp_light != NULL)
    {
      tmp_light = tmp_light->next;
      nb_light++;
    }
  data->nb_obj = nb_obj;
  data->nb_light = nb_light;
}

int		parser(t_scene *data, int fd)
{
  char		*line;
  int		flag_begin;
  int		flag_stop;

  flag_begin = 0;
  flag_stop = 0;
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
  if (flag_begin != 1)
    return (puterr(ERROR_NO_BEGIN));
  count_element(data);
  return (0);
}
