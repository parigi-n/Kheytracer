/*
** img.c for img in /home/vautie_a/rendu/MUL_2014_fdf
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Nov 18 14:37:14 2014 Jules Vautier
<<<<<<< HEAD
** Last update Wed May 27 08:01:48 2015 Jules Vautier
*/

#include "rtv1.h"
#include "list.h"
=======
** Last update Tue May 26 19:11:57 2015 david sebaoun
*/

#include "rt.h"
>>>>>>> 7b4f8b46492ef0dc1a0dac4d9277e1b011142ae6
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

int	gere_key_plan(int keycode, t_all *all)
{
  t_object	*tmp;

  tmp = my_getlist(&all->object, "plan");
  if (keycode == T)
    tmp->pos.z = tmp->pos.z + 10.0;
  else if (keycode == G)
    tmp->pos.z = tmp->pos.z - 10.0;
  else
    return (0);
  return (1);
}

int	gere_key_sphe(int keycode, t_all *all)
{
  t_object	*tmp;

  tmp = my_getlist(&all->object, "sphere1");
  if (keycode == O)
    tmp->pos.x = tmp->pos.x + 10.0;
  else if (keycode == L)
    tmp->pos.x = tmp->pos.x - 10.0;
  else if (keycode == K)
    tmp->pos.y = tmp->pos.y + 10.0;
  else if (keycode == M)
    tmp->pos.y = tmp->pos.y - 10.0;
  else if (keycode == P)
    tmp->pos.z = tmp->pos.z + 10.0;
  else if (keycode == I)
    tmp->pos.z = tmp->pos.z - 10.0;
  else if (keycode == R)
    tmp->a.z = tmp->a.z + 1.0;
  else if (keycode == Y)
    tmp->a.z = tmp->a.z - 1.0;
  else
    return (0);
  return (1);
}

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
