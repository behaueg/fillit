/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:20:01 by behaudeg          #+#    #+#             */
/*   Updated: 2019/07/12 14:20:03 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**backtrack(t_tetri *t, int index, int nb_t, t_point point)
{
	static char	**map;
	static int i;

	i = 2;
	if (point.y >= i)
		return (NULL);
	if (map == NULL)
	{
		map = create_map(i);
		map = init_map(map, i);
	}
	affiche_map(map, i);
	aff(t, nb_t);
	while (index < nb_t)
	{
		if (verif_mettre_piece(map, point, t[index]) == 1)
		{
			printf("Ou est le SEGFAULT DE MORT\n");
			map = mettre_piece(map, point, t, nb_t);
			if (point.x == i)
			{
				point.x = 0;
				point.y++;
			}
			index++;
			map = backtrack(t, index, nb_t, point);
		}
		if (verif_mettre_piece(map, point, t[index]) == 0)
		{
			if (index == 0)
			{
				free(map);
				map = create_map(i + 1);
				map = init_map(map, i + 1);
			}
			if (point.x == i)
			{
				point.x = 0;
				point.y++;
			}
			map = backtrack(t, index, nb_t, point);
		}
		index++;
	}
	return (map);
}

// int		backtrack(t_tetri *t, int nb_t, int size)
// {
// 	static char	**map;
// 	int			i;
// 	int			index;
// 	t_point		point;

// 	point.x = 0;
// 	point.y = 0;
// 	index = 0;
// 	i = 0;
// 	if (map == NULL)
// 	{
// 		map = create_map(size);
// 		map = init_map(map, size)
// 	}
// 	while ()
// 	{
// 		while (verif_mettre_piece(map, point, t[index]) == 0)
// 		{
// 			size++;
// 			free_map(map);
// 			create_map(size);
// 			intit_map(map, size);
// 		}
// 		while (verif_mettre_piece(map, point, t[index]) == 1)
// 		{
			
// 		}
// 	}
// 	return (map);
// }
