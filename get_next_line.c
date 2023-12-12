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

char	*get_next_line(int fd)
{
	char	*str;
	
	fd = f
	read(fd, str, 30);
	
	while(!str)
	{
		write(1, str, 1);
		++str;
	}                                                                      
}

int	main()
{
	int fd;

	fd = fopen("texte.txt", "r");
	get_next_line(fd);
}