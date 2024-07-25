/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 07:39:04 by rrabeari          #+#    #+#             */
/*   Updated: 2024/03/10 08:10:55 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*par;

	i = 1;
	if (!lst)
		return (0);
	par = lst;
	while (par->next != NULL)
	{
		i++;
		par = par->next;
	}
	return (i);
}
