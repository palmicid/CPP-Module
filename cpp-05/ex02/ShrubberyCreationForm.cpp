#include "ShrubberyCreationForm.hpp"

static inline void	writeTree2File(std::string const &target)
{
	std::ofstream	fout(target + "_shrubbery");
	if (!fout.is_open()) {
		std::cout << "Error: can not open file" << std::endl;
		return ;
	}
	fout << "            ,@@@@@@@," << std::endl;
    fout << "    ,,,.   ,@@@@@@K@@,  .oo8888o." << std::endl;
    fout << " ,&%%&%&&%,@@@@@K@@@@@@,8888K88K8o" << std::endl;
	fout << ",%&|%&&%&&%,@@@|@@@K@@@88|88888K88'" << std::endl;
	fout << "%&&%&%&K%&&%@@|@@K K@@@88888|88888'" << std::endl;
	fout << "%&&%K %&%%&&@@| V K@@' `88|8 `K88'" << std::endl;
	fout << " `&%| ` K%&'    |.|        | '|8'" << std::endl;
    fout << "     |o|        | |         | | " << std::endl;
    fout << "     |.|        | |         | | " << std::endl;
	fout << "_____| |wwwwwwww|w|wwwwwwwww| | " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("noName")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	_target = other._target;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const { return (_target); }

void	ShrubberyCreationForm::execute(Bureaucrat const &crat) const
{
	AForm::execute(crat);
	writeTree2File(_target);
}
