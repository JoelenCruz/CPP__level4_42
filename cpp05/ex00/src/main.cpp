/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/06/24 16:15:01 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

// Função para executar um teste específico
int runTest(int choice) {
    switch (choice) 
    {
        case 1: {
            PRINT_COLOR(YELLOW, "<-------Test 1: two correct Bureaucrats and one with a grade too high-------->");
            try {
                Bureaucrat b1;
                Bureaucrat b2("Lula da Silva", 45);
                
                std::cout << b1;
                std::cout << b2;
                
                Bureaucrat b3("Jair Bolsonaro", 0);
                
            } catch (Bureaucrat::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta caracteres inválidos no buffer
            } catch (Bureaucrat::GradeTooLowException & e) {
                std::cout << e.what() << std::endl;
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta caracteres inválidos no buffer
            }
            break;
        }
        case 2: {
            PRINT_COLOR(YELLOW, "<-------Test 2: one Bureaucrat with a grade too low-------------->")
            try {
                Bureaucrat b1("Marina Silva", 151);
                
            } catch (Bureaucrat::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta caracteres inválidos no buffer
            } catch (Bureaucrat::GradeTooLowException & e) {
                std::cout << e.what() << std::endl;
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta caracteres inválidos no buffer
            }
            break;
        }
        case 3: {
            PRINT_COLOR(YELLOW, "<----------Test 3: increment too much a Bureaucrat---------------->")
            try {
                Bureaucrat b1("Lula da Silva", 2);
                std::cout << b1;
                b1.incrementGrade();
                std::cout << b1;
                b1.incrementGrade();
                std::cout << b1;

            } catch (Bureaucrat::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta caracteres inválidos no buffer
            } catch (Bureaucrat::GradeTooLowException & e) {
                std::cout << e.what() << std::endl;
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta caracteres inválidos no buffer
            }
            break;
        }
        case 4: {
            PRINT_COLOR(YELLOW, "<---Test 4: decrement too much a Bureaucrat--->")
            try {
                Bureaucrat b1("Jair Bolsonaro", 149);
                std::cout << b1;
                b1.decrementGrade();
                std::cout << b1;
                b1.decrementGrade();
                std::cout << b1;

            } catch (Bureaucrat::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta caracteres inválidos no buffer
            } catch (Bureaucrat::GradeTooLowException & e) {
                std::cout << e.what() << std::endl;
                std::cin.clear(); // Limpa o estado de erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta caracteres inválidos no buffer
            }
            break;
        }
        default:
            std::cout << "Escolha inválida. Por favor, digite 1, 2, 3 ou 4." << std::endl;
            std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta caracteres inválidos no buffer
            break;
    }
    return (0);
}

int menu() {
    int choice = -1;

    PRINT_COLOR(GREEN, "---------------------------------------------");
    PRINT_COLOR(YELLOW, "Escolha um teste para rodar:");
    PRINT_COLOR(GREEN, "[1] Teste 1: two correct Bureaucrats and one with a grade too high");
    PRINT_COLOR(GREEN, "[2] Teste 2: one Bureaucrat with a grade too low");
    PRINT_COLOR(GREEN, "[3] Teste 3: increment too much a Bureaucrat");
    PRINT_COLOR(GREEN, "[4] Teste 4: decrement too much a Bureaucrat");
    PRINT_COLOR(GREEN, "[0] Sair do programa");
    PRINT_COLOR(GREEN, "---------------------------------------------");

    std::cin >> choice;
    return choice;
}

int main() {
    int choice = -1;

    while (choice != 0) 
    {
        choice = menu();
        if(choice >= 1 && choice <= 4)
            runTest(choice);
        else if (choice == 0) 
            std::cout << "Saindo do programa..." << std::endl;
        else 
        {
            std::cout << "Escolha inválida. Por favor, digite 0, 1, 2, 3 ou 4." << std::endl;
            std::cin.clear(); // Limpa o estado de erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Descarta caracteres inválidos no buffer
        }
            
    }
    return 0;
}