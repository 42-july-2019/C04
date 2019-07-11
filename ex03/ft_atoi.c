/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabreui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:17:36 by alabreui          #+#    #+#             */
/*   Updated: 2019/07/10 18:36:32 by alabreui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
			(c == '\r'))
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int result;
	int minus_count;
	int i;

	i = 0;
	minus_count = 0;
	result = 0;
	while (is_white_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus_count++;
		str++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (minus_count % 2 != 0 ? -1 * result : result);
}
