#include "Bureaucrat.hpp"

/* Orthodox Canonical Form */
Bureaucrat::Bureaucrat():_name(""), _grade(150)
{
	std::cout << "(Bureaucrat) Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :_name(name), _grade(grade)
{
	std::cout << "(Bureaucrat) Constructor called" << std::endl;
	checkOverGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name), _grade(rhs._grade)
{
	std::cout << "(Bureaucrat) Copy Constructor called"  << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "(Bureaucrat) Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << "(Bureaucrat) Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	const_cast<std::string&>(_name) = rhs._name;
	_grade = rhs._grade;
	return *this;
}

/* Getter */
const std::string&	Bureaucrat::getName(void) const
{
	return _name;
}

int	Bureaucrat::getGrade(void) const
{
	return _grade;
}

/* Function */
void	Bureaucrat::increaseGrade(void)
{
	checkOverGrade(_grade - 1);
	_grade--;
}

void	Bureaucrat::decreaseGrade(void)
{
	checkOverGrade(_grade + 1);
	_grade++;
}

void	Bureaucrat::checkOverGrade(const int grade) const
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		return;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "< Grade too high >";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "< Grade too low >";
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return os;
}
