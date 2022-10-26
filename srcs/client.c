/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-be <adiaz-be@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:20:18 by adiaz-be          #+#    #+#             */
/*   Updated: 2022/10/25 16:20:28 by adiaz-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int		g_mutex;

void	send_signal(char c, int pid)
{
	int	i;
	int	bit;

	i = 8;
	while (i-- > 0)
	{
		g_mutex = 0;
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_mutex == 0)
			usleep(1);
	}
}

void	signal_handler(int signal)
{
	static int	bits = 0;

	if (signal == SIGUSR2)
	{
		bits++;
		g_mutex = 1;
	}
	else
		exit(ft_printf("Bits received %d\n", bits));
}

int	main(int argc, char **argv)
{
	size_t				i;
	char				*str;

	if (argc != 3 || !ft_strlen(argv[2]))
		return (ft_printf("Error with arguments\n"), 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	i = 0;
	str = argv[2];
	while (ft_strlen(str) >= i)
	{
		send_signal(argv[2][i], ft_atoi(argv[1]));
		i++;
	}
	while (1)
		pause();
}
