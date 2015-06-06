/*
** content_parsing.c for content aprsing in 
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Wed Jun  3 18:59:43 2015 Nicolas PARIGI
** Last update Sat Jun  6 15:28:54 2015 Nicolas PARIGI
*/

#include "shared.h"
#include "struct.h"
#include "string.h"
#include "parser.h"

static const	t_parser_eye g_parser_eye[] =
  {
    {&parser_eye_origin, 0},
    {&parser_eye_rotation, 1},
    {NULL, '\0'}
  };

static int	parsing_launcher(t_scene *data, char *line, int order)
{
  char		**tab;

  if ((tab = my_word_to_tab(line, " ")) == NULL)
    return (puterr(ERROR_MALLOC));
  if (my_tablen(tab) < 2 || my_tablen(tab) > 4)
    return (puterr(ERROR_NBR_ARG));
  if (g_parser_eye[order++].fct(tab, data) == ERROR)
    return (ERROR);
  freetab(tab);
  return (0);
}

int		content_parsing_eye(t_scene *data, int fd, int flag_stop)
{
  char		*line;
  int		order;

  order = 0;
  while ((line = get_next_line(fd)) != NULL && order < 2 && flag_stop == 0)
    {
      data->last_line = data->last_line + 1;
      if ((line = epur_str(line, 1)) == NULL)
	return (puterr(ERROR_MALLOC));
      if (flag_stop == 0 || line[0] != '\0' || my_strcmp(line, "</END>") != 0)
	{
	  if (parsing_launcher(data, line, order++) == ERROR)
	    return (ERROR);
	}
      else if (my_strcmp(line, "</END>") == 0)
	flag_stop = 2;
      else if (line[0] == '\0')
	flag_stop = 1;
      free(line);
    }
  if (order != 2)
    return (puterr(ERROR_BAD_ORDER));
  return (flag_stop);
}
