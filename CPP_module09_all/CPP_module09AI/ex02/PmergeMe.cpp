#include "PmergeMe.hpp"

// Constructor: Initialize both containers with input
PmergeMe::PmergeMe(std::vector<int> input) : _vector(input), _deque(input.begin(), input.end()) {}

// Merge-Insertion Sort for std::vector
void PmergeMe::sortVector() {
    mergeInsertionSort(_vector);
}

// Merge-Insertion Sort for std::deque
void PmergeMe::sortDeque() {
    mergeInsertionSort(_deque);
}

// Merge-Insertion Sort Implementation for std::vector
void PmergeMe::mergeInsertionSort(std::vector<int>& arr) {
    if (arr.size() <= 1) return;

    std::vector<int> mainChain, insertions;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]);
        mainChain.push_back(arr[i + 1]);  // Larger element
        insertions.push_back(arr[i]);     // Smaller element
    }

    if (arr.size() % 2 != 0) mainChain.push_back(arr.back()); // Handle odd element

    mergeInsertionSort(mainChain);
    insertWithJacobsthal(mainChain, insertions);

    arr = mainChain; // Copy sorted elements back
}



// Merge-Insertion Sort Implementation for std::deque
void PmergeMe::mergeInsertionSort(std::deque<int>& arr) {
    if (arr.size() <= 1) return;

    std::deque<int> mainChain, insertions;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] > arr[i + 1]) std::swap(arr[i], arr[i + 1]);
        mainChain.push_back(arr[i + 1]);  // Larger value
        insertions.push_back(arr[i]);     // Smaller value
    }

    if (arr.size() % 2 != 0) mainChain.push_back(arr.back());

    mergeInsertionSort(mainChain);
    insertWithJacobsthal(mainChain, insertions);

    arr = mainChain;
}


// Insert elements using Jacobsthal sequence for std::vector
void PmergeMe::insertWithJacobsthal(std::vector<int>& mainChain, std::vector<int>& insertions) {
    std::vector<int> jacobSeq = generateJacobsthalSequence(insertions.size());
    std::vector<bool> inserted(insertions.size(), false);  // Track inserted elements

    for (int index : jacobSeq) {
        if (index < static_cast<int>(insertions.size()) && !inserted[index]) {
            auto pos = std::lower_bound(mainChain.begin(), mainChain.end(), insertions[index]);
            mainChain.insert(pos, insertions[index]);
            inserted[index] = true;  // Mark as inserted
        }
    }
}



// Insert elements using Jacobsthal sequence for std::deque
void PmergeMe::insertWithJacobsthal(std::deque<int>& mainChain, std::deque<int>& insertions) {
    std::vector<int> jacobSeq = generateJacobsthalSequence(insertions.size());
    std::vector<bool> inserted(insertions.size(), false);  // Track inserted elements

    for (int index : jacobSeq) {
        if (index < static_cast<int>(insertions.size()) && !inserted[index]) {
            auto pos = std::lower_bound(mainChain.begin(), mainChain.end(), insertions[index]);
            mainChain.insert(pos, insertions[index]);
            inserted[index] = true;  // Mark as inserted
        }
    }
}



// Generate Jacobsthal Sequence
std::vector<int> PmergeMe::generateJacobsthalSequence(int n) {
    std::vector<int> sequence = {0, 1};
    while (sequence.back() < n) {
        int next = sequence.back() + 2 * sequence[sequence.size() - 2];
        if (next >= n) break;
        sequence.push_back(next);
    }
    return sequence;
}

// Print Results
void PmergeMe::printResults() const {
    std::cout << "Sorted with std::vector: ";
    for (int num : _vector) std::cout << num << " ";
    std::cout << "\n";

    std::cout << "Sorted with std::deque: ";
    for (int num : _deque) std::cout << num << " ";
    std::cout << "\n";
}
