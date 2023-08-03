/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalp <aalp@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:44:04 by aalp              #+#    #+#             */
/*   Updated: 2023/07/19 17:25:38 by aalp             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	check_ucase(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int	check_lcase(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int	check_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	check_alpha_numeric(char c)
{
	if (check_ucase(c) || check_lcase(c) || check_numeric(c))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char	*str)
{
	char	c;
	int		current;
	int		last;

	current = 1;
	if (str[0] != '\0' && check_lcase(str[0]))
		str[0] -= 32;
	while (str[current] != '\0')
	{
		last = current - 1;
		if (!(check_alpha_numeric(str[last])))
		{
			c = str[current];
			if (check_lcase(c))
				str[current] -= 32;
		}
		else
		{
			c = str[current];
			if (check_ucase(c))
				str[current] += 32;
		}
		current++;
	}
	return (str);
}
