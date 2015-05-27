/*
** command_line.c for raytracer in /home/sebaou_d/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Tue May 26 19:07:33 2015 david sebaoun
** Last update Tue May 26 19:10:05 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"
#include "wordtab.h"
#include "cmd.h"

static const t_cmd	g_cmd[] =
  {
    {&help, "help"},
    {&edit, "edit"},
    {&show, "show"},
    {&clear, "clear"},
    {&my_exit, "exit"},
    {&render, "render"},
    {&load_file, "load"},
    {&create, "create_scene"}
  };

int	clear(char **tab)
{
  (void)tab;
  my_putstr("\x1b[2J\x1b[H");
  return (SUCCESS);
}

int	load_file(char **tab)
{
  (void)tab;
  my_putstr("load_file\n");
  return (SUCCESS);
}

int	create(char **tab)
{
  (void)tab;
  my_putstr("create\n");
  return (SUCCESS);
}

int	render(char **tab)
{
  (void)tab;
  my_putstr("render\n");
  return (SUCCESS);
}

int	help(char **tab)
{
  (void)tab;
  my_putstr("help          show this help\nedit          start a scene editor");
  my_putstr("\nshow          show informations about loaded objects\n        ");
  my_putstr("      ex: show sphere1\nclear         clear the screen\nload    ");
  my_putstr("      load a scene from a configuration file\n              ex: ");
  my_putstr("load file.rt\nrender        render the loaded scene\ncreate_scen");
  my_putstr("e  start a scene configuration file tool\nexit          exit the");
  my_putstr(" program\n");
  return (SUCCESS);
}

int	edit(char **tab)
{
  (void)tab;
  my_putstr("edit\n");
  return (SUCCESS);
}

int	show(char **tab)
{
  (void)tab;
  my_putstr("show\n");
  return (SUCCESS);
}

int	my_exit(char **tab)
{
  /*my_freetab(tab);*/
  (void)tab;
  return (EXIT);
}

int	command_line(t_all *all)
{
  int	i;
  int	return_value;
  char	**tab;
  
  return_value = 0;
  write(1, "kheytracer$> ", 13);
  while ((tab = my_word_to_tab(get_next_line(0), " "))!= NULL)
    {
      if (tab[0] != NULL)
	{
	  i = -1;
	  while (++i < 8)
	    {
	      if (my_strcmp(g_cmd[i].cmd, tab[0]) == 0)
		if ((return_value = g_cmd[i].function(tab)) == EXIT ||
		    return_value == ERROR)
		  return (return_value);
	    }
	}
      write(1, "kheytracer$> ", 13);
    }
  return (ERROR);
}
