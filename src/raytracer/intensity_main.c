/*
** intensity_main.c for intensity_main in /home/vautie_a/rendu/MUL_2014_rtv1/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Mar  5 09:35:28 2015 Jules Vautier
<<<<<<< HEAD
** Last update Wed May 27 10:04:47 2015 Jules Vautier
*/

#include "struct.h"
#include "rtv1.h"
#include <stdio.h>
=======
** Last update Tue May 26 19:14:05 2015 david sebaoun
*/

#include "struct.h"
#include "rt.h"
>>>>>>> 7b4f8b46492ef0dc1a0dac4d9277e1b011142ae6

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
  norm = norm + 0.000001;
  inten = (scal / norm);
  return (inten);
}

int		intensity_main(t_all *all,
			       t_object *obj_nb, int inte)
{
  int		intesphe;

  if (obj_nb != NULL)
    {
      calc_point_eye(&all->eye, all->pixel_nb);
      calc_vec(&all->eye, obj_nb);
	/*if (all->flag.rotate == 1)
	{
	  rotate(&all->eye, &all->object[obj_nb], -1);
	  rotate(&all->eye, &all->object[NB_OBJ], 1);
	  }*/
      calc_point_lum(&all->eye, &all->lum, obj_nb, all->calc.k);
      intesphe = g_fonct[obj_nb->type].ptr(all, &all->lum, obj_nb);
      inte = inte * intesphe / 1000;
    }
  else
    inte = 0;
  if (inte < 0)
    inte = 0;
  return (inte);
}
