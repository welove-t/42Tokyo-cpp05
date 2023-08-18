#include "PresidentialPardonForm.hpp"

/* Orthodox Canonical Form */
PresidentialPardonForm::PresidentialPardonForm()
: AForm("", _gradeSign, _gradeExecute), _target("")
{
	std::cout << "(PresidentialPardonForm) Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm(target, _gradeSign, _gradeExecute), _target(target)
{
	std::cout << "(PresidentialPardonForm) Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& rhs)
: AForm(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExecute()), _target(rhs._target)
{
	std::cout << "(PresidentialPardonForm) Copy Constructor called"  << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "(PresidentialPardonForm) Destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "(PresidentialPardonForm) Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	const_cast<std::string&>(_target) = rhs._target;
	AForm::operator=(rhs);
	return *this;
}

/* Function */

