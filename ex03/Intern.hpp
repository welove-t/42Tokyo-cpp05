#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	private:
		static const int	formSize = 3;
		std::string			formName[formSize];
	public:
		Intern();
		~Intern();

		Intern(const Intern& rhs);
		Intern& operator=(const Intern& rhs);

		AForm*	makeForm(std::string form, std::string target);
};


#endif
