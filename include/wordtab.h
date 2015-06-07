/*
** wordtab.h for wordtab in /home/vautie_a/rendu/Piscine_C_J08/wordtab
** 
** Made by jules vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Oct 28 19:11:11 2014 jules vautier
** Last update Sun Jun  7 23:24:07 2015 david sebaoun
*/

#ifndef WORDTAB_H_
# define WORDTAB_H_

char		*epur_str(char *, int);
int		my_count_nbr(char *dest);
int		my_wordlen(char *, int );
int		my_wordlen(char *dest, int i);
char		**my_word_to_tab(char *str, char *separ);
void		freetab(char **);
void		my_show_tab(char **);
int		my_tablen(char **);
char		**tabcpy(char **);

#endif /* !WORDTAB_H_ */
