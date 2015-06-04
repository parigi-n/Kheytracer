/*
** get_next_line.c for lem_in in /home/sebaou_d/rendu/CPE_2014_lemin
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Tue Apr 21 11:24:20 2015 david sebaoun
** Last update Thu Jun  4 17:50:17 2015 david sebaoun
*/

#include <unistd.h>
#include <stdlib.h>
#include "shared.h"

char	*re_alloc(char *str, char c)
{
  char	*new;
  int	i;

  i = 0;
  if (str)
    {
      if ((new = malloc(sizeof(char) * (my_strlen(str) + 2))) == NULL)
	return (NULL);
      while (str[i] != '\0')
	{
	  new[i] = str[i];
	  i++;
	}
      new[i++] = c;
      new[i++] = '\0';
      free(str);
      return (new);
    }
  return (NULL);
}

static int	check_char(const char c)
{
  if (c >= 0  && c < 7)
    return (ERROR);
  return (SUCCESS);
}

char	*get_next_line(int fd)
{
  char	buff[2];
  char	*str;
  int	len;

  if ((str = malloc(1)) == NULL)
    return (NULL);
  str[0] = '\0';
  while ((len = read(fd, buff, 1)) > 0)
    {
      if (check_char(buff[0]) == ERROR)
      	return (NULL);
      if (buff[0] == '\n')
        return (str);
      if ((str = re_alloc(str, buff[0])) == NULL)
	return (NULL);
    }
  return (NULL);
}
