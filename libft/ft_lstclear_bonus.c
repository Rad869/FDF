/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 07:57:56 by rrabeari          #+#    #+#             */
/*   Updated: 2024/03/10 10:27:24 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list	**lst, void (*del)(void *))
{
	t_list	*par;

	while (*lst)
	{
		par = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = par;
	}
	free(*lst);
	*lst = NULL;
}
