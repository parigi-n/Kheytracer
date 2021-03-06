/*
** writer.c for write scene in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico/Parser_5_JUles
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sat Jun  6 14:53:46 2015 Nicolas PARIGI
** Last update Sun Jun  7 23:21:11 2015 david sebaoun
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "struct.h"
#include "shared.h"
#include "rt.h"
#include "string.h"
#include "printf.h"

static const	t_obj_type g_obj_type[] =
  {
    {"SPHERE", TYPE_SPHERE},
    {"CONE", TYPE_CONE},
    {"CYLINDER", TYPE_CYLINDER},
    {"PLAN", TYPE_PLAN},
    {NULL, -1}
  };

static int	write_lights(t_scene *scene, int fd)
{
  t_light	*tmp;

  tmp = scene->light;
  while (tmp != NULL)
    {
      dprintf(fd, "      %s", "ELEMENT  LIGHT\n");
      dprintf(fd, "      %s     \"%s\"\n",
	      "NAME", tmp->name);
      dprintf(fd, "      %s   %f %f %f\n",
	      "ORIGIN", tmp->pos.x, tmp->pos.y, tmp->pos.z);
      dprintf(fd, "      %s    %X\n\n",
	      "COLOR", tmp->color);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

static int	write_objects(t_scene *scene, int fd)
{
  t_object	*tmp;

  tmp = scene->obj;
  while (tmp != NULL)
    {
      dprintf(fd, "      %s",
	      "ELEMENT  OBJECT\n");
      dprintf(fd, "      %s     \"%s\"\n",
	      "NAME", tmp->name);
      dprintf(fd, "      %s     %s\n",
	      "TYPE", g_obj_type[tmp->type].name);
      dprintf(fd, "      %s   %f %f %f\n",
	      "ORIGIN", tmp->pos.x, tmp->pos.y, tmp->pos.z);
      dprintf(fd, "      %s %f %f %f\n",
	      "ROTATION", tmp->a.x, tmp->a.y, tmp->a.z);
      dprintf(fd, "      %s   %d\n", "RADIUS", tmp->r);
      dprintf(fd, "      %s    %X\n", "COLOR", tmp->color);
      dprintf(fd, "      %s    %f\n", "SHINE", tmp->shine);
      dprintf(fd, "      %s    %d\n\n", "LIMIT", tmp->lim);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

static int	write_eye(t_scene *scene, int fd)
{
  dprintf(fd, "      %s", "ELEMENT  EYE\n");
  dprintf(fd, "      %s   %f %f %f\n", "ORIGIN",
	  scene->eye.pos.x, scene->eye.pos.y, scene->eye.pos.z);
  dprintf(fd, "      %s %f %f %f\n", "ROTATION",
	  scene->eye.a.x, scene->eye.a.y, scene->eye.a.z);
  return (SUCCESS);
}

static char	*new_name(char *path)
{
  if (my_strlcmp(path, ".khey", 5) == SUCCESS)
    return (path);
  if ((path = my_strcat_separ(path, "khey", '.')) == NULL)
    {
      puterr(ERROR_MALLOC);
      return (NULL);
    }
  return (path);
}

int		my_writer(t_all *all, t_scene *scene)
{
  int		fd;
  char		*path;

  if (all->loaded != SUCCESS)
    return (puterr("Error: No Scene loaded.\n"));
  if (all->tab == NULL || all->tab[1] == NULL || my_strlen(all->tab[1]) <= 0)
    return (my_putstr("Usage: write file_name\n"));
  if ((path = new_name(all->tab[1])) == NULL)
    return (ERROR);
  if (access(path, F_OK) == 0)
    return (printf_err("\033[1;41mError: %s already exist.\033[0m\n", path));
  if ((fd = open(path, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP |
		 S_IWGRP | S_IROTH)) == ERROR)
    return (puterr(ERROR_OPEN));
  dprintf(fd, "%s", "I love Greg Ballot\n\n");
  dprintf(fd,"%s\n%s \"%s\"\n", "<BEGIN>", "!NAME ", all->tab[1]);
  write_objects(scene, fd);
  write_lights(scene, fd);
  write_eye(scene, fd);
  dprintf(fd, "%s", "</END>");
  if (close(fd) == ERROR)
    return (puterr(ERROR_CLOSE));
  return (my_putstr(WRITE_SUCCESS));
}
