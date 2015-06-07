/*
** intensity_main.c for intensity_main in /home/vautie_a/rendu/MUL_2014_rtv1/rtv1_src
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Thu Mar  5 09:35:28 2015 Jules Vautier
<<<<<<< HEAD
<<<<<<< HEAD
** Last update Sun Jun  7 16:43:11 2015 Jules Vautier
=======
** Last update Sun Jun  7 16:27:09 2015 Oscar Nosworthy
>>>>>>> 5da8d75c10bc34ba9e58f99d732e5a3075bb1bc4
*/

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

  calc_light(all->point, lum, obj);
  tmp = g_fonct[obj->type].ptr(all, lum, obj, scene->eye);
  intensity = (int)tmp;
  intensity = intensity / scene->nb_light;
  return (intensity);
}
