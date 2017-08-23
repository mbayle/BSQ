/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointh.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 03:16:27 by ptruffau          #+#    #+#             */
/*   Updated: 2017/08/22 21:13:44 by ptruffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINTH_H
# define POINTH_H
#include <stdlib.h>

typedef struct		s_save
{
	int x;
	int y;
	int dim;
	int x_max;
	int y_max;
	int **map;
}					t_save;
void	ft_jaime_les_carres(t_save *save, int x, int y);
#endif
