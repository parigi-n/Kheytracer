/*
** load_file.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:33:12 2015 david sebaoun
** Last update Thu Jun  4 19:11:58 2015 david sebaoun
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "rt.h"
#include "cmd.h"
#include "parser.h"

static int	check_file(const char *path)
{
  int		fd;

  if (path == NULL)
    return (ERROR);
  if (my_strlen(path) < 6 || 
      (path[my_strlen(path) - 1] != 'y' ||
       path[my_strlen(path) - 2] != 'e' ||
       path[my_strlen(path) - 3] != 'h' ||
       path[my_strlen(path) - 4] != 'k' ||
       path[my_strlen(path) - 5] != '.') ||
      (fd = open(path, O_RDONLY)) == ERROR)
    {
      puterr("Error: File does not exist or is not compatible\n");
      return (ERROR);
    }
  if (close(fd) == ERROR)
    {
      puterr("Error: Something unexpected happened\n");
      return (EXIT);
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
  t_object	*obj;
  t_light	*light;
  int		fd;

  obj = NULL;
  light = NULL;
  scene->obj = obj;
  scene->light = light;
  scene->nb_obj = 0;
  scene->nb_light = 0;
  scene->last_line = 1;
  init_coord(&scene->pos);
  init_coord(&scene->a);
  if (((fd = open(path, O_RDONLY)) == ERROR) ||
      (parser(scene, fd) == ERROR) ||
      (close(fd) == ERROR))
    {
      my_putnbr(scene->last_line);
      all->loaded = ERROR;
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