/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:15:34 by aabouibr          #+#    #+#             */
/*   Updated: 2018/12/07 14:57:19 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myglib/myglib.h"

static int	*blue_tab(int *color)
{
	color = (int *)malloc(sizeof(int) * 16);
	color[0] = rgb_to_int(66, 30, 15);
	color[1] = rgb_to_int(25, 7, 26);
	color[2] = rgb_to_int(9, 1, 47);
	color[3] = rgb_to_int(4, 4, 73);
	color[4] = rgb_to_int(0, 7, 100);
	color[5] = rgb_to_int(12, 44, 138);
	color[6] = rgb_to_int(24, 82, 177);
	color[7] = rgb_to_int(57, 125, 209);
	color[8] = rgb_to_int(134, 181, 229);
	color[9] = rgb_to_int(211, 236, 248);
	color[10] = rgb_to_int(241, 233, 191);
	color[11] = rgb_to_int(248, 201, 95);
	color[12] = rgb_to_int(255, 170, 0);
	color[13] = rgb_to_int(204, 128, 0);
	color[14] = rgb_to_int(153, 87, 0);
	color[15] = rgb_to_int(106, 52, 3);
	return (color);
}

static int	*random_tab(int *color)
{
	color = (int *)malloc(sizeof(int) * 16);
	color[0] = rgb_to_int(234, 163, 163);
	color[1] = rgb_to_int(52, 35, 43);
	color[2] = rgb_to_int(72, 42, 61);
	color[3] = rgb_to_int(111, 91, 109);
	color[4] = rgb_to_int(124, 90, 105);
	color[5] = rgb_to_int(173, 134, 157);
	color[6] = rgb_to_int(253, 219, 219);
	color[7] = rgb_to_int(255, 201, 201);
	color[8] = rgb_to_int(255, 177, 177);
	color[9] = rgb_to_int(251, 146, 146);
	color[10] = rgb_to_int(201, 128, 123);
	color[11] = rgb_to_int(198, 140, 140);
	color[12] = rgb_to_int(206, 160, 89);
	color[13] = rgb_to_int(187, 193, 168);
	color[14] = rgb_to_int(93, 96, 84);
	color[15] = rgb_to_int(159, 134, 134);
	return (color);
}

static int	*psychedelic_tab(int *color)
{
	color = (int *)malloc(sizeof(int) * 16);
	color[0] = rgb_to_int(229, 167, 175);
	color[1] = rgb_to_int(238, 186, 167);
	color[2] = rgb_to_int(242, 206, 160);
	color[3] = rgb_to_int(249, 226, 154);
	color[4] = rgb_to_int(255, 246, 143);
	color[5] = rgb_to_int(232, 208, 25);
	color[6] = rgb_to_int(4, 102, 46);
	color[7] = rgb_to_int(44, 137, 179);
	color[8] = rgb_to_int(51, 29, 89);
	color[9] = rgb_to_int(222, 40, 45);
	color[10] = rgb_to_int(253, 0, 255);
	color[11] = rgb_to_int(253, 255, 0);
	color[12] = rgb_to_int(0, 255, 56);
	color[13] = rgb_to_int(0, 249, 255);
	color[14] = rgb_to_int(60, 0, 255);
	color[15] = rgb_to_int(0, 255, 56);
	return (color);
}

static int	*bw_tab(int *color)
{
	color = (int *)malloc(sizeof(int) * 16);
	color[0] = rgb_to_int(255, 255, 255);
	color[1] = rgb_to_int(0, 0, 0);
	color[2] = rgb_to_int(255, 255, 255);
	color[3] = rgb_to_int(0, 0, 0);
	color[4] = rgb_to_int(255, 255, 255);
	color[5] = rgb_to_int(0, 0, 0);
	color[6] = rgb_to_int(255, 255, 255);
	color[7] = rgb_to_int(0, 0, 0);
	color[8] = rgb_to_int(255, 255, 255);
	color[9] = rgb_to_int(0, 0, 0);
	color[10] = rgb_to_int(255, 255, 255);
	color[11] = rgb_to_int(0, 0, 0);
	color[12] = rgb_to_int(255, 255, 255);
	color[13] = rgb_to_int(0, 0, 0);
	color[14] = rgb_to_int(255, 255, 255);
	color[15] = rgb_to_int(0, 0, 0);
	return (color);
}

int			**colortab(int **tab)
{
	tab = (int **)malloc(sizeof(int*) * 4);
	tab[0] = blue_tab(tab[0]);
	tab[1] = random_tab(tab[1]);
	tab[2] = psychedelic_tab(tab[2]);
	tab[3] = bw_tab(tab[3]);
	return (tab);
}
