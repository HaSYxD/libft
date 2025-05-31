/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afromont <afromont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:20:42 by aliaudet          #+#    #+#             */
/*   Updated: 2024/06/25 12:30:55 by afromont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	neg_count;
	int	pos_count;
	int	res;

	neg_count = 0;
	pos_count = 0;
	res = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\v' || *str == '\f')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg_count++;
		if (*str == '+')
			pos_count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if ((neg_count + pos_count) > 1)
		return (0);
	if (neg_count == 1)
		res = -res;
	return (res);
}

float	ft_atof(const char *str)
{
	// Get the integer part of the float
	double	intPart = ft_atoi(str);

	// Check if there is a point in the number
	int	lenToPoint = 0;
	while (str[lenToPoint] && str[lenToPoint] != '.')
		lenToPoint++;
	if (lenToPoint == (int)ft_strlen(str))
		return (intPart);
	lenToPoint++;

	// Check the length of the correct decimal part
	int	decPartLen = 0;
	while (str[decPartLen + lenToPoint] && ft_isdigit(str[decPartLen + lenToPoint]))
		decPartLen++;
	if (!decPartLen)
		return (intPart);

	// Count the power of the decimal part to correctly assemble the final float
	double	decPart = ft_atoi(str + lenToPoint);
	int	div = 1;
	for (; decPartLen; decPartLen--)
		div *= 10;
	return intPart + (decPart / div);
}
