/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 18:31:25 by mnienow           #+#    #+#             */
/*   Updated: 2019/03/09 18:31:29 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	printer(t_map *map, int x, int y, int i)
{
	int		wid;
	int		hgt;

	hgt = 0;
	while (y < map->hgt)
	{
		wid = 20;
		while (x < map->wid)
		{
			while (i++ < 21)
			{
				mlx_pixel_put(map->mlx, map->wdw, x + wid + i, 20 + y + hgt,
				0xFFFFFF);
				mlx_pixel_put(map->mlx, map->wdw, x + wid, 20 + y + hgt + i,
				0xFFFFFF);
			}
			i = 0;
			wid += 20;
			x++;
		}
		hgt += 20;
		y++;
		x = 0;
	}
}
