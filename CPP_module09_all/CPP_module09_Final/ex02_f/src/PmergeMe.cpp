/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 21:06:43 by oabdelka          #+#    #+#             */
/*   Updated: 2025/03/19 21:40:07 by oabdelka         ###   ########.fr       */
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
static std::vector<int> generate_insertion_order(size_t pending_size) {
	std::vector<int> insertion_order;
	if (pending_size == 0) return insertion_order;
	insertion_order.push_back(0);
	if (pending_size == 1) return insertion_order;

	std::vector<int> jacobsthal_sequence;
	jacobsthal_sequence.push_back(0);
	jacobsthal_sequence.push_back(1);

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

	for (size_t missing_idx = 0; missing_idx < pending_size; ++missing_idx) {
	if (std::find(insertion_order.begin(), insertion_order.end(), missing_idx) == insertion_order.end()) {
		insertion_order.push_back(missing_idx);
	}
}

	// std::set<int> order_set(insertion_order.begin(), insertion_order.end());
	// size_t missing_idx = 0;
	// while (missing_idx < pending_size) {
	// 	if (order_set.find(missing_idx) == order_set.end()) {
	// 		insertion_order.push_back(missing_idx);
	// 	}
	// 	++missing_idx;
	// }

	return insertion_order;
}


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
bool pair_cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.second < b.second;
}


void sort_vector(std::vector<int>& numbers) {
	if (numbers.size() <= 1) return;

	// Pair elements explicitly
	std::vector<std::pair<int, int> > pairs;
	size_t i = 0;
	while (i < numbers.size()) {
		int first = numbers[i++];
		int second = (i < numbers.size()) ? numbers[i++] : -1;

		if (second != -1) {
			if (first < second)
				std::swap(first, second);
			pairs.push_back(std::make_pair(second, first)); // (small, large)
		} else {
			pairs.push_back(std::make_pair(-1, first)); // single element
		}
	}

	// Sort pairs based on larger elements explicitly
	std::sort(pairs.begin(), pairs.end(), pair_cmp);

	std::vector<int> main_chain, pending;
	std::vector<size_t> partner_indices;

	// Fill main_chain (larger elements) and pending (smaller elements)
	for (size_t idx = 0; idx < pairs.size(); ++idx) {
		if (pairs[idx].first != -1) {
			pending.push_back(pairs[idx].first);
			partner_indices.push_back(main_chain.size());
		}
		main_chain.push_back(pairs[idx].second);
	}

	// Recursively sort main_chain
	sort_vector(main_chain);

	// Handle base cases explicitly
	if (pending.empty()) {
		numbers.swap(main_chain);
		return;
	}

	std::vector<int> insertion_order = generate_insertion_order(pending.size());

	//Loop over the insertion order (Jacobsthal-based order)
	for (size_t k = 0; k < insertion_order.size(); ++k) {
		int pending_idx = insertion_order[k];
		// Find the value to insert
		int value = pending[pending_idx];

		// Find the optimal insertion position
		size_t upper_bound = partner_indices[pending_idx];
		if (upper_bound > main_chain.size())
			upper_bound = main_chain.size();

		std::vector<int>::iterator insertion_pos = std::lower_bound(
			main_chain.begin(),
			main_chain.begin() + upper_bound,
			value
		);

		size_t insertion_distance = insertion_pos - main_chain.begin();
		main_chain.insert(insertion_pos, value);

		for (size_t j = 0; j < partner_indices.size(); ++j) {
			if (partner_indices[j] >= insertion_distance)
				partner_indices[j]++;
		}
	}

	numbers.swap(main_chain);
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


void sort_deque(std::deque<int>& numbers) {
	if (numbers.size() <= 1) return;

	std::vector<std::pair<int, int> > pairs;
	size_t i = 0;
	while (i < numbers.size()) {
		int first = numbers[i++];
		int second = (i < numbers.size()) ? numbers[i++] : -1;

		if (second != -1) {
			if (first < second)
				std::swap(first, second);
			pairs.push_back(std::make_pair(second, first));
		} else {
			pairs.push_back(std::make_pair(-1, first));
		}
	}

	std::sort(pairs.begin(), pairs.end(), pair_cmp);

	std::deque<int> main_chain, pending;
	std::vector<size_t> partner_indices;

	for (size_t idx = 0; idx < pairs.size(); ++idx) {
		if (pairs[idx].first != -1) {
			pending.push_back(pairs[idx].first);
			partner_indices.push_back(main_chain.size());
		}
		main_chain.push_back(pairs[idx].second);
	}

	sort_deque(main_chain);

	if (pending.empty()) {
		numbers.swap(main_chain);
		return;
	}

	std::vector<int> insertion_order = generate_insertion_order(pending.size());

	for (size_t k = 0; k < insertion_order.size(); ++k) {
		int pending_idx = insertion_order[k];
		int value = pending[pending_idx];

		size_t upper_bound = partner_indices[pending_idx];
		if (upper_bound > main_chain.size())
			upper_bound = main_chain.size();

		std::deque<int>::iterator insertion_pos = std::lower_bound(
			main_chain.begin(),
			main_chain.begin() + upper_bound,
			value
		);

		size_t insertion_distance = insertion_pos - main_chain.begin();
		main_chain.insert(insertion_pos, value);

		for (size_t j = 0; j < partner_indices.size(); ++j) {
			if (partner_indices[j] >= insertion_distance)
				partner_indices[j]++;
		}
	}

	numbers.swap(main_chain);
}
