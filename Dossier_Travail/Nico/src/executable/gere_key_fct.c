/*
** img.c for img in /home/vautie_a/rendu/MUL_2014_fdf
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Nov 18 14:37:14 2014 Jules Vautier
** Last update Tue May 26 16:32:09 2015 Jules Vautier
*/

#include "rtv1.h"
#include "keyboard.h"

int	gere_key_eye(int keycode, t_all *all)
{
  if (keycode == CTRL)
    all->eye.pos.x = all->eye.pos.x + 20.0;
  else if (keycode == SHIFT)
    all->eye.pos.x = all->eye.pos.x - 20.0;
  else if (keycode == RIGHT)
    all->eye.a.z = all->eye.a.z + 0.02;
  else if (keycode == LEFT)
    all->eye.a.z = all->eye.a.z - 0.02;
  else if (keycode == UP)
    all->eye.a.y = all->eye.a.y + 0.02;
  else if (keycode == DOWN)
    all->eye.a.y = all->eye.a.y - 0.02;
  else
    return (0);
  return (1);
}

/*int	gere_key_plan(int keycode, t_all *all)
{
  if (keycode == F)
    all->px[2].ax = all->px[2].ax + 0.10;
  else if (keycode == H)
    all->px[2].ax = all->px[2].ax - 0.10;
  else if (keycode == T)
    all->px[2].z = all->px[2].z + 20.0;
  else if (keycode == G)
    all->px[2].z = all->px[2].z - 20.0;
  else
    return (0);
  return (1);
}

int	gere_key_obj(int keycode, t_all *all)
{
  if (keycode == O)
    all->px[0].x = all->px[0].x + 34.0;
  else if (keycode == L)
    all->px[0].x = all->px[0].x - 34.0;
  else if (keycode == K)
    all->px[0].y = all->px[0].y + 34.0;
  else if (keycode == M)
    all->px[0].y = all->px[0].y - 34.0;
  else if (keycode == P)
    all->px[0].z = all->px[0].z + 34.0;
  else if (keycode == I)
    all->px[0].z = all->px[0].z - 34.0;
  else if (keycode == R)
    all->px[3].ax = all->px[3].ax + 0.1;
  else if (keycode == Y)
    all->px[3].ax = all->px[3].ax - 0.1;
  else
    return (0);
  return (1);
}*/

int	gere_key_lum(int keycode, t_all *all)
{
  if (keycode == Z)
    all->lum.pos.x = all->lum.pos.x + 160.0;
  else if (keycode == S)
    all->lum.pos.x = all->lum.pos.x - 160.0;
  else if (keycode == Q)
    all->lum.pos.y = all->lum.pos.y + 160.0;
  else if (keycode == D)
    all->lum.pos.y = all->lum.pos.y - 160.0;
  else if (keycode == A)
    all->lum.pos.z = all->lum.pos.z + 160.0;
  else if (keycode == E)
    all->lum.pos.z = all->lum.pos.z - 160.0;
  else
    return (0);
  return (1);
}
