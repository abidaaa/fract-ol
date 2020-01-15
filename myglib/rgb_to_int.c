/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 19:47:46 by aabouibr          #+#    #+#             */
/*   Updated: 2018/12/07 15:44:37 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myglib.h"

int	rgb_to_int(int r, int g, int b)
{
	char	*result;

	result = (char *)malloc(4);
	result[3] = 0;
	result[2] = r;
	result[1] = g;
	result[0] = b;
	return (*((int *)result));
}
