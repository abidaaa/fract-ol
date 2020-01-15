/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:24:04 by aabouibr          #+#    #+#             */
/*   Updated: 2018/12/07 15:32:15 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myglib/myglib.h"

void	mandelbrot(t_thread *t, int **col)
{
	t->row = -1;
	while (++t->row < HEIGHT)
	{
		t->col = -1;
		while (++t->col < WIDTH)
		{
			t->f.c_re = (double)t->col / (WIDTH / (t->f.c_re_max -
						t->f.c_re_min)) + t->f.c_re_min + t->f.horizontal;
			t->f.c_im = (double)t->row / (HEIGHT / (t->f.c_im_max -
						t->f.c_im_min)) + t->f.c_im_min + t->f.vertical;
			t->f.x = 0;
			t->f.y = 0;
			t->i = 0;
			while (t->f.x * t->f.x + t->f.y * t->f.y <= 4
					&& ++t->i < t->f.max_iter)
			{
				t->f.x_new = t->f.x * t->f.x - t->f.y * t->f.y + t->f.c_re;
				t->f.y = 2 * t->f.x * t->f.y + t->f.c_im;
				t->f.x = t->f.x_new;
			}
			if (t->i < t->f.max_iter)
				put_pxl_to_img(t, t->col, t->row, col[t->f.c][t->i % 16]);
		}
	}
}

void	julia(t_thread *t, int **col)
{
	t->row = -1;
	while (++t->row < HEIGHT)
	{
		t->col = -1;
		while (++t->col < WIDTH)
		{
			t->f.x = (double)t->col / (WIDTH / (t->f.c_re_max -
						t->f.c_re_min)) + t->f.c_re_min + t->f.horizontal;
			t->f.y = (double)t->row / (HEIGHT / (t->f.c_im_max -
						t->f.c_im_min)) + t->f.c_im_min + t->f.vertical;
			t->i = 0;
			while (t->f.x * t->f.x + t->f.y * t->f.y <= 4 &&
					t->i < t->f.max_iter)
			{
				t->f.x_new = t->f.x * t->f.x - t->f.y * t->f.y + t->f.juliax;
				t->f.y = 2 * t->f.x * t->f.y + t->f.juliay;
				t->f.x = t->f.x_new;
				t->i++;
			}
			if (t->i < t->f.max_iter)
				put_pxl_to_img(t, t->col, t->row, col[t->f.c][t->i % 16]);
		}
	}
}

void	burningship(t_thread *t, int **col)
{
	t->row = -1;
	while (++t->row < HEIGHT)
	{
		t->col = -1;
		while (++t->col < WIDTH)
		{
			t->f.c_re = (double)t->col / (WIDTH / (t->f.c_re_max -
						t->f.c_re_min)) + t->f.c_re_min + t->f.horizontal;
			t->f.c_im = (double)t->row / (HEIGHT / (t->f.c_im_max -
						t->f.c_im_min)) + t->f.c_im_min + t->f.vertical;
			t->f.x = 0;
			t->f.y = 0;
			t->i = 0;
			while (t->f.x * t->f.x + t->f.y * t->f.y <= 4 &&
					++t->i < t->f.max_iter)
			{
				t->f.x_new = t->f.x * t->f.x - t->f.y * t->f.y + t->f.c_re;
				t->f.y = fabs(t->f.x * t->f.y);
				t->f.y = t->f.y + t->f.y + t->f.c_im;
				t->f.x = t->f.x_new;
			}
			if (t->i < t->f.max_iter)
				put_pxl_to_img(t, t->col, t->row, col[t->f.c][t->i % 16]);
		}
	}
}

void	tricorn(t_thread *t, int **col)
{
	t->row = -1;
	while (++t->row < HEIGHT)
	{
		t->col = -1;
		while (++t->col < WIDTH)
		{
			t->f.c_re = (double)t->col / (WIDTH / (t->f.c_re_max -
						t->f.c_re_min)) + t->f.c_re_min + t->f.horizontal;
			t->f.c_im = (double)t->row / (HEIGHT / (t->f.c_im_max -
						t->f.c_im_min)) + t->f.c_im_min + t->f.vertical;
			t->f.x = 0;
			t->f.y = 0;
			t->i = 0;
			while (t->f.x * t->f.x + t->f.y * t->f.y <= 4
					&& ++t->i < t->f.max_iter)
			{
				t->f.x_new = t->f.x * t->f.x - t->f.y * t->f.y + t->f.c_re;
				t->f.y = -2 * t->f.x * t->f.y + t->f.c_im;
				t->f.x = t->f.x_new;
			}
			if (t->i < t->f.max_iter)
				put_pxl_to_img(t, t->col, t->row, col[t->f.c][t->i % 16]);
		}
	}
}

void	duobrot(t_thread *t, int **col)
{
	t->row = -1;
	while (++t->row < HEIGHT && (t->col = -1))
	{
		while (++t->col < WIDTH)
		{
			t->f.c_re = (double)t->col / (WIDTH / (t->f.c_re_max -
						t->f.c_re_min)) + t->f.c_re_min + t->f.horizontal;
			t->f.c_im = (double)t->row / (HEIGHT / (t->f.c_im_max -
						t->f.c_im_min)) + t->f.c_im_min + t->f.vertical;
			t->f.x = 0;
			t->f.y = 0;
			t->i = 0;
			while (t->f.x * t->f.x + t->f.y * t->f.y <= 4
					&& ++t->i < t->f.max_iter)
			{
				t->f.x_new = t->f.x * t->f.x * t->f.x - 3 * t->f.x *
					t->f.y * t->f.y + t->f.c_re;
				t->f.y = 3 * t->f.x * t->f.x * t->f.y - t->f.y *
					t->f.y * t->f.y + t->f.c_im;
				t->f.x = t->f.x_new;
			}
			if (t->i < t->f.max_iter)
				put_pxl_to_img(t, t->col, t->row, col[t->f.c][t->i % 16]);
		}
	}
}
