/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:54:16 by mnienow           #+#    #+#             */
/*   Updated: 2019/03/30 15:54:18 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct		s_lst
{
	int				val;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

void				err(void);
t_lst				*set_stack_a(long *longs, size_t len);
t_lst 				*valider(char **str, size_t len);
long				ft_atol(const char *str);
t_lst				*lstnew(int val);
void				lstdelone(t_lst **alst);
void				printlst(t_lst *begin, char lst);
void    			parser(t_lst **a, t_lst **b);
void				swap(t_lst **lst, char ch, t_lst **sec);
void				push(t_lst **from, char ch, t_lst **to);
void				rotate(t_lst **lst, char ch, t_lst **sec);
void				rrotate(t_lst **lst, char ch, t_lst **sec);
void				pushIt(t_lst **a, t_lst **b, int len);
int					get_median(t_lst *list, size_t len);
void				sorta(t_lst **a, t_lst **b);
size_t				lstlen(t_lst *list);

#endif
