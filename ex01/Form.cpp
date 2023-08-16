#include "Form.hpp"

/* Orthodox Canonical Form */
Form::Form() :_name(""), _isSigned(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "(Form) Default Constructor called" << std::endl;
}

Form::Form(std::string name, const int gradeSign, const int gradeExecute)
:_name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << "(Form) Constructor called" << std::endl;
	checkOverGrade(gradeSign);
	checkOverGrade(gradeExecute);
}

Form::Form(const Form& rhs)
: _name(rhs._name), _isSigned(rhs._isSigned), _gradeSign(rhs._gradeSign), _gradeExecute(rhs._gradeExecute)
{
	std::cout << "(Form) Copy Constructor called"  << std::endl;
}

Form::~Form()
{
	std::cout << "(Form) Destructor called" << std::endl;
}

Form& Form::operator=(const Form& rhs)
{
	std::cout << "(Form) Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	const_cast<std::string&>(_name) = rhs._name;
	_isSigned = rhs._isSigned;
	const_cast<int&>(_gradeSign) = rhs._gradeSign;
	const_cast<int&>(_gradeExecute) = rhs._gradeExecute;
	return *this;
}

/* Getter */
const std::string&	Form::getName(void) const
{
	return _name;
}

int	Form::getIsSigned(void) const
{
	return _isSigned;
}

const int	Form::getGradeSign(void) const
{
	return _gradeSign;
}

const int	Form::getGradeExecute(void) const
{
	return _gradeExecute;
}

/* Function */

void	Form::checkOverGrade(const int grade) const
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	else if (grade < 1)
		throw Form::GradeTooHighException();
	else
		return;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return " Grade too high ";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return " Grade too low ";
}

std::ostream&	operator<<(std::ostream& os, const Form& rhs)
{
	os << "name: "<<rhs.getName() <<
		"\tisSigned: " << rhs.getIsSigned() <<
		"\tgradeSign: " << rhs.getGradeSign() <<
		"\tgradeExecute: " << rhs.getGradeExecute() << ".";
	return os;
}
