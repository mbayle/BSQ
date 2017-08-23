/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointh.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 03:16:27 by ptruffau          #+#    #+#             */
/*   Updated: 2017/08/23 15:06:55 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTH_H
# define POINTH_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_save
{
	int x;
	int y;
	int dim;
	int x_max;
	int y_max;
//	char *chara;
//	char **map;
	int **map;
}				t_save;
void			ft_analyse_balayage(t_save *save);
void			ft_jaime_les_carres(t_save *save, int x, int y, int a);
void			ft_square_founded(t_save *save);
void			ft_analyse();

#endif