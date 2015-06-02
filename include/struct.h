/*
** igraph.h for igraph in /home/vautie_a/rendu/MUL_2014_fdf
** 
** Made by Jules Vautier
** Login   <vautie_a@epitech.net>
** 
** Started on  Mon Dec  1 15:28:21 2014 Jules Vautier
** Last update Tue Jun  2 15:31:45 2015 david sebaoun
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
}			t_img;

typedef struct		s_coor
{
  double		x;
  double		y;
  double		z;
}			t_coor;

typedef struct		s_calcul
{
  t_coor		tmp;
  t_coor		pos;
  double		k;
  double		tmpk;
  double		prea;
}			t_calcul;

typedef struct		s_vec
{
  char			*name;
  t_coor		pos;
  t_coor		v;
  t_coor		a;
  t_coor		tmp;
  t_coor		new;
  int			color;
  struct s_vec		*next;
}			t_vec;

typedef	struct		s_object
{
  char			*name;
  int			type;
  t_coor		a;
  t_coor		pos;
  double		r;
  double		lim;
  int			color;
  struct s_object	*next;
}			t_object;

typedef struct		s_flags
{
  int			rotate;
  int			intensity;
  int			shadow;
}			t_flags;

typedef struct		s_all
{
  int			kill;
  char			**tab;
  t_object		*object;
  t_vec			*lum;
  t_coor		point;
  t_object		*obj;
  t_vec			eye;
  t_img			var;
  t_calcul		calc;
  int			pixel_nb;
  t_flags		flag;
}			t_all;

typedef struct		s_fonct
{
  double		(*ptr)(t_all *all, t_vec *vec, t_object *coor);
  int			type;
}			t_fonct;

#endif /* !STRUCT_H_ */
