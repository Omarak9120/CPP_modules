#include "../includes/PmergeMe.hpp"

/*__________________________________________ FUNCTIONS __________________________________________*/

void PmergeMe::sort_Vector() {
	startTime_Vector = clock();
	n2_Vector();
	n2_SwapPairValues_Vector();
	n2_RecursiveMergeSort_Vector(n2Sequence_Vector, 0, n2Sequence_Vector.size() - 1);
	set_LargerAndSmallerFromN2sequence_Vector();
	n2_SortWithJacobsthalNumbers_Vector(largerSequence_Vector, smallerSequence_Vector);
	endTime_Vector = clock();
	printResult_Vector();
}

void PmergeMe::n2_Vector() {
	std::vector<int>::iterator prevIt = inputSequence_Vector.begin(),
							   n2It = inputSequence_Vector.begin();

	for (; n2It < inputSequence_Vector.end(); n2It++) {
		if (std::distance(inputSequence_Vector.begin(), n2It) % 2 != 0)
			n2Sequence_Vector.push_back(std::make_pair(*prevIt, *n2It));
		prevIt = n2It;
	}
	if (std::distance(inputSequence_Vector.begin(), n2It) % 2 != 0)
		n2Sequence_Vector.push_back(std::make_pair(*prevIt, -1));
}

void PmergeMe::n2_SwapPairValues_Vector() {
	std::vector<std::pair<int, int> >::iterator n2It = n2Sequence_Vector.begin();

	for (; n2It < n2Sequence_Vector.end(); n2It++)
		if (n2It->first > n2It->second) std::swap(n2It->first, n2It->second);
}

void PmergeMe::merge_Vector(std::vector<std::pair<int, int> >& n2Sqnc, int left, int mid,
							int right) {
	int leftSize = mid - left + 1, rigthSize = right - mid;
	std::vector<std::pair<int, int> > leftVectorPart(leftSize), rightVectorPart(rigthSize);
	for (int i = 0; i < leftSize; ++i) leftVectorPart[i] = n2Sqnc[left + i];	   // copy stuff to
	for (int j = 0; j < rigthSize; ++j) rightVectorPart[j] = n2Sqnc[mid + 1 + j];  // the half parts
	int i = 0, j = 0, leftCopy = left;

	// sort the pairs based on the 2nd val
	while (i < leftSize && j < rigthSize) {
		if (leftVectorPart[i].second <= rightVectorPart[j].second) {
			n2Sqnc[leftCopy] = leftVectorPart[i++];
		} else
			n2Sqnc[leftCopy] = rightVectorPart[j++];
		leftCopy++;
	}
	while (i < leftSize) n2Sqnc[leftCopy++] = leftVectorPart[i++];
	while (j < rigthSize) n2Sqnc[leftCopy++] = rightVectorPart[j++];
}

void PmergeMe::n2_RecursiveMergeSort_Vector(std::vector<std::pair<int, int> >& n2Sqnc, int left,
											int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		n2_RecursiveMergeSort_Vector(n2Sqnc, left, mid);	   // left
		n2_RecursiveMergeSort_Vector(n2Sqnc, mid + 1, right);  // right
		merge_Vector(n2Sqnc, left, mid, right);
	}
}

void PmergeMe::n2_SortWithJacobsthalNumbers_Vector(std::vector<int>& targetVector,
												   std::vector<int>& insertionVector) {
	unsigned long lowerIndex = 1, upperIndex = getUpperJacobsIndex_Vector(insertionVector),
				  iterationCount = upperIndex;

	targetVector.insert(targetVector.begin(), insertionVector.at(0));
	for (; lowerIndex < insertionVector.size();) {
		n2_BinaryInsert_Vector(targetVector, insertionVector.at(iterationCount),
							   upperIndex + lowerIndex - 1);
		if (iterationCount == lowerIndex) {
			lowerIndex = upperIndex + 1;
			upperIndex = getNextUpperJacobsIndex_Vector(insertionVector, upperIndex);
			iterationCount = upperIndex;
		} else
			iterationCount--;
	}
	if (targetVector.front() == -1) targetVector.erase(targetVector.begin());
	sortedSequence_Vector = targetVector;
}

void PmergeMe::n2_BinaryInsert_Vector(std::vector<int>& targetVector, int value,
									  int insertionRange) {
	int lowerBound = 0, upperBound = getUpperBound_Vector(targetVector, insertionRange);

	while (lowerBound <= upperBound) {
		int mid = lowerBound + (upperBound - lowerBound) / 2;

		if (targetVector[mid] == value) {
			targetVector.insert(targetVector.begin() + mid + 1, value);
			return;
		} else if (targetVector[mid] < value) {
			lowerBound = mid + 1;
		} else
			upperBound = mid - 1;
	}
	targetVector.insert(targetVector.begin() + lowerBound, value);
}

void PmergeMe::printResult_Vector() {
	std::vector<int>::iterator sortedIt = sortedSequence_Vector.begin();
	std::cout << AFTER << std::endl;
	for (; sortedIt < sortedSequence_Vector.end(); sortedIt++) std::cout << *sortedIt << " ";
	std::cout << std::endl;
}

/*___________________________________________ SETTERS ___________________________________________*/

void PmergeMe::set_VectorSequence() {
	for (int i = 1; i < sequenceSize + 1; i++) {
		for (size_t j = 0; j < std::strlen(sequence[i]); j++)
			if (std::string(NUMBERS).find(sequence[i][j]) == std::string::npos)
				throw std::logic_error(WRONGCHAR);
		inputSequence_Vector.push_back(std::atoi(sequence[i]));
	}
	int prevIndex = -1;
	std::vector<int>::iterator seqIt = inputSequence_Vector.begin();
	for (; seqIt < inputSequence_Vector.end(); seqIt++) {
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

void PmergeMe::set_LargerAndSmallerFromN2sequence_Vector() {
	std::vector<std::pair<int, int> >::iterator n2It = n2Sequence_Vector.begin();
	for (; n2It < n2Sequence_Vector.end(); n2It++) {
		smallerSequence_Vector.push_back(n2It->first);
		largerSequence_Vector.push_back(n2It->second);
	}
}

/*___________________________________________ GETTERS ___________________________________________*/

unsigned long PmergeMe::getUpperJacobsIndex_Vector(const std::vector<int>& insertionVector) {
	if (insertionVector.size() > 2) return 2;
	return insertionVector.size() - 1;
}

unsigned long PmergeMe::getNextUpperJacobsIndex_Vector(const std::vector<int>& insertionVector,
													   unsigned int upperIndex) {
	if (getNextJacobsthalNumber(upperIndex + 1) > static_cast<int>(insertionVector.size()))
		return insertionVector.size() - 1;
	return getNextJacobsthalNumber(upperIndex + 1) - 1;
}

unsigned int PmergeMe::getUpperBound_Vector(const std::vector<int>& targetVector,
											unsigned long insertionRange) {
	if (targetVector.size() < static_cast<unsigned long>(insertionRange)) {
		return targetVector.size();
	} else
		return static_cast<unsigned int>(insertionRange);
}
