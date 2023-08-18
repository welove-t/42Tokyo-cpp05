#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main( void )
{
	const Bureaucrat b("b", 120);
	ShrubberyCreationForm s("test");
	RobotomyRequestForm r("robot");

	r.execute(b);
	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
