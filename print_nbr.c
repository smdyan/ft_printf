/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:15:03 by smdyan            #+#    #+#             */
/*   Updated: 2021/12/30 12:16:00 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_pointer_prefix(char **buf);
static int	put_minus(t_info *info, char **buf);
static int	put_minus2(int buf_len, t_info *info, char **buf);
static int	put_prec_str(unsigned long long nbr, t_info *info, char **buf);

static int	put_pointer_prefix(char **buf)
{
	char	*tmp;

	tmp = ft_strjoin("0x", *buf);
	free(*buf);
	*buf = tmp;
	return (ft_strlen(*buf));
}

static int	put_minus(t_info *info, char **buf)
{
	int		len_to_add;
	char	*tmp;

	len_to_add = 0;
	if (info->nbr_sign != -1)
		return (len_to_add);
	if ((info->type == 'i' || info->type == 'd') && info->zero == 0)
	{
		tmp = ft_strjoin("-", *buf);
		free(*buf);
		*buf = tmp;
		len_to_add = 1;
	}
	return (len_to_add);
}

static int	put_minus2(int buf_len, t_info *info, char **buf)
{
	int		len_to_add;
	char	*tmp;

	len_to_add = 0;
	if (info->nbr_sign == -1 && info->zero == 1)
	{
		if (buf_len >= info->width)
		{
			tmp = ft_strjoin("-", *buf);
			free(*buf);
			*buf = tmp;
			len_to_add = 1;
		}
		else
			*buf[0] = '-';
	}
	return (len_to_add);
}

static int	put_prec_str(unsigned long long nbr, t_info *info, char **buf)
{
	int	buf_len;
	int	ret;
	int	i;

	buf_len = ft_nbrlen(nbr, info);
	ret = buf_len;
	if (info->prec > buf_len)
		ret = info->prec;
	*buf = (char *)malloc(sizeof(char) * ret + 1);
	if (!(*buf))
		return (0);
	i = 0;
	(*buf)[ret] = '\0';
	while (buf_len + i < ret)
		(*buf)[i++] = '0';
	i = 1;
	if (nbr == 0 && info->prec != 0)
		(*buf)[ret - i] = '0';
	while (nbr)
	{
		(*buf)[ret - i++] = ft_baseset(info->type)[nbr % info->nbr_base];
		nbr /= info->nbr_base;
	}
	return (buf_len);
}

int	print_nbr(unsigned long long nbr, t_info *info)
{
	char	*buf;
	int		buf_len;
	int		ret;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr = -nbr;
	}
	buf_len = put_prec_str(nbr, info, &buf);
	buf_len += put_minus(info, &buf);
	if (info->type == 'p')
		buf_len = put_pointer_prefix(&buf);
	ret = put_width_str(&buf, info);
	ret += put_minus2(buf_len, info, &buf);
	ft_putstr_fd(buf, 1);
	free(buf);
	buf = NULL;
	return (ret);
}
