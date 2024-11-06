/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:29:05 by anferre           #+#    #+#             */
/*   Updated: 2024/11/05 13:03:14 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include "Format.hpp"
#include "Bureaucrat.hpp"

class AForm
{
	private :
		std::string const	_name;
		bool 				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;

	public :
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &copy);
		virtual ~AForm();

		AForm &operator=(AForm const &copy);

		class GradeTooHighException: public std::exception {
			public : 
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException: public std::exception {
			public : 
				virtual const char* what() const throw();
		};

		class AFormAlreadySignedException: public std::exception {
			public : 
				virtual const char* what() const throw();
		};

		class AFormNotSignedException: public std::exception {
			public : 
				virtual const char* what() const throw();
		};

		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual bool execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif