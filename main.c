/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 18:20:18 by gbetting          #+#    #+#             */
/*   Updated: 2017/08/23 23:14:53 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "ft_analyse.h"
#include "gp_function/ft_main.h"
#include "gp_function/ft_fonctions_chiants.h"

int		main(int argv, char **args)
{
	int i;
	int file;

	i = 1;
	if (argv > 1)
		while (i < argv)
		{
			if (!((file = open(args[i], O_RDONLY)) > 0)
			|| !ft_analyse(file))
				write(1, "map error\n", 10);
			i++;
			close(file);
			if (i < argv)
				write(1, "\n", 1);
		}
	else
	{
		if (!ft_analyse(0))
			write(1, "map error\n", 10);
	}
	return (0);
}
