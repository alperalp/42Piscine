/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalp <aalp@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 17:51:51 by aalp              #+#    #+#             */
/*   Updated: 2023/07/23 17:56:46 by aalp             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

void	permutate(int row[4], int post, int per_arr[24][4], int *j);

int		solve(int arg[4][4], int arr[4][4], int perm[24][4], int y);

void	ft_putstr(char *str);

void	arg_to_arr(char *arg, int arr[4][4])
{
	int	i;
	int	row;
	int	col;

	i = 0;
	row = 0;
	col = 0;
	while (arg[i])
	{
		if (arg[i] >= '1' && arg[i] <= '9')
		{
			arr[row][col] = arg[i] - 48;
			if (col != 3)
				col++;
			else
			{
				col = 0;
				row++;
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	example_arr[4];
	int	empty_arr[4][4];
	int	test_control[4][4];
	int	perm_test[24][4];
	int	perm_index;

	example_arr[0] = 1;
	example_arr[1] = 2;
	example_arr[2] = 3;
	example_arr[3] = 4;
	if (argc != 2)
	{
		ft_putstr("Error!");
		return (0);
	}
	arg_to_arr(argv[1], test_control);
	perm_index = 0;
	permutate(example_arr, 0, perm_test, &perm_index);
	if (!solve(test_control, empty_arr, perm_test, 0))
		ft_putstr("Error !!");
	return (0);
}
