/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:37:44 by smdyan            #+#    #+#             */
/*   Updated: 2021/12/30 01:06:29 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*parse_buf(char *str, int end, int len);

static char	*parse_buf(char *str, int end, int len)
{
	int		i;
	char	*buf;

	if (end > len)
		end = len;
	buf = (char *)malloc(sizeof(char) * end + 1);
	if (!buf)
		return (NULL);
	i = 0;
	while (i < end)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

int	put_width_str(char **buf, t_info *info)
{
	char	*width;
	int		i;

	if (info->width <= (int)ft_strlen(*buf))
		return ((int)ft_strlen(*buf));
	width = (char *)malloc(sizeof(char) * (info->width - ft_strlen(*buf) + 1));
	if (!width)
		return (0);
	i = 0;
	while ((size_t)i < info->width - ft_strlen(*buf))
	{
		if (info->zero == 1 && info->minus == 0)
			width[i] = '0';
		else
			width[i] = ' ';
		i++;
	}
	width[i] = '\0';
	if (info->minus == 0)
		*buf = ft_strjoin(width, *buf);
	else
		*buf = ft_strjoin(*buf, width);
	return (info->width);
}

int	print_str(char *str, t_info *info)
{
	int		ret;
	char	*buf;

	ret = 0;
	if (str == NULL)
		str = "(null)";
	if (info->prec == -1 || (size_t)info->prec > ft_strlen(str))
		info->prec = ft_strlen(str);
	buf = parse_buf(str, info->prec, ft_strlen(str));
	ret = put_width_str(&buf, info);
	ft_putstr_fd(buf, 1);
	free(buf);
	return (ret);
}
