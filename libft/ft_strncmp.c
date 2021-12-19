/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/07 20:35:34 by akant         #+#    #+#                 */
/*   Updated: 2021/12/01 18:28:19 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (n - i && ((unsigned char *)str1)[i] == ((unsigned char *)str2)[i]
		&& ((unsigned char *)str2)[i])
	{
		i++;
		if (i == n)
			return (0);
	}
	if (!n)
		return (0);
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}
