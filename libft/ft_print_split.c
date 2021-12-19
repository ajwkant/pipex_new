/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_split.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/21 14:21:04 by akant         #+#    #+#                 */
/*   Updated: 2021/12/01 18:23:52 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_split(char **split, int indexed)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		if (indexed)
			printf("split[%d]: %s\n", i, split[i]);
		else
			printf("%s\n", split[i]);
		i++;
	}
}
