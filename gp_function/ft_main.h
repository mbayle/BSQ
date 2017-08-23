/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:00:14 by gbetting          #+#    #+#             */
/*   Updated: 2017/08/23 19:46:51 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

char	**ft_main(int file, int *x, int *y);
int		ft_isvalid(char **array, int x, int y, char *data);
int		ft_isfinish(int file);
char	*ft_str_to_data(char *str, int *x);

#endif
