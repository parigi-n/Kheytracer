/*
** command_line.c for raytracer in /home/sebaou_d/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Tue May 26 19:07:33 2015 david sebaoun
** Last update Sun Jun  7 22:46:00 2015 Nicolas PARIGI
*/

#include "struct.h"
#include "string.h"
#include "shared.h"
#include "wordtab.h"
#include "cmd.h"

static const t_cmd	g_cmd[] =
  {
    {&ls, "ls"},
    {&load, "load"},
    {&help, "help"},
    {&show, "show"},
    {&create, "add"},
    {&clear, "clear"},
    {&my_exit, "exit"},
    {&render, "render"},
    {&my_writer, "write"},
    {NULL, ""}
  };

static void	cmd_start(t_all *all, t_scene *scene)
{
  scene->name = NULL;
  scene->obj = NULL;
  scene->light = NULL;
  scene->last_line = 0;
  scene->nb_obj = 0;
  scene->nb_light = 0;
  clear(all, scene);
  all->loaded = -1;
  my_putstr("Hello and welcome in kheytracer.\n");
  my_putstr("Type help to get infos about available actions.\n");
  my_putstr(PROMPT);
}

int		command_line(t_all *all)
{
  t_scene	scene;
  int		i;

  cmd_start(all, &scene);
  while ((all->tab = my_word_to_tab(get_next_line(0), " "))!= NULL)
    {
      if (all->tab[0] != NULL)
  	{
  	  i = -1;
  	  while (g_cmd[++i].function != NULL)
  	    {
  	      if (my_strcmp(g_cmd[i].cmd, all->tab[0]) == SUCCESS)
  		if (g_cmd[i].function(all, &scene) == EXIT)
  		  return (SUCCESS);
  	    }
  	}
      my_putstr(PROMPT);
    }
  return (ERROR);
}
