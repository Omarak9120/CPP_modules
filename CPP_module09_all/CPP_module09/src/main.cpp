#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <ctime>
#include <set>
#include <algorithm>  // Add this for std::adjacent_find
#include <functional>

bool hasDuplicates(const std::vector<int>& numbers) {
    std::set<int> seen;
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        if (!seen.insert(*it).second) return true;
    }
    return false;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " [list of positive integers]\n";
        return 1;
    }

    std::vector<int> numbers;
    for (int i = 1; i < argc; ++i) {
        std::stringstream ss(argv[i]);
        int num;
        if (!(ss >> num) || num < 0) {
            std::cerr << "Error: Invalid number '" << argv[i] << "'\n";
            return 1;
        }
        numbers.push_back(num);
    }

    if (hasDuplicates(numbers)) {
        std::cerr << "Error: Duplicate numbers found\n";
        return 1;
    }

    // Vector sort
    std::vector<int> vec(numbers.begin(), numbers.end());
    clock_t start = clock();
    PmergeMe::sort(vec);
    double vec_time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1e6;

    // Deque sort
    std::deque<int> deq(numbers.begin(), numbers.end());
    start = clock();
    PmergeMe::sort(deq);
    double deq_time = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1e6;

    // Verify sorting
    bool vec_sorted = std::adjacent_find(vec.begin(), vec.end(), std::greater<int>()) == vec.end();
    bool deq_sorted = std::adjacent_find(deq.begin(), deq.end(), std::greater<int>()) == deq.end();

    // Output results
    std::cout << "Before: ";
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\nAfter: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\nTime to process " << numbers.size() << " elements with std::vector: " << vec_time << " us\n";
    std::cout << "Time to process " << numbers.size() << " elements with std::deque: " << deq_time << " us\n";
    std::cout << "Vector is " << (vec_sorted ? "sorted" : "not sorted") << "\n";
    std::cout << "Deque is " << (deq_sorted ? "sorted" : "not sorted") << "\n";

    return 0;
}