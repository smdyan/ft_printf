/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:07:44 by smdyan            #+#    #+#             */
/*   Updated: 2021/12/27 18:46:57 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_width(int width, int len, int zero);

static int	put_width(int width, int len, int zero)
{
	int	ret;

	ret = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		len++;
		ret++;
	}
	return (ret);
}

int	print_char(int c, t_info *info)
{
	int	ret;

	ret = 0;
	if (info->type == '%' && info->minus == 1)
		info->zero = 0;
	if (info->minus == 1)
	{
		ft_putchar_fd(c, 1);
		ret++;
	}
	ret += put_width(info->width, 1, info->zero);
	if (info->minus == 0)
	{
		ft_putchar_fd(c, 1);
		ret++;
	}
	return (ret);
}
