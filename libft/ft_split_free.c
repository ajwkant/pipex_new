/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_free.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/13 15:55:21 by akant         #+#    #+#                 */
/*   Updated: 2021/12/01 18:25:16 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_split_free(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	if (split)
		free(split);
}
