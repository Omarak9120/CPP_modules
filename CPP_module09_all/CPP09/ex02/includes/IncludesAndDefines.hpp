#ifndef INCLUDESANDDEFINES_HPP
#define INCLUDESANDDEFINES_HPP

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstring>
#include <ctime>
#include <deque>
#include <exception>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#define RED "\033[1;31m"
#define END "\033[1;39m"
#define BLUE "\033[1;34m"
#define YELLOW "\033[1;33m"

#define NUMBERS "0123456789"
#define AFTER "\033[1;4;32mAfter:\033[1;0;39m "
#define BEFORE "\033[1;4;33mBefore:\033[1;0;39m "
#define DEQ_SORTED "\033[1;32mDeque is sorted.\033[1;39m"
#define VEC_SORTED "\033[1;32mVector is sorted.\033[1;39m"
#define DEQ_NOTSORTED "\033[1;31mDeque is not sorted.\033[1;39m"
#define VEC_NOTSORTED "\033[1;31mVector is not sorted.\033[1;39m"
#define DEQUE_RESULT1 "\033[1;4;34mTime to process a range of\033[1;0;39m "
#define DEQUE_RESULT2 "\033[1;4;34m elements with std::deque:\033[1;0;39m "
#define VECTOR_RESULT1 "\033[1;4;34mTime to process a range of\033[1;0;39m "
#define VECTOR_RESULT2 " \033[1;4;34melements with std::vector is:\033[1;0;39m "
#define ALREADYSORTED "\033[1;31mThe input sequence is already sorted.\033[1;39m"
#define WRONGCHAR "\033[1;31mThe input contains non numeric characters.\033[1;39m"
#define TOOSHORT "\033[1;31mThe sequence is too short, there is nothing to sort.\033[1;39m"
#define NOARG \
	"\033[1;31mFord needs a sequence of positive numbers to be able to Johnson around.\033[1;39m"

#endif