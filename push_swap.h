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
}					t_lst;

t_lst				*lstnew(int val);
void				printlst(t_lst *begin, char lst);
void				swap(t_lst **lst, char ch, t_lst **sec);
void				push(t_lst **from, char ch, t_lst **to);
void				rotate(t_lst **lst, char ch, t_lst **sec);
void				rrotate(t_lst **lst, char ch, t_lst **sec);
void				lstdelone(t_lst **alst);
void				err(void);
int					checker(char **str, char op);
void				valider1(char **str);
void				parser2(t_lst **a, t_lst **b);

#endif
