#ifndef SED_HPP
#define SED_HPP

#include <string>

class Sed {
private:
    std::string s1;
    std::string s2;

public:
    // Constructor
    Sed(const std::string& s1, const std::string& s2);

    // Function to perform the replacement
    std::string replaceAll(const std::string& input) const;
};

#endif