/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalp <aalp@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 15:21:50 by aalp              #+#    #+#             */
/*   Updated: 2023/07/16 18:06:08 by aalp             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	p_start;
	int	p_end; 

	p_start = 0;
	p_end = size - 1;
	while (p_start < p_end && p_start != p_end)
	{
		ft_swap(&tab[p_start], &tab[p_end]);
		p_start++;
		p_end--;
	}
}
