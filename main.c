/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 18:20:18 by gbetting          #+#    #+#             */
/*   Updated: 2017/08/23 18:40:35 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#include "ft_analyse.h"
#include "gp_function/ft_main.h"
#include "gp_function/ft_fonctions_chiants.h"

int main(int argv,char **args)
{
	int i;
	int file;
	int x;
	int y;
	char*chara;
	char**tab;

	tab = NULL;
	x = 0;
	y = 0;
	chara = 0;
	if (argv > 1)
	{
		i = 1;
		while(i < argv)
		{
			file = open(args[i],O_RDONLY);
			if(!(tab = ft_main(file,chara,&x,&y)))
				write(1,"map error\n",10);
			else
				ft_printd(tab,x,y);
			i++;
			if(i < argv)
				write(1,"\n",1);
		}
	}
	else
	{
		
		if(!ft_analyse(0))
		{
			write(1,"map error\n",10);
		}
		else
			ft_printd(tab,x,y);
	}
	return(0);
}
