#include "Sed.hpp"

// Constructor Implementation
Sed::Sed(const std::string& s1, const std::string& s2) : s1(s1), s2(s2) {}

// Function to replace all occurrences of s1 with s2 in the input string
std::string Sed::replaceAll(const std::string& input) const {
    if (s1.empty()) {
        // If s1 is empty, return the original string to avoid infinite loops
        return input;
    }

    std::string result;
    size_t pos = 0; // Current position in the input string
    size_t found = input.find(s1, pos);

    while (found != std::string::npos) {
        // Append the substring before s1
        result.append(input, pos, found - pos);
        // Append s2 instead of s1
        result += s2;
        // Move past the last occurrence of s1
        pos = found + s1.length();
        // Find the next occurrence of s1
        found = input.find(s1, pos);
    }

    // Append the remaining part of the string after the last occurrence of s1
    result.append(input, pos, std::string::npos);

    return result;
}
