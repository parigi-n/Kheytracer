/*
** get_data.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun Jun  7 12:12:49 2015 david sebaoun
** Last update Sun Jun  7 23:15:02 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"
#include "wordtab.h"
#include "printf.h"
#include "rt.h"

static const	t_obj_type g_obj_type[] =
  {
    {"SPHERE", TYPE_SPHERE},
    {"CONE", TYPE_CONE},
    {"CYLINDER", TYPE_CYLINDER},
    {"PLAN", TYPE_PLAN},
    {"LIGHT", TYPE_LIGHT},
    {NULL, -1}
  };

char		*up_case(char *str)
{
  int		i;

  i = -1;
  if (str != NULL)
    {
      while (str[++i] != 0)
	{
	  if (str[i] > 96 && str[i] < 123)
	    str[i] -= 32;
	}
      return (str);
    }
  return (NULL);
}

int		get_type()
{
  char		**tab;
  int		i;

  my_putstr("Welcome in the object creator tool.\n");
  my_putstr("Available types are : Sphere, \
Cylinder, Plan, Cone, Light\n");
  my_putstr("Type : ");
  while ((tab = (my_word_to_tab(get_next_line(0), " \t"))) != NULL)
    {
      i = 0;
      while (g_obj_type[i].type != -1)
	{
	  if (my_strcmp(up_case(tab[0]), g_obj_type[i].name) == SUCCESS)
	    return (g_obj_type[i].type);
	  i++;
	}
      my_putstr("Available types are : Sphere, \
Cylinder, Plan, Cone, Light\n");
      my_putstr("Type : ");
    }
  return (ERROR);
}

long		get_color()
{
  char		**tab;

  my_putstr("Color format is : XXXXXX with X being a symbol of base 16\n");
  my_putstr("Color : "); 
  while ((tab = (my_word_to_tab(get_next_line(0), " \t"))) != NULL)
    {
      if ((my_tablen(tab) == 1) && (my_strlen(tab[0]) == 6) &&
	  (is_hexa(tab[0]) == SUCCESS))
	return (strtol(tab[0], NULL, 16));
      my_putstr("Color format is : XXXXXX with X being a symbol of base 16\n");
      my_putstr("Color : ");
    }
  return (ERROR);
}

int		get_pos(t_coor *coord, char *str)
{
  char		**tab;

  my_printf("Position is set like : x y z\n%s : ", str);
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
      my_printf("Usage: x y z\n%s : ", str);
    }
  return (ERROR);
}

double		get_double(char *str)
{
  char		**tab;

  my_printf("%s : ", str);
  while ((tab = (my_word_to_tab(get_next_line(0), " \t"))) != NULL)
    {
      if (my_tablen(tab) == 1 && my_strlen(tab[0]) > 0)
	return (atof(tab[0]));
      my_printf("%s : ", str);
    }
  return (ERROR);
}
