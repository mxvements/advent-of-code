/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day03-part1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:15:52 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/03 22:26:06 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include "../ft_get_next_line/get_next_line.h"

int main(void)
{
	//READ FILE
	int	fd;
	char *gnl;
	
	fd = open("puzzle-input", O_RDONLY);

	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		//do things

		
		//done things
		free(gnl);
	}
	close(fd);	
	return (0);
}
