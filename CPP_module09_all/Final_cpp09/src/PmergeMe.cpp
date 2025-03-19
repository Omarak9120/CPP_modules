#include "../includes/PmergeMe.hpp"
#include <iostream>

// Generate the order of insertion using the Jacobsthal sequence
static std::vector<int> generate_insertion_order(size_t m) {
    std::vector<int> order;
    if (m == 0) return order;
    
    order.push_back(0);
    if (m == 1) return order;

    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    // Generate Jacobsthal numbers
    while (jacobsthal.back() < static_cast<int>(m)) {
        int next_j = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next_j);
    }

    size_t prev = 1;
    size_t current = 1;

    // Generate insertion order
    for (size_t i = 2; i < jacobsthal.size(); ++i) {
        current = jacobsthal[i];
        int start = prev + 1;
        int end = current - 1;

        if (start > end) {  
            prev = current;
            continue;
        }

        for (int j = end; j >= start; --j) {
            if (static_cast<size_t>(j) < m && std::find(order.begin(), order.end(), j) == order.end()) {
                order.push_back(j);
            }
        }

        prev = current;
        if (current >= m) break;
    }

    // Ensure all indices are included
    std::set<int> order_set(order.begin(), order.end());
    for (size_t i = 0; i < m; ++i) {
        if (order_set.find(i) == order_set.end()) {
            order.push_back(i);
        }
    }

    return order;
}

// Sort a vector using Merge-Insertion Sort
void sort_vector(std::vector<int>& v) {
    if (v.size() <= 1) return;

    // Pair elements and swap within pairs
    for (size_t i = 0; i < v.size(); i += 2) {
        if (i + 1 < v.size() && v[i] > v[i + 1]) {
            std::swap(v[i], v[i + 1]);
        }
    }

    // Create main_chain with pairs (main, pending)
    std::vector<std::pair<int, int> > main_chain;
    for (size_t i = 0; i < v.size(); i += 2) {
        if (i + 1 < v.size()) {
            main_chain.push_back(std::make_pair(v[i + 1], v[i]));
        } else {
            main_chain.push_back(std::make_pair(v[i], -1));
        }
    }

    // Recursively sort main values
    std::vector<int> main_values;
    for (size_t i = 0; i < main_chain.size(); ++i) {
        main_values.push_back(main_chain[i].first);
    }
    sort_vector(main_values);

    // Rebuild sorted main chain and track original indices
    std::vector<std::pair<int, int> > sorted_main_pairs;
    std::vector<size_t> original_indices(main_chain.size());

    std::vector<std::pair<int, size_t> > indexed_main;
    for (size_t i = 0; i < main_chain.size(); ++i) {
        indexed_main.push_back(std::make_pair(main_chain[i].first, i));
    }
    std::sort(indexed_main.begin(), indexed_main.end());

    for (size_t i = 0; i < indexed_main.size(); ++i) {
        original_indices[i] = indexed_main[i].second;
        sorted_main_pairs.push_back(std::make_pair(indexed_main[i].first, main_chain[indexed_main[i].second].second));
    }

    // Split sorted_main_chain and pend
    std::vector<int> sorted_main_chain;
    std::vector<int> pend;
    for (size_t i = 0; i < sorted_main_pairs.size(); ++i) {
        sorted_main_chain.push_back(sorted_main_pairs[i].first);
        if (sorted_main_pairs[i].second != -1) {
            pend.push_back(sorted_main_pairs[i].second);
        }
    }

    // Track positions of original main elements
    std::vector<size_t> main_positions(main_chain.size());
    for (size_t i = 0; i < sorted_main_pairs.size(); ++i) {
        main_positions[original_indices[i]] = i;
    }

    // Insert pending elements in Jacobsthal order
    std::vector<int> insertion_order = generate_insertion_order(pend.size());

    for (size_t i = 0; i < insertion_order.size(); ++i) {
        int idx = insertion_order[i];
        if (idx < 0 || static_cast<size_t>(idx) >= pend.size()) continue;

        int val = pend[idx];
        size_t pos_main = main_positions[idx];

        std::vector<int>::iterator insert_pos = std::lower_bound(
            sorted_main_chain.begin(),
            sorted_main_chain.begin() + pos_main + 1,
            val
        );
        sorted_main_chain.insert(insert_pos, val);
    }

    v.swap(sorted_main_chain);
}

// Sort a deque using Merge-Insertion Sort
void sort_deque(std::deque<int>& d) {
    if (d.size() <= 1) return;

    // Pair elements and swap within pairs
    for (size_t i = 0; i < d.size(); i += 2) {
        if (i + 1 < d.size() && d[i] > d[i + 1]) {
            std::swap(d[i], d[i + 1]);
        }
    }

    // Create main_chain with pairs (main, pending)
    std::deque<std::pair<int, int> > main_chain;
    for (size_t i = 0; i < d.size(); i += 2) {
        if (i + 1 < d.size()) {
            main_chain.push_back(std::make_pair(d[i + 1], d[i]));
        } else {
            main_chain.push_back(std::make_pair(d[i], -1));
        }
    }

    // Recursively sort main values
    std::deque<int> main_values;
    for (size_t i = 0; i < main_chain.size(); ++i) {
        main_values.push_back(main_chain[i].first);
    }
    sort_deque(main_values);

    // Rebuild sorted main chain and track original indices
    std::deque<std::pair<int, int> > sorted_main_pairs;
    std::vector<size_t> original_indices(main_chain.size());

    std::vector<std::pair<int, size_t> > indexed_main;
    for (size_t i = 0; i < main_chain.size(); ++i) {
        indexed_main.push_back(std::make_pair(main_chain[i].first, i));
    }
    std::sort(indexed_main.begin(), indexed_main.end());

    for (size_t i = 0; i < indexed_main.size(); ++i) {
        original_indices[i] = indexed_main[i].second;
        sorted_main_pairs.push_back(std::make_pair(indexed_main[i].first, main_chain[indexed_main[i].second].second));
    }

    // Split sorted main and pending elements
    std::deque<int> sorted_main_chain;
    std::deque<int> pend;

    for (size_t i = 0; i < sorted_main_pairs.size(); ++i) {
        sorted_main_chain.push_back(sorted_main_pairs[i].first);
        if (sorted_main_pairs[i].second != -1) {
            pend.push_back(sorted_main_pairs[i].second);
        }
    }

    // Track positions of original main elements
    std::vector<size_t> main_positions(main_chain.size());
    for (size_t i = 0; i < sorted_main_pairs.size(); ++i) {
        main_positions[original_indices[i]] = i;
    }

    // Insert pending elements in Jacobsthal order
    std::vector<int> insertion_order = generate_insertion_order(pend.size());

    for (size_t i = 0; i < insertion_order.size(); ++i) {
        int idx = insertion_order[i];
        if (idx < 0 || static_cast<size_t>(idx) >= pend.size()) continue;

        int val = pend[idx];
        size_t pos_main = main_positions[idx];

        std::deque<int>::iterator insert_pos = std::lower_bound(
            sorted_main_chain.begin(),
            sorted_main_chain.begin() + pos_main + 1,
            val
        );
        sorted_main_chain.insert(insert_pos, val);
    }

    d.swap(sorted_main_chain);
}
