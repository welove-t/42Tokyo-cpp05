#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat b("hoge", 150);

	try
	{
		b.checkOverGrade(0);
		b.checkOverGrade(150);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	std::cout << "name: " << b.getName() << "\tgrade: " << b.getGrade() << std::endl;
	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
