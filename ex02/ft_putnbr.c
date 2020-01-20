/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufujita <yufujita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 10:52:47 by yufujita          #+#    #+#             */
/*   Updated: 2020/01/21 05:05:55 by yufujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		write_int_limit(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	else
	{
		return (0);
	}
}

void	minus_write(int *nb)
{
	if (*nb < 0)
	{
		*nb *= -1;
		write(1, "-", 1);
	}
}

void	ft_putnbr(int nb)
{
	int		n;
	char	tmp;
	char	nb_str[10];

	if (write_int_limit(nb))
		return ;
	if (nb == 0)
		write(1, "0", 1);
	minus_write(&nb);
	n = 0;
	while (nb != 0)
	{
		tmp = nb % 10;
		nb_str[n] = tmp + '0';
		nb /= 10;
		n++;
	}
	while (0 < n)
	{
		if (nb_str[n - 1] != '\0')
			write(1, &nb_str[n - 1], 1);
		else if (n <= 9)
			write(1, "\0", 1);
		n--;
	}
}
