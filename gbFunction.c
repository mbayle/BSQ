/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbFunction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbetting <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 01:43:56 by gbetting          #+#    #+#             */
/*   Updated: 2017/08/23 10:22:42 by gbetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char	*ft_strncpy(char*,char*,unsigned int);
int		ft_atoi(char*);
int		ft_strlen(char*);

char	*gp_getknowedline(int file,int n)
{
	char *result;
	char buffer;
	int j;

	if(!(result = malloc(sizeof(char) * (n+1))))
		return(0);
	if((j = read(file,result,n)) && j != n)
		while(j != n)
			if(!(j += read(file,result+j,n-j)))
			{
				printf("Nothing readed\n");
				return(0);
			}
	result[n] = '\0';
	//printf("full read passed : %s",result);
	if(read(file,&buffer,1) && buffer == '\n')
		return(result);
	printf("is not a \\n : %c\n",buffer);
	free(result);
	return(0);
}

int		gp_isvalid(char **a, int x, int y, char *c)
{
	int x_;

	x -= 1;
	y -= 1;
	x_ = x;
	while(y > 0)
	{
		while(x > 0)
		{
			if(a[y][x] != c[0] && a[y][x] != c[1])
				return(0);
			x--;
		}
		x = x_;
		y--;
	}
	return(1);
}

int gp_isfinish(int file)
{
	char buffer;

	if(read(file,&buffer,1) && buffer != '\0')
	{
		return(0);
	}
	return(1);
}

char	*gp_getline(int file,char buffer,int *x)
{
	char *result;
	char *megarray;

	*x = 0;
	if(!(result = malloc(sizeof(char) * ++*x)))
		return(0);
	if(read(file,&buffer,1))
		result[0] = buffer;
	else
		return(0);
	while(read(file,&buffer,1) && buffer != '\n')
	{
		if(buffer == '\0')
			return(0);
		if(!(megarray = malloc(sizeof(char) * ++*x)))
			return(0);
		ft_strncpy(megarray,result,*x);
		free(result);
		megarray[*x-1] = buffer;
		if(!(result = malloc(sizeof(char) * *x)))
			return(0);
		ft_strncpy(result,megarray,*x);
		free(megarray);
	}
	result[*x] = '\0';
	return(result);
}	
char	*gp_fprocess(char *line, int *theint)
{
	int l;
	char *chara;
	char *numb;

	l = ft_strlen(line);
	if (l < 3)
		return(0);
	if(!(chara = malloc(sizeof(char) * 3)))
		return(0);
	if(!(numb = malloc(sizeof(char) * l-3)))
		return(0);
	ft_strncpy(numb,line,l-3);
	*theint = ft_atoi(numb);
	chara[0] = line[l - 3];
	chara[1] = line[l - 2];
	chara[2] = line[l - 1];
	return(chara);
}

void    ft_printd(char **array, int x, int y)
{
	int x_;
	int y_;

	y_ = 0;
	while (y_ < y)
	{
		x_ = 0;
		while (x_ < x)
		{
			write(1, &array[y_][x_++], 1);
		}
		write(1, "\n", 1);
		y_ += 1;
	}
}

int		ft_strlen(char *str)
{
	int l;

	l = 0;
	while(str[l])
		l++;
	return(l);
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
