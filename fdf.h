/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 05:47:37 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/25 11:05:40 by rrabeari         ###   ########.fr       */
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
	int		**z_matrix;
	void	*mlx;
	void	*win;
}				t_fdf;

//------------------------Read entry------------------------------------------
void	read_entry(char	*fname, t_fdf *data);
//------------------------Draw------------------------------------------------
void	breseham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);
//------------------------Error check------------------------------------------
void	p_error(char *title, char *err);
void	check_maps(int argc, char *argv[]);
//------------------------Tabular utils----------------------------------------
int 	d_tab_len(char  **argv);
void    tab_free(char **args);

#endif