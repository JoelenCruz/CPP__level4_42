/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:12:05 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/19 00:41:00 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"


// =============================================================================
// Exceptions
// =============================================================================

const char* PmergeMe::JustNumbers::what() const throw()
{
    PRINT_COLOR(RED, "Error: all parameters must be positive numbers");
    return " ";
}

const char* PmergeMe::AllEqual::what() const throw()
{
    PRINT_COLOR(RED, "Error: all numbers are equal");
    return " ";
}


const char* PmergeMe::ErrorParameter::what() const throw()
{
    PRINT_COLOR(RED, "Error: in type parameter");
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
    try{
        if (argc < 2)
		    throw ErrorParameter();
    
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
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this == &other)
		return *this;
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe& a)
{
	*this = a;
}

PmergeMe::~PmergeMe() {}

// =============================================================================
// FUNCTIONS VECTOR
// =============================================================================

void PmergeMe::printVector(const std::string& color) const
{
    for (std::vector<int>::size_type i = 0; i < _vector.size(); ++i)
    {
        PRINT_COLOR_N(color, _vector[i] << " ");
    }
    std::cout << std::endl;
}


bool PmergeMe::areAllEqualVector(std::vector<int>& vector) 
{
    if (vector.empty()) {
        return true;
    }

    int first = vector[0];
    for (unsigned int i = 1; i < vector.size(); ++i) {
        if (vector[i] != first) {
            return false;
        }
    }
    return true;
}
void PmergeMe::initVector(int size, char** args) {
    int current_value;
    for (int i = 0; i < (size - 1); ++i) {
        current_value = std::strtol(args[i + 1], NULL, 10);
        if (current_value < 0 || current_value > INT_MAX)
            throw std::invalid_argument("Only positive integers are allowed");
        _vector.push_back(current_value);
    }
}

void PmergeMe::createPairs(const std::vector<int>& vec, std::vector<std::pair<int, int> >& pairs) 
{
    // Iterate over the vector in steps of 2
    for (size_t i = 0; i < vec.size(); i += 2) {
        // If there is a next element, pair the current element with the next one
        if (i + 1 < vec.size()) {
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        } else {
            // If there is no next element, pair the current element with itself
            pairs.push_back(std::make_pair(vec[i], vec[i]));
        }
    }
}

void PmergeMe::insertSorted(std::vector<int>& sorted, int value) {
    std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

std::vector<int> PmergeMe::jacobsthalSequential(int number) 
{
    std::vector<int> vec;
    int current = 0, next = 1; 
    while (next <= number)  // Generate the Jacobsthal sequence up to the specified number
    {
        vec.push_back(next); // Add the current number to the sequence
        int temp = next; // Calculate the next number in the sequence
        next = current + 2 * next;
        current = temp;
    }
    return vec; 
}

std::vector<int> PmergeMe::jacobsthalDiff(int number) 
{
    std::vector<int> differences; // Store the differences between consecutive Jacobsthal numbers
    std::vector<int> jacobsthalNumbers = jacobsthalSequential(number); // Generate the Jacobsthal sequence

    // Iterate over the Jacobsthal sequence starting from the second element
    for (size_t index = 1; index < jacobsthalNumbers.size(); ++index) {
        // Calculate the difference between the current Jacobsthal number and the previous one
        differences.push_back(jacobsthalNumbers[index] - jacobsthalNumbers[index - 1]);
    }

    return differences; // Return the differences
}


void PmergeMe::processPairs(const std::vector<std::pair<int, int> >& inputPairs, 
                            std::vector<int>& pendingElements, 
                            std::vector<int>& sortedElements) 
{
    // Iterate over each pair in the inputPairs vector
    for (std::vector<std::pair<int, int> >::const_iterator pairIterator = inputPairs.begin(); pairIterator != inputPairs.end(); ++pairIterator) 
    {
        const std::pair<int, int>& currentPair = *pairIterator;
        pendingElements.push_back(currentPair.first); // Add the first element of the pair to the pendingElements vector
        sortedElements.push_back(currentPair.second);  // Add the second element of the pair to the sortedElements vector
    }
}


void PmergeMe::mergeAndInsert(std::vector<int>& pendingElements, 
                              std::vector<int>& sortedElements, 
                              int lastElement, 
                              bool isOdd) 
{
    std::vector<int> jacobsthalSequence = jacobsthalDiff(pendingElements.size());
    size_t currentIndex = 0;

    for (size_t i = 0; i < jacobsthalSequence.size(); ++i)// Iterate over the Jacobsthal sequence
    {
        size_t groupSize = jacobsthalSequence[i];
        if (currentIndex >= pendingElements.size()) 
            break;

        std::vector<int> group;
        
        for (size_t j = 0; j < groupSize && currentIndex < pendingElements.size(); ++j) //Create a group of elements from the pendingElements vector 
        {
            group.push_back(pendingElements[currentIndex]);
            ++currentIndex;
        }
        std::reverse(group.begin(), group.end());

        
        for (std::vector<int>::const_iterator it = group.begin(); it != group.end(); ++it)// Insert the elements of the group into the sortedElements vector 
        {
            int num = *it;
            insertSorted(sortedElements, num);
        }
    }

    // Insert the remaining elements from the pendingElements vector
    for (size_t i = currentIndex; i < pendingElements.size(); ++i) 
        insertSorted(sortedElements, pendingElements[i]);

    // If isOdd is true, insert the lastElement into the sortedElements vector
    if (isOdd) 
        insertSorted(sortedElements, lastElement);
}

std::vector<int> PmergeMe::sortVector(std::vector<int> inputVector) 
{
    
    if (inputVector.size() <= 1)// If the vector has 1 or 0 elements, it is already sorted
        return inputVector;

   
    bool isOdd = inputVector.size() % 2 != 0;  // Check if the size of the vector is odd
    int lastElement = 0;
    
    if (isOdd) {// If the size is odd, remove the last element and store it in lastElement
        lastElement = inputVector.back();
        inputVector.pop_back();
    }

    
    std::vector<std::pair<int, int> > pairs;
    createPairs(inputVector, pairs); // Create pairs from the inputVector

    
    std::vector<int> pendingElements; // Vectors to store the pending elements and the sorted elements
    std::vector<int> sortedElements;
    processPairs(pairs, pendingElements, sortedElements);
    
    
    sortedElements = sortVector(sortedElements); // Recursively sort the sortedElements vector

    
    mergeAndInsert(pendingElements, sortedElements, lastElement, isOdd); // Merge the pendingElements into the sortedElements vector and insert the lastElement if the size was odd

    return sortedElements;
}

void PmergeMe::fordJohnsonSortVector() {
    _vector = sortVector(_vector);
}


void PmergeMe::measureExecutionTimeVector() {
    
    clock_t start = clock();
    
    if(areAllEqualVector(_vector))
    {
        std::cout << "All elements are equal\n";
        return;
    }
    fordJohnsonSortVector();
    clock_t end = clock();

    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000; // Medir em microssegundos
    std::cout << "\nTime for vector: " << elapsed << " us\n";
}
