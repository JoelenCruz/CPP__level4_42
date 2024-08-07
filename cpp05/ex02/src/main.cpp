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

int runTest(int choice) 
{
        Bureaucrat ceo("Elon musk", 1);
        if (choice == 1) 
        {
            PRINT_COLOR(YELLOW, "<-------Test 1: bureaucrat CEO instanciated to sign the forms: -------->");
            try {
                    Bureaucrat	bureaucrat("Chico Buarque", 137);
                    ShrubberyCreationForm	form("Consturção");
                    ceo.signForm(form);
                    bureaucrat.executeForm(form);
		
                 } catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 2) 
        {
            PRINT_COLOR(YELLOW, "<-------bureaucrat can NOT execute the form (Grade Too Low)-------------->");
            try {
                
                Bureaucrat	bureaucrat("Clarice Falção", 148);
                PresidentialPardonForm	form("Oitavo andar");
                ceo.signForm(form);
                bureaucrat.executeForm(form);
                
             } catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 3)  
        {
            PRINT_COLOR(YELLOW, "<----------Test 3: bureaucrat can NOT execute the form (Form Not Signed)------------------->");
            try {
                Bureaucrat	bureaucrat("Los Hermanos", 100);
                ShrubberyCreationForm	form("Ana Julia");
                //ceo.signForm(form);
                bureaucrat.executeForm(form);
                
            } catch (std::exception & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 4)  
        {
            PRINT_COLOR(YELLOW, "<----------Test 3: ROBOTOMY REQUEST FORM TEST------------------->");
            try {
                Bureaucrat	bureaucrat("Edimilson Rodrigues", 40);
                RobotomyRequestForm	form("Robocopy");
                ceo.signForm(form);
                bureaucrat.executeForm(form);
                
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
    PRINT_COLOR(PINK, "[1] Teste 1: bureaucrat can sing the form");
    PRINT_COLOR(PINK, "[2] Teste 2: bureaucrat can not sing the form");
    PRINT_COLOR(PINK, "[3] Teste 3: form can not be instanciated");
    PRINT_COLOR(PINK, "[4] Teste 4: ROBOTOMY tests");
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
