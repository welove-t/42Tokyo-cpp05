#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


void	testFunc(std::string b_name, int b_grade)
{
	Bureaucrat	bureaucrat(b_name, b_grade);
	AForm* form[3] =
	{
		new ShrubberyCreationForm("home"),
		new RobotomyRequestForm("Marvin"),
		new PresidentialPardonForm("Arthur")
	};
	std::cout << GREEN << bureaucrat << RESET << std::endl;
	std::cout << "-----" << std::endl;

	int i = 0;
	try
	{
		while (i < 3)
		{
			std::cout << GREEN << *form[i] << RESET << std::endl;
			bureaucrat.signForm(*form[i]);
			form[i]->execute(bureaucrat);
			i++;
		}
	}
	catch(const AForm::NoSignedException& e)
	{
		std::cout << RED <<
			bureaucrat.getName() << " couldn\'t sign " << form[i]->getName() <<
			" because " << e.what() << "." <<
			RESET << std::endl;
	}

}

int main( void )
{
	std::cout << BLUE <<
	"              [ Init Test ]"	 <<
	RESET << std::endl;
	testFunc("bureaucrat1", 1);


	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
