/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_command.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/17 14:11:52 by akant         #+#    #+#                 */
/*   Updated: 2021/12/17 14:25:40 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	data_init(t_data *data)
{
	data->paths = NULL;
	data->working_path = NULL;
	data->split = NULL;
	data->envp = NULL;
	data->cmd = NULL;
}

void	make_command(t_data *data, char *errormessage)
{
	data->split = strip_command(data->cmd);
	if (data->split == NULL)
		exit(EXIT_FAILURE);
	if (access(data->split[0], X_OK == -1))
	{
		data->paths = find_paths(data->envp);
		data->working_path = check_access(data->paths, data->split[0]);
		ft_split_free(data->paths);
		if (!data->working_path)
		{
			perror(errormessage);
			exit(127);
		}
	}
	else
		data->working_path = data->split[0];
}
