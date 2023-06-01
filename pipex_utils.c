/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuukka <tuukka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:23:57 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/02/01 15:50:32 by tuukka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	getcommands1(t_cmd *cmd1, t_cmd *cmd2, char **argv, char **envp)
{
	int	i;
	int	j;

	j = 0;
	i = findpath(envp);
	if (i == 0)
		exitmsg("path not found\n");
	if (findstring(argv[2]) == 1)
		cmd1->cmd = ft_split_p(argv[2], ' ');
	else
		cmd1->cmd = ft_split(argv[2], ' ');
	cmd1->patharr = ft_split(envp[i] + 5, ':');
	if (cmd1->cmd == NULL || cmd1->patharr == NULL)
		mallocerror("1st cmd/patharr malloc fail", *cmd1, *cmd2);
	cmd1->pathcmd = getpath(cmd1->patharr, cmd1->pathcmd, cmd1->cmd[0], j);
	if (cmd1->pathcmd == NULL)
		cmderror(cmd1);
}

void	getcommands2(t_cmd *cmd1, t_cmd *cmd2, char **argv, char **envp)
{
	int	i;
	int	j;

	j = 0;
	i = findpath(envp);
	if (i == 0)
		exitmsg("path not found\n");
	if (findstring(argv[3]) == 1)
		cmd2->cmd = ft_split_p(argv[3], ' ');
	else
		cmd2->cmd = ft_split(argv[3], ' ');
	cmd2->patharr = ft_split(envp[i] + 5, ':');
	if (cmd2->cmd == NULL || cmd2->patharr == NULL)
		mallocerror("2nd cmd/patharr malloc fail", *cmd1, *cmd2);
	cmd2->pathcmd = getpath(cmd2->patharr, cmd2->pathcmd, cmd2->cmd[0], j);
	if (cmd2->pathcmd == NULL)
		cmderror(cmd2);
}

char	*getpath(char **patharr, char *pathcmd, char *cmd, int j)
{
	char	*tmp;

	if (access(cmd, F_OK) == 0)
	{
		pathcmd = ft_strdup(cmd);
		return (pathcmd);
	}
	while (patharr[j])
	{
		tmp = ft_strjoin(patharr[j], "/");
		pathcmd = ft_strjoin(tmp, cmd);
		if (access(pathcmd, F_OK) == 0)
			break ;
		else
		{
			free(tmp);
			free(pathcmd);
			j++;
		}
		if (!patharr[j])
			return (NULL);
	}
	free(tmp);
	return (pathcmd);
}

void	child1(int *pipefd, t_cmd cmd1, char **argv, char **envp)
{
	int		readfd;

	close (pipefd[0]);
	readfd = open(argv[1], O_RDONLY);
	if (readfd < 0)
		exit(EXIT_FAILURE);
	dup2(pipefd[1], STDOUT_FILENO);
	close (pipefd[1]);
	dup2(readfd, STDIN_FILENO);
	close (readfd);
	execve(cmd1.pathcmd, cmd1.cmd, envp);
	exit(EXIT_FAILURE);
}

void	child2(int *pipefd, t_cmd cmd2, char **argv, char **envp)
{
	int		writefd;

	writefd = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (writefd < 0)
		exitmsg("outfile open");
	dup2(writefd, STDOUT_FILENO);
	close(writefd);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	execve(cmd2.pathcmd, cmd2.cmd, envp);
	exit(EXIT_FAILURE);
}
