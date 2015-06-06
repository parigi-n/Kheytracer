/*
** writer.c for write scene in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico/Parser_5_JUles
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sat Jun  6 14:53:46 2015 Nicolas PARIGI
** Last update Sat Jun  6 16:04:49 2015 david sebaoun
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "struct.h"
#include "shared.h"

static int	write_lights(t_scene *scene, int fd)
{
  t_light	*tmp;

  tmp = scene->light;
  while (tmp != NULL)
    {
      dprintf(fd, "%s", "ELEMENT LIGHT\n");
      dprintf(fd, "%s%s\n", "NAME", tmp->name);
      dprintf(fd, "%s%f%f%f\n", "ORIGIN", tmp->pos.x, tmp->pos.y, tmp->pos.z);
      dprintf(fd, "%s%d\n\n", "COLOR", 42);
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
      dprintf(fd, "%s", "ELEMENT OBJECT\n");
      dprintf(fd, "%s%s\n", "NAME", tmp->name);
      dprintf(fd, "%s%s\n", "TYPE", "TMP");
      dprintf(fd, "%s%f%f%f\n", "ORIGIN", tmp->pos.x, tmp->pos.y, tmp->pos.z);
      dprintf(fd, "%s%f%f%f\n", "ROTATION", tmp->a.x, tmp->a.y, tmp->a.z);
      dprintf(fd, "%s%f\n", "RADIUS", tmp->r);
      dprintf(fd, "%s%d\n\n", "COLOR", 42);
      tmp = tmp->next;
    }
  return (SUCCESS);
}

static int	write_eye(t_scene *scene, int fd)
{
  dprintf(fd, "%s", "ELEMENT EYE\n");
  dprintf(fd, "%s%f%f%f\n", "ORIGIN", scene->eye.pos.x, scene->eye.pos.y, scene->eye.pos.z);
  dprintf(fd, "%s%f%f%f\n\n", "ROTATION", scene->eye.a.x, scene->eye.a.y, scene->eye.a.z);
  return (SUCCESS);
}

int		my_writer(t_all *all, t_scene *scene)
{
  int		fd;

  my_putchar('@');
  if (all->tab[1] == NULL)
    return (my_putstr("Usage : write file_name.khey\n"));
  if ((fd = open(all->tab[1], O_WRONLY | O_CREAT,
		 S_IRUSR | S_IWUSR | S_IRGRP |
		 S_IWGRP | S_IROTH)) == ERROR)
    return (ERROR);
  dprintf(fd, "%s", "I love Greg Ballot\n\n");
  dprintf(fd,"%s\n%s%s\n", "<BEGIN>", "NAME ", all->tab[1]);
  write_objects(scene, fd);
  write_lights(scene, fd);
  write_eye(scene, fd);
  dprintf(fd, "%s", "</END>");
  if (close(fd) == ERROR)
    return (ERROR);
  return (SUCCESS);
}