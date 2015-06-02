#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "shared.h"
#include "wordtab.h"
#include "struct.h"

#define MAX_OBJ_NAME	(64)
#define MAX_SCENE_NAME	(32)
#define	MAX_RADIUS_SIZE	(100000.000)

int	parser_obj_name(char **tab, t_object *parsing);
int	parser_type(char **tab, t_object *parsing);
int	parser_origin(char **tab, t_object *parsing);
int	parser_rotation(char **tab, t_object *parsing);
int	parser_radius(char **tab, t_object *parsing);
int	parser_color(char **tab, t_object *parsing);

typedef struct	s_parser
{
  int		(*fct)(char **tab, t_object *parsing);
  char		flag;
}		t_parser;

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

int	parser_obj_name(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr("Error : Wrong argument number on NAME.\n"));
  if (my_strcmp(tab[0], "NAME") != 0)
    return (puterr("Fail strcmp name\n"));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[1]) > MAX_OBJ_NAME)
    return (puterr("Fail strcmp name\n"));
  parsing->name = my_strcpy(tab[1]);
  return (0);
}

int	parser_type(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr("Error : Wrong argument number on TYPE.\n"));
  if (my_strcmp(tab[0], "TYPE") != 0)
    return (puterr("Fail strcmp type\n"));
  if (my_strlen(tab[1]) <= 0)
    return (puterr("Fail strcmptype\n"));
  if (my_strcmp(tab[1], "SPHERE") == 0)
    parsing->type = 0;
  else if (my_strcmp(tab[1], "CONE") == 0)
    parsing->type = 1;
  else if (my_strcmp(tab[1], "CYLINDER") == 0)
    parsing->type = 2;
  else if (my_strcmp(tab[1], "PLAN") == 0)
    parsing->type = 3;
  else
    return (puterr("Error : Object type doesn't exist.\n"));
  return (0);
}

int	parser_origin(char **tab, t_object *parsing)
{
  if (my_strcmp(tab[0], "ORIGIN") != 0)
    return (puterr("Fail strcmp origin\n"));
  if (my_tablen(tab) != 4)
    return (puterr("Error : Wrong argument number on ORIGIN.\n"));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[2]) <= 0 || my_strlen(tab[3]) <= 0)
    return (puterr("Fail strcmp origin\n"));
  parsing->pos.x = atof(tab[1]);
  parsing->pos.y = atof(tab[2]);
  parsing->pos.z = atof(tab[3]);
  return (0);
}

int	parser_rotation(char **tab, t_object *parsing)
{
  if (my_strcmp(tab[0], "ROTATION") != 0)
    return (puterr("Fail strcmp\n"));
  if (my_tablen(tab) != 4)
    return (puterr("Error : Wrong argument number on ROTATION.\n"));
  if (my_strlen(tab[1]) <= 0 || my_strlen(tab[2]) <= 0 || my_strlen(tab[3]) <= 0)
    return (puterr("Fail strcmp\n"));
  parsing->pos.x = atof(tab[1]);
  parsing->pos.y = atof(tab[2]);
  parsing->pos.z = atof(tab[3]);
  if (parsing->pos.x > 360 || parsing->pos.x < -360 ||
    parsing->pos.y > 360 || parsing->pos.y < -360 ||
      parsing->pos.z > 360 || parsing->pos.z < -360)
    return (puterr("Error : Wrong argument value on ROTATION (> / < (-)360).\n"));
}

int	parser_radius(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr("Error : Wrong argument number on RADIUS.\n"));
  if (my_strcmp(tab[0], "RADIUS") != 0)
    return (puterr("Fail strcmp\n"));
  if (my_strlen(tab[1]) <= 0)
    return (puterr("Fail strcmp\n"));
  parsing->r = atof(tab[1]);
  return (0);
}

int	parser_color(char **tab, t_object *parsing)
{
  if (my_tablen(tab) != 2)
    return (puterr("Error : Wrong argument number on COLOR.\n"));
  if (my_strcmp(tab[0], "COLOR") != 0)
    return (puterr("Fail strcmp\n"));
  if (my_strlen(tab[1]) != 6)
    return (puterr("Error : Hexadecimal int of COLOR must be 6 char long.\n"));
  parsing->color = strtol(tab[1], NULL, 16);
  return (0);
}

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
      if ((flag_stop = content_parsing(&obj, fd, flag_stop)) == -1)
	return (-1);
      /*my_putchar('\n');
      my_putstr("x : ");
      my_putnbr(obj->type);
      my_putchar('\n');*/
    }
  else
    ;
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
}
int	main()
{
  t_object	*obj;
  char		*raw_line;
  char		*line;
  char		*name;
  int		fd;
  int		flag_begin;
  int		flag_stop;

  obj = NULL;
  flag_begin = 0;
  flag_stop = 0;
  fd = open("test.khey", O_RDONLY);
  while ((raw_line = get_next_line(fd)) != NULL && flag_stop != 2)
    {
      line = epur_str(raw_line, 0);
      if (my_strcmp(line, "<BEGIN>") == 0 && flag_begin == 1)
	return (puterr("Error : BEGIN is defined twice in the file. Parsing stopped.\n"));
      if (my_strcmp(line, "<BEGIN>") == 0)
	flag_begin = 2;
      else if (flag_begin == 2)
	{
	  if (check_element_type(&obj, line, fd) == -1)
	    return (-1);
	  else
	    flag_begin = 1;
	}
      else if (flag_begin == 1)
	{
	  if ((flag_stop = check_element_type(&obj, line, fd)) == -1)
	    return (-1);
	}
    }
  if (flag_begin == 0)
    return (puterr("Error : No <BEGIN> variable found. No parsing done.\n"));
  my_putstr(name);
}