/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:26:33 by sstannis          #+#    #+#             */
/*   Updated: 2018/12/09 19:26:36 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*arr;

	if (!(arr = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		arr->content = NULL;
		arr->content_size = 0;
	}
	else
	{
		if (!(arr->content = (void *)malloc(content_size)))
		{
			free(arr);
			return (NULL);
		}
		ft_memcpy(arr->content, content, content_size);
		arr->content_size = content_size;
	}
	arr->next = NULL;
	return (arr);
}
