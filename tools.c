/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 22:51:56 by aabouibr          #+#    #+#             */
/*   Updated: 2018/12/07 15:40:34 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myglib/myglib.h"

void	zoom(t_thread *t)
{
	t->f.c_re_min = ((t->f.z * (t->f.c_re_min - t->mouse_re)) + t->mouse_re);
	t->f.c_re_max = ((t->f.z * (t->f.c_re_max - t->mouse_re)) + t->mouse_re);
	t->f.c_im_min = ((t->f.z * (t->f.c_im_min - t->mouse_im)) + t->mouse_im);
	t->f.c_im_max = ((t->f.z * (t->f.c_im_max - t->mouse_im)) + t->mouse_im);
}

void	put_pxl_to_img(t_thread *t, int x, int y, int color)
{
	ft_memcpy(t->p->img_data + 4 * WIDTH * y + x * 4, &color, sizeof(int));
}

void	*draw(void *toto)
{
	int			**color;
	t_thread	*t;

	color = NULL;
	color = colortab(color);
	t = toto;
	mlx_destroy_image(t->p->mlx_con, t->p->img_ptr);
	t->p->img_ptr = mlx_new_image(t->p->mlx_con, WIDTH, HEIGHT);
	t->p->img_data = mlx_get_data_addr(t->p->img_ptr, &(t->p->bpp)
			, &(t->p->size_line), &(t->p->endian));
	mlx_clear_window(t->p->mlx_con, t->p->window);
	if (t->f.fractal > 4)
		t->f.fractal = 0;
	if (t->f.fractal == 0)
		mandelbrot(t, color);
	if (t->f.fractal == 1)
		julia(t, color);
	if (t->f.fractal == 2)
		burningship(t, color);
	if (t->f.fractal == 3)
		tricorn(t, color);
	if (t->f.fractal == 4)
		duobrot(t, color);
	mlx_put_image_to_window(t->p->mlx_con, t->p->window, t->p->img_ptr, 0, 0);
	return (NULL);
}
