/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 17:11:49 by akant         #+#    #+#                 */
/*   Updated: 2021/12/01 18:25:03 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_splits(char *s, char c)
{
	int	size;
	int	boolean;

	size = 0;
	boolean = 1;
	while (*s)
	{
		if (*s != c)
		{
			if (boolean)
				size++;
			boolean = 0;
		}
		else
			boolean = 1;
		s++;
	}
	if (!size)
		return (1);
	return (size);
}

char	*fill_in(char *array, char *s, char delim)
{
	int	i;

	i = 0;
	while (s[i] != delim && s[i] != '\0')
		i++;
	array = ft_calloc(i + 1, sizeof(char));
	if (!array)
		return (NULL);
	i = 0;
	while (s[i] != delim && s[i] != '\0')
	{
		array[i] = s[i];
		i++;
	}
	return (array);
}

int	split_string(char **array, char *s, char c)
{
	int	boolean;
	int	i;

	boolean = 1;
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (boolean)
			{
				array[i] = fill_in(array[i], s, c);
				if (!array[i])
					return (i);
				i++;
			}
			boolean = 0;
		}
		else
			boolean = 1;
		s++;
	}
	return (0);
}

void	free_array(char **array, int i)
{
	while (i)
	{
		i--;
		free(array[i]);
		if (!i)
		{
			free(array);
			return ;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	if (!s)
		return (NULL);
	array = ft_calloc(count_splits((char *)s, c) + 1, sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	i = split_string(array, (char *)s, c);
	free_array(array, i);
	return (array);
}
