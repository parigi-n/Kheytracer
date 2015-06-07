/*
** shared.h for 42sh in /home/sebaou_d/rendu/PSU_2014_42sh
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun May 17 12:06:37 2015 david sebaoun
** Last update Sun Jun  7 18:27:40 2015 david sebaoun
*/

#ifndef SHARED_H_
# define SHARED_H_

# include <unistd.h>
# include <stdlib.h>

# define SUCCESS	0
# define ERROR		-1
# define QUOTE		39
# define DQUOTE		34
# define GNL_STR_LIMIT	256

int		is_hexa(const char *);
int		my_putnbr(int);
int		my_putstr(const char *);
int		puterr(const char *);
int		my_putchar(const char);
int		my_strlen(const char *);
int		char_cmp_str(char, char *);
int		my_strcmp(const char *, const char *);
int		my_strlcmp(const char *, const char *, int);
int		my_strcmp_op(const char *, const char *, int);
int		my_strncmp(const char *, const char *, const int);
char		*get_next_line(int);
char		*my_strcpy(char *);
char		*my_strncpy(char *, int);
char		*my_strlcpy(char *, int);
char		*my_strcpy_inter(char *, int, int);
char		*my_strcat(char *, char *);
char		*my_strcat_separ(char *, char *, const char);
char		*add_char(char *, int, char);
char		*decal(char *, int);
int		my_getnbr(const char *);
char		*decaln(char *, int, int);
char		*strlcpy(char *, const char *, unsigned int);

#endif /* !SHARED_H_ */
