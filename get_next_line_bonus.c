/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrajabia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:29:35 by nrajabia          #+#    #+#             */
/*   Updated: 2023/03/13 09:43:24 by nrajabia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
//#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE +1];
	char		*line;
	int			num;

	if (BUFFER_SIZE < 1 || fd == -1 || FOPEN_MAX < fd)
		return (NULL);
	line = ft_strjoin(0, buff[fd]);
	if (shift_line(buff[fd]))
		return (line);
	num = read(fd, buff[fd], BUFFER_SIZE);
	if (num < 0)
	{
		free(line);
		return (NULL);
	}
	while (num > 0)
	{
		line = ft_strjoin(line, buff[fd]);
		if (shift_line(buff[fd]))
			break ;
		num = read(fd, buff[fd], BUFFER_SIZE);
	}
	return (line);
}

/*int main(void)
{
    int x;
	int y;

    x = open("accept.txt", O_RDONLY);
	y = open("test.txt", O_RDONLY);
    printf("x 1: %s", get_next_line(x));
    printf("y 1: %s", get_next_line(y));
    printf("x 2: %s", get_next_line(x));
    printf("y 2: %s", get_next_line(y));
    //printf("y 2: %s", get_next_line(y));
    //printf("y 3: %s", get_next_line(y));
    //printf("x 4: %s", get_next_line(x));

    close(x);
	close(y);
    return (0);
}*/
