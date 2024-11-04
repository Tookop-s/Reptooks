/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:29:05 by anferre           #+#    #+#             */
/*   Updated: 2024/11/04 15:44:33 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Format.hpp"
#include "Bureaucrat.hpp"

class Form
{
	private :
		std::string const	_name;
		bool 				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public :
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(Form const &copy);
		~Form();

		Form &operator=(Form const &copy);

		class GradeTooHighException: public std::exception {
			public : 
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException: public std::exception {
			public : 
				virtual const char* what() const throw();
		};

		class FormAlreadySignedException: public std::exception {
			public : 
				virtual const char* what() const throw();
		};

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif