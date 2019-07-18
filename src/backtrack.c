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

int		backtrack(t_tetri *t, int nb_t, int index, int i)
{
	static char  **map;

	if (map == NULL)
		map = create_map(i);
	
	
}

int		backtrack(t_tetri *t, int nb_t, int index, int i)
{
	static int	i;
	static char  **map;

	i = 2;
	if (map == NULL)
		map = create_map(i);
	
}
