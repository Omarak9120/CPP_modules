/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:27:25 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/18 20:23:38 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <algorithm>
#include <set>

/**
 * Function to generate the insertion order using the Jacobsthal sequence.
 * This determines the order in which elements from the "pending" list
 * should be inserted into the sorted "main_chain".
 */
static std::vector<int> generate_insertion_order(size_t pending_size) {
    std::vector<int> insertion_order;
    if (pending_size == 0) return insertion_order;
    insertion_order.push_back(0);
    if (pending_size == 1) return insertion_order;

    std::vector<int> jacobsthal_sequence = {0, 1};

    while (static_cast<size_t>(jacobsthal_sequence.back()) < pending_size) {
        int next_jacobsthal = jacobsthal_sequence[jacobsthal_sequence.size() - 1] 
                            + 2 * jacobsthal_sequence[jacobsthal_sequence.size() - 2];
        jacobsthal_sequence.push_back(next_jacobsthal);
    }

    size_t previous_index = 1;
    size_t current_index = 1;
    
    size_t jacobsthal_idx = 2;
    while (jacobsthal_idx < jacobsthal_sequence.size()) {
        current_index = jacobsthal_sequence[jacobsthal_idx];
        int start = previous_index + 1;
        int end = current_index - 1;

        if (start <= end) {
            int i = end;
            while (i >= start) {
                if (static_cast<size_t>(i) < pending_size) {
                    if (std::find(insertion_order.begin(), insertion_order.end(), i) == insertion_order.end()) {
                        insertion_order.push_back(i);
                    }
                }
                --i;
            }
        }

        previous_index = current_index;
        if (static_cast<size_t>(current_index) >= pending_size)
            break;

        ++jacobsthal_idx;
    }

    std::set<int> order_set(insertion_order.begin(), insertion_order.end());
    size_t missing_idx = 0;
    while (missing_idx < pending_size) {
        if (order_set.find(missing_idx) == order_set.end()) {
            insertion_order.push_back(missing_idx);
        }
        ++missing_idx;
    }

    return insertion_order;
}

/**
 * Helper function to perform pairwise swaps in a given container.
 * It ensures that the larger element in each adjacent pair is positioned correctly.
 */
template <typename Container>
void pairwise_swap(Container& container) {
    size_t index = 0;
    while (index < container.size()) {
        if (index + 1 < container.size() && container[index] > container[index + 1]) {
            std::swap(container[index], container[index + 1]);
        }
        index += 2;
    }
}

/**
 * Sorting function for std::vector using Merge-Insertion Sort.
 */
void sort_vector(std::vector<int>& numbers) {
    if (numbers.size() <= 1) return;

    pairwise_swap(numbers);

    std::vector<int> main_chain, pending_elements;
    size_t index = 0;
    while (index < numbers.size()) {
        if (index % 2 == 1) {
            main_chain.push_back(numbers[index]);
        } else {
            pending_elements.push_back(numbers[index]);
        }
        ++index;
    }

    sort_vector(main_chain);

    std::vector<int> insertion_order = generate_insertion_order(pending_elements.size());
    size_t insertion_idx = 0;
    while (insertion_idx < insertion_order.size()) {
        int pending_index = insertion_order[insertion_idx++];
        if (pending_index < 0 || static_cast<size_t>(pending_index) >= pending_elements.size()) continue;

        int value_to_insert = pending_elements[pending_index];
        std::vector<int>::iterator insertion_pos = std::lower_bound(main_chain.begin(), main_chain.end(), value_to_insert);
        main_chain.insert(insertion_pos, value_to_insert);
    }

    numbers.swap(main_chain);
}

/**
 * Sorting function for std::deque using Merge-Insertion Sort.
 */
void sort_deque(std::deque<int>& numbers) {
    if (numbers.size() <= 1) return;

    pairwise_swap(numbers);

    std::deque<int> main_chain, pending_elements;
    size_t index = 0;
    while (index < numbers.size()) {
        if (index % 2 == 1) {
            main_chain.push_back(numbers[index]);
        } else {
            pending_elements.push_back(numbers[index]);
        }
        ++index;
    }

    sort_deque(main_chain);

    std::vector<int> insertion_order = generate_insertion_order(pending_elements.size());
    size_t insertion_idx = 0;
    while (insertion_idx < insertion_order.size()) {
        int pending_index = insertion_order[insertion_idx++];
        if (pending_index < 0 || static_cast<size_t>(pending_index) >= pending_elements.size()) continue;

        int value_to_insert = pending_elements[pending_index];
        std::deque<int>::iterator insertion_pos = std::lower_bound(main_chain.begin(), main_chain.end(), value_to_insert);
        main_chain.insert(insertion_pos, value_to_insert);
    }

    numbers.swap(main_chain);
}
