/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMeDeque.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-da <jcruz-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:16:52 by jcruz-da          #+#    #+#             */
/*   Updated: 2024/07/19 18:17:02 by jcruz-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"


void PmergeMe::printDeque(const std::string& color) const
{
    for (std::deque<int>::size_type i = 0; i < _deque.size(); ++i)
    {
        PRINT_COLOR_N(color, _deque[i] << " ");
    }
    std::cout << std::endl;
}


void PmergeMe::initDeque(int size, char** args) 
{
    int current_value;
    
    for (int i = 0; i < (size - 1); ++i) {
        current_value = std::strtol(args[i + 1], NULL, 10);
        if (current_value < 0 || current_value > INT_MAX)
            throw std::invalid_argument("Only positive integers are allowed");
        _deque.push_back(current_value);
    }
}

bool PmergeMe::areAllEqualDeque(std::deque<int>& deque) 
{
    if (deque.empty()) {
        return true;
    }

    int first = deque[0];
    for (unsigned int i = 1; i < deque.size(); ++i) {
        if (deque[i] != first) {
            return false;
        }
    }
    return true;
}

void PmergeMe::generatePairsDeque(const std::deque<int>& vec, std::deque<std::pair<int, int> >& pairs) 
{
    // Iterate over the deque in steps of 2
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

void PmergeMe::insertSortedDeque(std::deque<int>& sorted, int value) {
    std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(it, value);
}

std::deque<int> PmergeMe::jacobsthalSequentialDeque(int number) 
{
    std::deque<int> deque;
    int current = 0, next = 1; 
    while (next <= number)  // Generate the Jacobsthal sequence up to the specified number
    {
        deque.push_back(next); // Add the current number to the sequence
        int temp = next; // Calculate the next number in the sequence
        next = current + 2 * next;
        current = temp;
    }
    return deque; 
}

std::deque<int> PmergeMe::jacobsthalDiffDeque(int number) 
{
    std::deque<int> differences; // Store the differences between consecutive Jacobsthal numbers
    std::deque<int> jacobsthalNumbers = jacobsthalSequentialDeque(number); // Generate the Jacobsthal sequence

    // Iterate over the Jacobsthal sequence starting from the second element
    for (size_t index = 1; index < jacobsthalNumbers.size(); ++index) {
        // Calculate the difference between the current Jacobsthal number and the previous one
        differences.push_back(jacobsthalNumbers[index] - jacobsthalNumbers[index - 1]);
    }

    return differences; // Return the differences
}


void PmergeMe::handlePairsDeque(const std::deque<std::pair<int, int> >& inputPairs, 
                            std::deque<int>& pendingElements, 
                            std::deque<int>& sortedElements) 
{
    // Iterate over each pair in the inputPairs deque
    for (std::deque<std::pair<int, int> >::const_iterator pairIterator = inputPairs.begin(); pairIterator != inputPairs.end(); ++pairIterator) 
    {
        const std::pair<int, int>& currentPair = *pairIterator;
        pendingElements.push_back(currentPair.first); // Add the first element of the pair to the pendingElements deque
        sortedElements.push_back(currentPair.second);  // Add the second element of the pair to the sortedElements deque
    }
}


void PmergeMe::mergeAndInsertDeque(std::deque<int>& pendingElements, 
                              std::deque<int>& sortedElements, 
                              int lastElement, 
                              bool isOdd) 
{
    std::deque<int> jacobsthalSequence = jacobsthalDiffDeque(pendingElements.size());
    size_t currentIndex = 0;

    for (size_t i = 0; i < jacobsthalSequence.size(); ++i)// Iterate over the Jacobsthal sequence
    {
        size_t groupSize = jacobsthalSequence[i];
        if (currentIndex >= pendingElements.size()) 
            break;

        std::deque<int> group;
        
        for (size_t j = 0; j < groupSize && currentIndex < pendingElements.size(); ++j) //Create a group of elements from the pendingElements deque 
        {
            group.push_back(pendingElements[currentIndex]);
            ++currentIndex;
        }
        std::reverse(group.begin(), group.end());

        
        for (std::deque<int>::const_iterator it = group.begin(); it != group.end(); ++it)// Insert the elements of the group into the sortedElements deque 
        {
            int num = *it;
            insertSortedDeque(sortedElements, num);
        }
    }

    // Insert the remaining elements from the pendingElements deque
    for (size_t i = currentIndex; i < pendingElements.size(); ++i) 
        insertSortedDeque(sortedElements, pendingElements[i]);

    // If isOdd is true, insert the lastElement into the sortedElements deque
    if (isOdd) 
        insertSortedDeque(sortedElements, lastElement);
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> inputdeque) 
{
    
    if (inputdeque.size() <= 1)// If the deque has 1 or 0 elements, it is already sorted
        return inputdeque;

   
    bool isOdd = inputdeque.size() % 2 != 0;  // Check if the size of the deque is odd
    int lastElement = 0;
    
    if (isOdd) {// If the size is odd, remove the last element and store it in lastElement
        lastElement = inputdeque.back();
        inputdeque.pop_back();
    }

    
    std::deque<std::pair<int, int> > pairs;
    generatePairsDeque(inputdeque, pairs); // Create pairs from the inputdeque

    
    std::deque<int> pendingElements; // deques to store the pending elements and the sorted elements
    std::deque<int> sortedElements;
    handlePairsDeque(pairs, pendingElements, sortedElements);
    
    
    sortedElements = sortDeque(sortedElements); // Recursively sort the sortedElements deque

    
    mergeAndInsertDeque(pendingElements, sortedElements, lastElement, isOdd); // Merge the pendingElements into the sortedElements deque and insert the lastElement if the size was odd

    return sortedElements;
}

void PmergeMe::fordJohnsonSortDeque() 
{
    _deque = sortDeque(_deque);  
}

void PmergeMe::measureExecutionTimeDeque() 
{
    clock_t start = clock();
    
    if(areAllEqualDeque(_deque))
    {
        std::cout << "All elements are equal\n";
        return;
    }
    size_t count = _deque.size();
    fordJohnsonSortDeque();
    clock_t end = clock();
    

    

    double  elapsed = double (end - start) / CLOCKS_PER_SEC * 1000000.0; // Medir em microssegundos
    std::cout << "\n[Deque] Time to process a range of " << count <<" elements wit : " << elapsed << " us\n";

}


