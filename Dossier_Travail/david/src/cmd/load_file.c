/*
** load_file.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:33:12 2015 david sebaoun
** Last update Fri Jun  5 18:57:49 2015 david sebaoun
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "rt.h"
#include "cmd.h"
#include "parser.h"

static int	check_file(const char *path)
{
  if (path == NULL)
    return (ERROR);
  if (my_strlen(path) < 6 ||
      (my_strlcmp(path, ".khey", 5) == ERROR) ||
      (access(path, R_OK)))
    {
      puterr("Error: File does not exist or is not compatible\n");
      return (ERROR);
    }
  return (SUCCESS);
}

static void	init_coord(t_coor *coord)
{
  coord->x = 0;
  coord->y = 0;
  coord->z = 0;
}

static int	load_file(char *path, t_scene *scene, t_all *all)
{
  int		fd;

  scene->name = NULL;
  scene->obj = NULL;
  scene->light = NULL;
  scene->last_line = 0;
  scene->nb_obj = 0;
  scene->nb_light = 0;
  init_coord(&scene->pos);
  init_coord(&scene->a);
  if (((fd = open(path, O_RDONLY)) == ERROR) ||
      (parser(scene, fd) == ERROR) ||
      (close(fd) == ERROR))
    {
      all->loaded = ERROR;
      my_putnbr(scene->last_line);
      return (ERROR);
    }
  all->loaded = SUCCESS;
  my_putstr("\033[1;32mFile Successfully loaded\033[0m\n");
  return (SUCCESS);
}

int	load(t_all *all, t_scene *scene)
{
  int	loadable;

  loadable = ERROR;
  if (all->tab[1] == NULL)
    {
      my_putstr("Usage: load file.khey\n");
      return (SUCCESS);
    }
  if ((loadable = check_file(all->tab[1])) == EXIT)
    return (EXIT);
  if (loadable == SUCCESS)
    if (load_file(all->tab[1], scene, all) == ERROR)
      return (puterr("Error: The file could not be loaded\n"));
  return (SUCCESS);
}
