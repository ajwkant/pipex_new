/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/18 14:37:28 by akant         #+#    #+#                 */
/*   Updated: 2021/12/17 14:41:20 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_child(int fd, char *cmd, int *pip, char **envp)
{
	t_data	data;

	close(pip[0]);
	dup2(pip[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pip[1]);
	close(fd);
	data_init(&data);
	data.envp = envp;
	data.cmd = cmd;
	make_command(&data, "First command not found\n");
	execve(data.working_path, data.split, envp);
	perror("Error na execve in first child.\n");
	exit(EXIT_FAILURE);
}

void	middle_child(char *cmd, int *pip, int read_end, char **envp)
{
	t_data	data;

	dup2(read_end, STDIN_FILENO);
	dup2(pip[1], STDOUT_FILENO);
	close(pip[0]);
	close(read_end);
	data_init(&data);
	data.envp = envp;
	data.cmd = cmd;
	make_command(&data, "Middle command not found\n");
	execve(data.working_path, data.split, envp);
	perror("Error na execve in middle child.\n");
	exit(EXIT_FAILURE);
}

void	last_child(int fd, char *cmd, int read_end, char **envp)
{
	t_data	data;

	dup2(read_end, STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	close(read_end);
	data_init(&data);
	data.envp = envp;
	data.cmd = cmd;
	make_command(&data, "Last command not found\n");
	execve(data.working_path, data.split, envp);
	perror("Error na execve in last child.\n");
	exit(EXIT_FAILURE);
}

int	pipex(int *fd, char **argv, int argc, char **envp)
{
	int		pip[2];
	int		read_end;
	int		pipe_no;
	pid_t	child;

	pipe_no = 0;
	while (pipe_no < argc - 3)
	{
		if (pipe_no != argc - 4 && pipe(pip) == -1)
			return (error_return("Pipe: \n"));
		child = fork();
		if (child < 0)
			return (error_return("Forking: \n"));
		if (pipe_no == 0 && child == 0)
			first_child(fd[0], argv[2], pip, envp);
		else if (child == 0 && pipe_no < argc - 4)
			middle_child(argv[pipe_no + 2], pip, read_end, envp);
		else if (pipe_no == argc - 4 && child == 0)
			last_child(fd[1], argv[pipe_no + 2], read_end, envp);
		pipe_no++;
		read_end = pip[0];
		close(pip[1]);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	return_value;
	int	fd[2];

	if (argc < 5)
		return (error_return("Error: A minimal of 5 arguments needed.\n"));
	fd[0] = open(argv[1], O_RDONLY);
	if (fd[0] == -1)
		return (error_return("Error: opening inputfile failed.\n"));
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT, 00644);
	if (fd[1] == -1)
		return (error_return("Error: opening outputfile failed.\n"));
	return_value = pipex(fd, argv, argc, envp);
	while (wait(0) != -1)
		;
	return (return_value);
}
