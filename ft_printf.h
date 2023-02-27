/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smdyan <smdyan@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:44:48 by smdyan            #+#    #+#             */
/*   Updated: 2021/12/29 00:26:20 by smdyan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define TYPE "cspdiuxX%"

typedef struct s_info
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	char	type;
	int		nbr_base;
	int		nbr_sign;
}			t_info;

/*
********************************FT_PRINTF_C*************************************
*/
int		ft_printf(const char *format, ...);
int		print_char(int c, t_info *info);
int		print_str(char *str, t_info *info);
int		put_width_str(char **buf, t_info *info);
int		print_nbr(unsigned long long nbr, t_info *info);

/*
***********************************UTILS_C**************************************
*/
void	init_info(t_info *info);
void	patch_info(t_info *info);
int		ft_nbrlen(unsigned long long nbr, t_info *info);
char	*ft_baseset(char type);

#endif
