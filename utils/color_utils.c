/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 05:11:10 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/28 20:18:49 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_red(int color)
{
	int	value;

	value = (color >> 16) & 0xff;
	return (value);
}

int	get_green(int color)
{
	int	value;

	value = (color >> 8) & 0xff;
	return (value);
}

int	get_blue(int color)
{
	int	value;

	value = color & 0xff;
	return (value);
}

int	set_color(int red, int green, int blue)
{
	int	value;

	value = 0;
	value = (((red << 16) & 0xff0000) |\
		((green << 8) & 0x00ff00) |\
		(blue & 0x0000ff));
	return (value);
}

int	gradient_color(int col_dep, int col_arr, float percent)
{
	int	dif_red;
	int	dif_green;
	int	dif_blue;
	int	color;

	color = 0;
	dif_red = get_red(col_arr) - get_red(col_dep);
	dif_green = get_green(col_arr) - get_green(col_dep);
	dif_blue = get_blue(col_arr) - get_blue(col_dep);
	color = set_color(get_red(col_dep) + percent * dif_red, \
		get_green(col_dep) + percent * dif_green, \
		get_blue(col_dep) + percent * dif_blue);
	return (color);
}