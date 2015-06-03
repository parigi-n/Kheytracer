/*
** cmd.h for raytracer in /home/sebaou_d/rendu/Backup_2_MUL_2014_raytracer/parsing
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Tue May 26 15:17:04 2015 david sebaoun
** Last update Wed May 27 11:32:14 2015 david sebaoun
*/

#ifndef CMD_H_
# define CMD_H_

# define EXIT 42

# include "shared.h"
# include "struct.h"

typedef struct  s_cmd
{
  int          (*function)(t_all *all);
  char          *cmd;
}               t_cmd;

int	help(t_all *all);
int	edit(t_all *all);
int	show(t_all *all);
int	clear(t_all *all);
int	create(t_all *all);
int	render(t_all *all);
int	my_exit(t_all *all);
int	load(t_all *all);

#endif /* !CMD_H_ */
