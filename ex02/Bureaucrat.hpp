#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>

#define RED		"\e[0;31m" // Red
#define GREEN	"\e[0;32m" // Green
#define YELLOW	"\e[0;33m" // Yellow
#define BLUE	"\e[0;34m" // Blue
#define RESET 	"\e[0m"    // Reset

class AForm;
class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
		void				checkOverGrade(const int grade) const;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat(const Bureaucrat& rhs);
		Bureaucrat& operator=(const Bureaucrat& rhs);

		const std::string&	getName(void) const;
		int					getGrade(void) const;

		void	increaseGrade(void);
		void	decreaseGrade(void);
		void	signForm(AForm& form) const;
		void	executeForm(AForm const & form);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};

};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
