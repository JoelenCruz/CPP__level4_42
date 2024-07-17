/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:12:05 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/17 01:01:09 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"


// =============================================================================
// Exceptions
// =============================================================================

const char* PmergeMe::JustNumbers::what() const throw()
{
    PRINT_COLOR(RED, "Error: just numbers positives");
    return " ";
}

// =============================================================================
// Constructors and Destructor
// =============================================================================

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(int argc, char* argv[])
{
    if (argc < 2)
		throw JustNumbers();

	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			if (!std::isdigit(argv[i][j]))
				throw JustNumbers();
		}
	}
    
    PRINT_COLOR(PINK, "\n \n VECTOR");
	initVector(argc, argv);
    printVector(YELLOW);
    measureExecutionTimeVector();
    printVector(GREEN);
    
    PRINT_COLOR(PINK, "\n \n DEQUE");
	initDeque(argc, argv);
    printDeque(YELLOW);
    measureExecutionTimeDeque();
    printDeque(GREEN);
    
}

PmergeMe::PmergeMe(const PmergeMe& a)
{
	(void) a;
}

PmergeMe::~PmergeMe() {}

// =============================================================================
// FUNCTIONS
// =============================================================================


//	VECTOR FUNCTIONS

void PmergeMe::printVector(std::string color) const
{
    for (std::vector<int>::size_type i = 0; i < _vector.size(); ++i)
    {
        PRINT_COLOR_N(color, _vector[i] << " ");
    }
    std::cout << std::endl;
}

void	PmergeMe::initVector(int size, char** args)
{
	int	current_value;

	for (int i = 0; i < (size - 1); i++)
	{
		current_value = std::strtol(args[i + 1], NULL, 10);
		if (current_value < 0 || current_value > INT_MAX)
			throw JustNumbers();
		_vector.push_back(current_value);
	}
}


void PmergeMe::insertionSortVector(int left, int right)
{
    for (int i = left + 1; i <= right; ++i) {
        int key = _vector[i];
        int j = i - 1;
        while (j >= left && _vector[j] > key) {
            _vector[j + 1] = _vector[j];
            --j;
        }
        _vector[j + 1] = key;
    }
}

void PmergeMe::mergeVector(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = _vector[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = _vector[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            _vector[k] = L[i];
            ++i;
        } else {
            _vector[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        _vector[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        _vector[k] = R[j];
        ++j;
        ++k;
    }
}




void PmergeMe::fordJohnsonSortVector(int left, int right)
{
    if (left < right) 
    {
        int mid = left + (right - left) / 2;
        fordJohnsonSortVector(left, mid);
        fordJohnsonSortVector(mid + 1, right);
        mergeVector(left, mid, right);
    }
}

void PmergeMe::measureExecutionTimeVector()
{
    clock_t start = clock();
    fordJohnsonSortVector(0, _vector.size() - 1);
    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000.0; // Medir em microssegundos
    PRINT_COLOR(BLUE, "\nTime for vector: " << elapsed << " us\n");
}



//	DEQUE FUNCTIONSdeque
void PmergeMe::printDeque(std::string color) const
{
    for (std::deque<int>::size_type i = 0; i < _deque.size(); ++i)
    {
        PRINT_COLOR_N(color, _deque[i] << " ");
    }
    std::cout << std::endl;
}


void	PmergeMe::initDeque(int size, char** args)
{
	int	current_value;

	for (int i = 0; i < (size - 1); i++)
	{
		current_value = std::strtol(args[i + 1], NULL, 10);
		if (current_value < 0 || current_value > INT_MAX)
			throw JustNumbers();
		_deque.push_back(current_value);
	}
}

void PmergeMe::insertionSortDeque(int left, int right)
{
    for (int i = left + 1; i <= right; ++i) {
        int key = _deque[i];
        int j = i - 1;
        while (j >= left && _deque[j] > key) {
            _deque[j + 1] = _deque[j];
            --j;
        }
        _deque[j + 1] = key;
    }
}


void PmergeMe::mergeDeque(int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::deque<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = _deque[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = _deque[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            _deque[k] = L[i];
            ++i;
        } else {
            _deque[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        _deque[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        _deque[k] = R[j];
        ++j;
        ++k;
    }
}

void PmergeMe::fordJohnsonSortDeque(int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        fordJohnsonSortDeque(left, mid);
        fordJohnsonSortDeque(mid + 1, right);
        mergeDeque(left, mid, right);
    }
}


void PmergeMe::measureExecutionTimeDeque()
{
    clock_t start = clock();
    fordJohnsonSortDeque(0, _deque.size() - 1);
    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000.0; // Medir em microssegundos
    PRINT_COLOR(BLUE, "\nTime for deque: " << elapsed << " us\n");
}
