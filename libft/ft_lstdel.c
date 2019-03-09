/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:47:19 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/10 15:47:21 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (*alst != NULL)
	{
		while (*alst)
		{
			temp = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			ft_memdel((void **)alst);
			(*alst) = temp;
		}
	}
}
