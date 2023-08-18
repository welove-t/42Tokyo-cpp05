#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class ShrubberyCreationForm :public AForm
{
	private:
		const std::string	_target;
		const int			_gradeSign = 145;
		const int			_gradeExecute = 137;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string _target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

};

#endif
