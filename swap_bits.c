/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsoares- <vsoares-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 21:55:38 by vsoares-          #+#    #+#             */
/*   Updated: 2025/02/10 23:02:19 by vsoares-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

const char	swap_bits(const char octet)
{
	char	c;
	char	str[8];
	short	i;
	char	base[2] = "01";
	short	binary[8] = { 128, 64, 32, 16, 8, 4, 2, 1 };

	i = 7;
	c = octet;
	while (i >= 0)
	{
		str[i--] = base[c % 2];
		c /= 2;
	}
	i = 0;
	c = 0;
	while (i < 4)
	{
		c += ((str[i + 4] - '0') * binary[i]);
		i++;
	}
	while (i < 8)
	{
		c += ((str[i - 4] - '0') * binary[i]);
		i++;
	}
	return (c);
}

int	main(void)
{
	char	c;
	char	d;

	c = 'a';
	d = swap_bits((const char) c);
	printf("New bit value of %d -> %d\n", c, d);

	c = 'A';
	d = swap_bits(c);
	printf("New bit value of %d -> %d\n", c, d);

	c = (char) 86;
	d = swap_bits(c);
	printf("New bit value of %d -> %d\n", c, d);
	return (0);
}
