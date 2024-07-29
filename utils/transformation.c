/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 10:55:10 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/29 11:13:44 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	transform_origine(float *x, float *y, int *z, t_fdf *data)
{
	compute_origine(data);
	*z *= data->ecart;
	*x *= data->ecart;
	*y *= data->ecart;
	isometric(x, y, *z, data);
}

void	transform_translation(float *x, float *y, t_fdf *data)
{
	*x += data->x_pos;
	*y += data->y_pos;
}

int	convert_hexa(char *s)
{
	int	value;
	int	i;
	int	tmp;

	value = 0;
	tmp = 0;
	i = ft_strlen(s) * 4 - 4;
	if (ft_strchr(s, '\n'))
		i -= 4;
	while (i >= 0)
	{
		if (*s <= 'F' && *s >= 'A')
			tmp = *s - 'A' + 10;
		else if (*s <= 'f' && *s >= 'a')
			tmp = *s - 'a' + 10;
		else if (*s >= '0' && *s <= '9')
			tmp = *s - '0';
		else
			p_error("Color error", "You entered an error format of color");
		value += (tmp << i);
		s++;
		i -= 4;
	}
	return (value);
}
