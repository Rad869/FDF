/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:55:10 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/25 22:19:16 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
/*
*	Print the error and stop the program
*	title : Title of the error
*		Ex: Error : number of args too small
			Please make the args just one
*/
void	p_error(char *title, char *err)
{
	ft_printf(BRED"ERROR :"RED" %s\n"CRESET, title);
	ft_printf("%s\n\n"CRESET, err);
	exit(EXIT_FAILURE);
}
