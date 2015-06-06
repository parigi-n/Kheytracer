/*
** content_parsing.c for content aprsing in 
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Wed Jun  3 18:59:43 2015 Nicolas PARIGI
** Last update Sat Jun  6 15:28:38 2015 Nicolas PARIGI
*/

#include "shared.h"
#include "struct.h"
#include "string.h"
#include "parser.h"

static const	t_parser_obj g_parser_obj[] =
  {
    {&parser_obj_name, 0},
    {&parser_type, 1},
    {&parser_origin, 2},
    {&parser_rotation, 3},
    {&parser_radius, 4},
    {&parser_color, 5},
    {NULL, '\0'}
  };

static int	my_put_in_list_obj(t_object **obj, t_object *parsing)
{
  parsing->next = *obj;
  *obj = parsing;
}

static int	parsing_launcher(t_object *parsing, char *line, int order)
{
  char		**tab;

  if ((tab = my_word_to_tab(line, " ")) == NULL)
    return (puterr(ERROR_MALLOC));
  if (my_tablen(tab) < 2 || my_tablen(tab) > 4)
    return (puterr(ERROR_NBR_ARG));
  if (g_parser_obj[order++].fct(tab, parsing) == ERROR)
    return (ERROR);
  freetab(tab);
  return (0);
}

int		content_parsing_obj(t_object **obj, int fd, int flag_stop, t_scene *data)
{
  t_object	*parsing;
  char		*line;
  int		order;

  if ((parsing = malloc(sizeof(*parsing))) == NULL)
    return (ERROR);
  order = 0;
  while ((line = get_next_line(fd)) != NULL && order < 6 && flag_stop == 0)
    {
      data->last_line = data->last_line + 1;
      if ((line = epur_str(line, 1)) == NULL)
	return (puterr(ERROR_MALLOC));
      if (flag_stop == 0 || line[0] != '\0' || my_strcmp(line, "</END>") != 0)
	{
	  if (parsing_launcher(parsing, line, order++) == ERROR)
	    return (ERROR);
	}
      else if (my_strcmp(line, "</END>") == 0)
	flag_stop = 2;
      else if (line[0] == '\0')
	flag_stop = 1;
      free(line);
    }
  if (order == 6)
    my_put_in_list_obj(obj, parsing);
  return (flag_stop);
}
