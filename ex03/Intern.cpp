#include "Intern.hpp"

/* Orthodox Canonical Form */
Intern::Intern()
{
	std::cout << "(Intern) Default Constructor called" << std::endl;
}

Intern::Intern(const Intern& rhs)
{
	std::cout << "(Intern) Copy Constructor called" << std::endl;
}

Intern::~Intern()
{
	std::cout << "(Intern) Destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& rhs)
{
	std::cout << "(Intern) Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	return *this;
}

/* Function */
