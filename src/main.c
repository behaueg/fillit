/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:01:48 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/28 11:05:56 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		main(int argc, char **argv)
{
	int			fd;
	char		*str;
	t_tetri		*tetriminios;
	char		**str_split;
	int			nb_tetris;
	char 		**map;
	t_point		point;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (!(str = init_checker(fd)))
		return (-1);
	if (checker(str) == 0)
		return (0);
	if (!(str_split = ft_strsplit(str, '\n')))
		return (0);
	nb_tetris = count_tetris(str);
	tetriminios = create_tetris(str, str_split);
	tetriminios = create_coord(tetriminios, nb_tetris);
	tetriminios = create_letter(tetriminios, nb_tetris);
	create_size(tetriminios, nb_tetris);
	printf("Valide\n");
	map = create_map(7);
	printf("val dans main de x = %d\n", tetriminios[1].coord[0].x);
	map = init_map(map, 7);
	affiche_map(map, 7);
	printf("\n");
	point.x = 0;
	point.y = 0;
	if (verif_mettre_piece(map, point, tetriminios[1]) == 0 )
	{
		printf("erreur\n");
		return (0);
	}
	map = mettre_piece(map, point, tetriminios, 1);
	affiche_map(map, 7);
	// aff(tetriminios, str);
	free(tetriminios);
	return (0);
}
