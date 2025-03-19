#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "IncludesAndDefines.hpp"

class PmergeMe {
   public:
	PmergeMe();
	PmergeMe(int _sequenceSize, char **_sequence);
	PmergeMe(PmergeMe const &cpy);
	~PmergeMe();
	PmergeMe &operator=(PmergeMe const &cpy);

	void sortSequence();
	void setSequence();
	int getNextJacobsthalNumber(int n);
	void printTime();
	void isSorted();

	void sort_Vector();
	void set_VectorSequence();
	void n2_Vector();
	void n2_SwapPairValues_Vector();
	void n2_RecursiveMergeSort_Vector(std::vector<std::pair<int, int> > &n2Sqnc, int left,
									  int right);
	void merge_Vector(std::vector<std::pair<int, int> > &n2Sqnc, int left, int mid, int right);
	void set_LargerAndSmallerFromN2sequence_Vector();
	void n2_SortWithJacobsthalNumbers_Vector(std::vector<int> &targetVector,
											 std::vector<int> &insertionVector);
	unsigned long getUpperJacobsIndex_Vector(const std::vector<int> &insertionVector);
	unsigned long getNextUpperJacobsIndex_Vector(const std::vector<int> &insertionVector,
												 unsigned int upperJacobsIndex);
	unsigned int getUpperBound_Vector(const std::vector<int> &targetVector,
									  unsigned long insertionRange);
	void n2_BinaryInsert_Vector(std::vector<int> &targetVector, int value, int insertionRange);
	void printResult_Vector();

	void sort_Deque();
	void set_DequeSequence();
	void n2_Deque();
	void n2_SwapPairValues_Deque();
	void n2_RecursiveMergeSort_Deque(std::deque<std::pair<int, int> > &n2Sqnc, int left, int right);
	void merge_Deque(std::deque<std::pair<int, int> > &n2Sqnc, int left, int mid, int right);
	void set_LargerAndSmallerFromN2sequence_Deque();
	void n2_SortWithJacobsthalNumbers_Deque(std::deque<int> &targetDeque,
											std::deque<int> &insertionDeque);
	unsigned long getUpperJacobsIndex_Deque(const std::deque<int> &insertionDeque);
	unsigned long getNextUpperJacobsIndex_Deque(const std::deque<int> &insertionDeque,
												unsigned int upperJacobsIndex);
	unsigned int getUpperBound_Deque(const std::deque<int> &targetDeque,
									 unsigned long insertionRange);
	void n2_BinaryInsert_Deque(std::deque<int> &targetDeque, int value, int insertionRange);
	void printResult_Deque();

   private:
	int sequenceSize;
	char **sequence;

	clock_t startTime_Vector;
	std::vector<int> inputSequence_Vector;
	std::vector<std::pair<int, int> > n2Sequence_Vector;
	std::vector<int> smallerSequence_Vector;
	std::vector<int> largerSequence_Vector;
	std::vector<int> sortedSequence_Vector;
	clock_t endTime_Vector;

	clock_t startTime_Deque;
	std::deque<int> inputSequence_Deque;
	std::deque<std::pair<int, int> > n2_Sequence_Deque;
	std::deque<int> smallerSequence_Deque;
	std::deque<int> largerSequence_Deque;
	std::deque<int> sortedSequence_Deque;
	clock_t endTime_Deque;
};

#endif