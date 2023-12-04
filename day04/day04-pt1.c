/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day04-pt1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciama2 <luciama2@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:09:54 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/04 11:09:56 by luciama2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include "../ft_get_next_line/get_next_line.h"

int powerb2(int count)
{
	int b = 2;
	int rslt = 1; 

	//printf("COUNT: %d\n", count);
	while (--count > 0)
		rslt *= b; //exp == count - 1
	return (rslt);
}

int istrchr(char *s, char c)
{
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	getlinepts(char  *line)
{
	int count = 0;
	int winnbr[10];
	int nbr[25];
	int i;
	int j;

	//add winning nbrs to arr
	i = 0;
	j = istrchr(line, '|') - 3;
	while (i < 10)
	{
		if (isdigit(line[j]) != 0)
		{
			winnbr[i] = (line[j] - '0') * 10;
			winnbr[i] += (line[j + 1] - '0');
		}
		else
			winnbr[i] = (line[j + 1] - '0');
		j -= 3;
		i++;
	}
	
	//add nbrs to arr
	i = 0;
	j = istrchr(line, '|') + 2;
	while (i < 25)
	{
		if (isdigit(line[j]) != 0)
		{
			nbr[i] = (line[j] - '0') * 10;
			nbr[i] += (line[j + 1] - '0');
		}
		else
			nbr[i] = (line[j + 1] - '0');
		j += 3;
		i++;
	}

	//compare arrays and get pts
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 25)
		{
			if (winnbr[i] == nbr[j])
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (0);
	return (powerb2(count));	
}

int main(void)
{
	int		fd;
	char	*gnl;
	//DAY04
	int 	pts;
	int		sumpts = 0;

	fd = open("puzzle-input", O_RDONLY);
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		//do things
		pts = getlinepts(gnl);
		sumpts += pts;
		//printf("LINEPTS: %d\n", pts);
		//done things
		free(gnl);
	}
	close(fd);
	printf("TOTAL: %d\n", sumpts);
	return (0);
}