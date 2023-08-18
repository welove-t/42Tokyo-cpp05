#include "AForm.hpp"

/* Orthodox Canonical Form */
AForm::AForm() :_name(""), _isSigned(false), _gradeSign(150), _gradeExecute(150)
{
	std::cout << "(AForm) Default Constructor called" << std::endl;
}

AForm::AForm(std::string name, const int gradeSign, const int gradeExecute)
:_name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute)
{
	std::cout << "(AForm) Constructor called" << std::endl;
	checkOverGrade(gradeSign);
	checkOverGrade(gradeExecute);
}

AForm::AForm(const AForm& rhs)
: _name(rhs._name), _isSigned(rhs._isSigned), _gradeSign(rhs._gradeSign), _gradeExecute(rhs._gradeExecute)
{
	std::cout << "(AForm) Copy Constructor called"  << std::endl;
}

AForm::~AForm()
{
	std::cout << "(AForm) Destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& rhs)
{
	std::cout << "(AForm) Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	const_cast<std::string&>(_name) = rhs._name;
	_isSigned = rhs._isSigned;
	const_cast<int&>(_gradeSign) = rhs._gradeSign;
	const_cast<int&>(_gradeExecute) = rhs._gradeExecute;
	return *this;
}

/* Getter */
const std::string&	AForm::getName(void) const
{
	return _name;
}

int	AForm::getIsSigned(void) const
{
	return _isSigned;
}

int	AForm::getGradeSign(void) const
{
	return _gradeSign;
}

int	AForm::getGradeExecute(void) const
{
	return _gradeExecute;
}

/* Function */

void	AForm::checkOverGrade(const int grade) const
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
	else if (grade < 1)
		throw AForm::GradeTooHighException();
	else
		return;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw AForm::GradeTooLowException();
	_isSigned = true;
}

void	AForm::checkExecutable(const Bureaucrat& bureaucrat) const
{
	if (_isSigned == false)
		throw NoSignedException();
	if (_gradeExecute < bureaucrat.getGrade())
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char* AForm::NoSignedException::what() const throw()
{
	return "No Signed";
}

std::ostream&	operator<<(std::ostream& os, const AForm& rhs)
{
	os << "< AForm > \n" <<
		"name:\t\t" <<rhs.getName() << "\n" <<
		"isSigned:\t" << rhs.getIsSigned() << "\n" <<
		"gradeSign:\t" << rhs.getGradeSign() << "\n" <<
		"gradeExecute:\t" << rhs.getGradeExecute();
	return os;
}
