/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:16:32 by mnienow           #+#    #+#             */
/*   Updated: 2019/04/05 17:16:34 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t		lstlen(t_lst *list)
{
	size_t	len;

	len = 0;
	while (list->next)
	{
		list = list->next;
		len++;
	}
	return (len);
}

int			*lst_to_arr(t_lst *list, size_t len)
{
	int		*arr;
	int		i;

	arr = (int*)malloc(sizeof(int) * len);
	i = 0;
	while (list->next)
	{
		arr[i++] = list->val;
		list = list->next;
	}
	return (arr);
}

void qs(int *number, int first,int last)
{
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      qs(number,first,j-1);
      qs(number,j+1,last);
   }
}

int			get_median(t_lst *list, size_t len)
{
	int		*ints;

	ints = lst_to_arr(list, len);
	// printf("int array created\n");
	qs(ints, ints[0], ints[len - 1]);
	// printf("sorted\n");
	return (ints[len / 2]);
}
