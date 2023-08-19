#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

#define RED		"\e[0;31m" // Red
#define GREEN	"\e[0;32m" // Green
#define YELLOW	"\e[0;33m" // Yellow
#define BLUE	"\e[0;34m" // Blue
#define RESET 	"\e[0m"    // Reset

class Bureaucrat;
class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExecute;
		void				checkOverGrade(const int grade) const;
	public:
		AForm();
		AForm(std::string name, const int gradeSign, const int gradeExecute);
		virtual ~AForm();

		AForm(const AForm& rhs);
		AForm& operator=(const AForm& rhs);

		const std::string&	getName(void) const;
		int					getIsSigned(void) const;
		int					getGradeSign(void) const;
		int					getGradeExecute(void) const;

		void				beSigned(const Bureaucrat& bureaucrat);
		void				checkExecutable(const Bureaucrat& bureaucrat) const;
		virtual void		execute(Bureaucrat const & executor) const = 0;

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
		class NoSignedException
		{
			public:
				const char* what() const throw();
		};

};

std::ostream&	operator<<(std::ostream& os, const AForm& rhs);

#endif
