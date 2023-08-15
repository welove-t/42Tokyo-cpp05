#include "Bureaucrat.hpp"

int main( void )
{
	Bureaucrat b("hoge", 1);

	std::cout << "name: " << b.getName() << "\tgrade: " << b.getGrade() << std::endl;
	return	0;
}

__attribute((destructor))
static void destructor() {
	system("leaks -q main");
}
