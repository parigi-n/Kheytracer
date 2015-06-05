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

# define MAX_OBJ_NAME		(64)
# define MAX_SCENE_NAME		(32)
# define MAX_RADIUS_SIZE	(100000.000)

int		parser(t_scene *data, int fd);
int		parser_obj_name(char **tab, t_object *parsing);
int		parser_type(char **tab, t_object *parsing);
int		parser_origin(char **tab, t_object *parsing);
int		parser_rotation(char **tab, t_object *parsing);
int		parser_radius(char **tab, t_object *parsing);
int		parser_color(char **tab, t_object *parsing);
int		parser_light_name(char **tab, t_light *parsing);
int		parser_light_origin(char **tab, t_light *parsing);
int		parser_light_color(char **tab, t_light *parsing);
int		parser_eye_origin(char **tab, t_scene *data);
int		parser_eye_rotation(char **tab, t_scene *data);

int		content_parsing_obj(t_object **obj, int fd, int flag_stop);
int		content_parsing_light(t_light **light, int fd, int flag_stop);
int		content_parsing_eye(t_scene *data, int fd, int flag_stop);

typedef struct	s_parser_obj
{
  int		(*fct)(char **tab, t_object *parsing);
  char		flag;
}		t_parser_obj;

typedef struct	s_parser_light
{
  int		(*fct)(char **tab, t_light *parsing);
  char		flag;
}		t_parser_light;

typedef struct	s_parser_eye
{
  int		(*fct)(char **tab, t_scene *data);
  char		flag;
}		t_parser_eye;

#endif /* !PARSER_H_ */
