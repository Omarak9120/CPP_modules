/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:06:43 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/20 18:28:23 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"
#include <algorithm>
// #include <set>
// #include <map>
#include <deque>
#include <vector>

/**
 * Function to generate the insertion order using the Jacobsthal sequence.
 * This determines the order in which elements from the "pending" list
 * should be inserted into the sorted "main_chain".
 */
std::vector<int> generate_insertion_order(size_t pending_size) {
	std::vector<int> insertion_order;
	if (pending_size == 0) return insertion_order;
	insertion_order.push_back(0);
	if (pending_size == 1) return insertion_order;

	std::vector<int> jacobsthal_sequence;
	jacobsthal_sequence.push_back(0);
	jacobsthal_sequence.push_back(1);

	while (static_cast<int>(pending_size) > jacobsthal_sequence.back()) {
		int next = jacobsthal_sequence[jacobsthal_sequence.size() - 1] + 2 * jacobsthal_sequence[jacobsthal_sequence.size() - 2];
		jacobsthal_sequence.push_back(next);
	}

	for (size_t i = 2; i < jacobsthal_sequence.size(); ++i) {
		int current = jacobsthal_sequence[i];
		int prev = jacobsthal_sequence[i - 1];
		for (int val = current - 1; val > prev; --val) {
			if (val >= static_cast<int>(pending_size)) continue;
			if (std::find(insertion_order.begin(), insertion_order.end(), val) == insertion_order.end()) {
				insertion_order.push_back(val);
			}
		}
	}

	for (int val = 0; val < static_cast<int>(pending_size); ++val) {
		if (std::find(insertion_order.begin(), insertion_order.end(), val) == insertion_order.end()) {
			insertion_order.push_back(val);
		}
	}

	return insertion_order;
}

	// std::set<int> order_set(insertion_order.begin(), insertion_order.end());
	// size_t missing_idx = 0;
	// while (missing_idx < pending_size) {
	// 	if (order_set.find(missing_idx) == order_set.end()) {
	// 		insertion_order.push_back(missing_idx);
	// 	}
	// 	++missing_idx;
	// }

/**
 * Helper function to perform pairwise swaps in a given container.
 * It ensures that the larger element in each adjacent pair is positioned correctly.
 */
// Pairwise swap function for vector
// Pairwise swap helper (vector)


// void pairwise_swap(std::vector<int>& numbers) {
//     for (size_t i = 0; i + 1 < numbers.size(); i += 2)
//         if (numbers[i] > numbers[i + 1])
//             std::swap(numbers[i], numbers[i + 1]);
// }



// Sorting pairs by their largest elements
// Pairwise swap before pairing explicitly
// void pairwise_swap(std::vector<int>& numbers) {
// 	for (size_t i = 0; i + 1 < numbers.size(); i += 2)
// 		if (numbers[i] > numbers[i + 1])
// 			std::swap(numbers[i], numbers[i + 1]);
// }
void sort_vector(std::vector<int>& v) {
	if (v.size() <= 1) return;

	// Step 1: Pairwise swap (small, large)
	for (size_t i = 0; i + 1 < v.size(); i += 2)
		if (v[i] > v[i + 1])
			std::swap(v[i], v[i + 1]);

	// Step 2: Create pairs (main, pend)
	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i < v.size(); i += 2) {
		if (i + 1 < v.size())
			pairs.push_back(std::make_pair(v[i + 1], v[i]));
		else
			pairs.push_back(std::make_pair(v[i], -1));
	}

	// Step 3: Extract main values and recursively sort them
	std::vector<int> main_values;
	for (size_t i = 0; i < pairs.size(); ++i)
		main_values.push_back(pairs[i].first);
	sort_vector(main_values);

	// Step 4: Rebuild sorted_pairs matching sorted main_values and keep track of original indices
	std::vector<std::pair<int, int> > sorted_pairs;
	std::vector<size_t> original_indices;
	std::vector<bool> used(pairs.size(), false);
	for (size_t i = 0; i < main_values.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j) {
			if (!used[j] && pairs[j].first == main_values[i]) {
				sorted_pairs.push_back(pairs[j]);
				original_indices.push_back(j);
				used[j] = true;
				break;
			}
		}
	}

	// Step 5: Separate sorted_main and pend
	std::vector<int> sorted_main, pend;
	for (size_t i = 0; i < sorted_pairs.size(); ++i) {
		sorted_main.push_back(sorted_pairs[i].first);
		if (sorted_pairs[i].second != -1)
			pend.push_back(sorted_pairs[i].second);
	}

	// Step 6: Generate Jacobsthal insertion order
	std::vector<int> insertion_order = generate_insertion_order(pend.size());

	// Step 7: Optimized insertion using lower_bound (search only up to the original index)
	for (size_t i = 0; i < insertion_order.size(); ++i) {
		int pend_idx = insertion_order[i];
		int val = pend[pend_idx];

		size_t original_pos = original_indices[pend_idx];

		std::vector<int>::iterator insert_pos = std::lower_bound(
			sorted_main.begin(),
			sorted_main.begin() + original_pos + 1,
			val
		);

		sorted_main.insert(insert_pos, val);
	}

	v.swap(sorted_main);
}




/**
 * Sorting function for std::deque using Merge-Insertion Sort.
 */
// Pairwise swap function for deque

// void pairwise_swap(std::deque<int>& numbers) {
//     for (size_t i = 0; i + 1 < numbers.size(); i += 2)
//         if (numbers[i] > numbers[i + 1])
//             std::swap(numbers[i], numbers[i + 1]);
// }


// void pairwise_swap(std::deque<int>& numbers) {
// 	for (size_t i = 0; i + 1 < numbers.size(); i += 2)
// 		if (numbers[i] > numbers[i + 1])
// 			std::swap(numbers[i], numbers[i + 1]);
// }

void sort_deque(std::deque<int>& dq) {
	if (dq.size() <= 1) return;

	// Step 1: Pairwise swap (small, large)
	for (size_t i = 0; i + 1 < dq.size(); i += 2)
		if (dq[i] > dq[i + 1])
			std::swap(dq[i], dq[i + 1]);

	// Step 2: Create pairs (main, pend)
	std::deque<std::pair<int, int> > pairs;
	for (size_t i = 0; i < dq.size(); i += 2) {
		if (i + 1 < dq.size())
			pairs.push_back(std::make_pair(dq[i + 1], dq[i]));
		else
			pairs.push_back(std::make_pair(dq[i], -1)); // odd case
	}

	// Step 3: Extract main values and recursively sort them
	std::deque<int> main_values;
	for (size_t i = 0; i < pairs.size(); ++i)
		main_values.push_back(pairs[i].first);
	sort_deque(main_values);

	// Step 4: Rebuild sorted_pairs matching sorted main_values and keep track of original indices
	std::deque<std::pair<int, int> > sorted_pairs;
	std::deque<size_t> original_indices; // track original indices
	std::deque<bool> used(pairs.size(), false);
	for (size_t i = 0; i < main_values.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j) {
			if (!used[j] && pairs[j].first == main_values[i]) {
				sorted_pairs.push_back(pairs[j]);
				original_indices.push_back(j);
				used[j] = true;
				break;
			}
		}
	}

	// Step 5: Separate sorted_main and pend
	std::deque<int> sorted_main, pend;
	for (size_t i = 0; i < sorted_pairs.size(); ++i) {
		sorted_main.push_back(sorted_pairs[i].first);
		if (sorted_pairs[i].second != -1)
			pend.push_back(sorted_pairs[i].second);
	}

	// Step 6: Generate Jacobsthal insertion order
	std::vector<int> insertion_order = generate_insertion_order(pend.size());

	// Step 7: Optimized insertion using lower_bound (search only up to the original index)
	for (size_t i = 0; i < insertion_order.size(); ++i) {
		int pend_idx = insertion_order[i];
		int val = pend[pend_idx];

		// Get original position for the corresponding main element
		size_t original_pos = original_indices[pend_idx];

		// Find insertion point (searching from begin to original_pos+1 ONLY)
		std::deque<int>::iterator insert_pos = std::lower_bound(
			sorted_main.begin(),
			sorted_main.begin() + original_pos + 1,
			val
		);
		
		sorted_main.insert(insert_pos, val);
	}

	dq.swap(sorted_main);
}