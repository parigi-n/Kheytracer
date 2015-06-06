/*
** strlcpy_mlx_substitute.c for strlcpy_mlx in /home/parigi_n/Testrendu/MUL_2014_wolf3d
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sun Dec 28 17:13:58 2014 Nicolas PARIGI
** Last update Thu Jun  4 17:10:59 2015 david sebaoun
*/

#include <stddef.h>

char	*strlcpy(char *dst, const char *src, unsigned int size)
{
  int	length;

  length = 0;
  while (src[length] != '\0')
    {
      length = length + 1;
    }
  if (length < size)
    {
      size = length;
      dst[size] = '\0';
    }
  while (size >= 0)
    {
      size = size - 1;
      dst[size] = src[size];
    }
  return (dst);
}
