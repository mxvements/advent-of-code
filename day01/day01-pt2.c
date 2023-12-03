/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day01-pt2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 09:25:21 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/03 19:28:07 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include "./gnl/get_next_line.h"

void	arrbzero(int nbr[], int len)
{
	int	i;

	i = 0;
	while (i <= len)
		nbr[i++] = 0;
	return ;
}

int		checkstrnbr(char *s, int i)
{
	char *numbers[10] = {
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine"
	};

	if (strncmp((s + i), numbers[1], 3) == 0)
		return (1);
	if (strncmp((s + i), numbers[2], 3) == 0)
		return (2);
	if (strncmp((s + i), numbers[3], 5) == 0)
		return (3);
	if (strncmp((s + i), numbers[4], 4) == 0)
		return (4);
	if (strncmp((s + i), numbers[5], 4) == 0)
		return (5);
	if (strncmp((s + i), numbers[6], 3) == 0)
		return (6);
	if (strncmp((s + i), numbers[7], 5) == 0)
		return (7);
	if (strncmp((s + i), numbers[8], 5) == 0)
		return ( 8);
	if (strncmp((s + i), numbers[9], 4) == 0)
		return (9);

	return (0);
}

int	getfirstnum(char *gnl, int nbr)
{
	int	i = 0;
	
	while (gnl[i] != '\0')
	{
		if (isdigit(gnl[i]) != 0)
		{
			nbr = (gnl[i] - '0');
			break;
		}
		if (checkstrnbr(gnl, i) != 0)
		{
			nbr = checkstrnbr(gnl, i);
			break;
		}
		i++;			
	}
	return (nbr);
}

int	getlastnum(char *gnl, int nbr)
{
	int i = strlen(gnl);
	
	while (i >= 0)
	{
		if (isdigit(gnl[i]) != 0)
		{
			nbr *= 10;
			nbr += (gnl[i] - '0');
			break;
		}
		if (checkstrnbr(gnl, i) != 0)
		{
			nbr *= 10;
			nbr += checkstrnbr(gnl, i);
			break;
		}
		i--;
	}
	return (nbr);
}

int	gettotalsum(int nbr[], int len)
{
	int sum = 0;
	int i = 0;
	
	while (i < len)
	{
		sum += nbr[i];
		i++;
	}
	return (sum);
}

int	main(void)
{
	int		fd;
	int		len = 1000;
	int		nbr[len];
	char	*gnl;
	int		i;
	int		sum;

	fd = open("puzzle-input", O_RDONLY);

	i = 0;
	arrbzero(nbr, len);
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		nbr[i] = getfirstnum(gnl, nbr[i]);
		nbr[i] = getlastnum(gnl, nbr[i]);		
		i++;		
		free(gnl);
	}
	sum = gettotalsum(nbr, len);
	printf("sum: %d\n", sum);	
	close(fd);	
	return (0);
}