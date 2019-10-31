/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:16:32 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/31 00:07:58 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t      lstlen(t_lst *list)
{
    size_t  len;

    len = 0;
    while (list)
    {
        list = list->next;
        len++;
    }
    return (len);
}

int         get_value(t_lst *list, int index)
{
    int value;

    value = 0;
    while (list)
    {
        if (list->index == index)
            value = list->val;
        list = list->next;
    }
    return value;
}

int         get_median(t_lst *list, size_t len)
{
    int     min;
    int     max;
    t_lst   *link;

    min = 2147483647;
    max = 0;
    link = list;
    while (link && len)
    {
        if (min > link->index)
            min = link->index;
        if  (max < link->index)
            max = link->index;
        link = link->next;
        len--;
    }
    if (len == 4)
        return get_value(list, min + 1);
    return (get_value(list,max - ((max - min) / 2)));
}
