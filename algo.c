/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabayle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 14:53:12 by mabayle           #+#    #+#             */
/*   Updated: 2017/08/21 15:35:42 by mabayle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**GlobalCkeck(char tab[][], int size_x, int size_y)
{
	char	hg[][];
	int x;
	int y;

	x = 0;
	y = 0;
	hg[][] = tab[x][y];
	while(hg[x][y] || x < size_x - x || y < size_y - y)
	{
		check_hd(hg[x][y], x, y);
		check_bg(hg[x][y], x, y);
		check_diag(hg[x][y], x, y);
		if (hd[x] > hg[x] && bg[y] > hg[y] && diag[x][y] > hg[x][y])
			
	}
}
