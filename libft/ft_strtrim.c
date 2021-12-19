/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 20:03:36 by akant         #+#    #+#                 */
/*   Updated: 2021/12/01 18:29:41 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char *set, char c)
{
	while (set && *set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

int	trimmed_size(char *string, char *set)
{
	int	count;
	int	i;
	int	j;

	i = 0;
	j = 0;
	count = 0;
	while (string[i])
	{
		if (!is_in_set(set, string[i]))
		{
			if (count)
				count += j;
			j = 0;
			count++;
		}
		else
			j++;
		i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	int		i;
	int		size;

	i = 0;
	if (!s1)
		return (NULL);
	size = trimmed_size((char *)s1, (char *)set);
	while (is_in_set((char *)set, s1[i]))
		i++;
	string = ft_substr(s1, i, size);
	return (string);
}
