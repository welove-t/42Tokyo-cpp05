#include "Bureaucrat.hpp"
#include "Form.hpp"

void test(std::string b_name, int b_grade, std::string f_name, int f_grade_sign, int f_grade_exe)
{
	std::cout << BLUE <<
	"------------------------------------------" << std::endl <<
	" Param"	 								<< std::endl <<
	"   Bureaucrat"	 							<< std::endl <<
	"    - name:\t\t" << b_name	 				<< std::endl <<
	"    - grade:\t\t" << b_grade	 				<< std::endl <<
	"   Form"	 								<< std::endl <<
	"    - name:\t\t" << f_name	 				<< std::endl <<
	"    - gradeSign:\t" << f_grade_sign	 	<< std::endl <<
	"    - gradeEXE:\t\t" << f_grade_exe	 		<< std::endl <<
	"------------------------------------------" << std::endl <<
	RESET << std::endl;

	Bureaucrat	bureaucrat;
	Form		form;

	try
	{
		bureaucrat = Bureaucrat(b_name, b_grade);
		form = Form(f_name, f_grade_sign, f_grade_exe);
		std::cout << GREEN << bureaucrat << RESET << std::endl;
		std::cout << GREEN << form << RESET << std::endl;
		bureaucrat.signForm(form);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	catch(Form::GradeTooLowException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	catch(Form::GradeTooHighException& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int main( void )
{
	test("bureaucrat1", 150, "form1", 151, 150);
	test("bureaucrat2", 150, "form2", 150, 151);
	test("bureaucrat3", 150, "form3", 0, 1);
	test("bureaucrat4", 150, "form4", 1, 0);
	test("bureaucrat5", 150, "form5", 1, 1);
	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
