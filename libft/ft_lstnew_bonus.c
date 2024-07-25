/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:31:08 by rrabeari          #+#    #+#             */
/*   Updated: 2024/03/06 10:12:38 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*value;

	value = (t_list *)malloc(sizeof(t_list));
	if (!value)
		return (NULL);
	value->content = content;
	value->next = NULL;
	return (value);
}
