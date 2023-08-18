#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class PresidentialPardonForm :public AForm
{
	private:
		const std::string	_target;
		static const int			_gradeSign = 25;
		static const int			_gradeExecute = 5;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string _target);
		~PresidentialPardonForm();

		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

		void	execute(Bureaucrat const & executor) const;

};

#endif
