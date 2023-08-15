#include "Bureaucrat.hpp"

/* Orthodox Canonical Form */
Bureaucrat::Bureaucrat()
{
	std::cout << "(Bureaucrat) Default Constructor called" << std::endl;
}

// Bureaucrat::Bureaucrat(std::string type):type(type)
// {
// 	std::cout << "(Bureaucrat) Constructor called" << std::endl;
// }

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : type(rhs.type)
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
	// type = rhs.type;
	std::cout << "(Bureaucrat) Copy assignment operator called" << std::endl;
	return *this;
}

/* Function */

