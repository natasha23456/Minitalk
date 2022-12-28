/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkidd <nkidd@student.42adel.org.au>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 18:40:20 by nkidd             #+#    #+#             */
/*   Updated: 2022/08/22 18:40:25 by nkidd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	ft_printf_string(const char *input, int *output)
{
	int	i;

	i = 0;
	if (input == NULL)
	{
		(*output) += write(1, "(null)", 6);
		return ;
	}
	while (input[i])
	{
		ft_printf_char(input[i], output);
		i++;
	}
}
