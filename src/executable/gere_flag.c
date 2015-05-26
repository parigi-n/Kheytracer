/*
** gere_flag.c for gere_flag in /home/vautie_a/rendu/MUL_2014_rtv1/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Mar  5 08:42:44 2015 Jules Vautier
** Last update Tue May 26 19:11:48 2015 david sebaoun
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "rt.h"

static int	readme()
{
  int		fd;
  int		len;
  char		buff[1024];

  if ((fd = open("README", O_RDONLY)) == -1)
    {
      puterr("Fail with open\n");
      return (-1);
    }
  while ((len = read(fd, buff, 1023)) > 0)
    {
      buff[len] = '\0';
      my_putstr(buff);
    }
  if (close(fd) == -1)
    {
      puterr("Fail with close\n");
      return (-1);
    }
  return (0);
}

static int	put_help()
{
  my_putstr("Usage: ./rtv1 [-all]remove all   [-o]shadow ");
  my_putstr("[-r]rotation [-i]intensity.\n");
  my_putstr("Type [-k] [--key] to know how use the keyboard.\n");
  return (0);
}

static int	do_flag(t_flags *flag, char **argv, int i)
{
  if (my_strcmp(argv[i], "-all") == 0)
    {
      flag->rotate = 0;
      flag->intensity = 0;
      flag->shadow = 0;
      return (1);
    }
  else if (my_strcmp(argv[i], "-r") == 0)
    flag->rotate = 0;
  else if (my_strcmp(argv[i], "-i") == 0)
    flag->intensity = 0;
  else if (my_strcmp(argv[i], "-o") == 0)
    flag->shadow = 0;
  else if (my_strcmp(argv[i], "-h") == 0 ||
	   my_strcmp(argv[i], "-help") == 0)
    return (put_help());
  else if (my_strcmp(argv[i], "-k") == 0 ||
	   my_strcmp(argv[i], "--key") == 0)
	   if (readme() == -1)
	     return (-1);
  return (0);
}

int	gere_flag(t_flags *flag, int argc, char **argv)
{
  int	i;
  int	check;

  i = 0;
  flag->rotate = 1;
  flag->intensity = 1;
  flag->shadow = 1;
  while (i < argc)
    {
      if ((check = do_flag(flag, argv, i)) != 0)
	return (check);
      i++;
    }
  return (0);
}
