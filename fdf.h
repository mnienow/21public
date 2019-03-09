/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 08:09:55 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/24 08:09:57 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "./miniLibX/mlx.h"
# include "stdio.h"
# define WIDTH 1280
# define HEIGHT 720
# define CHN(y) if ((y) == 0) return (-1)
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_map
{
    char    	*lmap;
    int     	wid;
    int     	hgt;
	int			**imap;
	void		*mlx;
	void		*wdw;
}   t_map;

int     main(int argc, char **argv);
void	printer(t_map *map, int x, int y, int i);

#endif
