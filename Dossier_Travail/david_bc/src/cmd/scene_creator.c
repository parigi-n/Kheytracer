/*
** scene_creator.c for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Wed May 27 11:38:32 2015 david sebaoun
** Last update Sat Jun  6 17:44:32 2015 david sebaoun
*/

#include "struct.h"
#include "shared.h"
#include "printf.h"

#include <termios.h>

# define EXIT	27
# define UP	4283163
# define DOWN	4348699
# define DELETE	2117294875

int			canon()
{
  struct termios	t;

  if ((tcgetattr(0, &t)) == ERROR)
    return (ERROR);
  t.c_lflag &= ~ICANON;
  t.c_cc[VMIN] = 1;
  t.c_cc[VTIME] = 0;
  if ((tcsetattr(0, TCSANOW, &t)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int			my_echo()
{
  struct termios	t;

  if ((tcgetattr(0, &t)) == ERROR)
    return (ERROR);
  t.c_lflag &= ~ECHO;
  if ((tcsetattr(0, TCSANOW, &t)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int			set(t_edit *edit)
{
  char			buff[100];
  struct termios	t;

  edit->y = 0;
  edit->status = 1;
  if (tgetent(buff, getenv("TERM")) != 1)
    {
      my_putstr("Error : scene_creator couldn't access terminal informations\n");
      return (ERROR);
    }
  if ((tcgetattr(0, &t)) == ERROR)
    return (ERROR);
  if ((edit->term_cl = tgetstr("cl", NULL)) == NULL)
    return (ERROR);
  if ((edit->term_cm = tgetstr("cm", NULL)) == NULL)
    return (ERROR);
  if ((edit->term_vi = tgetstr("vi", NULL)) == NULL)
    return (ERROR);
  if ((edit->term_ve = tgetstr("ve", NULL)) == NULL)
    return (ERROR);
  if (my_echo() == ERROR)
    return (ERROR);
  if (canon() == ERROR)
    return (ERROR);
  return (SUCCESS);
}

unsigned int		get_key(t_edit *edit)
{
  int			n;
  unsigned long		keycode;

  n = 1;
  if (my_putstr(edit->term_vi, 2) == NULL)
    edit->status = 0;
  /* display(file, edit, 98); */
  while (n != 0)
    {
      keycode = 0;
      if ((n = read(0, &keycode, sizeof(keycode))) == ERROR)
	edit->status = 0;
      if (keycode == EXIT)
	return (EXIT);
      else if (keycode == UP || keycode == DOWN)
	return (keycode);
    }
  return (ERROR);
}

int	init_creator()
{

  return (SUCCESS);
}

int		create(t_all *all, t_scene *scene)
{
  if (all->tab[1] == NULL)
    {
      my_putstr("Usage: create file.khey\n");
      return (ERROR);
    }
  if (init_creator() == ERROR)
    return (SUCCESS);
  return (SUCCESS);
}
