/*
** intensity_main.c for inten in /home/vautie_a/rendu/MUL_2014_rtracer/src/raytracer
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Sun Jun  7 23:21:11 2015 Jules Vautier
** Last update Sun Jun  7 23:21:12 2015 Jules Vautier
*/

#include "rt.h"

static const	t_fonct g_fonct[] =
  {
    {&intensity_sphere, TYPE_SPHERE},
    {&intensity_cone, TYPE_CONE},
    {&intensity_cylinder, TYPE_CYLINDER},
    {&intensity_plan, TYPE_PLAN},
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

double		prepare_intensity(t_all *all, t_light *lum,
				  t_object *obj, t_scene *scene)
{
  double	intensity;

  (void)scene;
  calc_light(all->point, lum, obj);
  intensity = g_fonct[obj->type].ptr(all, lum, obj);
  intensity = intensity / scene->nb_light;
  return (intensity);
}
