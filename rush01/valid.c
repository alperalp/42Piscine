/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalp <aalp@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:52:39 by aalp              #+#    #+#             */
/*   Updated: 2023/07/23 17:52:42 by aalp             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	reverse_arr(int row[4]);
void	cp_array(int dest[4][4], int src[4][4]);
int		check_visibility(int row[4]);

int	val_left_to_right(int arg[4][4], int arr[4][4])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (arg[2][i] != check_visibility(arr[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	val_right_to_left(int arg[4][4], int arr[4][4])
{
	int	i;
	int	tmp[4][4];

	cp_array(tmp, arr);
	i = 0;
	while (i < 4)
	{
		reverse_arr(tmp[i]);
		if (arg[3][i] != check_visibility(tmp[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	val_up_down(int arg[4][4], int arr[4][4])
{
	int	i;
	int	tmp[4];
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp[j] = arr[j][i];
			j++;
		}
		if (arg[0][i] != check_visibility(tmp))
			return (0);
		i++;
	}
	return (1);
}

int	val_down_up(int arg[4][4], int arr[4][4])
{
	int	i;
	int	tmp[4];
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp[j] = arr[j][i];
			j++;
		}
		reverse_arr(tmp);
		if (arg[1][i] != check_visibility(tmp))
			return (0);
		i++;
	}
	return (1);
}

int	val_check_sol(int arg[4][4], int arr[4][4])
{
	if (val_down_up(arg, arr) && val_up_down(arg, arr) && val_left_to_right(arg,
			arr) && val_right_to_left(arg, arr))
		return (1);
	else
		return (0);
}
