/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiaz-be <adiaz-be@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:06:33 by adiaz-be          #+#    #+#             */
/*   Updated: 2022/10/24 17:06:37 by adiaz-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *param)
{
	static char	c = 0;
	static int	bit = 7;
	static int	pid = 0;

	(void)param;
	if (signal == SIGUSR2)
		c = c | (1 << bit);
	if (pid == 0)
		pid = info->si_pid;
	kill(pid, SIGUSR2);
	bit--;
	if (bit < 0)
	{
		bit = 7;
		if (c == '\0')
		{
			c = 0;
			kill(pid, SIGUSR1);
			ft_printf("\n");
			pid = 0;
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	info;

	ft_printf("PID: %d\n", getpid());
	info.sa_flags = SA_SIGINFO;
	info.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &info, NULL);
	sigaction(SIGUSR2, &info, NULL);
	while (1)
		pause();
}
