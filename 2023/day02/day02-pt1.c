/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day02-pt1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 19:33:59 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/03 21:40:41 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include "../ft_get_next_line/get_next_line.h"

int	main(void)
{	
	//READ FILE
	int	fd;
	char *gnl;
	//RGB MAX
	int	redmax = 12;
	int	greenmax = 13;
	int	bluemax = 14;
	//RGB IN LINE
	int red = 0;
	int green = 0;
	int blue = 0;
	//SUM OF POSSIBLE LINES
	int	id = 0;
	int possibles = 0;
	//
	int i;
	

	fd = open("puzzle-input", O_RDONLY);

	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		//do things

		id++;
		i = 0;
		
		red = 0;
		green = 0;
		blue = 0;
		while (gnl[++i] != '\0')
		{
			//reset data on red, green and blue cubes
			if (gnl[i] == ';')
			{
				red = 0;
				green = 0;
				blue = 0;
			}
			
			//red
			if (gnl[i] == 'r' && gnl[i - 1] == ' ')
			{
				if (isdigit(gnl[i - 2]) != 0)
					red += gnl[i - 2] - '0';
				if (isdigit(gnl[i - 3]) != 0)
					red += ((gnl[i - 3] - '0') * 10);
			}
			//green
			if (gnl[i] == 'g' && gnl[i - 1] == ' ')
			{
				if (isdigit(gnl[i - 2]) != 0)
					green += gnl[i - 2] - '0';
				if (isdigit(gnl[i - 3]) != 0)
					green += ((gnl[i - 3] - '0') * 10);
			}
			//blue
			if (gnl[i] == 'b' && gnl[i - 1] == ' ')
			{
				if (isdigit(gnl[i - 2]) != 0)
					blue += gnl[i - 2] - '0';
				if (isdigit(gnl[i - 3]) != 0)
					blue += ((gnl[i - 3] - '0') * 10);
			}

			//if any of the numbers is > to the limit, break loop on line
			if (red > redmax || green > greenmax || blue > bluemax)
				break;

			//if next is EOL, then the game is possible
			if (gnl[i + 1] == '\0')
			{
				possibles += id;
				break;
			}
		}
		
		//done things
		free(gnl);
	}
	close(fd);

	printf("%d\n", possibles);
	
	return (0);
}