#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "shared.h"
#include "wordtab.h"

#define MAX_NAME 64
int	content_parsing(char line, int fd)
{
  char	*raw_line;
  char	**tab;
  int	order;

  order = 0;
  while ((raw_line = get_next_line(fd)) != NULL)
    {
      my_word_to_tab(line, " ");
      if (my_tablen(tab) < 2 || my_tablen(tab) > 4)
	return (puterr("Error tablen\n");
      if (order == 0)
	{
	  if (my_strcmp(tab[0], "TYPE") != 0)
	    return (puterr("Fail strcmp\n"));
	  if (my_strlen(tab[1]) <= 0)
	    return (puterr("Fail strcmp\n"));
	  order++;
	}
      else if (order == 1)
	{
	  if (my_strcmp(tab[0], "ORIGIN") != 0)
	    return (puterr("Fail strcmp\n"));
	  if (my_strlen(tab[1]) <= 0)
	    return (puterr("Fail strcmp\n"));
	  order++;
	}
      else if (order == 2)
	{
	  if (my_strcmp(tab[0], "ROTATION") != 0)
	    return (puterr("Fail strcmp\n"));
	  if (my_strlen(tab[1]) <= 0)
	    return (puterr("Fail strcmp\n"));
	  order++;
	}
      else if (order == 3)
	{
	  if (my_strcmp(tab[0], "RAYON") != 0)
	    return (puterr("Fail strcmp\n"));
	  if (my_strlen(tab[1]) <= 0)
	    return (puterr("Fail strcmp\n"));
	  order++;
	}
      else if (order == 4)
	{
	  if (my_strcmp(tab[0], "COLOR") != 0)
	    return (puterr("Fail strcmp\n"));
	  if (my_strlen(tab[1]) <= 0)
	    return (puterr("Fail strcmp\n"));
	  order++;
	}
    }
}

int	main()
{
  char	*raw_line;
  char	*line;
  char	**tab;
  char	*name;
  int	fd;
  int	flag_begin;

  flag_begin = 0;
  fd = open("test.khey", O_RDONLY);
  while ((raw_line = get_next_line(fd)) != NULL)
    {
      line = epur_str(raw_line, 0);
      if (my_strcmp(line, "<BEGIN>") == 0 && flag_begin == 1)
	return (puterr("Error : BEGIN is defined twice in the file. Parsing stopped.\n"));
      if (my_strcmp(line, "<BEGIN>") == 0)
	flag_begin = 2;
      else if (flag_begin == 2)
	{
	  if ((tab = my_word_to_tab(line, " ")) == NULL)
	    return (puterr("Error : Malloc failed"));
	  if (my_tablen(tab) == 2 && my_strcmp(tab[0], "!NAME") == 0)
	    {
	      if (tab[1] == NULL || my_strlen(tab[1]) < 1 || my_strlen(tab[1]) > MAX_NAME)
		return(puterr("Error : !NAME content is NULL or is larger than 64 char. Parsing stopped.\n"));
	      flag_begin = 1;
	      name = my_strcpy(tab[1]);
	    }
	  else
	    return (puterr("Error : No !NAME variable defined after <BEGIN>, or variable is badly defined. Parsing stopped.\n"));
	}
      else if (flag_begin == 1)
	{
	  content_parsing(line, fd);
	}
    }
  if (flag_begin == 0)
    return (puterr("Error : No <BEGIN> variable found. No parsing done.\n"));
  my_putstr(name);
}
