/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:56:18 by aabouibr          #+#    #+#             */
/*   Updated: 2018/12/07 17:59:56 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myglib/myglib.h"

void	init_fractol(t_thread *t)
{
	t->f.z = 1;
	t->f.c = 0;
	t->f.horizontal = 0.0;
	t->f.vertical = 0.0;
	t->f.c_re_min = (0 - WIDTH / 2.0) * 4.0 / WIDTH;
	t->f.c_im_min = (0 - HEIGHT / 2.0) * 4.0 / WIDTH;
	t->f.c_re_max = (WIDTH - WIDTH / 2.0) * 4.0 / WIDTH;
	t->f.c_im_max = (HEIGHT - HEIGHT / 2.0) * 4.0 / WIDTH;
	t->f.off = 0.1;
	t->f.sier_iter = 1000000;
	t->f.max_iter = 100;
	t->check = 0;
}

int		error(int nb, char *str)
{
	if (nb != 2)
	{
		ft_putstr("usage:  ./fractol [mandelbrot]\n        ./fractol [julia]\n \
	./fractol [burningship]\n        ./fractol [tricorn]\n \
	./fractol [duobrot]\n");
		return (1);
	}
	else if (ft_strcmp(str, "mandelbrot") != 0
			&& ft_strcmp(str, "julia") != 0
			&& ft_strcmp(str, "burningship") != 0
			&& ft_strcmp(str, "tricorn") != 0
			&& ft_strcmp(str, "duobrot") != 0)
	{
		ft_putstr("usage:  ./fractol [mandelbrot]\n        ./fractol [julia]\n \
	./fractol [burningship]\n        ./fractol [tricorn]\n \
	./fractol [duobrot]\n");
		return (1);
	}
	return (0);
}

void	menu(void)
{
	ft_putstr("\e[35m########### MENU ########\e[39m\n");
	ft_putstr("\e[92mMOUSE WHEEL TO ZOOM\n");
	ft_putstr("UP DOWN RIGHT LEFT = offset\n");
	ft_putstr("SHIFT = switch fractal\n");
	ft_putstr("c = color\n");
	ft_putstr("i = initialize\n");
	ft_putstr("ESC = quit program\n");
	ft_putstr("+ = zoom up\n");
	ft_putstr("- = zoom down\n");
	ft_putstr("for julia :\n");
	ft_putstr("right button to unlock the julia set\n");
	ft_putstr("left button to fix the julia set\n");
	ft_putstr("moving mouse allows you to evolve the julia set\n");
	ft_putstr("\e[35m#########################\e[39m\n");
}

int		main(int argc, char **argv)
{
	t_thread t;
	t_params p;

	if (error(argc, argv[1]) == 1)
		return (0);
	menu();
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		t.f.fractal = 0;
	else if (ft_strcmp(argv[1], "julia") == 0)
		t.f.fractal = 1;
	else if (ft_strcmp(argv[1], "burningship") == 0)
		t.f.fractal = 2;
	else if (ft_strcmp(argv[1], "tricorn") == 0)
		t.f.fractal = 3;
	else if (ft_strcmp(argv[1], "duobrot") == 0)
		t.f.fractal = 4;
	init(&p, argv[1]);
	t.p = &p;
	init_fractol(&t);
	draw(&t);
	mlx_key_hook(t.p->window, key_hook, (void *)&t);
	mlx_mouse_hook(t.p->window, mouse_hook, (void *)&t);
	mlx_hook(t.p->window, 6, 0, mouse_move, (void *)&t);
	mlx_loop(t.p->mlx_con);
	return (0);
}
