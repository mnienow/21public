/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:34:11 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/10 17:34:12 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*out;
	t_list	*del;

	if (lst == NULL || f == NULL)
		return (NULL);
	temp = f(lst);
	out = temp;
	del = lst;
	while (lst->next)
	{
		lst = lst->next;
		if (!(temp->next = f(lst)))
		{
			while (del)
			{
				out = del->next;
				free(del);
				del = out;
			}
			return (NULL);
		}
		temp = temp->next;
	}
	return (out);
}
