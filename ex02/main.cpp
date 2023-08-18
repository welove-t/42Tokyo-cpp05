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

	r.execute(b);
	p.execute(b);

	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
