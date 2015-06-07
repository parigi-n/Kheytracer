/*
** is_hexa.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer/Dossier_Travail/david
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sun Jun  7 12:20:04 2015 david sebaoun
** Last update Sun Jun  7 12:21:14 2015 david sebaoun
*/

#include "shared.h"

int	is_hexa(const char *str)
{
  int	i;

  i = -1;
  while (str[++i] != 0)
    if (str[i] < 48 || (str[i] > 57 && str[i] < 65) ||
  	(str[i] > 70 && str[i] < 97) || str[i] > 102)
      return (ERROR);
  return (SUCCESS);
}
