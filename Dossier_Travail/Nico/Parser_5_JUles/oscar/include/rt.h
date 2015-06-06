/*
** rt.h for raytracer in /home/sebaou_d/MUL_2014_rtracer/include
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
<<<<<<< HEAD:include/rtv1.h
** Started on  Mon Dec  1 15:28:21 2014 Jules Vautier
** Last update Sat Jun  6 11:29:37 2015 Oscar Nosworthy
=======
** Started on  Tue May 26 19:10:52 2015 david sebaoun
** Last update Tue May 26 19:11:03 2015 david sebaoun
>>>>>>> 7b4f8b46492ef0dc1a0dac4d9277e1b011142ae6:include/rt.h
*/


#ifndef RT_H_
# define RT_H_

# include <unistd.h>
# include </usr/include/mlx.h>
# include <X11/X.h>
# include <stdlib.h>
# include <math.h>
#include "struct.h"

# define NB_OBJ		5
# define SIZE_LARG	640
# define SIZE_LONG	480
# define SIZE_IMG       SIZE_LONG * SIZE_LARG * 4
# define D		100
# define PI		3.14
# define RAD		1.57
# define TYPE_SPHERE	0
# define TYPE_CONE	1
# define TYPE_CYLINDER	2
# define TYPE_PLAN	3
# define TYPE_DISC	4
# define TYPE_HYPER	5
# define TYPE_TRIANGLE	6
# define MAXCOLOR(c)	(((c) >= 255) ? (254) : (c))
# define TODEGREE(a)	((180) * (a) / (PI))
# define TORADIAN(a)	((a) * (PI) / 180.0)

int	command_line(t_all *);
char	*mlx_get_data_addr(void *, int *, int *, int *);
int	my_load(t_all *);
int	shadow(t_all *, double, t_vec *, t_object *);
int	gere_expose(t_all *all);
int	gere_key(int, void *);
int	check_error(t_img *var);
int	init_calc(t_all *all);
int	calc_vec(t_vec *, t_object *);
int	calc_point_eye(t_vec *, int);
int	calc_point_lum(t_vec *, t_vec *, t_object *, double);
int	do_k(t_all *, t_object **);
int	raytrace(t_all *);
t_coor  crossProduct(t_coor point1, t_coor point2);
double  dotProduct(t_coor point1, t_coor point2);
t_coor	minus(t_coor point1, t_coor point2);
int	inter_triangle(t_all *all, t_vec *vec, t_object *obj);
int	inter_hyper(t_all *all, t_vec *vec, t_object *obj);
int     inter_disc(t_all *all, t_vec *vec, t_object *obj);
int	inter_sphere(t_all *, t_vec *, t_object *);
int	inter_plan(t_all *, t_vec *, t_object *);
int	inter_cone(t_all *, t_vec *, t_object *);
int	inter_cylinder(t_all *, t_vec *, t_object *);
int	inter_disque(t_all *, t_vec *, t_object *);
int	intensity_main(t_all *, t_vec **, t_object *, int);
int	intensity_plan(t_all *, t_vec *, t_object *);
int	intensity_sphere(t_all *, t_vec *, t_object *);
int	intensity_cone(t_all *, t_vec *, t_object *);
int	intensity_cylinder(t_all *, t_vec *, t_object *);
int	intensity_disque(t_all *, t_vec *, t_object *);
double	do_inten(t_vec *, t_vec *);
int	init_obj_un(t_all *all);
int	init_obj_deux(t_all *all);
int	init_obj_trois(t_all *all);
int	init_obj_quatre(t_all *all);
int	init_eye(t_all *all);
int	init_lum(t_all *all);
int	gere_flag(t_flags *, int, char **);
int	gere_key_eye(int, t_all *);
int	gere_key_obj(int, t_all *);
int	gere_key_plan(int, t_all *);
int	gere_key_lum(int, t_all *);
int	find_point(t_vec *, t_coor *, double);
int	init_rotate(t_all *);
int	rotate(t_vec *, t_object *, int);
void	my_loading(int current, int total);

#endif /* !RT_H_ */