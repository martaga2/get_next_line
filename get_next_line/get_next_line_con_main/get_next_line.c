/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martaga2 <martaga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:55:34 by martaga2          #+#    #+#             */
/*   Updated: 2024/05/09 12:43:24 by martaga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_error(char *final)
{
	free(final);
	final = NULL;
	return (NULL);
}

char	*ft_read(char *final, int fd)
{
	char	tmp[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = BUFFER_SIZE;
	tmp[0] = '\0';
	while (!ft_strchr(tmp, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, tmp, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_error(final));
		tmp[bytes_read] = '\0';
		if (bytes_read == 0 && (!final || !*final))
			return (free_error(final));
		else if (final == NULL)
			final = ft_strdup(tmp);
		else
			final = ft_strjoin(final, tmp);
	}
	return (final);
}

char	*ft_search(char *text)
{
	int		i;
	int		j;
	char	*last_str;

	i = 0;
	j = 0;
	if (!text)
		return (NULL);
	while (text[i] != '\n' && text[i])
		i++;
	if (!text[i])
		return (NULL);
	last_str = malloc((ft_strlen(text) + 1) * sizeof(char));
	if (!last_str)
		return (NULL);
	if (text[i])
		i++;
	while (text[i])
		last_str[j++] = text[i++];
	last_str[j] = '\0';
	free(text);
	return (last_str);
}

// take line for return
char	*ft_line(char *text)
{
	char	*line;
	int		i;

	i = 0;
	if (!text)
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\0')
	{
		return (text);
	}
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (text[i] && text[i] != '\n')
	{
		line[i] = text[i];
		i++;
	}
	if (text[i] && text[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*final;
	char		*new_text;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	final = ft_read(final, fd);
	if (!final)
		return (NULL);
	new_text = ft_line(final);
	if (final)
		final = ft_search(final);
	return (new_text);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*line;

// 	//atexit(ft_leaks);
// 	fd = open("read_error.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Error al abrir el archivo\n");
// 		return (1);
// 	}
// 	line = get_next_line(fd);
// 	printf("%s", line);
// 	while ((line != NULL) && (*line != '\0'))
// 	{
// 	//	printf("Read:%s \n", line);
// 		free(line);
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }
