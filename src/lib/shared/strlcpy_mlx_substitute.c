/*
** strlcpy_mlx_substitute.c for strlcpy_mlx in /home/parigi_n/Testrendu/MUL_2014_wolf3d
** 
** Made by Nicolas PARIGI
** Login   <parigi_n@epitech.net>
** 
** Started on  Sun Dec 28 17:13:58 2014 Nicolas PARIGI
** Last update Sat Jun  6 12:30:12 2015 david sebaoun
*/

#include <stddef.h>
#include <limits.h>

char		*strlcpy(char *dst, const char *src, unsigned int size)
{
  unsigned int	length;

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
  while (size != UINT_MAX)
    {
      size = size - 1;
      dst[size] = src[size];
    }
  return (dst);
}
