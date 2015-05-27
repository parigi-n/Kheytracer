/*
** intensity_main.c for intensity_main in /home/vautie_a/rendu/MUL_2014_rtv1/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Mar  5 09:35:28 2015 Jules Vautier
** Last update Tue May 26 11:29:51 2015 Jules Vautier
*/

#include "struct.h"
#include "rtv1.h"

static const	t_fonct g_fonct[] =
  {
    {&intensity_sphere, TYPE_SPHERE},
    {&intensity_cone, TYPE_CONE},
    {&intensity_cylinder, TYPE_CYLINDER},
    {&intensity_plan, TYPE_PLAN},
    {NULL, -1}
  };

double		do_inten(t_vec *vec1, t_vec *vec2)
{
  double	inten;
  double	norm;
  double	scal;

  norm = (sqrt(vec1->v.x * vec1->v.x + vec1->v.y * vec1->v.y
               + vec1->v.z * vec1->v.z) *
	  sqrt(vec2->v.x * vec2->v.x
	       + vec2->v.y * vec2->v.y +
	       vec2->v.z * vec2->v.z));
  scal = (vec1->v.x * vec2->v.x + vec1->v.y * vec2->v.y
	  + vec1->v.z * vec2->v.z);
  inten = (scal / norm);
  return (inten);
}

int	intensity_main(t_all *all, int obj_nb, int inte)
{
  int	intesphe;

  if (obj_nb < NB_OBJ - 1)
    {
      calc_point_eye(&all->eye, all->pixel_nb);
      calc_vec(&all->eye, &all->object[obj_nb]);
      if (all->flag.rotate == 1)
	{
	  rotate(&all->eye, &all->object[obj_nb], -1);
	  rotate(&all->eye, &all->object[NB_OBJ], 1);
	}
      calc_point_lum(all, &all->object[obj_nb], &all->lum);
      /*intesphe = g_fonct[tmp->type].ptr(all, &all->lum, &all->object[obj_nb]);*/
      inte = inte * intesphe / 1000;
    }
  else
    inte = 0;
  if (inte < 0)
    inte = 0;
  return (inte);
}
