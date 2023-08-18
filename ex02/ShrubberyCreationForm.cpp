#include "ShrubberyCreationForm.hpp"

/* Orthodox Canonical Form */
ShrubberyCreationForm::ShrubberyCreationForm()
: AForm("", _gradeSign, _gradeExecute), _target("")
{
	std::cout << "(ShrubberyCreationForm) Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm(target, _gradeSign, _gradeExecute), _target(target)
{
	std::cout << "(ShrubberyCreationForm) Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
: AForm(rhs), _target(rhs._target)
{
	std::cout << "(ShrubberyCreationForm) Copy Constructor called"  << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "(ShrubberyCreationForm) Destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << "(ShrubberyCreationForm) Copy assignment operator called" << std::endl;
	if (this == &rhs)
		return *this;
	const_cast<std::string&>(_target) = rhs._target;
	AForm::operator=(rhs);
	return *this;
}

/* Function */
void	ShrubberyCreationForm::DrawTree(std::ofstream& out, int height) const
{
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < height - i - 1; ++j) {
			out << ' ';
		}
		for (int j = 0; j < 2 * i + 1; ++j) {
			out << '*';
		}
		out << std::endl;
	}
	int trunk_height = height / 4;
	int trunk_width = height / 10;

	for (int i = 0; i < trunk_height; ++i) {
		for (int j = 0; j < height - trunk_width - 1; ++j) {
			out << ' ';
		}
		for (int j = 0; j < 2 * trunk_width + 1; ++j) {
			out << '*';
		}
		out << std::endl;
	}
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::ofstream outFile((_target + "_shrubbery").c_str());
	(void)executor.getName();
	if (!outFile)
	{
		std::cerr << "Failed to open the file." << std::endl;
		return ;
	}
	DrawTree(outFile, 25);
	outFile.close();
}
