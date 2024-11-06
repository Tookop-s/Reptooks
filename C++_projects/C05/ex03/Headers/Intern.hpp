/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:19:30 by anferre           #+#    #+#             */
/*   Updated: 2024/11/06 13:49:23 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern & operator=( Intern const & rhs );

		class FormNotFoundException: public std::exception {
			public : 
				virtual const char* what() const throw();
		};

		AForm *makeForm(std::string name, std::string target);

	private:

};

#endif