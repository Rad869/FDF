/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrabeari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 10:36:30 by rrabeari          #+#    #+#             */
/*   Updated: 2024/03/10 11:22:03 by rrabeari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*par;
	t_list	*value;

	if (!lst || !f || !del)
		return (NULL);
	value = NULL;
	while (lst)
	{
		par = ft_lstnew(f(lst->content));
		if (!par)
		{
			ft_lstclear(&value, del);
			return (NULL);
		}
		ft_lstadd_back(&value, par);
		lst = lst->next;
	}
	return (value);
}
