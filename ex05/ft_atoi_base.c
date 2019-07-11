/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:10:41 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/11 12:03:32 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_base(char *base, int *base_length)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (!(base[i] >= 'a' && base[i] <= 'z') &&
				!(base[i] >= 'A' && base[i] <= 'Z') &&
				!(base[i] >= '0' && base[i] <= '9'))
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

int		get_digit(char c, char *base, int *base_length)
{
	int i;

	i = 0;
	while (i < *base_length && base[i] != c)
	{
		i++;
	}
	if (i == *base_length)
		return (-1);
	return (i);
}

int		convert_to_int(char *str, char *base, int *base_length)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i] >= base[0] && str[i] <= base[*base_length - 1])
	{
		result = result * *base_length;
		result = result +
		get_digit(str[i], base, base_length);
		i++;
	}
	return (result);
}

int		ft_atoi_base(char *str, char *base)
{
	int length;
	int *base_length;
	int result;
	int minus_count;

	length = 0;
	base_length = &length;
	minus_count = 0;
	result = 0;
	if (check_base(base, base_length))
	{
		while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' ||
		(*str == '\f') || (*str == '\r'))
			str++;
		while (*str == '+' || *str == '-')
		{
			if (*str == '-')
				minus_count++;
			str++;
		}
		result = convert_to_int(str, base, base_length);
	}
	return (minus_count % 2 != 0 ? -1 * result : result);
}
