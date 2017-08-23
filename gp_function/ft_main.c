/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:03:25 by gbetting          #+#    #+#             */
/*   Updated: 2017/08/23 23:14:26 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "ft_fonctions_chiants.h"
#include "ft_reader.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	**ft_main(int file, int *i, int *line)
{
	char	**tab;
	int		cur;
	char	*chara;

	cur = 0;
	if (!(chara = ft_getline(file, 0, i)))
		return (0);
	if (!(chara = ft_str_to_data(chara, line)))
		return (0);
	if (!(tab = malloc(sizeof(char*) * *line + 1))
		|| !(tab[cur++] = ft_getline(file, 0, i)))
		return (0);
	while (cur < *line)
		if (!(tab[cur++] = ft_getknowedline(file, *i)))
		{
			free(tab);
			return (0);
		}
	if (!ft_isfinish(file) || !ft_isvalid(tab, *i, *line, chara))
	{
		free(tab);
		return (0);
	}
	tab[*line] = chara;
	return (tab);
}

int		ft_isvalid(char **a, int x, int y, char *c)
{
	int x_;

	x -= 1;
	y -= 1;
	x_ = x;
	while (y >= 0)
	{
		while (x >= 0)
		{
			if (a[y][x] != c[0] && a[y][x] != c[1])
				return (0);
			x--;
		}
		x = x_;
		y--;
	}
	return (1);
}

int		ft_isfinish(int file)
{
	char buffer;

	if (read(file, &buffer, 1) > 0 && buffer != '\0')
		return (0);
	return (1);
}

char	*ft_str_to_data(char *line, int *theint)
{
	int l;
	char*chara;
	char*num;

	l = ft_strlen(line);
	num = NULL;
	if (l < 3)
		return (0);
	if (!(chara = malloc(sizeof(char) * 3))
	|| !(num = malloc(sizeof(char) * l - 3)))
		return (0);
	ft_strncpy(num, line, l - 3);
	if (ft_str_is_numeric(num))
		*theint = ft_atoi(num);
	else
		return (0);
	chara[0] = line[l - 3];
	chara[1] = line[l - 2];
	chara[2] = line[l - 1];
	return (chara);
}
