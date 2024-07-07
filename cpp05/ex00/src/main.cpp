/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/07/07 14:13:37 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int runTest(int choice) 
{
        if (choice == 1) 
        {
            PRINT_COLOR(YELLOW, "<-------Test 1: two correct Bureaucrats and one with a grade too high-------->");
            try {
                Bureaucrat b1;
                Bureaucrat b2("Lula da Silva", 45);
                Bureaucrat b3("Jair Bolsonaro", 0);
                
            } catch (Bureaucrat::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
            } catch (Bureaucrat::GradeTooLowException & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 2) 
        {
            PRINT_COLOR(YELLOW, "<-------Test 2: one Bureaucrat with a grade too low-------------->");
            try {
                Bureaucrat b1("Marina Silva", 151);
                
            } catch (Bureaucrat::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
            } catch (Bureaucrat::GradeTooLowException & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 3)  
        {
            PRINT_COLOR(YELLOW, "<----------Test 3: increment too much a Bureaucrat---------------->");
            try {
                Bureaucrat b1("Lula da Silva", 2);
                std::cout << b1;
                b1.incrementGrade();
                std::cout << b1;
                b1.incrementGrade();
                std::cout << b1;

            } catch (Bureaucrat::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
            } catch (Bureaucrat::GradeTooLowException & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 4)  
        {
            PRINT_COLOR(YELLOW, "<---Test 4: decrement too much a Bureaucrat--->");
            try {
                Bureaucrat b1("Jair Bolsonaro", 149);
                Bureaucrat b2 = b1;
                
                std::cout << b2;
                b2.decrementGrade();
                std::cout << b2;
                b2.decrementGrade();
                std::cout << b2;

            } catch (Bureaucrat::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
            } catch (Bureaucrat::GradeTooLowException & e) {
                std::cout << e.what() << std::endl;
            }
        }
         else if (choice == 5)  
        {
            PRINT_COLOR(YELLOW, "<----------Test 5: All Bureaucrats ok-------------->");
            try {
                Bureaucrat b1("Lula da Silva", 45);
                Bureaucrat b2("Jair Bolsonaro", 100);
                Bureaucrat b3("Marina Silva", 150);
                std::cout << b1;
                std::cout << b2;
                std::cout << b3;

            } catch (Bureaucrat::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
            } catch (Bureaucrat::GradeTooLowException & e) {
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
    // int choise;

    PRINT_COLOR(PINK, "---------------------------------------------");
    PRINT_COLOR(PINK, "Escolha um teste para rodar:");
    PRINT_COLOR(PINK, "[1] Teste 1: two correct Bureaucrats and one with a grade too high");
    PRINT_COLOR(PINK, "[2] Teste 2: one Bureaucrat with a grade too low");
    PRINT_COLOR(PINK, "[3] Teste 3: increment too much a Bureaucrat");
    PRINT_COLOR(PINK, "[4] Teste 4: decrement too much a Bureaucrat");
    PRINT_COLOR(PINK, "[5] Teste 5: all Bureaucrat ok");
    PRINT_COLOR(PINK, "[0] End programa");
    PRINT_COLOR(PINK, "---------------------------------------------");

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
            std::cout << "Saindo do programa..." << std::endl;
        } 
        else 
            std::cout << "Escolha inválida. Por favor, digite 0, 1, 2, 3 ou 4." << std::endl;
    }
    return 0;
}
