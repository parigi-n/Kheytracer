/*
** parser.h for pzrser.h in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Jun  2 12:49:13 2015 Nicolas PARIGI
** Last update Tue Jun  2 12:49:17 2015 Nicolas PARIGI
*/

#ifndef PARSER_H_
# define PARSER_H_

#define MAX_OBJ_NAME	(64)
#define MAX_SCENE_NAME	(32)
#define	MAX_RADIUS_SIZE	(100000.000)

int	parser(t_scene *data, int fd);
int	parser_obj_name(char **tab, t_object *parsing);
int	parser_type(char **tab, t_object *parsing);
int	parser_origin(char **tab, t_object *parsing);
int	parser_rotation(char **tab, t_object *parsing);
int	parser_radius(char **tab, t_object *parsing);
int	parser_color(char **tab, t_object *parsing);
char	*begin_parsing_check(char *line, int flag_begin);
int	begin_parsing(char *line);
int	check_element_type(t_object **obj, char *line, int fd);
int	content_parsing(t_object **obj, int fd, int flag_stop);

typedef struct	s_parser
{
  int		(*fct)(char **tab, t_object *parsing);
  char		flag;
}		t_parser;

#endif /* !PARSER_H_ */
