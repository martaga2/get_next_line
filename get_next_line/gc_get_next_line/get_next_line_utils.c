/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martaga2 <martaga2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:51:31 by martaga2          #+#    #+#             */
/*   Updated: 2024/05/09 10:15:00 by martaga2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// para localizar el caracter salto de página en las líneas
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (0);
}

//para saber la longitud
int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

//para unir lo que nos quedó de una línea con la siguiente
char	*ft_strjoin(char *s1, char *s2)
{
	char		*completed;
	size_t		i;
	size_t		j;

	if (!s1 || !s2)
		return (NULL);
	completed = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!completed)
		return (NULL);
	i = -1;
	while (s1[++i])
		completed[i] = s1[i];
	j = -1;
	while (s2[++j])
		completed[i + j] = s2[j];
	completed[i + j] = '\0';
	free(s1);
	return (completed);
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;

	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
