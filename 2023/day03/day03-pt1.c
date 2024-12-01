/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   day03-pt1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmmielgo <lmmielgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 22:15:52 by luciama2          #+#    #+#             */
/*   Updated: 2023/12/04 00:33:27 by lmmielgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <ctype.h>
#include <string.h>
#include "../ft_get_next_line/get_next_line.h"

int	issymbol(char c)
{
	if (isprint(c) != 0)
	{
		if (isdigit(c) == 0 && c != '.')
			return (1); //true, not digit and not '.'
	}
	return (0);
}

int	getnbr(char **text, int i, int j)
{
	int nbr = 0;

	while (isdigit(text[i][j]) != 0)
		j--;
	while (isdigit(text[i][++j]))
	{
		nbr *= 10;
		nbr += text[i][j] - '0';
	}
	printf("%d\n", nbr);
	return (nbr);
}

int main(void)
{
	//READ FILE
	int	fd;
	char *gnl;
	//DAY03
	char **text;
	int i;
	int j;

	text = (char **)malloc(sizeof(char *) * (140 + 1));
	if (!text)
		return (0);
	text[140] = '\0';
	
	fd = open("puzzle-input", O_RDONLY);
	i = 0;
	while (1)
	{
		gnl = get_next_line(fd);
		if (gnl == NULL)
			break ;
		//do things
		text[i] = gnl;
		i++;
		//done things
		//free(gnl);
	}
	text[i] = NULL;
	close(fd);

	//FIND NUMBERS SURROUNDED BY SYMBOLS
	i = 0;
	int sum = 0;
	int prev = 0;
	int curr = 0;
	while (text[i] != NULL)
	{
		j = 0;
		while (text[i][j] != '\0')
		{
			if (issymbol(text[i][j]) != 0)
			{
				if (text[i - 1] != NULL)
				{
					if (isdigit(text[i - 1][j - 1]) != 0)
					{ 
						curr = getnbr(text, i - 1, j - 1);
						if (curr != prev)
						{
							prev = curr;
							sum += prev;
						}
						
					}
					if (isdigit(text[i - 1][j]) != 0)
					{
						curr = getnbr(text, i - 1, j);
						if (curr != prev)
						{
							prev = curr;
							sum += prev;
						}
					}
					if (isdigit(text[i - 1][j + 1]) != 0)
					{
						curr = getnbr(text, i - 1, j + 1);
						if (curr != prev)
						{
							prev = curr;
							sum += prev;
						}
					}
				}
				if(text[i] != NULL)
				{
					if (isdigit(text[i][j - 1]) != 0)
					{
						curr = getnbr(text, i, j - 1);
						if (curr != prev)
						{
							prev = curr;
							sum += prev;
						}
					}
					if (isdigit(text[i][j + 1]) != 0)
					{
						curr = getnbr(text, i, j + 1);
						if (curr != prev)
						{
							prev = curr;
							sum += prev;
						}
					}
				}
				if (text[i + 1] != NULL)
				{
					if (isdigit(text[i + 1][j - 1]) != 0)
					{
						curr = getnbr(text, i + 1, j - 1);
						if (curr != prev)
						{
							prev = curr;
							sum += prev;
						}
					}
					if (isdigit(text[i + 1][j]) != 0)
					{
						curr = getnbr(text, i + 1, j);
						if (curr != prev)
						{
							prev = curr;
							sum += prev;
						}
					}
					if (isdigit(text[i + 1][j + 1]) != 0)
					{
						curr = getnbr(text, i + 1, j + 1);
						if (curr != prev)
						{
							prev = curr;
							sum += prev;
						}
					}
				}
			}
			//printf("%d\n", sum);
			j++;
		}
		i++;
	}
	printf("%d\n", sum);
	return (0);
}
