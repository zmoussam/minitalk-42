/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:31:58 by zmoussam          #+#    #+#             */
/*   Updated: 2022/03/25 18:10:29 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main(int argc, char **argv)
{
	int i;
	int shift;
	int pid;

	i = -1;
	if(argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while(argv[2][++i])
		{
			shift = 8;
			while(shift-- > 0 )
			{
				if ((argv[2][i] >> shift) & 1)
					kill(pid,SIGUSR1);
				else
					kill(pid,SIGUSR2);
				usleep(30);
			}
		}
	}
	else
		write(1,"invalide argument!!\n",20);
}
