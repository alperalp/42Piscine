/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalp <aalp@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:20:03 by aalp              #+#    #+#             */
/*   Updated: 2023/07/16 13:09:15 by aalp             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putout(int n, int	*arr)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(arr[i] + '0');
		i++;
	}
}

void	ft_increment_rank(int n, int	*arr)
{
	int	i;
	int	max;

	i = n - 1;
	max = 9;
	while (arr[i] == max)
	{
		i -= 1;
		max -= 1;
	}
	arr[i] += 1;
	while (i < n)
	{
		arr[i + 1] = arr[i] + 1;
		i++;
	}
}

void	ft_increment_loop(int n, int	*arr)
{
	while (arr[0] != 10 - n || arr[n - 1] != 9)
	{
		if (arr[n - 1] != 9)
		{
			arr[n - 1] += 1;
		}
		else
		{
			ft_increment_rank(n, arr);
		}
		ft_putout(n, arr);
		if (arr[0] != 10 - n || arr[n - 1] != 9)
			write(1, ", ", 2);
	}
}

void	ft_print_combn(int n)
{
	int	arr[9];
	int	i;
	int	l;

	i = 0;
	while (i < n)
	{
		arr[i] = i;
		i++;
	}
	ft_putout(n, arr);
	write(1, ", ", 2);
	ft_increment_loop(n, arr);
}
