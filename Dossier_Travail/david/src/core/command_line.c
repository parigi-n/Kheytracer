/*
** command_line.c for raytracer in /home/sebaou_d/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Tue May 26 19:07:33 2015 david sebaoun
** Last update Sat Jun  6 10:20:33 2015 david sebaoun
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
    {&load, "load"},
    {&ls, "ls"},
    {&create, "create_scene"}
  };

static void	cmd_start(t_all *all, t_scene *scene)
{
  clear(all, scene);
  all->loaded = -1;
  my_putstr("Hello and welcome in kheytracer.\n");
  my_putstr("Type help to get infos about available actions.\n");
  my_putstr("kheytracer$> ");
}

int		command_line(t_all *all)
{
  t_scene	scene;
  int		i;
  
  cmd_start(all, &scene);
  /* load(all, &scene); */
  /* render(all, &scene); */
  while ((all->tab = my_word_to_tab(get_next_line(0), " "))!= NULL)
    {
      if (all->tab[0] != NULL)
  	{
  	  i = -1;
  	  while (++i < 9)
  	    {
  	      if (my_strcmp(g_cmd[i].cmd, all->tab[0]) == 0)
  		if (g_cmd[i].function(all, &scene) == EXIT)
  		  return (SUCCESS);
  	    }
  	}
      write(1, "kheytracer$> ", 13);
    }
  return (ERROR);
}
