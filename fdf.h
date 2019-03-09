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
# define WIDTH 1280
# define HEIGHT 720

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_map
{
    char    	*linemap;
    int     	width;
    int     	height;
	int			**intmap;
	void		*mlx;
	void		*window;
}   t_map;

int     main(int argc, char **argv);

#endif
