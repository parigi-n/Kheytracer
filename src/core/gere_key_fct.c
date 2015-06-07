/*
** img.c for img in /home/vautie_a/rendu/MUL_2014_fdf
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Tue Nov 18 14:37:14 2014 Jules Vautier
** Last update Sun Jun  7 22:36:44 2015 Nicolas PARIGI
*/

#include "rt.h"
#include "list.h"
#include "keyboard.h"

int	gere_key_eye(int keycode, t_scene *scene)
{
  if (keycode == CTRL)
    scene->eye.pos.x = scene->eye.pos.x + 20.0;
  else if (keycode == SHIFT)
    scene->eye.pos.x = scene->eye.pos.x - 20.0;
  else if (keycode == RIGHT)
    scene->eye.a.z = scene->eye.a.z + 0.02;
  else if (keycode == LEFT)
    scene->eye.a.z = scene->eye.a.z - 0.02;
  else if (keycode == UP)
    scene->eye.a.y = scene->eye.a.y + 0.02;
  else if (keycode == DOWN)
    scene->eye.a.y = scene->eye.a.y - 0.02;
  else
    return (0);
  return (1);
}

int	gere_key_plan(int keycode, t_object *tmp)
{
  if (keycode == T)
    tmp->pos.z = tmp->pos.z + 10.0;
  else if (keycode == G)
    tmp->pos.z = tmp->pos.z - 10.0;
  else
    return (0);
  return (1);
}

int	gere_key_sphe(int keycode, t_object *tmp)
{
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

int	gere_key_lum(int keycode, t_light *light)
{
  if (keycode == Z)
    light->pos.x = light->pos.x + 160.0;
  else if (keycode == S)
    light->pos.x = light->pos.x - 160.0;
  else if (keycode == Q)
    light->pos.y = light->pos.y + 160.0;
  else if (keycode == D)
    light->pos.y = light->pos.y - 160.0;
  else if (keycode == A)
    light->pos.z = light->pos.z + 160.0;
  else if (keycode == E)
    light->pos.z = light->pos.z - 160.0;
  else
    return (0);
  return (1);
}
