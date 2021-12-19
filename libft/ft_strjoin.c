/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 17:07:39 by akant         #+#    #+#                 */
/*   Updated: 2021/10/24 11:56:12 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		total_length;
	char	*string;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	total_length = (int)(ft_strlen(s1) + ft_strlen(s2));
	string = ft_calloc((total_length + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	while (i < total_length && *s1)
	{
		string[i] = *s1;
		s1++;
		i++;
	}
	while (i < total_length && *s2)
	{
		string[i] = *s2;
		s2++;
		i++;
	}
	return (string);
}
