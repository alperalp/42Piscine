/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalp <aalp@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 02:38:08 by aalp              #+#    #+#             */
/*   Updated: 2023/07/29 17:43:33 by aalp             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int prime)
{
	unsigned int	i;
	unsigned int	number;

	i = 2;
	if (prime <= 1)
		return (0);
	number = prime;
	while (i * i <= number)
	{
		if (prime % i++ == 0)
			return (0);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}
