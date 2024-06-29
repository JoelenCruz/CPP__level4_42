/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joe <joe@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:59:06 by joe               #+#    #+#             */
/*   Updated: 2024/06/29 17:15:28 by joe              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

#include "../includes/Form.hpp"

int runTest(int choice) 
{
        if (choice == 1) 
        {
            PRINT_COLOR(YELLOW, "<-------Test 1: bureaucrat can sing the form-------->");
            try {
                    Bureaucrat	bureaucrat("Sr.John", 50);
                    Form		form("Get A Private Office", 50, 20);
                    
                    PRINT_COLOR(GREEN, form);
                    bureaucrat.signForm(form);
                    PRINT_COLOR(GREEN, form);
		
                } catch (Form::GradeTooHighException& e) {
                    std::cout << e.what();
                } catch (Form::GradeTooLowException& e) {
                    std::cout << e.what();
                }
        }
        else if (choice == 2) 
        {
            PRINT_COLOR(YELLOW, "<-------Test 2: bureaucrat can not sing the form-------------->");
            try {
                
                Bureaucrat	bureaucrat("Sr.Apple", 75);
                Form		form("Get A Company Car", 40, 150);
                PRINT_COLOR(GREEN, form);
                bureaucrat.signForm(form);
                PRINT_COLOR(GREEN, form);

		      
                
            } catch (Form::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
            } catch (Form::GradeTooLowException & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 3)  
        {
            PRINT_COLOR(YELLOW, "<----------Test 3: form can not be instanciated (Grade Too High)------------------->");
            try {
               Bureaucrat	bureaucrat("Sra.Teacup", 1);
               Form		form("Get To Be CEO", 0, 1);
               PRINT_COLOR(GREEN, form);


            } catch (Form::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
            } catch (Form::GradeTooLowException & e) {
                std::cout << e.what() << std::endl;
            }
        }
        else if (choice == 4)  
        {
            PRINT_COLOR(YELLOW, "<---Test 4: form can not be instanciated (Grade Too Low)--->");
            try 
            {
                Bureaucrat	bureaucrat("Sra.Teacup", 10);
                Form		form("Get To Be CEO", 154, 1);

                PRINT_COLOR(GREEN, form);               
                bureaucrat.signForm(form);
                PRINT_COLOR(GREEN, form);

            } catch (Form::GradeTooHighException & e) {
                std::cout << e.what() << std::endl;
            } catch (Form::GradeTooLowException & e) {
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
    PRINT_COLOR(PINK, "[1] Teste 1: bureaucrat can sing the form");
    PRINT_COLOR(PINK, "[2] Teste 2: bureaucrat can not sing the form");
    PRINT_COLOR(PINK, "[3] Teste 3: form can not be instanciated");
    PRINT_COLOR(PINK, "[4] Teste 4: form can not be instanciated");
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
            std::cout << "END PROG!!..." << std::endl;
        } 
        else 
            std::cout << "Escolha inválida. Por favor, digite 0, 1, 2, 3 ou 4." << std::endl;
    }
    return 0;
}
