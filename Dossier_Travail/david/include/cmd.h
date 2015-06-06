/*
** cmd.h for raytracer in /home/sebaou_d/rendu/Backup_2_MUL_2014_raytracer/parsing
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Tue May 26 15:17:04 2015 david sebaoun
** Last update Fri Jun  5 19:02:14 2015 david sebaoun
*/

#ifndef CMD_H_
# define CMD_H_

# define EXIT 42

# include "shared.h"
# include "struct.h"

typedef struct  s_cmd
{
  int          (*function)(t_all *, t_scene *);
  char          *cmd;
}               t_cmd;

int	help(t_all *, t_scene *);
int	edit(t_all *, t_scene *);
int	show(t_all *, t_scene *);
int	clear(t_all *, t_scene *);
int	create(t_all *, t_scene *);
int	render(t_all *, t_scene *);
int	my_exit(t_all *, t_scene *);
int	load(t_all *, t_scene *);
int	ls(t_all *, t_scene *);

#endif /* !CMD_H_ */
