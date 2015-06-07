/*
** scene_creator.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:38:32 2015 david sebaoun
** Last update Sat Jun  6 23:40:50 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"
#include "wordtab.h"
#include "printf.h"
#include "parser.h"
#include "rt.h"

static const	t_obj_type g_obj_type[] =
  {
    {"SPHERE", TYPE_SPHERE},
    {"CONE", TYPE_CONE},
    {"CYLINDER", TYPE_CYLINDER},
    {"PLAN", TYPE_PLAN},
    {"DISC", TYPE_DISC},
    {"TRIANGLE", TYPE_TRIANGLE},
    {"HYPERB", TYPE_HYPERB},
    {"LIGHT", TYPE_LIGHT},
    {NULL, -1}
  };

static int	get_type()
{
  char		**tab;
  int		i;

  my_putstr("Type : "); 
  while ((tab = (my_word_to_tab(get_next_line(0), " \t"))) != NULL)
    {
      i = 0;
      while (g_obj_type[i].type != -1)
	{
	  if (my_strcmp(tab[0], g_obj_type[i].name) == SUCCESS)
	    return (g_obj_type[i].type);
	  i++;
	}
      my_putstr("Type : ");    
    }
  return (ERROR);
}

static int	get_pos(t_coor *coord, char *str)
{
  char		**tab;

  my_printf("%s : ", str); 
  while ((tab = (my_word_to_tab(get_next_line(0), " \t"))) != NULL)
    {
      if (my_tablen(tab) == 3 && my_strlen(tab[0]) > 0 &&
	  my_strlen(tab[1]) > 0 && my_strlen(tab[2]) > 0)
	{
	  coord->x = atof(tab[0]);
	  coord->y = atof(tab[1]);
	  coord->z = atof(tab[2]);
	  return (SUCCESS);
	}
      my_printf("%s : ", str);
    }
  return (ERROR);
}

static int	get_radius()
{
  int		radius;
  char		**tab;
  
  radius = 0;
  my_putstr("Radius : ");
  while ((tab = (my_word_to_tab(get_next_line(0), " \t"))) != NULL)
    {
      if (my_tablen(tab) == 1 && my_strlen(tab[0]) > 0)
	return (radius);
      my_putstr("Radius : ");
    }
  return (ERROR);
}

int		check_hexa(char *str)
{
  int		i;

  i = -1;
  while (str[++i] != 0)
    if (str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
  	(str[i] > 70 && str[i] < 97) || str[i] > 102)
      return (ERROR);
  return (SUCCESS);
}

static long	get_color()
{
  char		**tab;

  my_putstr("Color : "); 
  while ((tab = (my_word_to_tab(get_next_line(0), " \t"))) != NULL)
    {
      if ((my_tablen(tab) == 1) && (my_strlen(tab[0]) == 6) &&
	  (check_hexa(tab[0]) == SUCCESS))
	return (strtol(tab[0], NULL, 16));
      my_putstr("Color : ");
    }
  return (ERROR);
}

static int	add_light(t_scene *scene, char *name)
{
  t_light	*tmp_light;

  if ((tmp_light = malloc(sizeof(t_light))) == NULL)
    return (ERROR);
  tmp_light->name = my_strcpy(name);
  if ((tmp_light->color = get_color()) == ERROR)
    return (ERROR);
  if (get_pos(&tmp_light->pos, "Position") == ERROR)
    return (ERROR);
  tmp_light->next = scene->light;
  scene->light = tmp_light; 
  return (SUCCESS);
}

static int	add_object(t_scene *scene, char *name, int type)
{
  t_object	*tmp_obj;

  if ((tmp_obj = malloc(sizeof(t_object))) == NULL)
    return (ERROR);
  tmp_obj->name = my_strcpy(name);
  tmp_obj->type = type;
  if (get_pos(&tmp_obj->pos, "Position") == ERROR)
    return (ERROR);
  if (get_pos(&tmp_obj->a, "Angle") == ERROR)
    return (ERROR);
  if ((tmp_obj->r = get_radius()) == ERROR)
    return (ERROR);
  if ((tmp_obj->color = get_color()) == ERROR)
    return (ERROR);
  tmp_obj->next = scene->obj;
  scene->obj = tmp_obj;
  return (SUCCESS);
}

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
	  return (SUCCESS);
	}
      my_putstr("Scene Name : ");
    }
  return (ERROR);
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
  if (((type = get_type()) == TYPE_LIGHT) && (add_light(scene, all->tab[1]) == ERROR))
    return (ERROR);
  else if ((type != ERROR) && (add_object(scene, all->tab[1], type) == ERROR))
    return (ERROR);
  all->loaded = SUCCESS;
  return (SUCCESS);
}
