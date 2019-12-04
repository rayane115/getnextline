/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rqouchic <rayane.qouchich@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:52:12 by rqouchic          #+#    #+#             */
/*   Updated: 2019/11/29 17:31:01 by rqouchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
	int fd;
	int ret;
	int line;
	char *buff;

	line = 0;
	fd = open("test/64_line_nl", O_RDWR);
	while ((ret = get_next_line(fd, &buff)) > 0)
	{
		printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
		if (buff)
			free(buff);
	}
	printf("[Return: %d] Line #%d: %s\n", ret, ++line, buff);
	if (ret == -1)
		printf("-----------\nError\n\n");
	else if (ret == 0)
		printf("-----------\nEnd of file\n\n");
		close(fd);
	system("leaks a.out");
	return (0);
}
