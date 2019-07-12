/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 18:32:14 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/12 11:28:40 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		is_not_alphanumeric(char c)
{
	if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z') &&
			!(c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int		check_base(char *base, int *base_length)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (is_not_alphanumeric(base[i]))
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	*base_length = i;
	if (*base == '\0' || *base_length <= 1)
		return (0);
	return (1);
}

void	assign_digit(int nbr, char *base, int *base_length)
{
	if (nbr == -2147483648)
	{
		assign_digit(-2147483648 / *base_length, base, base_length);
		nbr = -2147483648 % *base_length * -1;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= *base_length)
	{
		assign_digit(nbr / *base_length, base, base_length);
		nbr = nbr % *base_length;
	}
	if (nbr < *base_length)
	{
		ft_putchar(base[nbr]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int length;
	int *base_length;

	length = 0;
	base_length = &length;
	if (check_base(base, base_length))
		assign_digit(nbr, base, base_length);
}
