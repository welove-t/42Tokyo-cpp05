#include "Bureaucrat.hpp"

/* Orthodox Canonical Form */
Bureaucrat::Bureaucrat():_name(""), _grade(1)
{
	std::cout << "(Bureaucrat) Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) :_name(name), _grade(grade)
{
	std::cout << "(Bureaucrat) Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : _name(rhs._name), _grade(rhs._grade)
{
	std::cout << "(Bureaucrat) Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "(Bureaucrat) Destructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this == &rhs)
		return *this;
	const_cast<std::string&>(_name) = rhs._name;
	_grade = rhs._grade;
	std::cout << "(Bureaucrat) Copy assignment operator called" << std::endl;
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
	_grade--;
}

void	Bureaucrat::decreaseGrade(void)
{
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too low";
}
