/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:35:47 by ptruffau          #+#    #+#             */
/*   Updated: 2017/08/22 21:58:43 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pointh.h"
void	ft_init_struct(t_save *save)
{
	int i;
	int j;
	save->x_max = 6;
	save->y_max = 6;
	save->dim = 0;
	save->map = (int**)malloc(sizeof(int*) * (save->y_max + 18));
	i = 0;
	while (i < save->y_max)
	{
		save->map[i] = (int*)malloc(sizeof(int) * (save->x_max + 18));
		j = 0;
		while (j < save->x_max)
		{
			save->map[i][j] = 0;
			j++;
		}
		i++;
	}
	save->map[5][0] = 1;
}
void teststr(t_save save)
{
	// test de toutes les valeurs de la structure 
	printf("x = %d \ny = %d \ndim = %d \nxmax = %d\nymax = %d \n\n",save.x,save.y,save.dim,save.x_max,save.y_max);
}

void	ft_analyse(t_save *save)
{
	int i;
	int j;
	int x;
	int y;

	y = 0;
	while (y < save->y_max - save->dim)
	{
		x = 0;
		while (x < save->x_max - save->dim)
		{
			if (save->map[y][x] != 1)
				ft_jaime_les_carres(save, x, y);		
			x++;
		}
		y++;
	}
	teststr(*save);

	//dessin du carre
	i = save->y;
	j = save->x;
	while (i < save->y + save->dim)
	{
		j = save->x;
		while (j < save->x + save->dim)
		{
			save->map[i][j] = 7;
			j++;
		}
		i++;
	}
	//affichage de map
	i = 0;
	while (i < save->y_max)
	{
		j = 0;
		while (j <  save->x_max)
		{
			printf("%i ",save->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	ft_jaime_les_carres(t_save *save, int x, int y)
{
	int j;
	int i;
	int test;

	j = 0;
	i = 1;
	test = 0;
	while (test == 0 && i <= save->x_max && i <= save->y_max)
	{
		j = i;
		while (j >= 0)
		{
			if (save->map[y + i - j][x + i] == 1 || save->map[y + i][x + i - j] == 1)
				test = 1;
			j--;
		}
		i++;
	}
	if (i - 1 > save->dim)
	{
		save->dim = i - 1;
		save->x = x;
		save->y = y;
	}
}


int main()
{
	t_save save;	
	ft_init_struct(&save);
	ft_analyse(&save);
	return (0);
}
