/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:35:47 by ptruffau          #+#    #+#             */
/*   Updated: 2017/08/23 22:01:03 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_analyse.h"
#include "gp_function/ft_main.h"
#include "gp_function/ft_fonctions_chiants.h"

void	ft_square_founded(t_save *save)
{
	int i;
	int j;

	i = save->y;
	while (i < save->y + save->dim)
	{
		j = save->x;
		while (j < save->x + save->dim)
		{
			save->map[i][j] = save->map[save->y_max][2];
			j++;
		}
		i++;
	}
}

void	ft_analyse_balayage(t_save *save)
{
	int x;
	int y;

	y = 0;
	while (y < save->y_max - save->dim)
	{
		x = 0;
		while (x < save->x_max - save->dim)
		{
			if (save->map[y][x] != 1)
				ft_jaime_les_carres(save, x, y, 0);
			x++;
		}
		y++;
	}
}

void	ft_jaime_les_carres(t_save *save, int x, int y, int i)
{
	int test;
	int j;

	j = 0;
	test = 0;
	while (test == 0 && i + x < save->x_max && i + y < save->y_max)
	{
		j = i;
		while (j >= 0 && test == 0)
		{
			if (save->map[y + i - j][x + i] == save->map[save->y_max][1] ||
				save->map[y + i][x + i - j] == save->map[save->y_max][1])
				test = 1;
			j--;
		}
		i++;
	}
	if (test == 0 && (x + i == save->x_max || y + i == save->y_max))
		i++;
	if (i - 1 > save->dim)
	{
		save->dim = i - 1;
		save->x = x;
		save->y = y;
	}
}

int		ft_analyse(int file)
{
	t_save	save;

	save.dim = 0;
	if (!(save.map = ft_main(file, &save.x_max, &save.y_max)))
		return (0);
	ft_analyse_balayage(&save);
	ft_square_founded(&save);
	ft_printd(save.map, save.x_max, save.y_max);
	return (1);
}
