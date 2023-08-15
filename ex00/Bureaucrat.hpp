#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define RED		"\e[0;31m" // Red
#define GREEN	"\e[0;32m" // Green
#define YELLOW	"\e[0;33m" // Yellow
#define BLUE	"\e[0;34m" // Blue
#define RESET 	"\e[0m"    // Reset

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
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
		void	checkOverGrade(const int grade) const;

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

#endif
