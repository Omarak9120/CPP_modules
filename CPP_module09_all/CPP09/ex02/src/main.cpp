#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv) {
	try {
		if (argc < 2) throw std::logic_error(NOARG);
		PmergeMe fordJohnson(argc - 1, argv);
		fordJohnson.setSequence();
		fordJohnson.sortSequence();
		fordJohnson.printTime();
		fordJohnson.isSorted();
	} catch (std::exception &error) {
		std::cout << error.what() << std::endl;
	}
	return 0;
}

// https://en.wikipedia.org/wiki/Merge-insertion_sort
// https://en.wikipedia.org/wiki/Jacobsthal_number
// https://www.geeksforgeeks.org/binary-insertion-sort/