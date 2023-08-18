#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class RobotomyRequestForm :public AForm
{
	private:
		const std::string	_target;
		static const int			_gradeSign = 72;
		static const int			_gradeExecute = 45;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string _target);
		~RobotomyRequestForm();

		RobotomyRequestForm(const RobotomyRequestForm& rhs);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

		void	execute(Bureaucrat const & executor) const;

};

#endif
