/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:48:05 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/22 17:04:21 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	atoi_ps(const char *str)
{
	int		signe;
	int		number;
	char	*strcopy;

	strcopy = (char *)str;
	number = 0;
	signe = 1;
	while (*strcopy == ' ' | *strcopy == '\t' | *strcopy == '\n'
		| *strcopy == '\r' | *strcopy == '\v' | *strcopy == '\f')
		strcopy++;
	if (*strcopy == '-' || *strcopy == '+')
	{
		if (*strcopy == '-')
			signe *= -1;
		strcopy++;
	}
	while ('0' <= *strcopy && *strcopy <= '9')
	{
		number *= 10;
		number += *strcopy - '0';
		strcopy++;
	}
	return (number * signe);
}
