/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myglib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:03:42 by aabouibr          #+#    #+#             */
/*   Updated: 2018/12/07 17:25:44 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYGLIB_H
# define MYGLIB_H
# define WIDTH 1024
# define HEIGHT 768
# include "../libft/libft.h"
# include <math.h>
# include <pthread.h>

typedef struct	s_params
{
	void		*window;
	void		*mlx_con;
	void		*img_ptr;
	char		*img_data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_params;

typedef struct	s_fractal
{
	double		c_re;
	double		c_im;
	double		x;
	double		y;
	double		x_new;
	double		off;
	double		c_re_min;
	double		c_re_max;
	double		c_im_min;
	double		c_im_max;
	double		z;
	int			c;
	double		horizontal;
	double		vertical;
	double		juliax;
	double		juliay;
	int			max_iter;
	int			sier_iter;
	int			fractal;
}				t_fractal;

typedef struct	s_thread
{
	t_params	*p;
	t_fractal	f;
	double		mouse_re;
	double		mouse_im;
	int			check;
	int			row;
	int			col;
	int			i;
}				t_thread;

int				rgb_to_int(int r, int g, int b);
void			init(t_params *p, char *window_title);
int				**colortab(int **tab);
void			init_fractol(t_thread *t);
int				mouse_hook(int key, int x, int y, void *param);
int				key_hook(int key, void *params);
int				mouse_move(int x, int y, void *param);
void			*draw(void *toto);
void			duobrot(t_thread *t, int **color);
void			tricorn(t_thread *t, int **color);
void			burningship(t_thread *t, int **color);
void			julia(t_thread *t, int **color);
void			mandelbrot(t_thread *t, int **color);
void			put_pxl_to_img(t_thread *t, int x, int y, int color);
void			zoom(t_thread *t);
int				error(int nb, char *str);
#endif
