#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"



void initBureaucrat(std::string b_name, int b_grade, Bureaucrat& bureaucrat)
{
	try
	{
		bureaucrat = Bureaucrat(b_name, b_grade);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

void	formExecute(Bureaucrat& bureaucrat, AForm* form)
{
	std::cout << GREEN << bureaucrat << RESET << std::endl;
	std::cout << "-----" << std::endl;
	std::cout << GREEN << *form << RESET << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	delete form;
}

void	testFunc(std::string b_name, int b_grade, std::string f_name, std::string f_target)
{
	Intern intern;
	Bureaucrat	bureaucrat;
	AForm* form;

	initBureaucrat(b_name, b_grade, bureaucrat);
	form = intern.makeForm(f_name, f_target);
	formExecute(bureaucrat, form);
}

int main( void )
{

	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
