/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:31:58 by zmoussam          #+#    #+#             */
/*   Updated: 2022/03/25 18:20:56 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void handler(int signum)
{
	if(signum == 30)
		write(1, "message recu\n",13);
}
void send_character(char c, int pid)
{
	int shift;
	
	shift = 8;
	while(shift-- > 0 )
	{
		if ((c >> shift) & 1)
			kill(pid,SIGUSR1);
		else
			kill(pid,SIGUSR2);
		usleep(30);
	}
}
int main(int argc, char **argv)
{
	int i;
	int pid;

	i = -1;
	signal(SIGUSR1, &handler);
	if(argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while(argv[2][++i])
			send_character(argv[2][i],pid);
		send_character('\0',pid);
	}
	else
		write(1,"invalide argument!!\n",20);
}
