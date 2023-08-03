/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalp <aalp@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:52:19 by aalp              #+#    #+#             */
/*   Updated: 2023/07/23 17:52:22 by aalp             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	print_grid(int arr[4][4]);

void	ft_putstr(char *str);

int		val_check_sol(int arg[4][4], int arr[4][4]);

int	check_solve(int arg[4][4], int arr[4][4])
{
	if (val_check_sol(arg, arr))
	{
		print_grid(arr);
		return (1);
	}
	return (0);
}

int	check_error(int i, int y)
{
	if (i == 23 && y == 0)
	{
		ft_putstr("Error!!");
		return (1);
	}
	return (0);
}

int	solve(int arg[4][4], int arr[4][4], int perm[24][4], int y)
{
	int	i;
	int	j;
	int	old_y;

	old_y = y;
	i = 0;
	while (i < 24)
	{
		j = 0;
		while (j < 4)
		{
			arr[y][j] = perm[i][j];
			j++;
		}
		if (check_solve(arg, arr))
			return (1);
		if (y == 4)
			return (0);
		y++;
		if (solve(arg, arr, perm, y))
			return (1);
		y = old_y;
		i++;
	}
	return (0);
}
