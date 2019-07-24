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

t_tetri		*create_letter(t_tetri *t, int nb_tetris)
{
	int		nb_t;
	char	l;

	nb_t = 0;
	l = 'A' - 1;
	while (nb_t < nb_tetris)
	{
		l++;
		t[nb_t].lettre = l;
		nb_t++;
	}
	return (t);
}

// void		create_size(t_tetri *t, int nb_t)
// {
// 	int tmpy;
// 	int k;

// 	tmpy = 0;
// 	k = 0;
// 	get_y(t, nb_t, k, tmpy);
// 	get_x(t, nb_t, k);
// }

// void		get_y(t_tetri *t, int nb_t, int k, int tmpy)
// {
// 	int tmpy2;

// 	tmpy2 = 0;
// 	while (--nb_t >= 0)
// 	{
// 		while (++k < 4)
// 		{
// 			if (t[nb_t].coord[k].y < t[nb_t].coord[tmpy].y)
// 				tmpy = k;
// 			if (t[nb_t].coord[k].y > t[nb_t].coord[tmpy2].y)
// 				tmpy2 = k;
// 		}
// 		t[nb_t].haut = t[nb_t].coord[tmpy2].y - t[nb_t].coord[tmpy].y;
// 		t[nb_t].haut += 1;
// 		k = 0;
// 		tmpy = 0;
// 		tmpy2 = 0;
// 	}
// }

// void		get_x(t_tetri *t, int nb_t, int k)
// {
// 	int tmpx;
// 	int tmpx2;

// 	tmpx = 0;
// 	tmpx2 = 0;
// 	while (--nb_t >= 0)
// 	{
// 		while (++k < 4)
// 		{
// 			if (t[nb_t].coord[k].x < t[nb_t].coord[tmpx].x)
// 				tmpx = k;
// 			if (t[nb_t].coord[k].x > t[nb_t].coord[tmpx2].x)
// 				tmpx2 = k;
// 		}
// 		t[nb_t].larg = t[nb_t].coord[tmpx2].x - t[nb_t].coord[tmpx].x;
// 		t[nb_t].larg += 1;
// 		k = 0;
// 		tmpx = 0;
// 		tmpx2 = 0;
// 	}
// }
