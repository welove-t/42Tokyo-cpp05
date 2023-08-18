#include "ShrubberyCreationForm.hpp"

/* Orthodox Canonical Form */
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("", _gradeSign, _gradeExecute), _target("")
{
	std::cout << "(ShrubberyCreationForm) Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm(target, _gradeSign, _gradeExecute), _target(target)
{
	std::cout << "(ShrubberyCreationForm) Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
: AForm(rhs.getName(), rhs.getGradeSign(), rhs.getGradeExecute()), _target(rhs._target)
{
	std::cout << "(ShrubberyCreationForm) Copy Constructor called"  << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "(ShrubberyCreationForm) Destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << "(ShrubberyCreationForm) Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	const_cast<std::string&>(_target) = rhs._target;
	AForm::operator=(rhs);
	return *this;
}

/* Function */

