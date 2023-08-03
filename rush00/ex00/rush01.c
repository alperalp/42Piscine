/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalp <aalp@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 13:20:25 by aalp              #+#    #+#             */
/*   Updated: 2023/07/16 16:13:49 by aalp             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_draw_line(char c_start, char c_middle, char c_end, int x)
{
	int	middle_count;
	int	i;

	i = 0;
	middle_count = x - 2;
	ft_putchar(c_start);
	if (x == 1)
	{
		ft_putchar('\n');
		return ;
	}
	else
	{
		while (i < middle_count)
		{
			ft_putchar(c_middle);
			i++;
		}
		ft_putchar(c_end);
		ft_putchar('\n');
	}
}

void	rush(int x, int y)
{
	int	i;
	int	gap_count;

	if (x <= 0 || y <= 0)
	{
		write(1, "Wrong Input: X and Y cannot be smaller than one.\n", 49);
		return ;
	}
	i = 0;
	gap_count = y - 2;
	ft_draw_line('/', '*', '\\', x);
	if (y == 1)
	{
		return ;
	}
	else
	{
		while (i < gap_count)
		{
			ft_draw_line('*', ' ', '*', x);
			i++;
		}
	}
	ft_draw_line('\\', '*', '/', x);
}
