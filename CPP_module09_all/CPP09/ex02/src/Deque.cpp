#include "../includes/PmergeMe.hpp"

/*__________________________________________ FUNCTIONS __________________________________________*/

void PmergeMe::sort_Deque() {
	startTime_Deque = clock();
	n2_Deque();
	n2_SwapPairValues_Deque();
	n2_RecursiveMergeSort_Deque(n2_Sequence_Deque, 0, n2_Sequence_Deque.size() - 1);
	set_LargerAndSmallerFromN2sequence_Deque();
	n2_SortWithJacobsthalNumbers_Deque(largerSequence_Deque, smallerSequence_Deque);
	endTime_Deque = clock();
	// printResult_Deque();
}

void PmergeMe::n2_Deque() {
	std::deque<int>::iterator prevIt = inputSequence_Deque.begin(),
							  n2It = inputSequence_Deque.begin();

	for (; n2It < inputSequence_Deque.end(); n2It++) {
		if (std::distance(inputSequence_Deque.begin(), n2It) % 2 != 0)
			n2_Sequence_Deque.push_back(std::make_pair(*prevIt, *n2It));
		prevIt = n2It;
	}
	if (std::distance(inputSequence_Deque.begin(), n2It) % 2 != 0)
		n2_Sequence_Deque.push_back(std::make_pair(*prevIt, -1));
}

void PmergeMe::n2_SwapPairValues_Deque() {
	std::deque<std::pair<int, int> >::iterator n2It = n2_Sequence_Deque.begin();

	for (; n2It < n2_Sequence_Deque.end(); n2It++)
		if (n2It->first > n2It->second) std::swap(n2It->first, n2It->second);
}

void PmergeMe::merge_Deque(std::deque<std::pair<int, int> > &n2Sqnc, int left, int mid, int right) {
	int leftSize = mid - left + 1, rightSize = right - mid;
	std::deque<std::pair<int, int> > leftVectorPart(leftSize), rightVectorPart(rightSize);
	for (int i = 0; i < leftSize; i++) leftVectorPart[i] = n2Sqnc[left + i];	   // copy stuff to
	for (int j = 0; j < rightSize; j++) rightVectorPart[j] = n2Sqnc[mid + 1 + j];  // the half parts
	int i = 0, j = 0, leftCopy = left;

	// sort the pairs based on the 2nd val
	while (i < leftSize && j < rightSize) {
		if (leftVectorPart[i].second <= rightVectorPart[j].second) {
			n2Sqnc[leftCopy] = leftVectorPart[i++];
		} else
			n2Sqnc[leftCopy] = rightVectorPart[j++];
		leftCopy++;
	}
	while (i < leftSize) n2Sqnc[leftCopy++] = leftVectorPart[i++];
	while (j < rightSize) n2Sqnc[leftCopy++] = rightVectorPart[j++];
}

void PmergeMe::n2_RecursiveMergeSort_Deque(std::deque<std::pair<int, int> > &n2Sqnc, int left,
										   int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		n2_RecursiveMergeSort_Deque(n2Sqnc, left, mid);		  // left
		n2_RecursiveMergeSort_Deque(n2Sqnc, mid + 1, right);  // right
		merge_Deque(n2Sqnc, left, mid, right);
	}
}

void PmergeMe::n2_SortWithJacobsthalNumbers_Deque(std::deque<int> &targetDeque,
												  std::deque<int> &insertionDeque) {
	unsigned long lowerIndex = 1, upperIndex = getUpperJacobsIndex_Deque(insertionDeque),
				  iterationCount = upperIndex;

	targetDeque.insert(targetDeque.begin(), insertionDeque.at(0));
	for (; lowerIndex < insertionDeque.size();) {
		n2_BinaryInsert_Deque(targetDeque, insertionDeque.at(iterationCount),
							  upperIndex + lowerIndex - 1);
		if (iterationCount == lowerIndex) {
			lowerIndex = upperIndex + 1;
			upperIndex = getNextUpperJacobsIndex_Deque(insertionDeque, upperIndex);
			iterationCount = upperIndex;
		} else
			iterationCount--;
	}
	if (targetDeque.front() == -1) targetDeque.erase(targetDeque.begin());
	sortedSequence_Deque = targetDeque;
}

void PmergeMe::n2_BinaryInsert_Deque(std::deque<int> &targetDeque, int value, int insertionRange) {
	int lowerBound = 0, upperBound = getUpperBound_Deque(targetDeque, insertionRange);

	while (lowerBound <= upperBound) {
		int mid = lowerBound + (upperBound - lowerBound) / 2;

		if (targetDeque[mid] == value) {
			targetDeque.insert(targetDeque.begin() + mid + 1, value);
			return;
		} else if (targetDeque[mid] < value) {
			lowerBound = mid + 1;
		} else
			upperBound = mid - 1;
	}
	targetDeque.insert(targetDeque.begin() + lowerBound, value);
}

void PmergeMe::printResult_Deque() {
	std::deque<int>::iterator sortedIt = sortedSequence_Deque.begin();
	std::cout << AFTER << std::endl;
	for (; sortedIt < sortedSequence_Deque.end(); sortedIt++) std::cout << *sortedIt << " ";
	std::cout << std::endl;
}

/*___________________________________________ SETTERS ___________________________________________*/

void PmergeMe::set_DequeSequence() {
	for (int i = 1; i < sequenceSize + 1; i++) {
		for (size_t j = 0; j < std::strlen(sequence[i]); j++)
			if (std::string(NUMBERS).find(sequence[i][j]) == std::string::npos)
				throw std::logic_error(WRONGCHAR);
		inputSequence_Deque.push_back(std::atoi(sequence[i]));
	}
	int prevIndex = -1;
	std::deque<int>::iterator seqIt = inputSequence_Deque.begin();
	for (; seqIt < inputSequence_Deque.end(); seqIt++) {
		if (prevIndex != -1) {
			if (prevIndex < *seqIt)
				;
			else
				return;
		}
		prevIndex = *seqIt;
	}
	throw std::logic_error(ALREADYSORTED);
}

void PmergeMe::set_LargerAndSmallerFromN2sequence_Deque() {
	std::deque<std::pair<int, int> >::iterator n2It = n2_Sequence_Deque.begin();
	for (; n2It < n2_Sequence_Deque.end(); n2It++) {
		smallerSequence_Deque.push_back(n2It->first);
		largerSequence_Deque.push_back(n2It->second);
	}
}

/*___________________________________________ GETTERS ___________________________________________*/

unsigned long PmergeMe::getUpperJacobsIndex_Deque(const std::deque<int> &insertionDeque) {
	if (insertionDeque.size() > 2) return 2;
	return insertionDeque.size() - 1;
}

unsigned long PmergeMe::getNextUpperJacobsIndex_Deque(const std::deque<int> &insertionDeque,
													  unsigned int upperJacobsIndex) {
	if (getNextJacobsthalNumber(upperJacobsIndex + 1) > static_cast<int>(insertionDeque.size()))
		return insertionDeque.size() - 1;
	return getNextJacobsthalNumber(upperJacobsIndex + 1) - 1;
}

unsigned int PmergeMe::getUpperBound_Deque(const std::deque<int> &targetDeque,
										   unsigned long insertionRange) {
	if (targetDeque.size() < static_cast<unsigned long>(insertionRange)) {
		return targetDeque.size();
	} else
		return static_cast<unsigned int>(insertionRange);
}
