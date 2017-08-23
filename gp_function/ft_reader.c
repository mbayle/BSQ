/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:25:42 by gbetting          #+#    #+#             */
/*   Updated: 2017/08/23 22:52:40 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fonctions_chiants.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	*ft_getknowedline(int file, int n)
{
	char	*result;
	int		j;
	char	buffer;

	if (!(result = malloc(sizeof(char) * (n + 1))))
		return (0);
	if ((j = read(file, result, n)) > 0 && j != n)
	{
		while (j != n)
			if (!((j += read(file, result + j, n - j)) > 0))
				return (0);
	}
	else
		return (0);
	result[n] = '\0';
	if (read(file, &buffer, 1) > 0 && buffer == '\n')
		return (result);
	free(result);
	return (0);
}

char	*ft_getline(int file, char buffer, int *x)
{
	char *result;
	char *megarray;

	*x = 0;
	if (!(result = malloc(sizeof(char) * ++*x)))
		return (0);
	if (read(file, &buffer, 1) > 0)
		result[0] = buffer;
	else
		return (0);
	while (read(file, &buffer, 1) > 0 && buffer != '\n')
	{
		if (buffer == '\0' || !(megarray = malloc(sizeof(char) * ++*x)))
			return (0);
		ft_strncpy(megarray, result, *x);
		free(result);
		megarray[*x - 1] = buffer;
		if (!(result = malloc(sizeof(char) * *x)))
			return (0);
		ft_strncpy(result, megarray, *x);
		free(megarray);
	}
	result[*x] = '\0';
	return (result);
}
