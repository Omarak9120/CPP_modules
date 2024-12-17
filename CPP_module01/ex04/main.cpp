/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:17:00 by oabdelka          #+#    #+#             */
/*   Updated: 2024/12/13 13:47:22 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "Sed.hpp"

// Function to display usage instructions
void displayUsage(const std::string& programName) {
	std::cerr << "Usage: " << programName << " <filename> <s1> <s2>" << std::endl;
	std::cerr << "Replaces all occurrences of <s1> with <s2> in <filename> and saves the result to <filename>.replace" << std::endl;
}

int main(int argc, char* argv[]) {
	// Check for exactly three arguments (program name + 3)
	if (argc != 4) {
		displayUsage(argv[0]);
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// Check if s1 is empty
	if (s1.empty()) {
		std::cerr << "Error: The string to replace (s1) cannot be empty." << std::endl;
		return 1;
	}

	// Open the input file for reading
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: Could not open the file \"" << filename << "\" for reading." << std::endl;
		return 1;
	}

	// Create the output filename by appending ".replace"
	std::string outputFilename = filename + ".replace";

	// Open the output file for writing
	std::ofstream outputFile(outputFilename.c_str());
	if (!outputFile.is_open()) {
		std::cerr << "Error: Could not create the file \"" << outputFilename << "\" for writing." << std::endl;
		inputFile.close();
		return 1;
	}

	// Read the entire content of the input file into a string
	std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());

	// Close the input file as it's no longer needed
	inputFile.close();

	// Create a Sed object to handle the replacement
	Sed sed(s1, s2);
	std::string modifiedContent = sed.replaceAll(content);

	// Write the modified content to the output file
	outputFile << modifiedContent;

	// Close the output file
	outputFile.close();

	// Inform the user of successful operation
	std::cout << "Replacement complete. Modified content saved to \"" << outputFilename << "\"." << std::endl;

	return 0;
}
