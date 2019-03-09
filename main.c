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

void	writer(t_map *map, int i)
{
	int		index;
	int		column;

	map->imap = (int **)malloc(sizeof(int *) * (map->hgt + 1));
	map->imap[map->hgt] = NULL;
	while (i < map->hgt)
		map->imap[i++] = (int *)malloc(sizeof(int) * (map->wid));
	i = 0;
	index = 0;
	column = 0;
	while (map->lmap[i++])
	{
		if (map->lmap[i] >= '0' && map->lmap[i] <= '9')
		{
			map->imap[column][index++] = ft_atoi(&map->lmap[i]);
			while (map->lmap[i + 1] >= '0' && map->lmap[i + 1] <= '9')
				i++;
		}
		if (map->lmap[i] == '\n')
		{
			column++;
			index = 0;
		}
	}
}

void	valider(t_map *map, int i)
{
	while (map->lmap[++i])
	{
		if (map->lmap[i] == ' ' && map->hgt == 0)
			map->wid++;
		if (map->lmap[i] == '\n')
			map->hgt++;
		if (map->lmap[i + 1] == ' ')
			i++;
	}
	writer(map, 0);
}

int		reader(int fd, t_map *map)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		map->lmap = ft_strjoin(map->lmap, buf);
	}
	return (0);
}

void	*newmap(t_map *map)
{
	map->lmap = ft_strnew(1);
	map->wid = 1;
	map->hgt = 0;
	return (map);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	if (argc != 2)
		return (0);
	newmap(&map);
	fd = open(argv[1], O_RDONLY);
	reader(fd, &map);
	valider(&map, -1);
	map.mlx = mlx_init();
	map.wdw = mlx_new_window(map.mlx, WIDTH, HEIGHT, "my awesome fdf");
	printf(" width: (%d)\n", map.wid);
	printf("height: %d)\n", map.hgt);
	printf("");
	printer(&map, 0, 0, 0);
	mlx_loop(map.mlx);
	return (0);
}
