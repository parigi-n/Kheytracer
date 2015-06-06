/*
** my_loading.c for loading in /home/parigi_n/Testrendu/MUL_2014_Raytracer/rtv1_src
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Tue Apr 14 16:57:05 2015 Nicolas PARIGI
** Last update Sat Jun  6 10:22:14 2015 Jules Vautier
*/

#include "struct.h"
#include "shared.h"

void	my_loading(int current, int total)
{
  int	per_cent;
  int	i;

  i = 0;
  per_cent = (100 * current) / (total);

  my_putchar('[');
  while (per_cent > 0)
    {
      if (per_cent > 0)
        {
	  my_putchar('|');
	  per_cent = per_cent - 10;
	  i++;
        }
    }
  while (i++ < 10)
    my_putchar(' ');
  my_putchar(']');
  my_putstr("\r");
}
