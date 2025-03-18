#include "../includes/PmergeMe.hpp"
#include <algorithm>
#include <map>
#include <iterator>

// Generate Jacobsthal-based insertion order
std::vector<int> PmergeMe::generate_insertion_order(size_t pending_size) {
    std::vector<int> order;
    if (pending_size == 0) return order;

    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (static_cast<size_t>(jacob.back()) < pending_size) {
        int next = jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2];
        jacob.push_back(next);
    }

    size_t prev = 0;
    order.push_back(0);
    for (size_t i = 2; i < jacob.size(); ++i) {
        size_t current = jacob[i];
        for (size_t num = std::min(current, pending_size); num > prev; --num) {
            if (std::find(order.begin(), order.end(), num-1) == order.end()) {
                order.push_back(num-1);
            }
        }
        prev = current;
        if (current >= pending_size) break;
    }

    // Add missing indices
    for (size_t i = 0; i < pending_size; ++i) {
        if (std::find(order.begin(), order.end(), i) == order.end()) {
            order.push_back(i);
        }
    }

    return order;
}

// Create value-to-index map
template <typename Container>
std::map<int, size_t> PmergeMe::create_index_map(const Container& sorted) {
    std::map<int, size_t> map;
    for (size_t i = 0; i < sorted.size(); ++i) {
        map[sorted[i]] = i;
    }
    return map;
}

// Pairwise swap implementation
template <typename Container>
void PmergeMe::pairwise_swap(Container& container) {
    for (size_t i = 0; i < container.size(); i += 2) {
        if (i+1 < container.size() && container[i] > container[i+1]) {
            std::swap(container[i], container[i+1]);
        }
    }
}

// Vector sort implementation
void PmergeMe::sort(std::vector<int>& numbers) {
    if (numbers.size() <= 1) return;

    pairwise_swap(numbers);

    std::vector<int> main_chain, pending, original_main;
    bool has_straggler = numbers.size() % 2 != 0;

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i % 2 == 1) {
            main_chain.push_back(numbers[i]);
            original_main.push_back(numbers[i]);
        } else {
            pending.push_back(numbers[i]);
        }
    }

    // Handle straggler
    int straggler = -1;
    if (has_straggler) {
        straggler = pending.back();
        pending.pop_back();
    }

    sort(main_chain);

    // Insert straggler first if exists
    if (has_straggler) {
        std::vector<int>::iterator pos = std::lower_bound(
            main_chain.begin(), main_chain.end(), straggler
        );
        main_chain.insert(pos, straggler);
    }

    std::map<int, size_t> index_map = create_index_map(main_chain);
    std::vector<int> insertion_order = generate_insertion_order(pending.size());

    for (size_t i = 0; i < insertion_order.size(); ++i) {
        int pending_idx = insertion_order[i];
        if (pending_idx < 0 || static_cast<size_t>(pending_idx) >= pending.size()) continue;

        int val = pending[pending_idx];
        int paired_val = original_main[pending_idx];
        size_t upper_bound = index_map[paired_val];

        std::vector<int>::iterator start = main_chain.begin();
        std::vector<int>::iterator end = main_chain.begin() + 
            std::min(upper_bound + 1, main_chain.size());
        std::vector<int>::iterator pos = std::lower_bound(start, end, val);
        main_chain.insert(pos, val);

        index_map = create_index_map(main_chain); // Update map
    }

    numbers.swap(main_chain);
}

// Deque sort implementation
void PmergeMe::sort(std::deque<int>& numbers) {
    if (numbers.size() <= 1) return;

    pairwise_swap(numbers);

    std::deque<int> main_chain, pending, original_main;
    bool has_straggler = numbers.size() % 2 != 0;

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i % 2 == 1) {
            main_chain.push_back(numbers[i]);
            original_main.push_back(numbers[i]);
        } else {
            pending.push_back(numbers[i]);
        }
    }

    int straggler = -1;
    if (has_straggler) {
        straggler = pending.back();
        pending.pop_back();
    }

    sort(main_chain);

    if (has_straggler) {
        std::deque<int>::iterator pos = std::lower_bound(
            main_chain.begin(), main_chain.end(), straggler
        );
        main_chain.insert(pos, straggler);
    }

    std::map<int, size_t> index_map = create_index_map(main_chain);
    std::vector<int> insertion_order = generate_insertion_order(pending.size());

    for (size_t i = 0; i < insertion_order.size(); ++i) {
        int pending_idx = insertion_order[i];
        if (pending_idx < 0 || static_cast<size_t>(pending_idx) >= pending.size()) continue;

        int val = pending[pending_idx];
        int paired_val = original_main[pending_idx];
        size_t upper_bound = index_map[paired_val];

        std::deque<int>::iterator start = main_chain.begin();
        std::deque<int>::iterator end = main_chain.begin() + 
            std::min(upper_bound + 1, main_chain.size());
        std::deque<int>::iterator pos = std::lower_bound(start, end, val);
        main_chain.insert(pos, val);

        index_map = create_index_map(main_chain);
    }

    numbers.swap(main_chain);
}