#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	formExecute(Bureaucrat& bureaucrat, AForm* form)
{
	std::cout << GREEN << bureaucrat << RESET << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << GREEN << *form << RESET << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete form;
}

bool initBureaucrat(std::string b_name, int b_grade, Bureaucrat& bureaucrat)
{
	try
	{
		bureaucrat = Bureaucrat(b_name, b_grade);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return false;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		return false;
	}
	return true;
}

void	testFunc(std::string b_name, int b_grade, std::string f_name, std::string f_target)
{
	Intern intern;
	Bureaucrat	bureaucrat;
	AForm* form;

	if (!initBureaucrat(b_name, b_grade, bureaucrat))
		return ;
	if ((form = intern.makeForm(f_name, f_target)) == NULL)
		return ;
	formExecute(bureaucrat, form);
}

int main( void )
{
	testFunc("bureaucrat1", 151, "shrubbery creation", "piyo");
	testFunc("bureaucrat2", 137, "shrubbery creation", "home");
	testFunc("bureaucrat3", 45, "robotomy request", "nop");
	testFunc("bureaucrat4", 5, "presidential pardon", "terabu");
	testFunc("bureaucrat4", 5, "bad", "piyo");
	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
