/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day01-pt1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 09:25:21 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/03 17:38:33 by lmmielgo         ###   ########.fr       */
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