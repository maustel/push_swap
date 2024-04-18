/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:57:49 by maustel           #+#    #+#             */
/*   Updated: 2024/04/18 12:16:21 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	else
		return (0);
}
// #include <stdio.h>
// #include <ctype.h>
// int main ()
// {
// 	printf("isprint\n");
//     int c = 'a';
//     if (ft_isprint(c) == isprint(c))
//         printf("Ok!\n");
//     c = 127;
//     if (ft_isprint(c) == isprint(c))
//         printf("Ok!\n");
// }