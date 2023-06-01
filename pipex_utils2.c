/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuukka <tuukka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:24:39 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/27 11:27:10 by tuukka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	findpath(char **arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i][j])
	{
		if (arr[i][j] == 'P')
			if (arr[i][j + 1] == 'A')
				if (arr[i][j + 2] == 'T')
					if (arr[i][j + 3] == 'H')
						if (arr[i][j + 4] == '=')
							return (i);
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen((char *)s1);
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*getnew(int s1len, int s2len)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (s1len + s2len) + 1);
	if (new == NULL)
		return (NULL);
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		s1l;
	int		s2l;
	int		i;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	new = getnew((s1l = ft_strlen((char *)s1)), (s2l = ft_strlen((char *)s2)));
	if (new == NULL)
		return (NULL);
	while (i < s1l)
	{
		new[i] = s1[i];
		i++;
	}
	while (i < s1l + s2l)
	{
		new[i] = s2[i - s1l];
		i++;
	}
	new[i] = '\0';
	return (new);
}
