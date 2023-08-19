#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


// void	testFunc(std::string b_name, int b_grade)
// {
// 	Bureaucrat	bureaucrat;
// 	const int ALLOC_COUNT = 3;
//     AForm* form[ALLOC_COUNT] = {nullptr};

// 	try
// 	{
// 		bureaucrat = Bureaucrat(b_name, b_grade);
// 		form[0] = new ShrubberyCreationForm("home");
// 		form[1] = new RobotomyRequestForm("Marvin");
// 		form[2] = new PresidentialPardonForm("Arthur");
// 	}
// 	catch(Bureaucrat::GradeTooLowException& e)
// 	{
// 		std::cout << RED << e.what() << RESET << std::endl;
// 		for (int i = 0; i < ALLOC_COUNT; ++i)
// 		{
//         	delete form[i];
//         	form[i] = nullptr;
//    		}
// 		return ;
// 	}
// 	catch(Bureaucrat::GradeTooHighException& e)
// 	{
// 		std::cout << RED << e.what() << RESET << std::endl;
// 		for (int i = 0; i < ALLOC_COUNT; ++i)
// 		{
//         	delete form[i];
//         	form[i] = nullptr;
//    		}
// 		return ;
// 	}
// 	catch (const std::bad_alloc& e)
// 	{
//         std::cerr << RED<< "Memory allocation failed." << e.what() << RESET << std::endl;
//         for (int i = 0; i < ALLOC_COUNT; ++i)
// 		{
//             delete form[i];
//             form[i] = nullptr;
//         }
// 	}

// 	std::cout << GREEN << bureaucrat << RESET << std::endl;
// 	std::cout << "-----" << std::endl;

// 	for (int i = 0; i < 3; i++)
// 	{
// 		std::cout << GREEN << *form[i] << RESET << std::endl;
// 		bureaucrat.signForm(*form[i]);
// 		bureaucrat.executeForm(*form[i]);
// 		delete form[i];
// 	}

// }

bool init(std::string b_name, int b_grade, Bureaucrat& bureaucrat, AForm* form[], const int ALLOC_COUNT)
{
	try
	{
		bureaucrat = Bureaucrat(b_name, b_grade);
		form[0] = new ShrubberyCreationForm("home");
		form[1] = new RobotomyRequestForm("Marvin");
		form[2] = new PresidentialPardonForm("Arthur");
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		for (int i = 0; i < ALLOC_COUNT; ++i)
		{
			delete form[i];
			form[i] = nullptr;
		}
		return false;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
		for (int i = 0; i < ALLOC_COUNT; ++i)
		{
			delete form[i];
			form[i] = nullptr;
		}
		return false;
	}
	catch (const std::bad_alloc& e)
	{
		std::cerr << RED << "Memory allocation failed: " << e.what() << RESET << std::endl;
		for (int i = 0; i < ALLOC_COUNT; ++i)
		{
			delete form[i];
			form[i] = nullptr;
		}
		return false;
	}
	return true;
}

void formExecute(Bureaucrat& bureaucrat, AForm* form[], const int ALLOC_COUNT)
{
	std::cout << GREEN << bureaucrat << RESET << std::endl;
	std::cout << "-----" << std::endl;

	for (int i = 0; i < ALLOC_COUNT; i++)
	{
		std::cout << GREEN << *form[i] << RESET << std::endl;
		bureaucrat.signForm(*form[i]);
		bureaucrat.executeForm(*form[i]);
		delete form[i];
		form[i] = nullptr;
	}
}

void testFunc(std::string b_name, int b_grade)
{
	Bureaucrat	bureaucrat;
	const int ALLOC_COUNT = 3;
	AForm* form[ALLOC_COUNT] = {nullptr};

	if (init(b_name, b_grade, bureaucrat, form, ALLOC_COUNT))
	{
		formExecute(bureaucrat, form, ALLOC_COUNT);
	}
}

int main( void )
{
	std::cout << BLUE <<
	"-------------------------------------" << std::endl <<
	"[ TEST 1 ]"	 << std::endl <<
	"Form\t\t " << "Sign\t" << "Exec" << std::endl <<
	"Shrubbery\t:" << " x\t"<< " x" << std::endl <<
	"Robotomy\t:" << " x\t"<< " x" << std::endl <<
	"Presidential\t:" << " x\t"<< " x" << std::endl <<
	"-------------------------------------" << std::endl <<
	RESET << std::endl;
	testFunc("bureaucrat1", 146);

	std::cout << BLUE <<
	"-------------------------------------" << std::endl <<
	"[ TEST 2 ]"	 << std::endl <<
	"Form\t\t " << "Sign\t" << "Exec" << std::endl <<
	"Shrubbery\t:" << " ○\t"<< " x" << std::endl <<
	"Robotomy\t:" << " x\t"<< " x" << std::endl <<
	"Presidential\t:" << " x\t"<< " x" << std::endl <<
	"-------------------------------------" << std::endl <<
	RESET << std::endl;
	testFunc("bureaucrat2", 138);

	std::cout << BLUE <<
	"-------------------------------------" << std::endl <<
	"[ TEST 3 ]"	 << std::endl <<
	"Form\t\t " << "Sign\t" << "Exec" << std::endl <<
	"Shrubbery\t:" << " ○\t"<< " ○" << std::endl <<
	"Robotomy\t:" << " x\t"<< " x" << std::endl <<
	"Presidential\t:" << " x\t"<< " x" << std::endl <<
	"-------------------------------------" << std::endl <<
	RESET << std::endl;
	testFunc("bureaucrat3", 73);

	std::cout << BLUE <<
	"-------------------------------------" << std::endl <<
	"[ TEST 4 ]"	 << std::endl <<
	"Form\t\t " << "Sign\t" << "Exec" << std::endl <<
	"Shrubbery\t:" << " ○\t"<< " ○" << std::endl <<
	"Robotomy\t:" << " ○\t"<< " x" << std::endl <<
	"Presidential\t:" << " x\t"<< " x" << std::endl <<
	"-------------------------------------" << std::endl <<
	RESET << std::endl;
	testFunc("bureaucrat4", 46);

	std::cout << BLUE <<
	"-------------------------------------" << std::endl <<
	"[ TEST 5 ]"	 << std::endl <<
	"Form\t\t " << "Sign\t" << "Exec" << std::endl <<
	"Shrubbery\t:" << " ○\t"<< " ○" << std::endl <<
	"Robotomy\t:" << " ○\t"<< " ○" << std::endl <<
	"Presidential\t:" << " x\t"<< " x" << std::endl <<
	"-------------------------------------" << std::endl <<
	RESET << std::endl;
	testFunc("bureaucrat5", 26);

	std::cout << BLUE <<
	"-------------------------------------" << std::endl <<
	"[ TEST 6 ]"	 << std::endl <<
	"Form\t\t " << "Sign\t" << "Exec" << std::endl <<
	"Shrubbery\t:" << " ○\t"<< " ○" << std::endl <<
	"Robotomy\t:" << " ○\t"<< " ○" << std::endl <<
	"Presidential\t:" << " ○\t"<< " x" << std::endl <<
	"-------------------------------------" << std::endl <<
	RESET << std::endl;
	testFunc("bureaucrat6", 6);

	std::cout << BLUE <<
	"-------------------------------------" << std::endl <<
	"[ TEST 7 ]"	 << std::endl <<
	"Form\t\t " << "Sign\t" << "Exec" << std::endl <<
	"Shrubbery\t:" << " ○\t"<< " ○" << std::endl <<
	"Robotomy\t:" << " ○\t"<< " ○" << std::endl <<
	"Presidential\t:" << " ○\t"<< " ○" << std::endl <<
	"-------------------------------------" << std::endl <<
	RESET << std::endl;
	testFunc("bureaucrat7", 5);

	std::cout << BLUE <<
	"-------------------------------------" << std::endl <<
	"[ Leaks Test ]"	 << std::endl <<
	"-------------------------------------" <<
	RESET << std::endl;
	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
