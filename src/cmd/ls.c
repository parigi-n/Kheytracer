/*
** ls.c for ls in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Wed Jun  3 16:29:16 2015 Nicolas PARIGI
** Last update Sun Jun  7 22:59:41 2015 Nicolas PARIGI
*/

#include <stddef.h>
#include <dirent.h>
#include "shared.h"
#include "string.h"
#include "struct.h"
#include "printf.h"

static void	check_file_type(char *file_name, int d_type)
{
  if (file_name[0] != '.')
    {
      if (my_strlcmp(file_name, ".khey", 5) == SUCCESS)
	my_printf("%s\n", file_name);
      else if (d_type == DT_DIR)
	my_printf("\033[0;36m%s\n\033[0m", file_name);
    }
}

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
    check_file_type((*entry).d_name, (*entry).d_type);
  if (closedir(fd) == ERROR)
    return (ERROR);
  return (SUCCESS);
  (void)all;
  (void)scene;
}
