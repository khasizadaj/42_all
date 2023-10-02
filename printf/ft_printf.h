/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkhasiza <jkhasiza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 18:10:18 by jkhasiza          #+#    #+#             */
/*   Updated: 2023/10/02 21:18:10 by jkhasiza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int		chr_in(char c, char const *str);
int		ft_printf(const char *input, ...);
char	*ft_strjoin_on_steroids(int n, ...);
char	*u_to_hex(unsigned int n, int lowercase);
char	*llu_to_hex(unsigned long long n, int lowercase);
void	ft_puthexlower_fd(unsigned int n, int fd);
void	ft_puthexupper_fd(unsigned int n, int fd);
char	*ft_lldtoa(int n);
char	*ft_utoa(unsigned int n);

