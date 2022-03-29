/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tterribi <tterribi@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:59:04 by tterribi          #+#    #+#             */
/*   Updated: 2022/03/29 20:29:53 by tterribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <strings.h>
# include <signal.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
void	*ft_memset(void *str, int c, size_t n);
void	decimal_to_binary(int decimal, char *octet);
int		ft_strlen(char *str);

#endif