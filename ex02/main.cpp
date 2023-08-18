#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void )
{
	const Bureaucrat b("b", 120);
	ShrubberyCreationForm s("test");
	RobotomyRequestForm r("robot");
	PresidentialPardonForm p("zzz");

	try
	{

		std::cout << GREEN << b << RESET << std::endl;
		std::cout << GREEN << p << RESET << std::endl;
		r.execute(b);
		p.execute(b);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	catch(AForm::NoSignedException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}


	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
