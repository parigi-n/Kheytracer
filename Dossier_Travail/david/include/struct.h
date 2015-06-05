/*
** igraph.h for igraph in /home/vautie_a/rendu/MUL_2014_fdf
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Dec  1 15:28:21 2014 Jules Vautier
** Last update Fri Jun  5 17:41:23 2015 Jules Vautier
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct		s_img
{
  void			*mlx_ptr;
  void			*win_ptr;
  void			*img_ptr;
  void			*inter_ptr;
  char			*data;
  int			bpp;
  int			sizeline;
  int			endian;
  int			lenght;
  int			x_xpm;
  int			y_xpm;
}			t_img;

typedef struct		s_coor
{
  double		x;
  double		y;
  double		z;
}			t_coor;

typedef	struct		s_object
{
  char			*name;
  int			type;
  t_coor		a;
  t_coor		pos;
  int			r;
  double		lim;
  int			color;
  struct s_object	*next;
}			t_object;

typedef struct		s_light
{
  char			*name;
  t_coor		pos;
  t_coor		v;
  t_coor		a;
  t_coor		tmp;
  t_coor		new;
  int			color;
  struct s_light		*next;
}			t_light;

typedef struct		s_calcul
{
  t_coor		tmp;
  t_coor		pos;
  double		k;
  double		tmpk;
  t_object		*save;
  double		prea;
}			t_calcul;

typedef	struct		s_scene
{
  char			*name;
  t_object		*obj;
  t_light		*light;
  t_light		eye;
  t_coor		pos;
  t_coor		a;
  int			nb_obj;
  int			nb_light;
  int			last_line;
}			t_scene;

typedef struct		s_flags
{
  int			rotate;
  int			intensity;
  int			shadow;
}			t_flags;

typedef struct		s_all
{
  int			loaded;
  char			**tab;
  t_object		*object;
  t_light		*lum;
  t_coor		point;
  t_object		*obj;
  t_light		eye;
  t_img			var;
  t_calcul		calc;
  int			pixel_nb;
  t_flags		flag;
}			t_all;

typedef struct		s_fonct
{
  int			(*ptr)(t_all *all, t_light *vec, t_object *coor);
  int			type;
}			t_fonct;

#endif /* !STRUCT_H_ */
