/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-be <adiaz-be@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 11:35:45 by adiaz-be          #+#    #+#             */
/*   Updated: 2022/10/15 11:36:22 by adiaz-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(unsigned long long n, char *base)
{
	size_t				len;
	unsigned long long	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_atoi_base(unsigned long long n, char *base)
{
	char	*str;
	int		num_len;
	int		base_len;

	num_len = ft_len(n, base);
	base_len = ft_strlen(base);
	str = ft_calloc((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len = num_len - 1;
		str[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}
