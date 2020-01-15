/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:49:13 by aabouibr          #+#    #+#             */
/*   Updated: 2018/12/07 15:05:49 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myglib/myglib.h"

int			mouse_move(int x, int y, void *param)
{
	t_thread	*t;
	double		width;
	double		height;
	pthread_t	thread;

	t = (t_thread *)param;
	if (t->check == 0)
		return (0);
	else
	{
		width = (double)WIDTH;
		height = (double)HEIGHT;
		t->f.juliay = (x == 0) ? 0 : x / width + 0.1;
		t->f.sier_iter = (x == 0) ? 0 : 1000000 / x;
		t->f.juliax = (y == 0) ? 0 : -y / height + 0.1;
		t->f.sier_iter = (y == 0) ? 0 : 1000000 / y;
		pthread_create(&thread, NULL, draw, t);
		pthread_join(thread, NULL);
	}
	return (0);
}

static void	switch_init(int key, t_thread *t)
{
	if (key == 34)
		init_fractol(t);
	if (key == 258)
	{
		if (t->f.fractal > 4)
			t->f.fractal = 0;
		else
		{
			t->f.fractal++;
			init_fractol(t);
		}
	}
}

int			key_hook(int key, void *params)
{
	t_thread	*t;
	pthread_t	thread;

	t = (t_thread *)params;
	if (key == 124 || key == 123)
		t->f.horizontal += (key == 124) ? t->f.off : -t->f.off;
	else if (key == 126 || key == 125)
		t->f.vertical += (key == 126) ? -t->f.off : t->f.off;
	else if (key == 78 || key == 69)
	{
		t->f.z = (key == 78) ? 1.1 : 1 / 1.1;
		zoom(t);
	}
	if (key == 53)
		exit(0);
	if (key == 8)
		t->f.c = (t->f.c == 3) ? 0 : t->f.c + 1;
	else if (key == 116 || key == 121)
		t->f.max_iter += (key == 116) ? 10 : -10;
	if (t->f.max_iter < 10)
		t->f.max_iter = 10;
	switch_init(key, t);
	pthread_create(&thread, NULL, draw, t);
	pthread_join(thread, NULL);
	return (0);
}

int			mouse_hook(int key, int x, int y, void *param)
{
	t_thread	*t;
	pthread_t	thread;

	t = (t_thread *)param;
	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		t->mouse_re = ((double)x / (WIDTH / (t->f.c_re_max - t->f.c_re_min))
				+ t->f.c_re_min);
		t->mouse_im = ((double)y / (HEIGHT / (t->f.c_im_max - t->f.c_im_min))
				+ t->f.c_im_min);
	}
	if (key == 4 || key == 5)
	{
		t->f.z = (key == 4) ? 1.1 : 1 / 1.1;
		zoom(t);
	}
	if (key == 2)
		t->check = 1;
	if (key == 1)
		t->check = 0;
	pthread_create(&thread, NULL, draw, t);
	pthread_join(thread, NULL);
	return (0);
}
