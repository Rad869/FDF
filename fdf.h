/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 05:47:37 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/27 15:16:45 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define CRESET "\e[0m"
# define RED "\e[0;31m"
# define BLU "\e[0;34m"
# define BRED "\e[1;31m"
# define PI 3.14159265
# include <math.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct	s_fdf
{
	int		len_col;
	int		len_row;
	int		ecart;
	int		x_pos;
	int		y_pos;
	int		x_max;
	int		y_max;
	int		win_x;
	int		win_y;
	float	theta;
	float	phi;
	int		**z_matrix;
	int		**c_matrix;
	void	*mlx;
	void	*win;
}				t_fdf;

t_fdf	*initialize_fdf(int argc, char *argv[]);
void	compute_origine(t_fdf *data);
//------------------------Read entry------------------------------------------
void	read_entry(char	*fname, t_fdf *data);
int		convert_hexa(char *s);
//------------------------Draw------------------------------------------------
void	breseham(float x, float y, float x1, float y1, t_fdf *data);
void	isometric(float *x, float *y, int z, t_fdf *data);
void	draw(t_fdf *data);
//------------------------Error check------------------------------------------
void	p_error(char *title, char *err);
void	check_maps(int argc, char *argv[]);
//------------------------Tabular utils----------------------------------------
int 	d_tab_len(char  **argv);
void    tab_free(char **args);

#endif