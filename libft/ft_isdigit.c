/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maustel <maustel@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:29:51 by maustel           #+#    #+#             */
/*   Updated: 2024/04/18 12:16:16 by maustel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main ()
// {
// 	printf("isdigit\n");
//     int c = 'a';
//     if (ft_isdigit(c) == isdigit(c))
//         printf("Ok!\n");
//     c = '9';
//     if (ft_isdigit(c) == isdigit(c))
//         printf("Ok!\n");
// }