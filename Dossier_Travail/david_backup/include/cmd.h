/*
** cmd.h for raytracer in /home/sebaou_d/rendu/Backup_2_MUL_2014_raytracer/parsing
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Tue May 26 15:17:04 2015 david sebaoun
** Last update Wed Jun  3 16:31:28 2015 david sebaoun
*/

#ifndef CMD_H_
# define CMD_H_

# define EXIT 42

# include "shared.h"
# include "struct.h"

typedef struct  s_cmd
{
  int          (*function)(t_all *all, t_scene *scene);
  char          *cmd;
}               t_cmd;

int	help(t_all *all, t_scene *scene);
int	edit(t_all *all, t_scene *scene);
int	show(t_all *all, t_scene *scene);
int	clear(t_all *all, t_scene *scene);
int	create(t_all *all, t_scene *scene);
int	render(t_all *all, t_scene *scene);
int	my_exit(t_all *all, t_scene *scene);
int	load(t_all *all, t_scene *scene);
int	ls(t_all *all, t_scene *scene);

#endif /* !CMD_H_ */
