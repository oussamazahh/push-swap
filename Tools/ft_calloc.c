/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozahidi <ozahidi@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:16:56 by ozahidi           #+#    #+#             */
/*   Updated: 2024/05/07 12:30:08 by ozahidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tools.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	nb;
	void	*ptr;

	nb = count * size;
	if (count != 0 && nb / count < size)
		return (NULL);
	ptr = malloc(nb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nb);
	return (ptr);
}
