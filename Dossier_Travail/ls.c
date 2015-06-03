/*
** ls.c for ls in /home/parigi_n/Testrendu/MUL_2014_rtracer/Dossier_Travail
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Wed Jun  3 16:29:16 2015 Nicolas PARIGI
** Last update Wed Jun  3 16:29:18 2015 Nicolas PARIGI
*/

#include <dirent.h>
#include <stddef.h>

int		my_ls()
{
  DIR		*fd;
  struct dirent	*entry;
  char		*name;

  if ((fd = opendir(".")) == NULL)
    return (-1);
  entry = readdir(fd);
  while ((entry = readdir(fd)) != NULL)
    {
      name = (*entry).d_name;
      if (name[0] != '.')
        {
	  if (my_strlen(name) >= 6 &&
	    name[my_strlen(name) - 1] == 'y' &&
	    name[my_strlen(name) - 2] == 'e' &&
	    name[my_strlen(name) - 3] == 'h' &&
	    name[my_strlen(name) - 4] == 'k' &&
	    name[my_strlen(name) - 5] == '.')
	      {
		my_putstr(name);
		my_putchar('\n');
	      }
        }
    }
  if (closedir(fd) == -1)
    return (-1);
  return (0);
}
