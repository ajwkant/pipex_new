/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/19 12:49:55 by akant         #+#    #+#                 */
/*   Updated: 2021/12/17 14:40:19 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_data
{
	char **paths;
	char *working_path;
	char **split;
	char **envp;
	char *cmd;
}		t_data;

int		main(int argc, char **argv, char **envp);

// Make command
void	data_init(t_data *data);
void	make_command(t_data *data, char *errormessage);


// Parse and helperfunctions
char	**strip_command(char *str);
char	**split_after_first_word(char *str, char c);
void	*return_null_and_free(char **split);
int		count_words(char *s, char c);
void	remove_argument_quotes(char **argv);

// Path access
char	*find_path_line(char **envp);
char	**find_paths(char **envp);
char	*check_access(char **paths, char *cmd);

// Error
int		error_return(char *str);

#endif
