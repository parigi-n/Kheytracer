/*
** load_file.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:33:12 2015 david sebaoun
** Last update Tue Jun  2 16:26:06 2015 david sebaoun
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

static void		show_list_scene(t_object *obj)
{
  t_object		*tmp;

  tmp = obj;
  while (tmp != NULL)
    {
      printf("\nname: %s\ntype: %d\nax: %f\nay: %f\naz: %f\nposx: %f\nposy: %f\nposz: %f\nr: %d\nlim: %f\ncolor: %d\n", tmp->name, tmp->type, tmp->a.x, tmp->a.y, tmp->a.z, tmp->pos.x, tmp->pos.y, tmp->pos.z, tmp->r, tmp->lim, tmp->color);
      tmp = tmp->next;
    }
}

static int	load_file(char *path, t_scene *scene, t_all *all)
{
  int		fd;

  if ((fd = open(path, O_RDONLY)) == ERROR)
    return (ERROR);
  if (parser(scene, fd) == ERROR)
    return (ERROR);
  if (close(fd) == ERROR)
    return (ERROR);
  show_list_scene(&scene->obj);
  all->loaded = SUCCESS;
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
