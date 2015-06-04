/*
** strlcpy_mlx_substitute.c for strlcpy_mlx in /home/parigi_n/Testrendu/MUL_2014_wolf3d
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sun Dec 28 17:13:58 2014 Nicolas PARIGI
** Last update Thu Jan  1 22:48:18 2015 Nicolas PARIGI
*/

#include <stddef.h>

char	*my_strncpy(char *dest, const char *src, int nb)
{
  int	lenght2;

  lenght2 = 0;
  while (src[lenght2] != '\0')
    {
      lenght2 = lenght2 + 1;
    }
  if (lenght2 < nb)
    {
      nb = lenght2;
      dest[nb] = '\0';
    }
  while (nb >= 0)
    {
      nb = nb - 1;
      dest[nb] = src[nb];
    }
  return (dest);
}

char	*strlcpy(char *dst, const char *src, unsigned int siz)
{
  return (my_strncpy(dst, src, siz));
}
