/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:16:51 by anferre           #+#    #+#             */
/*   Updated: 2024/11/05 17:25:00 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Format.hpp"

#ifndef DEBUG
# define DEBUG true
#endif

class AForm;

class Bureaucrat
{
	private : 
		std::string const _name;
		int _grade;
	
	public :
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &copy);
		
		class GradeTooHighException: public std::exception {
			public : 
				virtual const char* what() const throw();
		};
		
		class GradeTooLowException: public std::exception {
			public : 
				virtual const char* what() const throw();
		};
		
		class CantExecuteFormException: public std::exception {
			private : 
				std::string _msg;
			public : 
				CantExecuteFormException(const std::string &msg);
				virtual ~CantExecuteFormException() throw();
				virtual const char* what() const throw();
		};
		
		std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(AForm &form);
		void executeForm(AForm const &form);

};
	
std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif