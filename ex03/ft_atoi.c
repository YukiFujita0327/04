/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yufujita <yufujita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:29:31 by yufujita          #+#    #+#             */
/*   Updated: 2020/01/20 00:21:31 by yufujita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char c)
{
	if (c == '\n' || c == '\r' || c == '\t')
		return (1);
	else if (c == ' ' || c == '\f' || c == '\v')
		return (1);
	else
		return (0);
}

int		is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int		is_numeric(char c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int n;
	int mns_sign;
	int	ret;

	n = 0;
	ret = 0;
	mns_sign = 1;
	while (is_space(str[n]))
		n++;
	while (is_sign(str[n]))
	{
		if (str[n] == '-')
			mns_sign *= -1;
		n++;
	}
	while (is_numeric(str[n]))
	{
		ret = ret * 10;
		ret = ret + (str[n] - 48);
		n++;
	}
	return (ret * mns_sign);
}
