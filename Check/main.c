/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnienow <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:47:45 by mnienow           #+#    #+#             */
/*   Updated: 2019/04/03 21:47:50 by mnienow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "checker.h"

int		main(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	if (argc < 2)
		err();
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] >= 48 && argv[i][j] <= 57) || argv[i][j] == 45 ||
			argv[i][j] == 32)
				j++;
			else
				err();
		}
	}
	if ((i = checker(&argv[1])) == -1)
		err();
	else if (i == -2)
		write(1, "KO\n", 4);
	else if (i == 0)
		write(1, "OK\n", 4);
	return (0);
}