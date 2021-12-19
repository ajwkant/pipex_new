/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 17:03:17 by akant         #+#    #+#                 */
/*   Updated: 2021/12/01 17:59:29 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t	i;

	i = 0;
	while (n - i && ((unsigned char *) str1)[i] == ((unsigned char *) str2)[i])
	{
		i++;
		if (i == n)
			return (0);
	}
	if (!n)
		return (0);
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}
