#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input provided.\n";
        return 1;
    }

    std::vector<int> input;
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: Invalid input. Only positive integers allowed.\n";
            return 1;
        }
        if (std::find(input.begin(), input.end(), num) != input.end()) {
            std::cerr << "Error: Duplicate numbers are not allowed.\n";
            return 1;
        }
        input.push_back(num);
    }

    PmergeMe sorter(input);

    auto start1 = std::chrono::high_resolution_clock::now();
    sorter.sortVector();
    auto end1 = std::chrono::high_resolution_clock::now();
    
    auto start2 = std::chrono::high_resolution_clock::now();
    sorter.sortDeque();
    auto end2 = std::chrono::high_resolution_clock::now();

    sorter.printResults();
    std::cout << "Time for std::vector: " << std::chrono::duration<double, std::micro>(end1 - start1).count() << " μs\n";
    std::cout << "Time for std::deque: " << std::chrono::duration<double, std::micro>(end2 - start2).count() << " μs\n";

    return 0;
}
