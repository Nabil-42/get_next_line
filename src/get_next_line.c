
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboud <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:19:05 by nabboud           #+#    #+#             */
/*   Updated: 2023/12/12 15:59:44 by nabboud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		searchn(char *str)
{
	int		i;
	int 	k;
	
	k = 0;
	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			++k;
		++i;
	}
	return (k);
}

static char	*exctract(char *str)
{
	static int		i = 0;
	int		j;
	char	*rendu;

	j = 0;
	while (1)
	{
		if (str[i] == '\n')
			{
				rendu = (char *)malloc(sizeof(char) * (j + 1));
				ft_strlcpy(rendu, str+(i-j), j + 1);
				++i;
				break;			
			}
			++i;
			++j;
	}
	return (rendu);
}

static char	*stash(char *str)
{
	static char		*stock;
	static char 	*final;

	if (!final)
	{
		final = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
		ft_strlcpy(final, str, ft_strlen(str) + 1);
	}
	else{
		stock = ft_strjoin(final, str);
		final = stock;
	}
	return (final);
}



 char	*get_next_line(int fd)
{
	static char	*str;
	static char	*buff;
	int		n;
	static int		j = 0;

	n = 0;
	
	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if(!str)
	{
		return(NULL);
	}

	while(1)
	{
		if (j == 0)
		{
			n = read(fd, str, BUFFER_SIZE);
		
			if(n == 0)
				return (NULL);

			buff = stash(str);
			j = searchn(str);
		}
		else{
				--j;
				return (exctract(buff));
		}
	}
	return (NULL);
}

int	main()
{
	int fd;
	int i;

	i = 0;
	fd = open("texte.txt", O_RDONLY);
	printf("la phrase = %s\n", get_next_line(fd));
	printf("la phrase = %s\n", get_next_line(fd));
	printf("la phrase = %s\n", get_next_line(fd));
	printf("la phrase = %s\n", get_next_line(fd));

	close(fd);
}