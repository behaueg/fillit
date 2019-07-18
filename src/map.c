/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 14:19:31 by behaudeg          #+#    #+#             */
/*   Updated: 2019/07/12 14:19:33 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**create_map(int size)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char**)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	map[size] = NULL;
	while (i < size)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		map[i][size] = '\0';
		i++;
	}
	return (map);
}

char		**init_map(char **map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	return (map);
}

int     verif_mettre_piece(char **map, t_point point, t_tetri t)
{
    int i;                                                                   
    int dx;                                                                      
    int dy;                                                                     

    i = 0;              
	printf("val de x = %d\n", (t.coord[0].x));                                               
    dx = point.x - t.coord[0].x;                                           
    dy = point.y - t.coord[0].y;                                                                                        
    while (i < 4)                                                            
    {       
		printf("dy = %d\n", dy);
		printf("dx = %d\n", dx);
		printf("val de y = %d\n", (t.coord[i].y));         
		printf("val de x = %d\n", (t.coord[i].x));  
		printf("nouvelle val de y = %d\n", (t.coord[i].y) + dy);         
		printf("nouvelle val de x = %d\n", (t.coord[i].x) + dx); 
		if (t.coord[i].y + dy >= 7 || t.coord[i].x + dx >= 7)
			return (0);      
        if (map[(t.coord[i].y) + dy][(t.coord[i].x) + dx] != '.' )
            return (0);
		printf("\n");                                                        
        i++;                                                                 
    }                                                                            
    return (1);
}

char    **mettre_piece(char **map, t_point point, t_tetri *t, int nb_t)
 {
    int index;
    int dx;
    int dy;

    index = 0;
    dx = point.x - t[nb_t].coord[0].x;
    dy = point.y - t[nb_t].coord[0].y;
    // t[nb_t].coord[0].x = point.x;
    // t[nb_t].coord[0].y = point.y;

	printf("dx = %d && dy = %d\n", dx, dy);
    while (index < 4)
    {
		printf("truc = %d\n", (t[nb_t].coord[index].y));
        map[(t[nb_t].coord[index].y) + dy][(t[nb_t].coord[index].x) + dx] = t[nb_t].lettre;
        index++;
    }
    return (map);
 }

void	affiche_map(char **map, int size)
 {
	 int i;
	 int j;

	 i = 0;
	 j = 0;
	 while (i < size)
	 {
		 while (j < size)
		 {
			 printf("%c", map[i][j]);
			 j++;
		 }
		 printf("\n");
		 j = 0;
		 i++;
	 }
 }
