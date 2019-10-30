/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:16:32 by mnienow           #+#    #+#             */
/*   Updated: 2019/10/30 22:03:18 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void swap(long *number, int i, int j)
{
    long     temp;

    temp = number[i];
    number[i] = number[j];
    number[j] = temp;
}

void        ft_qs(long *number, int first, int last)
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
                swap(number, i, j);
        }
        temp = number[pivot];
        number[pivot] = number[j];
        number[j] = temp;
        ft_qs(number, first, j - 1);
        ft_qs(number, j + 1, last);
    }
}
