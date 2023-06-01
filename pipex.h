/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuukka <tuukka@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:35:15 by ttikanoj          #+#    #+#             */
/*   Updated: 2023/02/02 17:07:08 by ttikanoj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/stat.h>

typedef struct s_cmd
{
	char		*pathcmd;
	char		**cmd;
	char		**patharr;
}				t_cmd;

int			main(int argc, char **argv, char **env);
void		mainhelper(t_cmd **cmd1, t_cmd **cmd2, char **argv, char **envp);
void		freearray(char **arr);
void		doublefree(t_cmd *cmd1, t_cmd *cmd2);
void		freehelper(t_cmd *cmd);
void		getcommands1(t_cmd *cmd1, t_cmd *cmd2, char **argv, char **envp);
void		getcommands2(t_cmd *cmd1, t_cmd *cmd2, char **argv, char **envp);
int			findpath(char **arr);
char		*getpath(char **patharr, char *pathcmd, char *cmd, int j);
void		child1(int *pipefd, t_cmd cmd1, char **argv, char **envp);
void		child2(int *pipefd, t_cmd cmd2, char **argv, char **envp);
void		mallocerror(char *msg, t_cmd cmd1, t_cmd cmd2);
void		cmderror(t_cmd *cmd1);
void		exitmsg(char *msg);
char		*getnew(int s1len, int s2len);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *str);
char		*ft_strdup(const char *s1);
int			wordlen(char *dup, char c);
char		**getarray(char *dup, char c, int wcount);
int			wordcount(const char *s, char c);
char		**fillarr(char **arr, const char *s, char c, int wcount);
char		**ft_split(char const *s, char c);
int			emptycheck(char **argv, int i);
int			spacecheck(char *cmd);
int			wordlen_p(char *dup, char c, int len);
char		**createempty_p(char **arr);
char		**getarray_p(char *dup, char c, int wcount);
int			wordcount_p(const char *s, char c);
char		**fillarr_p(char **arr, const char *s, char c, int wcount);
char		**ft_split_p(char const *s, char c);
int			findstring(char *str);
void		fillhelper(char *arr, int *b, size_t *i, char *c);
int			fillhelper2(const char *s, size_t *i, char *c);

#endif
