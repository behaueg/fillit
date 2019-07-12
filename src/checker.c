/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:26:16 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/20 14:26:19 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	*init_checker(int fd)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];
	char	*str;

	ret = 0;
	buff[0] = '\0';
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (!(str = ft_strjoin_free(str, buff, 1)))
			return (0);
	}
	return (str);
}

int		line_checker(char *str)
{
	int i;
	int n;

	n = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			n++;
		if (n % 5 == 0 && str[i] != '\n')
			return (0);
		i++;
	}
	return (n % 5 != 0) ? 0 : 1;
}

int		check_char(char *str)
{
	char	**ret;
	int		lines;
	int		col;
	int		c;

	ret = NULL;
	if (!(ret = ft_strsplit((char const *)str, '\n')))
		return (0);
	lines = 0;
	col = 0;
	c = 0;
	while (ret[lines] != NULL)
	{
		while (ret[lines][col] != '\0')
		{
			if (ret[lines][col] != '#' && ret[lines][col] != '.')
				return (0);
			col++;
		}
		if (col != 4)
			return (0);
		col = 0;
		lines++;
	}
	return (1);
}

int		check_char2(char *str)
{
	int i;
	int hash;
	int points;

	i = -1;
	hash = 0;
	points = 0;
	if (check_char3(str, i, hash, points) == 0)
		return (0);
	return (1);
}

int		check_char3(char *str, int i, int hash, int points)
{
	int n;

	n = 1;
	while (str[++i])
	{
		while (n % 5 != 0)
		{
			if (str[i] == '.')
				points++;
			if (str[i] == '\n')
				n++;
			if (str[i] == '#')
				hash++;
			i++;
		}
		if (points != 12 || hash != 4 || n % 5 != 0)
			return (0);
		points = 0;
		hash = 0;
		n++;
	}
	return (1);
}
