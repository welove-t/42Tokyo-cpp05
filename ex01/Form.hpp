#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

#define RED		"\e[0;31m" // Red
#define GREEN	"\e[0;32m" // Green
#define YELLOW	"\e[0;33m" // Yellow
#define BLUE	"\e[0;34m" // Blue
#define RESET 	"\e[0m"    // Reset

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;
		void				checkOverGrade(const int grade) const;
	public:
		Form();
		Form::Form(std::string name, const int gradeSign, const int gradeExecute);
		~Form();

		Form(const Form& rhs);
		Form& operator=(const Form& rhs);

		const std::string&	getName(void) const;
		int					getIsSigned(void) const;
		const int			getGradeSign(void) const;
		const int			getGradeExecute(void) const;

		void				beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException
		{
			public:
				const char* what() const throw();
		};

};

std::ostream&	operator<<(std::ostream& os, const Form& rhs);

#endif
