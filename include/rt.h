/*
** rt.h for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sat Jun  6 15:33:47 2015 david sebaoun
** Last update Sat Jun  6 15:56:56 2015 Jules Vautier
*/


#ifndef RT_H_
# define RT_H_

# include <unistd.h>
# include </usr/include/mlx.h>
# include <X11/X.h>
# include <stdlib.h>
# include <math.h>
# include "struct.h"

# define SPLASHSCREEN_X	1920
# define SPLASHSCREEN_Y	1080
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
# define MAXCOLOR(c)	(((c) >= 255) ? (254) : (c))
# define TODEGREE(a)	((180) * (a) / (PI))
# define TORADIAN(a)	((a) * (PI) / 180.0)

int	command_line(t_all *);
char	*mlx_get_data_addr(void *, int *, int *, int *);
int	my_load(t_all *);
int	shadow(t_all *, t_light *, t_scene *);
int	gere_expose(t_all *);
int	gere_key(int, void *);
int	check_error(t_img *);
int	init_calc(t_all *);
int	calc_vec(t_light *, t_object *);
int	calc_point_eye(t_light *, int);
int	calc_point_lum(t_light *, t_light *, t_object *, double);
int	find_point(t_light *, t_coor *, double);
int	init_rotate(t_object **);
int	do_k(t_all *, t_object **);
int	raytrace(t_all *, t_scene *);
int	prepare_intensity(t_all *, t_light *, t_object *, t_scene *);
int	rotate(t_light *, t_coor , int);
void	my_loading(int, int);
int	creat_pixel(t_all *, t_scene *);
double	inter_sphere(t_all *, t_light *, t_object *);
double	inter_plan(t_all *, t_light *, t_object *);
double	inter_cone(t_all *, t_light *, t_object *);
double	inter_cylinder(t_all *, t_light *, t_object *);
double	inter_disc(t_all *, t_light *, t_object *);
int	intensity_main(t_all *, t_light **, t_object *, int);
int	intensity_plan(t_all *, t_light *, t_object *, t_light);
int	intensity_sphere(t_all *, t_light *, t_object *, t_light);
int	intensity_cone(t_all *, t_light *, t_object *, t_light);
int	intensity_cylinder(t_all *, t_light *, t_object *, t_light);
int	intensity_disque(t_all *, t_light *, t_object *, t_light);
double	do_inten(t_light *, t_light *);
int	init_obj_un(t_all *);
int	init_obj_deux(t_all *);
int	init_obj_trois(t_all *);
int	init_obj_quatre(t_all *);
int	init_eye(t_all *);
int	init_lum(t_all *);
int	gere_flag(t_flags *, int, char **);
int	gere_key_eye(int, t_all *);
int	gere_key_sphe(int, t_all *);
int	gere_key_obj(int, t_all *);
int	gere_key_plan(int, t_all *);
int	gere_key_lum(int, t_all *);
int	splash_screen();

#endif /* !RT_H_ */
