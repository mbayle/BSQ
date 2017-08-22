/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:35:47 by ptruffau          #+#    #+#             */
/*   Updated: 2017/08/22 06:58:17 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "pointh.h"

void teststr(t_save save)
{
	// test de toutes les valeurs de la structure 
	printf("x = %d \ny = %d \ndim = %d \nxmax = %d\nymax = %d \n\n",save.x,save.y,save.dim,save.x_max,save.y_max);
}

int		ft_analyse(t_save save)
{
	int i;
	int j;
	int test;
	int x;
	int y;
	int map[9][9]={{0, 0, 0, 0, 0, 1, 0, 0, 0},
	               {0, 0, 0, 0, 0, 0, 0, 0, 0},
	               {0, 0, 0, 0, 0, 0, 0, 0, 0},
	               {0, 0, 0, 0, 0, 0, 0, 0, 0},
	               {0, 0, 1, 0, 0, 0, 0, 0, 0},
	               {0, 0, 0, 0, 0, 0, 0, 0, 0},
	               {1, 0, 0, 0, 0, 0, 0, 0, 0},
	               {0, 0, 0, 0, 0, 0, 0, 1, 0},
	               {0, 0, 0, 0, 0, 0, 0, 0, 1}};

	y = 0;
	while (y < save.y_max - save.dim)
	{
		x = 0;
		while (x < save.x_max - save.dim)
		{
			j = 0;
			i = 1;
			test = 0;
			while (test == 0 && i <= save.x_max && i <= save.y_max)
			{
				j = i;
				while (j >= 0)
				{
					if (map[x + i - j][y + i] == 1 || map[x + i][y + i - j] == 1)
						test = 1;
					j--;
				}
			i++;
			}
			if (i - 1 > save.dim)
			{
				// maj de la structure (apres avoir trouver un plus gros carre)
				save.dim = i - 1;
				save.x = x;
				save.y = y;
			}
			x++;
		}
		y++;
	}
//	teststr(save);

	//dessin du carre
	i = save.y;
	j = save.x;
	while (i < save.y + save.dim)
	{
		j = save.x;
		while (j < save.x + save.dim)
		{
			map[i][j] = 7;
			j++;
		}
		i++;
	}
	//affichage de map
	i = 0;
	while (i < save.y_max)
	{
		j = 0;
		while (j <  save.x_max)
		{
			printf("%i ",map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


int main()
{
	//   initialisation de la structure 
	t_save save;
	save.x_max = 9;
	save.y_max = 9;
	save.dim = 0;
	ft_analyse(save);
	return (0);
}
