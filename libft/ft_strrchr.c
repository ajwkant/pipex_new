/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 17:11:29 by akant         #+#    #+#                 */
/*   Updated: 2021/12/01 18:28:52 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*save_pointer;

	save_pointer = 0;
	if (!*str && c == 0)
		return ((char *)str);
	while (*str || *str == (unsigned char)c)
	{
		if (*str == (unsigned char)c)
		{
			if (*str == '\0')
				return ((char *)str);
			save_pointer = (char *)str;
		}
		str++;
	}
	return (save_pointer);
}
