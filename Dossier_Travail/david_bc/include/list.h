/*
** list.h for list.h in /home/vautie_a/rendu/PSU_2014_minishell2/mysh_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Feb 26 17:38:14 2015 Jules Vautier
** Last update Mon Jun  1 17:09:31 2015 david sebaoun
*/

#ifndef LIST_H_
# define LIST_H_

void		my_show_list(t_object *list);
void		free_list(t_object **list);
int		erase_list_object(t_object **list, char *str);
int		listlen(t_object **list);
int		my_put_in_list_object(t_object **, char *);
int		my_put_in_list_light(t_light **, char *);
void		my_show_list(t_object *);
t_object	*my_getlist_obj(t_object **, char *);
t_light		*my_getlist_light(t_light **, char *);

#endif /* !LIST_H_ */
