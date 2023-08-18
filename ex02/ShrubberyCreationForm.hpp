#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

class ShrubberyCreationForm :public AForm
{
	private:
		const std::string	_target;
		static const int	_gradeSign = 145;
		static const int	_gradeExecute = 137;
		void				DrawTree(std::ofstream& out, int height) const;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

		void	execute(Bureaucrat const & executor) const;

};

#endif
