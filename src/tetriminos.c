/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 12:27:31 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/28 12:27:33 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			count_tetris(char *str)
{
	int i;
	int nb;
	int n;

	i = 0;
	nb = 0;
	n = 1;
	while (str[i])
	{
		if (n % 5 == 0)
		{
			nb++;
			i++;
			n++;
		}
		if (str[i] == '\n')
			n++;
		i++;
	}
	return (nb + 1);
}

t_tetri		*create_tetriss(char **str_split, t_tetri *test, char *str)
{
	int		nb_tetri;
	int		lines;
	int		col;
	int		index;
	int		lines1;

	nb_tetri = count_tetris(str) + 1;
	lines = -1;
	col = -1;
	index = 0;
	lines1 = 0;
	while (--nb_tetri >= 1)
	{
		while (++lines < 4)
		{
			while (++col <= 4)
				test[index].tetri[lines][col] = str_split[lines1][col];
			test[index].tetri[lines][col] = '\0';
			col = -1;
			lines1++;
		}
		lines = -1;
		index++;
	}
	return (test);
}

t_tetri		*create_tetris(char *str, char **str_split)
{
	t_tetri	*test;

	if (!(test = (t_tetri*)malloc(sizeof(test) * count_tetris(str))))
		return (0);
	test = create_tetriss(str_split, test, str);
	return (test);
}

t_tetri		*create_coordd(t_tetri *test, int nb_tetri, int j, int k)
{
	int index;
	int i;

	i = -1;
	index = -1;
	while (++index < nb_tetri)
	{
		while (++i < 4)
		{
			while (++j < 4)
			{
				if (test[index].tetri[i][j] == '#')
				{
					test[index].coord[k].x = j;
					test[index].coord[k].y = i;
					k++;
				}
			}
			j = -1;
		}
		i = -1;
		k = 0;
	}
	return (test);
}

t_tetri		*create_coord(t_tetri *test, int nb_tetri)
{
	int	j;
	int k;

	j = -1;
	k = 0;
	test = create_coordd(test, nb_tetri, j, k);
	return (test);
}

void		aff(t_tetri *test, int c_tetris)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (c_tetris >= 1)
	{
		while (x < 4)
		{
			while (y < 4)
			{
				printf("%c", test->tetri[x][y]);
				y++;
			}
			x++;
			y = 0;
			printf("\n");
		}
		c_tetris--;
		test++;
		x = 0;
		printf("\n\n");
	}
}
