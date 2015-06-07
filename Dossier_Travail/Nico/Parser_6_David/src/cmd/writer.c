/*
** writer.c for write scene in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico/Parser_5_JUles
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sat Jun  6 14:53:46 2015 Nicolas PARIGI
** Last update Sat Jun  6 22:15:41 2015 Nicolas PARIGI
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "struct.h"
#include "shared.h"
#include "rt.h"
#include "string.h"

static const	t_obj_type g_obj_type[] =
  {
    {"SPHERE", TYPE_SPHERE},
    {"CONE", TYPE_CONE},
    {"CYLINDER", TYPE_CYLINDER},
    {"PLAN", TYPE_PLAN},
    {"DISC", TYPE_DISC},
    {"TRIANGLE", TYPE_TRIANGLE},
    {"HYPERB", TYPE_HYPERB},
    {NULL, -1}
  };

static int	write_lights(t_scene *scene, int fd)
{
  t_light	*tmp;

  tmp = scene->light;
  while (tmp != NULL)
    {
      dprintf(fd, "      %s", "ELEMENT  LIGHT\n");
      dprintf(fd, "      %s     \"%s\"\n", "NAME", tmp->name);
      dprintf(fd, "      %s   %f %f %f\n", "ORIGIN", tmp->pos.x, tmp->pos.y, tmp->pos.z);
      dprintf(fd, "      %s    %X\n\n", "COLOR", tmp->color);
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
      dprintf(fd, "      %s", "ELEMENT  OBJECT\n");
      dprintf(fd, "      %s     \"%s\"\n", "NAME", tmp->name);
      dprintf(fd, "      %s     %s\n", "TYPE", g_obj_type[tmp->type].name);
      dprintf(fd, "      %s   %f %f %f\n", "ORIGIN", tmp->pos.x, tmp->pos.y, tmp->pos.z);
      dprintf(fd, "      %s %f %f %f\n", "ROTATION", tmp->a.x, tmp->a.y, tmp->a.z);
      dprintf(fd, "      %s   %d\n", "RADIUS", tmp->r);
      dprintf(fd, "      %s    %X\n\n", "COLOR", tmp->color);
      dprintf(fd, "      %s    %f\n\n", "SHINE", tmp->shine);
      dprintf(fd, "      %s    %D\n\n", "COLOR", tmp->limit);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

static int	write_eye(t_scene *scene, int fd)
{
  dprintf(fd, "      %s", "ELEMENT  EYE\n");
  dprintf(fd, "      %s   %f %f %f\n", "ORIGIN", scene->eye.pos.x, scene->eye.pos.y, scene->eye.pos.z);
  dprintf(fd, "      %s %f %f %f\n\n", "ROTATION", scene->eye.a.x, scene->eye.a.y, scene->eye.a.z);
  return (SUCCESS);
}

int		my_writer(t_all *all, t_scene *scene)
{
  int		fd;
  char		*path;
  
  if (all->loaded != SUCCESS)
    return (puterr("Error : No Scene loaded.\n"));
  if (all->tab == NULL || all->tab[1] == NULL || my_strlen(all->tab[1]) <= 0)
    return (my_putstr("Usage : write file_name.khey\n"));
  if ((path = my_strcat_separ(all->tab[1], "khey", '.')) == NULL)
    return (puterr(ERROR_MALLOC));
  if (access(path, F_OK) == 0)
    return (printf_err("%s%s%s%s%s", "\033[1;41m", "Error : ", path, " already exist.\n", "\033[0m"));
  if ((fd = open(path, O_WRONLY | O_CREAT,
		 S_IRUSR | S_IWUSR | S_IRGRP |
		 S_IWGRP | S_IROTH)) == ERROR)
    return (ERROR);
  dprintf(fd, "%s", "I love Greg Ballot\n\n");
  dprintf(fd,"%s\n%s \"%s\"\n", "<BEGIN>", "!NAME ", all->tab[1]);
  write_objects(scene, fd);
  write_lights(scene, fd);
  write_eye(scene, fd);
  dprintf(fd, "%s", "</END>");
  if (close(fd) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
