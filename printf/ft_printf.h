/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:10:18 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/10/01 19:32:30 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int		chr_in(char c, char const *str);
int		ft_printf(const char *input, ...);
char	*strjoin_on_steroids(int n, ...);
char	*nbr_to_hex(unsigned long long n, int lowercase);
void	ft_puthexlower_fd(void *arg, int fd);
void	ft_puthexupper_fd(void *arg, int fd);
char	*ft_llutoa(unsigned long long n);

