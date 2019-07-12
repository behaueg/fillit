/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:02:08 by behaudeg          #+#    #+#             */
/*   Updated: 2019/07/12 13:02:09 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		shapo(char *str)
{
	int i;
	int n;
	int link;
	int test;

	link = 0;
	i = -1;
	n = 1;
	test = 0;
	while (str[++i])
	{
		while (n % 5 != 0)
		{
			if (str[i] == '\n')
				n++;
			link = shapoo(i, str, test, link);
			i++;
		}
		if (link != 6 && link != 8)
			return (0);
		n++;
		test += 21;
		link = 0;
	}
	return (1);
}

int		shapoo(int i, char *str, int test, int link)
{
	if (str[i] == '#')
	{
		if (((i + 1) < 20 + test) && str[i + 1] == '#')
			link++;
		if ((i - 1) >= 0 + test && str[i - 1] == '#')
			link++;
		if (((i + 5) < 20 + test) && str[i + 5] == '#')
			link++;
		if ((i - 5) >= 0 + test && str[i - 5] == '#')
			link++;
	}
	return (link);
}

int		checker(char *str)
{
	int nb_tetri;

	nb_tetri = count_tetris(str);
	if (shapo(str) == 0)
		printf("shapo erreur\n");
	if (check_char(str) == 0)
		printf("check_char erreur\n");
	if (line_checker(str) == 0)
		printf("line_checker erreur\n");
	if (check_char2(str) == 0)
		printf("check_char2 erreur\n");
	return (shapo(str) == 0 || check_char(str) == 0
		|| line_checker(str) == 0 || check_char2(str) == 0) ? 0 : 1;
}
