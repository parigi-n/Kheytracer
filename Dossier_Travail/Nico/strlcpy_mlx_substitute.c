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

char	*strlcpy(char *dst, const char *src, unsigned int siz)
{
  return (my_strncpy(dst, src, siz));
}
