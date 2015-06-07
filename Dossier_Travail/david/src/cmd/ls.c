/*
** ls.c for ls in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Wed Jun  3 16:29:16 2015 Nicolas PARIGI
** Last update Sun Jun  7 13:42:31 2015 david sebaoun
*/

#include <dirent.h>
#include <stddef.h>
#include "shared.h"
#include "string.h"
#include "struct.h"
#include "printf.h"

int		ls(t_all *all, t_scene *scene)
{
  DIR		*fd;
  struct dirent	*entry;

  if (all->tab[1] != NULL)
    {
      if ((fd = opendir(all->tab[1])) == NULL)
	return (puterr(ERROR_ACCESS));
    }
  else
    if ((fd = opendir(".")) == NULL)
      return (ERROR);
  while ((entry = readdir(fd)) != NULL)
    {
      if ((*entry).d_name[0] != '.')
        {
	  if (my_strlcmp((*entry).d_name, ".khey", 5) == SUCCESS)
	    my_printf("%s\n", (*entry).d_name);
        }
    }
  if (closedir(fd) == ERROR)
    return (ERROR);
  return (SUCCESS);
  (void)all;
  (void)scene;
}
