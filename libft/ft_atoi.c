/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sseo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:54:55 by sseo              #+#    #+#             */
/*   Updated: 2020/04/05 03:29:17 by sseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *nptr)
{
	int			sum;
	int			is_plus;
	long long	over;

	sum = 0;
	over = 0;
	is_plus = 1;
	while (*nptr == '\n' || *nptr == ' ' || *nptr == '\t' || *nptr == '\f' || \
			*nptr == '\r' || *nptr == '\v')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			is_plus = -1;
		nptr++;
	}
	while (*nptr && *nptr <= '9' && *nptr >= '0')
	{
		sum = sum * 10 + *nptr - '0';
		if (over != (over * 10 + *nptr - '0') / 10)
			return (is_plus == 1 ? -1 : 0);
		over = over * 10 + *nptr - '0';
		nptr++;
	}
	return (sum * is_plus);
}
