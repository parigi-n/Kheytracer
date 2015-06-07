/*
** load_file.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:33:12 2015 david sebaoun
** Last update Sun Jun  7 20:48:32 2015 david sebaoun
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "string.h"
#include "rt.h"
#include "cmd.h"
#include "parser.h"
#include "printf.h"
#include "wordtab.h"

static int	check_file(const char *path)
{
  if (path == NULL)
    return (ERROR);
  if (my_strlen(path) < 6 ||
      (my_strlcmp(path, ".khey", 5) == ERROR) ||
      (access(path, R_OK)))
    {
      puterr(ERROR_FILE);
      return (ERROR);
    }
  return (SUCCESS);
}

static int	load_file(char *path, t_scene *scene, t_all *all)
{
  int		fd;

  if (((fd = open(path, O_RDONLY)) == ERROR) ||
      (parser(scene, fd) == ERROR) ||
      (close(fd) == ERROR))
    {
      all->loaded = ERROR;
      printf_err(ERROR_LINE, scene->last_line);
      return (ERROR);
    }
  all->loaded = SUCCESS;
  my_putstr(LOAD_SUCCESS);
  return (SUCCESS);
}

int	check_reload()
{
  char		**tab;

  puterr("A scene is already loaded\n");
  my_putstr("Do you want to overwrite it [y/n] : ");
  while ((tab = (my_word_to_tab(get_next_line(0), " \t"))) != NULL)
    {
      if (my_strlen(tab[0]) == 1 &&
	  (tab[0][0] == 'y' || tab[0][0] == 'Y'))
	return (SUCCESS);
      if (my_strlen(tab[0]) == 1 &&
	  (tab[0][0] == 'n' || tab[0][0] == 'N'))
	return (ERROR);
      my_putstr("Do you want to overwrite it [y/n] : ");
    }
  return (ERROR);
}

int		load(t_all *all, t_scene *scene)
{
  int		loadable;

  loadable = ERROR;
  if (all->tab[1] == NULL)
    {
      my_putstr(LOAD_USAGE);
      return (SUCCESS);
    }
  if (all->loaded == SUCCESS && check_reload() == ERROR)
    return (ERROR);
  free_scene(all, scene);
  if ((loadable = check_file(all->tab[1])) == EXIT)
    return (EXIT);
  if (loadable == SUCCESS)
    if (load_file(all->tab[1], scene, all) == ERROR)
      return (puterr(ERROR_LOAD));
  return (SUCCESS);
}
