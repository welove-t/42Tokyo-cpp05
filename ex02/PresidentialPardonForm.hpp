#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class PresidentialPardonForm :public AForm
{
	private:
		const std::string	_target;
		const int			_gradeSign = 145;
		const int			_gradeExecute = 137;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string _target);
		~PresidentialPardonForm();

		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

};

#endif
