#include "RobotomyRequestForm.hpp"

/* Orthodox Canonical Form */
RobotomyRequestForm::RobotomyRequestForm()
: AForm("", _gradeSign, _gradeExecute), _target("")
{
	std::cout << "(RobotomyRequestForm) Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm(target, _gradeSign, _gradeExecute), _target(target)
{
	std::cout << "(RobotomyRequestForm) Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs)
: AForm(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExecute()), _target(rhs._target)
{
	std::cout << "(RobotomyRequestForm) Copy Constructor called"  << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "(RobotomyRequestForm) Destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "(RobotomyRequestForm) Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	const_cast<std::string&>(_target) = rhs._target;
	AForm::operator=(rhs);
	return *this;
}

/* Function */

