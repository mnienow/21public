/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstannis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 07:24:29 by sstannis          #+#    #+#             */
/*   Updated: 2019/02/24 07:24:31 by sstannis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdio.h"
#include "./miniLibX/mlx.h"

void	*newmap(t_map	*map)
{
    map->linemap = ft_strnew(1);
    map->width = 1;
    map->height = 0;
	return (map);
}

void    reader(int fd, t_map *map)
{
    char    buf[BUFF_SIZE + 1];
    int     ret;
	int		i;
	int 	index;
	int		column;

    while ((ret = read(fd, buf, BUFF_SIZE)))
    {
        buf[ret] = '\0';
        map->linemap = ft_strjoin(map->linemap, buf);
    }
	ret = -1;
	while (map->linemap[++ret])
	{
		if (map->linemap[ret] == ' ' && map->height == 0)
			map->width++;
		if (map->linemap[ret] == '\n')
			map->height++;
		if (map->linemap[ret + 1] == ' ')
			ret++;
	}
	map->intmap = (int **)malloc(sizeof(int *) * (map->height + 1));
	map->intmap[map->height] = NULL;
	ret = 0;
	while (ret < map->height)
	{
		map->intmap[ret] = (int *)malloc(sizeof(int) * (map->width));
		ret++;
	}
	i = 0;
	index = 0;
	column = 0;
	while(map->linemap[i])
	{
		if ((int)map->linemap[i] >= '0' && (int)map->linemap[i] <= '9')
		{
			map->intmap[column][index] = ft_atoi(&map->linemap[i]);
			index++;
			while ((int)map->linemap[i + 1] >= '0' && (int)map->linemap[i + 1] <= '9')
					i++;
		}
		if (map->linemap[i] == '\n')
		{
			column++;
			index = 0;
		}
		i++;
	}
}

int     main(int argc, char **argv)
{
    int     fd;
    t_map   map;
	int 	x = 0;
	int 	y = 0;
	int 	wid;
	int		hgt = 0;
	int		parcer = 0;

    if (argc != 2)
        return (0);
   	newmap(&map);
    fd = open(argv[1], O_RDONLY);
    reader(fd, &map);
	map.mlx = mlx_init();
	map.window = mlx_new_window(map.mlx, WIDTH, HEIGHT, "my awesome fdf");
	printf(" width: (%d)\n", map.width);
	printf("height: %d)\n", map.height);
	while (y < map.height)
	{
		wid = 20;
		while (x < map.width)
		{ 
			while (parcer++ < 21)
			{
				mlx_pixel_put(map.mlx, map.window, x + wid + parcer, 20 + y + hgt, 0xFFFFFF);
				mlx_pixel_put(map.mlx, map.window, x + wid, 20 + y + hgt + parcer, 0xFFFFFF);
			}
			parcer = 0;
			wid += 20;
			x++;
		}
		hgt += 20;
		y++;
		x = 0;
	}
	mlx_loop(map.mlx);
    return (0);
}
