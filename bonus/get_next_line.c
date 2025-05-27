/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:56:33 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 21:59:48 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *backup)
{
	size_t	i;
	char	*line;

	if (backup == NULL || backup[0] == '\0')
		return (NULL);
	i = 0;
	while (backup[i] != '\n' && backup[i])
		i++;
	line = ft_substr(backup, 0, i);
	return (line);
}

static char	*make_new_backup(char *backup)
{
	size_t	i;
	size_t	len;
	char	*new_backup;

	if (backup == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(backup);
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		i++;
	new_backup = ft_substr(backup, i, len - i);
	free(backup);
	return (new_backup);
}

static char	*read_file(int fd, char *backup)
{
	int		read_rtn;
	char	*buf;

	read_rtn = 1;
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (buf == NULL)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	while (read_rtn != 0 && !ft_strchr(backup, '\n'))
	{
		read_rtn = read(fd, buf, BUFFER_SIZE);
		if (read_rtn == -1)
		{
			free(backup);
			free(buf);
			return (NULL);
		}
		buf[read_rtn] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	free(buf);
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_file(fd, backup);
	line = extract_line(backup);
	if (line == NULL || line[0] == '\0')
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = make_new_backup(backup);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
// 	char	*line;
// 	//int		fd;

// 	//fd = open("test.txt", O_RDONLY);
// 	while ((line = get_next_line(0)) != NULL)
// 	{
// 		printf("%s\n", line);
// 		free(line);
// 	}
// }