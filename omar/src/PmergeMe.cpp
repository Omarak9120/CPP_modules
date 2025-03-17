/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:27:25 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/17 23:27:26 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <algorithm>
#include <set>

// Function to generate the insertion order based on the Jacobsthal sequence
static std::vector<int> generate_insertion_order(size_t m) {
    std::vector<int> order;
    if (m == 0) return order;
    order.push_back(0);
    if (m == 1) return order;

    std::vector<int> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while (static_cast<size_t>(jacobsthal.back()) < m) {
        int next_j = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next_j);
    }

    size_t prev = 1;
    size_t current = 1;
    
    size_t i = 2;
    while (i < jacobsthal.size()) {
        current = jacobsthal[i];
        int start = prev + 1;
        int end = current - 1;
        
        if (start <= end) {
            int j = end;
            while (j >= start) {
                if (static_cast<size_t>(j) < m) {
                    if (std::find(order.begin(), order.end(), j) == order.end()) {
                        order.push_back(j);
                    }
                }
                --j;
            }
        }
        
        prev = current;
        if (static_cast<size_t>(current) >= m)
            break;
        
        ++i;
    }

    std::set<int> order_set(order.begin(), order.end());
    size_t k = 0;
    while (k < m) {
        if (order_set.find(k) == order_set.end()) {
            order.push_back(k);
        }
        ++k;
    }

    return order;
}

// Helper function to pairwise swap elements if needed
template <typename Container>
void pairwise_swap(Container& c) {
    size_t i = 0;
    while (i < c.size()) {
        if (i + 1 < c.size() && c[i] > c[i + 1]) {
            std::swap(c[i], c[i + 1]);
        }
        i += 2;
    }
}

// Sorting function for vector using Merge-Insertion Sort
void sort_vector(std::vector<int>& v) {
    if (v.size() <= 1) return;

    pairwise_swap(v);

    std::vector<int> main_chain, pend;
    size_t i = 0;
    while (i < v.size()) {
        if (i % 2 == 1) {
            main_chain.push_back(v[i]);
        } else {
            pend.push_back(v[i]);
        }
        ++i;
    }

    sort_vector(main_chain);

    std::vector<int> insertion_order = generate_insertion_order(pend.size());
    size_t j = 0;
    while (j < insertion_order.size()) {
        int idx = insertion_order[j++];
        if (idx < 0 || static_cast<size_t>(idx) >= pend.size()) continue;

        int val = pend[idx];
        std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
        main_chain.insert(pos, val);
    }

    v.swap(main_chain);
}

// Sorting function for deque using Merge-Insertion Sort
void sort_deque(std::deque<int>& d) {
    if (d.size() <= 1) return;

    pairwise_swap(d);

    std::deque<int> main_chain, pend;
    size_t i = 0;
    while (i < d.size()) {
        if (i % 2 == 1) {
            main_chain.push_back(d[i]);
        } else {
            pend.push_back(d[i]);
        }
        ++i;
    }

    sort_deque(main_chain);

    std::vector<int> insertion_order = generate_insertion_order(pend.size());
    size_t j = 0;
    while (j < insertion_order.size()) {
        int idx = insertion_order[j++];
        if (idx < 0 || static_cast<size_t>(idx) >= pend.size()) continue;

        int val = pend[idx];
        std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), val);
        main_chain.insert(pos, val);
    }

    d.swap(main_chain);
}
