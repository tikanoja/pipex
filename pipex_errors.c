/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttikanoj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:33:51 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/01/28 13:37:57 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	cmderror(t_cmd *cmd)
{
	write(STDERR_FILENO, "command not found\n", 18);
}

void	exitmsg(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	freearray(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	mallocerror(char *msg, t_cmd cmd1, t_cmd cmd2)
{
	if (msg[0] == '1')
	{
		perror(msg);
		if (cmd1.cmd != NULL)
			freearray(cmd1.cmd);
		if (cmd1.patharr != NULL)
			freearray(cmd1.patharr);
	}
	if (msg[0] == '2')
	{
		perror(msg);
		freehelper(&cmd1);
		if (cmd2.cmd != NULL)
			freearray(cmd2.cmd);
		if (cmd2.patharr != NULL)
			freearray(cmd2.patharr);
	}
	exit(EXIT_FAILURE);
}
