#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main( void )
{
	const Bureaucrat b("b", 120);
	ShrubberyCreationForm s("test");

	s.execute(b);
	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
