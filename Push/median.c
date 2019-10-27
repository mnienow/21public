/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:16:32 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/27 23:38:33 by null             ###   ########.fr       */
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

int         *lst_to_arr(t_lst *list, size_t len)
{
    int     *arr;
    int     i;

    arr = (int *) malloc(sizeof(int) * len);
    i = 0;
    while (list)
    {
        arr[i] = list->val;
        list = list->next;
        i++;
    }
    return (arr);
}
void        swap_ints(int *number, int i, int j)
{
    int     temp;

    temp = number[i];
    number[i] = number[j];
    number[j] = temp;
}

void        qs(int *number, int first, int last)
{
    int     i;
    int     j;
    int     pivot;
    int     temp;

    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        while (i < j)
        {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
                swap_ints(number, i, j);
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        qs(number, first, j - 1);
        qs(number, j + 1, last);
    }
}

int         get_median(t_lst **list, size_t len)
{
    int     *ints;

    ints = lst_to_arr(*list, len);
    qs(ints, 0, len - 1);
    if ((*list)->index == 0)
        set_indexes(list, ints, len);
    if (len == 4)
        return ints[1];
    return (ints[len / 2]);
}
