/*
** my_put_nbr_base.c for my_put_nbr_base in /home/sebaou_d/rendu/PSU_2014_my_printf/lib/my
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed Nov 12 16:56:52 2014 david sebaoun
** Last update Fri Nov 14 19:21:31 2014 david sebaoun
*/

#include "my.h"
#include "my_printf.h"

void			my_put_nbr_base(int nb, char *base)
{
  struct s_count	count;
  int			result;
  int			div;
  int			size_base;

  size_base = my_strlen(base);
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
      ++count.count;
    }
  div = 1;
  while ((nb / div) >= size_base)
    div = div * size_base;
  while (div > 0)
    {
      result = (nb / div) % size_base;
      my_putchar(base[result]);
      ++count.count;
      div = div / size_base;
    }
}
