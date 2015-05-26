/*
** cmd.h for raytracer in /home/sebaou_d/rendu/Backup_2_MUL_2014_raytracer/parsing
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Tue May 26 15:17:04 2015 david sebaoun
** Last update Tue May 26 16:29:02 2015 david sebaoun
*/

#ifndef CMD_H_
# define CMD_H_

# define EXIT 42

typedef struct  s_cmd
{
  int          (*function)(char **tab);
  char          *cmd;
}               t_cmd;

int	help(char **tab);
int	edit(char **tab);
int	show(char **tab);
int	clear(char **tab);
int	create(char **tab);
int	render(char **tab);
int	my_exit(char **tab);
int	load_file(char **tab);

#endif /* !CMD_H_ */
