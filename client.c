/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkidd <nkidd@student.42adel.org.au>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:27:16 by nkidd             #+#    #+#             */
/*   Updated: 2022/12/28 15:27:19 by nkidd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/includes/ft_printf.h"

void	send_bit(int pid, char *str, size_t len)
{
		int		shift;
		size_t 	i;

		i = 0;
		while (i <= len)
		{
			shift = 0;
			while (shift < 7)
			{
					if ((str[i] >> shift) & 1)
							kill(pid, SIGUSR2);
					else
							kill(pid, SIGUSR1);
					shift++;
					usleep(1000);
			}
			i++;
		}
}

int		main(int argc, char **argv)
{
		int		pid;
		char	*str;

		if (argc == 3)
		{
			pid = ft_atoi(argv[1]);
			str = argv[2];
			send_bit(pid, str, ft_strlen(str));
		}
		else
			ft_printf("\nThe CLIENT program should be run with the PID, and ONE parameter to be printed ONLY.\n\n");
}