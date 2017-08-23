/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptruffau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 03:16:27 by ptruffau          #+#    #+#             */
/*   Updated: 2017/08/23 22:05:53 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ANALYSE_H
# define FT_ANALYSE_H
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_save
{
	int		x;
	int		y;
	int		dim;
	int		x_max;
	int		y_max;
	char	**map;
}				t_save;
void			ft_analyse_balayage(t_save *save);
void			ft_jaime_les_carres(t_save *save, int x, int y, int a);
void			ft_square_founded(t_save *save);
int				ft_analyse(int file);

#endif
