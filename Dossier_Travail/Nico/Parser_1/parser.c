#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "shared.h"
#include "wordtab.h"
#include "struct.h"
#include "parser.h"

#define MAX_OBJ_NAME	(64)
#define MAX_SCENE_NAME	(32)
#define	MAX_RADIUS_SIZE	(100000.000)

static const		t_parser g_parser[] =
  {
    {&parser_obj_name, 0},
    {&parser_type, 1},
    {&parser_origin, 2},
    {&parser_rotation, 3},
    {&parser_radius, 4},
    {&parser_color, 5},
    {NULL, '\0'}
  };

int		content_parsing(t_object **obj, int fd, int flag_stop)
{
  t_object	*parsing;
  char		*line;
  char		*raw_line;
  char		**tab;
  int		order;

  if ((parsing = malloc(sizeof(*parsing))) == NULL)
    return (ERROR);
  order = 0;
  while ((raw_line = get_next_line(fd)) != NULL && order < 6 && flag_stop == 0)
    {
      my_putnbr(order);
      my_putchar('\n');
      line = epur_str(raw_line, 0);
      if (flag_stop == 0 || line[0] != '\0' || my_strcmp(line, "</END>") != 0)
	{
	  tab = my_word_to_tab(line, " ");
	  if (my_tablen(tab) < 2 || my_tablen(tab) > 4)
	    return (puterr("Error tablen\n"));
	  if (g_parser[order].fct(tab, parsing) == -1)
	    return (-1);
	  else
	    order++;
	}
      else if (my_strcmp(line, "</END>") == 0)
	flag_stop = 2;
      else if (line[0] == '\0')
	flag_stop = 1;
    }
  if (order == 6)
    {
      parsing->next = *obj;
      *obj = parsing;
    }
  return (flag_stop);
}

int		check_element_type(t_object **obj, char *line, int fd)
{
  char		**tab;
  int		flag_stop;

  flag_stop = 0;
  tab = my_word_to_tab(line, " ");
  if (my_tablen(tab) != 2)
    return (puterr("Error : Wrong argument number on OBJECT.\n"));
  if (my_strcmp(tab[0], "ELEMENT") != 0)
    return (puterr("Fail strcmp element 1\n"));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[1]) > MAX_OBJ_NAME)
    return (puterr("Fail strcmp element 2\n"));
  if (my_strcmp(tab[1], "OBJECT") == 0)
    {
      if ((flag_stop = content_parsing(obj, fd, flag_stop)) == -1)
	return (-1);
    }
  else
     flag_stop = flag_stop;
  return (flag_stop);
}

int		begin_parsing(char *line)
{
  char		**tab;

  if ((tab = my_word_to_tab(line, " ")) == NULL)
    return (puterr("Error : Malloc failed"));
  if (my_tablen(tab) == 2 && my_strcmp(tab[0], "!NAME") == 0)
    {
      if (tab[1] == NULL || my_strlen(tab[1]) < 1 || my_strlen(tab[1]) > MAX_OBJ_NAME)
	return (puterr("Error : !NAME content is NULL or is larger than 64 char. Parsing stopped.\n"));
      /*name = my_strcpy(tab[1]);*/
    }
  else
    return (puterr("Error : No !NAME variable defined after <BEGIN>, or variable is badly defined. Parsing stopped.\n"));
  return (1);
}

char		*begin_parsing_check(char *line, int flag_begin)
{
  char		*epur_line;

  if ((epur_line = epur_str(line, 0)) == NULL)
    {
      puterr("Error : Malloc error.\n");
      return (NULL);
    }
  if (my_strcmp(line, "<BEGIN>") == 0 && flag_begin == 1)
    {
      puterr("Error : BEGIN is defined twice in the file. Parsing stopped.\n");
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
  char		*name;
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
	  if ((flag_begin = begin_parsing(line)) == -1)
	    return (-1);
	}
      else if (flag_begin == 1)
	{
	  if ((flag_stop = check_element_type(&obj, line, fd)) == -1)
	    return (-1);
	  my_putstr(obj->name);
	}
    }
  if (flag_begin == 0)
    return (puterr("Error : No <BEGIN> variable found. No parsing done.\n"));
  data->obj = *obj;
  return (0);
}
