/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:32:19 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/02/02 17:08:17 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	spacecheck(char *cmd)
{
	int	ret;
	int	i;

	ret = 1;
	i = 0;
	while (cmd[i] == ' ')
		i++;
	if (!cmd[i])
		return (0);
	else
		return (1);
}

int	emptycheckhelper(char **argv, int i)
{
	if (ft_strlen(argv[2]) == 0)
	{
		write(2, "zsh: permission denied:\n", 24);
		i = 1;
	}
	else if (spacecheck(argv[2]) == 0)
	{
		write(2, "zsh: command not found:\n", 24);
		i = 1;
	}
	if (ft_strlen(argv[3]) == 0)
	{
		write(2, "zsh: permission denied:\n", 24);
		i = 1;
	}
	else if (spacecheck(argv[3]) == 0)
	{
		write(2, "zsh: command not found:\n", 24);
		i = 1;
	}
	return (i);
}

int	emptycheck(char **argv, int i)
{
	int	writefd;

	i = emptycheckhelper(argv, i);
	if (i == 1)
	{
		writefd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		close(writefd);
	}
	return (i);
}
