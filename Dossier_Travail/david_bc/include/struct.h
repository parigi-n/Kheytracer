/*
** struct.h for raytracer in /home/sebaou_d/rendu/MUL_2014_rtracer
** 
** Made by david sebaoun
** Login   <sebaou_d@epitech.net>
** 
** Started on  Sat Jun  6 17:46:45 2015 david sebaoun
** Last update Sat Jun  6 17:50:12 2015 david sebaoun
*/

#ifndef STRUCT_H_
# define STRUCT_H_

/* typedef struct		s_img */
/* { */
/*   void			*mlx_ptr; */
/*   void			*win_ptr; */
/*   void			*img_ptr; */
/*   void			*inter_ptr; */
/*   char			*data; */
/*   int			bpp; */
/*   int			sizeline; */
/*   int			endian; */
/*   int			lenght; */
/*   int			x_xpm; */
/*   int			y_xpm; */
/* }			t_img; */

/* typedef struct		s_coor */
/* { */
/*   double		x; */
/*   double		y; */
/*   double		z; */
/* }			t_coor; */

/* typedef	struct		s_object */
/* { */
/*   char			*name; */
/*   char			type; */
/*   t_coor		a; */
/*   t_coor		pos; */
/*   int			r; */
/*   double		lim; */
/*   int			color; */
/*   struct s_object	*next; */
/* }			t_object; */

/* typedef struct		s_light */
/* { */
/*   char			*name; */
/*   t_coor		pos; */
/*   t_coor		v; */
/*   t_coor		a; */
/*   t_coor		tmp; */
/*   t_coor		new; */
/*   int			color; */
/*   struct s_light       	*next; */
/* }			t_light; */

/* typedef struct		s_calcul */
/* { */
/*   t_coor		tmp; */
/*   t_coor		pos; */
/*   double		k; */
/*   double		tmpk; */
/*   t_object		*save; */
/*   double		prea; */
/* }			t_calcul; */

/* typedef	struct		s_scene */
/* { */
/*   char			*name; */
/*   t_object		*obj; */
/*   t_light		*light; */
/*   t_light		eye; */
/*   t_coor		pos; */
/*   t_coor		a; */
/*   int			nb_obj; */
/*   int			nb_light; */
/*   int			last_line; */
/* }			t_scene; */

/* typedef struct		s_flags */
/* { */
/*   int			rotate; */
/*   int			intensity; */
/*   int			shadow; */
/* }			t_flags; */

/* typedef struct		s_all */
/* { */
/*   int			loaded; */
/*   char			**tab; */
/*   t_object		*object; */
/*   t_light		*lum; */
/*   t_coor		point; */
/*   t_object		*obj; */
/*   t_light		eye; */
/*   t_img			var; */
/*   t_calcul		calc; */
/*   int			pixel_nb; */
/*   t_flags		flag; */
/* }			t_all; */

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

typedef struct		s_tri
{
  t_coor		tr1;
  t_coor		tr2;
  t_coor		tr3;
}			t_tri;

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
  struct s_light	*next;
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

typedef struct		s_edit
{
  char			*term_cl;
  char			*term_cm;
  char			*term_ve;
  char			*term_vi;
  int			i;
  int			x;
  int			y;
  int			z;
  int			status;
}			t_edit;

typedef struct		s_fonct
{
  double		(*ptr)(t_all *, t_light *, t_object *);
  int			type;
}			t_fonct;

typedef struct		s_finten
{
  int			(*ptr)(t_all *, t_light *,
			       t_object *, t_light);
  int			type;
}			t_finten;

typedef struct		s_obj_type
{
  char			*name;
  int			type;
}			t_obj_type;

#endif /* !STRUCT_H_ */
