/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/06/30 15:15:18 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int runTest(int choice) 
{
       Bureaucrat	ceo("CEO", 1);

        AForm* presidentialForm;
        AForm* robotomyForm;
        AForm* shrubberyForm;
        AForm* wrongForm;
        Intern randomIntern;

        if (choice == 1) 
        {
            PRINT_COLOR(YELLOW, "<-------Test 1: Presidential Form -------->");
            try {
                    presidentialForm = randomIntern.makeForm("presidential pardon", "Robert");
                    ceo.signForm(*presidentialForm);
                    ceo.executeForm(*presidentialForm);
                    delete presidentialForm;
		
                 } catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 2) 
        {
            PRINT_COLOR(YELLOW, "<-------Robotomy Form Test-------------->");
            try {
                
                robotomyForm = randomIntern.makeForm("robotomy request", "Marvin");
                ceo.signForm(*robotomyForm);
                ceo.executeForm(*robotomyForm);

                delete robotomyForm;
                
             } catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 3)  
        {
            PRINT_COLOR(YELLOW, "<----------Shrubbery Form Test------------------->");
            try {
               shrubberyForm = randomIntern.makeForm("shrubbery creation", "Beach");
                ceo.signForm(*shrubberyForm);
                ceo.executeForm(*shrubberyForm);

                delete shrubberyForm;
                
            } catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 4)  
        {
            PRINT_COLOR(YELLOW, "<---------- Wrong Form Test ------------------->");
            try {
               wrongForm = randomIntern.makeForm("test form", "abcd-e");
               delete wrongForm;
                
             } catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else
            std::cout << "Escolha inválida. Por favor, digite 1, 2, 3 ou 4." << std::endl;
        return(choice);
}

void getInput(int &userInput) {
    PRINT_COLOR(PINK,"Choice a number: ");
    std::cin >> userInput;
}

int menu() 
{

    PRINT_COLOR(PINK, "-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#--#-#-#-#-#");
    PRINT_COLOR(PINK, "Escolha um teste para rodar:");
    PRINT_COLOR(PINK, "[1] Teste 1: Presidential Form");
    PRINT_COLOR(PINK, "[2] Teste 2: Robotomy Form");
    PRINT_COLOR(PINK, "[3] Teste 3: Shrubbery Form");
    PRINT_COLOR(PINK, "[4] Teste 4: Wrong Form");
    PRINT_COLOR(PINK, "[0] End programa");
    PRINT_COLOR(PINK, "-#-#-#-#-#--#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#-#");

    int userInput;
    getInput(userInput);

    return(userInput);
}

int main() 
{   
    int choice = -1;
    
    while (choice != 0) 
    {
        choice = menu();
        if(choice >= 1 && choice <= 5)
            runTest(choice);
        else if (choice == 0)
        {
            std::cout << "END PROG!!..." << std::endl;
        } 
        else 
            std::cout << "Escolha inválida. Por favor, digite 0, 1, 2, 3 ou 4." << std::endl;
    }
    return 0;
}
