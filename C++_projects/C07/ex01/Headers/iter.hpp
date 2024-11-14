/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookops <tookops@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:22:01 by tookops           #+#    #+#             */
/*   Updated: 2024/11/14 17:52:48 by tookops          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include "Format.hpp"

template <typename T, typename F>
void iter(T *array, const size_t arrayLength, F func)
{
	for (size_t i = 0; i < arrayLength; i++)
	{
		func(array[i]);
	}
}

#endif
