/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fonctions_chiants.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 14:55:14 by gbetting          #+#    #+#             */
/*   Updated: 2017/08/23 16:22:18 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_str_is_numeric(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 48 || str[i] > 57))
			return (0);
		i++;
	}
	return (1);
}

int		ft_atoi(char *str)
{
	int i;
	int num;
	int neg;

	i = 0;
	num = 0;
	neg = 1;
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (neg * num);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int len_src;
	int len_dest;

	len_dest = 0;
	len_src = 0;
	while (src[len_src] != '\0' && len_src != (int)n)
		dest[len_dest++] = src[len_src++];
	return (dest);
}

void	ft_printd(char **array, int x, int y)
{
	int y_;

	y_ = 0;
	while (y_ != y)
	{
		write(1, array[y_], x);
		write(1, "\n", 1);
		y_++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
