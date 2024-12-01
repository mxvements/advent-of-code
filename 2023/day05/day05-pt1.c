/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day05-pt1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:02:04 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/05 12:37:28 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include "../ft_get_next_line/get_next_line.h"

int main(void)
{
	int		fd;
	char	*gnl;
	//DAY05

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