/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:29:39 by behaudeg          #+#    #+#             */
/*   Updated: 2019/07/12 14:29:42 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetri		*create_letter(t_tetri *tetri, int nb_tetris)
{
	int index;
	char l;

	index = 0;
	l = 'A' - 1;
	while (index < nb_tetris)
	{
		l++;
		tetri[index].lettre = l;
		index++; 
	}
	return (tetri);
}
