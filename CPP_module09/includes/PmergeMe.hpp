#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <map>

class PmergeMe {
public:
    static void sort(std::vector<int>& numbers);
    static void sort(std::deque<int>& numbers);

private:
    template <typename Container>
    static void pairwise_swap(Container& container);
    
    static std::vector<int> generate_insertion_order(size_t pending_size);
    template <typename Container>
    static std::map<int, size_t> create_index_map(const Container& sorted);
};

#endif