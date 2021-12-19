/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 10:33:46 by akant         #+#    #+#                 */
/*   Updated: 2021/12/01 18:29:28 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_this_needle(char *haystack, char *needle, int i)
{
	while (haystack[i] == *needle && *needle)
	{
		i++;
		needle++;
	}
	if (!*needle)
		return (1);
	return (0);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == *needle)
		{
			if (is_this_needle((char *)haystack, (char *)needle, i))
				return ((char *)&(haystack[i]));
		}
		i++;
	}
	return (NULL);
}
