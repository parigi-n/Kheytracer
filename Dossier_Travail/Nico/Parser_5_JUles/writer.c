/*
** writer.c for write scene in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail/Nico/Parser_5_JUles
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sat Jun  6 14:53:46 2015 Nicolas PARIGI
** Last update Sat Jun  6 15:36:10 2015 Nicolas PARIGI
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "struct.h"

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
  dprintf(fd, "%s%f%f%f\n", "ORIGIN", eye->pos.x, eye->pos.y, eye->pos.z);
  dprintf(fd, "%s%f%f%f\n\h", "ROTATION", eye->a.x, eye->a.y, eye->>a.z);
  return (SUCCESS);
}

int		scene_writer(t_scene *data, char *name)
{
  int		fd;

  if ((fd = open(name, O_WRONLY)) == -1)
    return (-1);;
  dprintf(fd, "%s", "I love Greg Ballot\n\n");
  dprintf(fd,"%s\n%s%s\n", "<BEGIN>", "NAME ", data->name);
  write_objects(data, fd);
  write_lights(data, fd);
  write_eye(data, fd);
  dprintf(fd, "%s", "</END>");
  if (close(fd) == -1)
    return (-1);
}
