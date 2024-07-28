/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 21:28:19 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/28 05:04:35 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	module(float var)
{
	if (var < 0)
		return (-var);
	return (var);
}
