/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 05:47:37 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/29 20:28:29 by rrabeari         ###   ########.fr       */
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
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

typedef struct s_fdf
{
	int		len_col;
	int		len_row;
	int		ecart;
	int		x_pos;
	int		y_pos;
	int		x_max;
	int		x_min;
	int		y_max;
	int		y_min;
	int		win_x;
	int		win_y;
	float	theta;
	float	phi;
	int		**z_matrix;
	int		**c_matrix;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_fdf;

typedef struct s_point
{
	float	x;
	float	y;
	int		z;
	int		color;
}				t_point;

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
int		gradient_color(int col_dep, int col_arr, float percent);
//-----------------------Math------------------------------------------------
float	max(float a, float b);
float	module(float var);
int		get_col(char *fname);
int		get_row(char *fname);
//-----------------------Transformation--------------------------------------
void	transform_origine(float *x, float *y, int *z, t_fdf *data);
void	transform_translation(float *x, float *y, t_fdf *data);
int		convert_hexa(char *s);
//---------------------------------------------------------------------------
t_fdf	*initialize_fdf(int argc, char *argv[]);
void	compute_origine(t_fdf *data);
void	transform_origine(float *x, float *y, int *z, t_fdf *data);
//------------------------Read entry------------------------------------------
void	read_entry(char	*fname, t_fdf *data);
int		convert_hexa(char *s);
//------------------------Draw------------------------------------------------
void	breseham(t_point depart, t_point arr, t_fdf *data);
void	isometric(float *x, float *y, int z, t_fdf *data);
void	draw(t_fdf *data);
//------------------------Error check------------------------------------------
void	p_error(char *title, char *err);
void	check_maps(int argc, char *argv[]);
void	check_char_entry(int fd);
void	check_empty(char *fname);
//------------------------Tabular utils----------------------------------------
int		d_tab_len(char **argv);
void	tab_free(char **args);

#endif
