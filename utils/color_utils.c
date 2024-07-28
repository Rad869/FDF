/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 05:11:10 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/28 05:52:16 by rrabeari         ###   ########.fr       */
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
	value = ((red << 16) | (green << 8) | blue) & 0xffffff;
	return (value);
}
/*
int	gradient_color(int col_dep, int col_arr, float percent)
{
	if (col_dep > 0)
		return (col_arr);
	return ((int) percent);
}*/