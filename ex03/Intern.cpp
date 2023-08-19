#include "Intern.hpp"

const std::string Intern::formName[formSize] =
{
	"shrubbery creation",
	"robotomy request",
	"presidential pardon",
};

/* Orthodox Canonical Form */
Intern::Intern()
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
AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	AForm *form;

	try
	{
		switch (1)
		{
			case 0:
				form = new ShrubberyCreationForm(target);
				break;
			case 1:
				form = new RobotomyRequestForm(target);
				break;
			case 2:
				form = new PresidentialPardonForm(target);
				break;
			default:
				throw badFormException();

		}
	}
	catch(const Intern::badFormException& e)
	{
		std::cout << RED << formName << " is not an eligible form" << std::endl;
		return NULL;
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << RESET << std::endl;
		return NULL;
	}

	std::cout << GREEN << "Intern creates " << form << std::endl;
	return form;
}

int		Intern::getIndexForm(const std::string& name)
{
	for (int i = 0; i < formSize; i++)
	{
		if (name == formName[i])
			return i;
	}
	return -1;
}
