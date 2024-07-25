/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <rrabeari@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 07:42:28 by rrabeari          #+#    #+#             */
/*   Updated: 2024/07/24 06:17:12 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int d_tab_len(char  **argv)
{
    int i;

    i = 0;
    while (argv[i])
    {
        i++;
    }
    return (i);
}

void    tab_free(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        free(args[i]);
        args[i] = NULL;
        i++;
    }
    free(args);
    args = NULL;
}