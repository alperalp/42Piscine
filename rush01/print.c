/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalp <aalp@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:52:07 by aalp              #+#    #+#             */
/*   Updated: 2023/07/23 17:52:10 by aalp             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_grid(int arr[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = arr[i][j] + 48;
			ft_putchar(c);
			if (j != 3)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_row(int row[4])
{
	int	i;

	i = 0;
	ft_putchar('[');
	while (i < 4)
	{
		ft_putchar(row[i] + 48);
		if (i != 3)
		{
			ft_putchar(',');
		}
		i++;
	}
	ft_putchar(']');
}
