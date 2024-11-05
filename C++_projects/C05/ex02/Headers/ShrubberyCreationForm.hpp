/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:28:51 by anferre           #+#    #+#             */
/*   Updated: 2024/11/05 13:42:16 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private :
		std::string	_target;

	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &copy);

		class FileNotOpenException: public std::exception {
			private : 
				std::string _msg;
			public :
				FileNotOpenException(std::string target);
				virtual ~FileNotOpenException() throw();
				virtual const char* what() const throw();
		};

		class FileAlreadyExistsException: public std::exception {
			private : 
				std::string _msg;
			public : 
				FileAlreadyExistsException(std::string target);
				virtual ~FileAlreadyExistsException() throw();
				virtual const char* what() const throw();
		};

		std::string getTarget() const;
		bool execute(Bureaucrat const &executor) const;
};

#endif