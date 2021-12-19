/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/26 10:33:29 by akant         #+#    #+#                 */
/*   Updated: 2021/12/01 17:57:33 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_in_str(int n, char *string, int digits, int neg)
{
	int	i;

	i = 0;
	if (n == -0)
	{
		string[0] = '0';
		string[1] = '\0';
		return (string);
	}
	if (neg == -1)
		string[0] = '-';
	while (n)
	{
		string[digits - i - 1] = n % 10 * neg + '0';
		n /= 10;
		i++;
	}
	return (string);
}

char	*ft_itoa(int n)
{
	int		digits;
	int		num;
	char	*string;
	int		neg;

	digits = 0;
	neg = 1;
	if (n < 0)
	{
		digits++;
		neg = -1;
	}
	num = n;
	while (num != 0)
	{
		digits++;
		num /= 10;
	}
	if (n == -0)
		digits = 1;
	string = ft_calloc(digits + 1, sizeof(char));
	if (!string)
		return (NULL);
	return (fill_in_str(n, string, digits, neg));
}
