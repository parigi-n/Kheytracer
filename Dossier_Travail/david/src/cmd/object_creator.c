/*
** scene_creator.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:38:32 2015 david sebaoun
** Last update Sun Jun  7 12:29:48 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"
#include "wordtab.h"
#include "printf.h"
#include "parser.h"
#include "rt.h"
#include "cmd.h"

static int	new_scene(t_scene *scene)
{
  char		**tab;

  puterr("There is currently no scene in memory\
, please choose a name for a new one\n"); 
  my_putstr("Scene Name : "); 
  while ((tab = (my_word_to_tab(get_next_line(0), " \t"))) != NULL)
    {
      if ((my_tablen(tab) == 1) && (my_strlen(tab[0]) > 0))
	{
	  scene->name = my_strcpy(tab[0]);
	  puterr("You also need a camera\n");
	  if (get_pos(&scene->eye.pos, "Position") == ERROR)
	    return (ERROR);
	  if (get_pos(&scene->eye.a, "Rotation") == ERROR)
	    return (ERROR);
	  return (SUCCESS);
	}
      my_putstr("Scene Name : ");
    }
  return (ERROR);
}

int		free_scene(t_all *all, t_scene *scene)
{
  all->loaded = ERROR;
  return (SUCCESS);
}

int		create(t_all *all, t_scene *scene)
{
  int		type;

  if (all->tab[1] == NULL)
    {
      my_putstr("Usage: add new_object_name\n");
      return (ERROR);
    }
  if ((all->loaded == ERROR) && (new_scene(scene) == ERROR))
    return (ERROR);
  if ((type = get_type()) == TYPE_LIGHT)
    {
      if (add_light(scene, all->tab[1]) != ERROR)
  	{
  	  all->loaded = SUCCESS;
  	  return (SUCCESS);
  	}
    }
  else if (type != ERROR &&
	   add_object(scene, all->tab[1], type) != ERROR)
    {
      all->loaded = SUCCESS;
      return (SUCCESS);
    }
  free_scene(all, scene);
  return (ERROR);
}
