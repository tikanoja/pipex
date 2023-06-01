/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuukka <tuukka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:27:32 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/02/02 17:11:28 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	freehelper(t_cmd *cmd)
{
	int	i;

	i = 0;
	free(cmd->pathcmd);
	while (cmd->cmd[i])
	{
		free(cmd->cmd[i]);
		i++;
	}
	free(cmd->cmd);
	i = 0;
	while (cmd->patharr[i])
	{
		free(cmd->patharr[i]);
		i++;
	}
	free(cmd->patharr);
	free(cmd);
}

void	doublefree(t_cmd *cmd1, t_cmd *cmd2)
{
	int	i;

	i = 0;
	free(cmd1->pathcmd);
	while (cmd1->cmd[i])
	{
		free(cmd1->cmd[i]);
		i++;
	}
	free(cmd1->cmd);
	i = 0;
	while (cmd1->patharr[i])
	{
		free(cmd1->patharr[i]);
		i++;
	}
	free(cmd1->patharr);
	free(cmd1);
	freehelper(cmd2);
}

void	mainhelper(t_cmd **cmd1, t_cmd **cmd2, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid[2];

	getcommands1(*cmd1, *cmd2, argv, envp);
	getcommands2(*cmd1, *cmd2, argv, envp);
	if (pipe(pipefd) == -1)
		exitmsg("pipe fail\n");
	pid[0] = fork();
	if (pid[0] == -1)
		exitmsg("fork fail\n");
	else if (pid[0] == 0)
		child1(pipefd, **cmd1, argv, envp);
	close (pipefd[1]);
	pid[1] = fork();
	if (pid[1] == -1)
		exitmsg("fork fail\n");
	else if (pid[1] == 0)
		child2(pipefd, **cmd2, argv, envp);
	close (pipefd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	int		i;

	i = 0;
	if (argc < 5)
	{
		write(2, "missing arg\n", 12);
		return (1);
	}
	if (emptycheck(argv, i) == 1)
		return (1);
	cmd1 = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd1)
		return (1);
	cmd2 = (t_cmd *)malloc(sizeof(t_cmd));
	if (!cmd2)
	{
		free(cmd1);
		return (1);
	}
	mainhelper(&cmd1, &cmd2, argv, envp);
	doublefree(cmd1, cmd2);
	return (0);
}
