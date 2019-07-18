/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:50:03 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/25 14:50:06 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 1

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetri
{
	int			larg;
	int			haut;
	char		lettre;
	char		tetri[4][5];
	t_point		coord[4];
}				t_tetri;

t_tetri			*create_tetriss(char **str_split, t_tetri *test, char *str);
t_tetri			*create_tetris(char *str, char **str_split);
t_tetri			*create_coordd(t_tetri *test, int nb_tetri, int j, int k);
t_tetri			*create_coord(t_tetri *test, int nb_tetrix);
t_tetri			*create_letter(t_tetri *tetri, int nb_tetris);
void			create_size(t_tetri *tetri, int nb_t);
void			get_x(t_tetri *t, int nb_t, int k);
void			aff(t_tetri *test, char *str);
void			free_split(char **str_split);
void			get_y(t_tetri *t, int nb_t, int k, int tmpy);
int				count_tetris(char *str);
int				checker(char *str);
int				line_checker(char *str);
int				check_char(char *str);
int				check_char2(char *str);
int				check_char3(char *str, int i, int hash, int points);
int				shapo(char *str);
int				shapoo(int i, char *str, int test, int link);
char			*init_checker(int fd);
char			**init_map(char **map, int size);
int     		verif_mettre_piece(char **map, t_point point, t_tetri t);
char    		**mettre_piece(char **map, t_point point, t_tetri *t, int nb_t);
char			**create_map(int size);
void	        affiche_map(char **map, int size);

#endif
