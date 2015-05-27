/*
** load_file.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:33:12 2015 david sebaoun
** Last update Wed May 27 11:43:37 2015 david sebaoun
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "rt.h"
#include "cmd.h"

static int	check_file(const char *path)
{
  int		fd;

  if (path == NULL)
    return (ERROR);
  if ((path[my_strlen(path) - 1] != 't' ||
       path[my_strlen(path) - 2] != 'r' ||
       path[my_strlen(path) - 3] != '.') ||
      (fd = open(path, O_RDONLY)) == ERROR)
    {
      my_putstr("Error: File does not exist or is not compatible\n");
      return (ERROR);
    }
  if (close(fd) == ERROR)
    {
      my_putstr("Error: Something unexpected happened\n");
      return (EXIT);
    }
  return (SUCCESS);
}

static int	load_file(t_all *all)
{
  return (SUCCESS);
}

int	load(t_all *all)
{
  int	loadable;

  loadable = ERROR;
  if (all->tab[1] == NULL)
    {
      my_putstr("Usage: load file.rt\n");
      return (SUCCESS);
    }
  if ((loadable = check_file(all->tab[1])) == EXIT)
    return (EXIT);
  if (loadable == SUCCESS)
    load_file(all);
  return (SUCCESS);
}
