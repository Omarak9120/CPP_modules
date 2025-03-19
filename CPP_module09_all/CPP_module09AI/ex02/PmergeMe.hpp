#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <chrono>
#include <algorithm>
#include <cstdlib>

class PmergeMe {
public:
    PmergeMe(std::vector<int> input);
    
    void sortVector();
    void sortDeque();
    
    void printResults() const;

private:
    std::vector<int> _vector;
    std::deque<int> _deque;

    void mergeInsertionSort(std::vector<int>& arr);
    void mergeInsertionSort(std::deque<int>& arr);

    void insertWithJacobsthal(std::vector<int>& mainChain, std::vector<int>& insertions);
    void insertWithJacobsthal(std::deque<int>& mainChain, std::deque<int>& insertions);

    std::vector<int> generateJacobsthalSequence(int n);
};

#endif
