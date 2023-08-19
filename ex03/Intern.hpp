#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		static const int			formSize = 3;
		static const std::string 	formName[formSize];
	public:
		Intern();
		~Intern();

		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);

		int		getIndexForm(std::string name);
		AForm*	makeForm(const std::string& formName, const std::string& target);
};


#endif
