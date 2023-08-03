/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalp <aalp@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:52:27 by aalp              #+#    #+#             */
/*   Updated: 2023/07/23 17:52:28 by aalp             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	check_visibility(int row[4])
{
	int	i;
	int	j;
	int	visibility;

	visibility = 4;
	i = 1;
	if (row[0] == 4)
		return (1);
	while (i < 4)
	{
		j = 0;
		while (j < i)
		{
			if (row[j] == row[i])
				return (-1);
			if (row[j] > row[i])
			{
				visibility--;
				break ;
			}
			j++;
		}
		i++;
	}
	return (visibility);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	reverse_arr(int row[4])
{
	swap(&row[0], &row[3]);
	swap(&row[1], &row[2]);
}

void	cp_array(int dest[4][4], int src[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			dest[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

void	permutate(int row[4], int pos, int per_arr[24][4], int *j)
{
	int	t;
	int	i;

	if (pos == 3)
	{
		t = 0;
		while (t < 4)
		{
			per_arr[*j][t] = row[t];
			t++;
		}
		*j += 1;
		return ;
	}
	i = pos;
	while (i < 4)
	{
		swap(&row[i], &row[pos]);
		permutate(row, pos + 1, per_arr, j);
		swap(&row[i], &row[pos]);
		i++;
	}
}
