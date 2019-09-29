/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:48:56 by mnienow           #+#    #+#             */
/*   Updated: 2019/03/30 15:48:58 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    swapper(t_lst **a, t_lst **b, char *line)
{
    if (!ft_strcmp(line, "sb"))
        swap(b, 'b', a);
    else if (!ft_strcmp(line, "sa"))
        swap(a, 'a', b);
    else if (!ft_strcmp(line, "ss"))
    {
        swap(a, 'a', b);
        swap(b, 'b', a);
    }
    else
        err();
}

void    rot(t_lst **a, t_lst **b, char *line)
{
    if (line[1] == 'a')
        rotate(a, 'a', b);
    else if (line[1] == 'b')
        rotate(b, 'b', a);
    else if (line[1] == 'r')
    {
        rotate(a, 'a', b);
        rotate(b, 'b', a);
    }
    else
        err();
}

void    rrot(t_lst **a, t_lst **b, char *line)
{
    if (line[1] == 'r')
    {
        if (line[2] == 'a')
            rrotate(a, 'a', b);
        else if (line[2] == 'b')
            rrotate(b, 'b', a);
        else if (line[2] == 'r')
        {
            rrotate(a, 'a', b);
            rrotate(b, 'b', a);
        }
        else
            err();
    }
    else
        err();
}

void    parser(t_lst **a, t_lst **b)
{
    char *line;

    line = 0;
    while (get_next_line(0, &line))
    {
        if (line[0] == 's')
            swapper(a, b, line);
        else if (!ft_strcmp(line, "pa"))
            push(b, 'a', a);
        else if (!ft_strcmp(line, "pb"))
            push(a, 'b', b);
        else if (line[0] == 'r')
        {
            if (ft_strlen(line) == 2)
                rot(a, b, line);
            else if (ft_strlen(line) == 3)
                rrot(a, b, line);
            else
                err();
        }
        else
            err();
    }
}