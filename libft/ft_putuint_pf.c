/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-be <adiaz-be@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:35:21 by adiaz-be          #+#    #+#             */
/*   Updated: 2022/10/15 14:35:28 by adiaz-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putuint_pf(unsigned int num, size_t *counter)
{
	char	*str;

	str = ft_atoi_base(num, "0123456789");
	ft_putstr_pf(str, counter);
	free(str);
}
