/*
** intensity_main.c for intensity_main in /home/vautie_a/rendu/MUL_2014_rtv1/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Mar  5 09:35:28 2015 Jules Vautier
<<<<<<< HEAD
** Last update Sun Jun  7 09:06:25 2015 Jules Vautier
*/

#include <stdio.h>
#include "rt.h"

static const	t_finten g_fonct[] =
  {
    {&intensity_sphere, TYPE_SPHERE},
    {&intensity_cone, TYPE_CONE},
    {&intensity_cylinder, TYPE_CYLINDER},
    {&intensity_plan, TYPE_PLAN},
    {&intensity_plan, TYPE_DISC},
    {NULL, -1}
  };

double		do_inten(t_light *vec1, t_light *vec2)
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

int		prepare_intensity(t_all *all, t_light *lum,
				  t_object *obj, t_scene *scene)
{
  int		intensity;
  double	tmp;

  /*calc_point_eye(&scene->eye, all->pixel_nb);
    calc_vec(&scene->eye, obj);*/
  calc_light(all->point, lum, obj);
  /*if (all->flag.rotate == 1)
    {
      rotate(lum, scene->eye.a, 1);
      rotate(lum, obj->a, 1);
    }*/
  tmp = g_fonct[obj->type].ptr(all, lum, obj, scene->eye);
  intensity = (int)tmp;
  /*intensity = 1000;*/
  printf("%i\n", intensity);
  return (intensity);
}
