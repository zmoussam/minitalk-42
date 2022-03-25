/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:42:05 by zmoussam          #+#    #+#             */
/*   Updated: 2022/03/25 18:11:57 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

init t;

void	init_by_zero(void)
{
	t.c = (char)255;
	t.i = 0;
}

void	handler1(int signum, siginfo_t *info, void *sheet)
{
	(void)sheet;
	int static pid;
	
	if(pid != info->si_pid)
	{
		pid = info->si_pid;
		init_by_zero();
	}
	if(signum == SIGUSR1)
		t.c |= (0x80 >> t.i++);
	else if(signum == SIGUSR2)
		t.c ^= (0x80 >> t.i++);
	if(t.c == '\0')
		kill(info->si_pid,SIGUSR1);
	if(t.i == 8)
	{
		ft_putchar(t.c);
		init_by_zero();
	}
}

int main()
{
	struct sigaction new_act1;
	new_act1.sa_sigaction = &handler1;
	new_act1.sa_flags = SA_SIGINFO;
	ft_putnbr(getpid());
	write(1, "\n", 1);

	sigaction(SIGUSR1, &new_act1, NULL);
	sigaction(SIGUSR2, &new_act1, NULL);
	while(1)
		pause();
}
