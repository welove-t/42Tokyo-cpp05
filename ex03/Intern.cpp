#include "Intern.hpp"

/* Orthodox Canonical Form */
Intern::Intern()
: formName{"shrubbery creation", "robotomy request", "presidential pardon"}
{
	std::cout << "(Intern) Default Constructor called" << std::endl;

}

Intern::Intern(const Intern& rhs)
{
	std::cout << "(Intern) Copy Constructor called" << std::endl;
	 for (int i = 0; i < formSize; ++i)
		const_cast<std::string&>(formName[i]) = rhs.formName[i];
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
	for (int i = 0; i < formSize; ++i)
		const_cast<std::string&>(formName[i]) = rhs.formName[i];
	return *this;
}

/* Function */
AForm*	Intern::makeForm(std::string form, std::string target)
{

}
