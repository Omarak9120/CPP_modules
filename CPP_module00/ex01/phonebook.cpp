/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:49:02 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/23 17:19:24 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>

// Utility Functions

// Function to trim whitespace from both ends of a string
std::string trim(const std::string& s) {
	size_t start = s.find_first_not_of(" \t\r\n");
	size_t end = s.find_last_not_of(" \t\r\n");
	if (start == std::string::npos)
		return "";
	return s.substr(start, end - start + 1);
}

// Function to convert a string to uppercase
std::string toUpper(const std::string& s) {
	std::string result = s;
	for (size_t i = 0; i < result.length(); ++i)
		result[i] = toupper(result[i]);
	return result;
}

// Contact Class
class Contact {
private:
	std::string fname;
	std::string lname;
	std::string nname;
	std::string pnum;
	std::string darkestSecret; 

public:
	// Constructors
	Contact() {}
	Contact(const std::string& firstName, const std::string& lastName,
			const std::string& nickName, const std::string& phoneNumber)
		: fname(firstName), lname(lastName), nname(nickName), pnum(phoneNumber) {}

	// Getter Methods
	std::string getFirstName() const { return fname; }
	std::string getLastName() const { return lname; }
	std::string getNickName() const { return nname; }
	std::string getPhoneNumber() const { return pnum; }
	std::string getDarkestSecret() const { return darkestSecret; }

	// Setter Methods
	void setFirstName(const std::string& firstName) { fname = firstName; }
	void setLastName(const std::string& lastName) { lname = lastName; }
	void setNickName(const std::string& nickName) { nname = nickName; }
	void setPhoneNumber(const std::string& phoneNumber) { pnum = phoneNumber; }
	void setDarkestSecret(const std::string& secret) { darkestSecret = secret; }
};

// Function to print strings with formatting rules
void print_with_rules(const std::string& str, bool isLastField) {
	if (str.length() > 10) {
		std::cout << std::setw(9) << std::right << str.substr(0, 9) << ".";
	} else {
		// Right-align the string within a 10-character width
		std::cout << std::setw(10) << std::right << str;
	}

	if (!isLastField)
		std::cout << " | ";
	else
		std::cout << std::endl;
}

// PhoneBook Class
class PhoneBook
{
private:
	Contact contacts[8];
	int currentIndex;
	int contactCount;

	// Helper Method to Format Output
	void printWithRules(const std::string& str, bool isLastField) const {
		print_with_rules(str, isLastField);
	}

public:
	// Constructor
	PhoneBook() : currentIndex(0), contactCount(0) {}

	// Add a New Contact
	void addContact(const Contact& newContact) {
		contacts[currentIndex] = newContact;
		currentIndex = (currentIndex + 1) % 8;
		if (contactCount < 8)
			contactCount++;
		std::cout << "Contact added successfully!" << std::endl;
	}

	// Search and Display Contacts
	void searchContacts() const {
		if (contactCount == 0) {
			std::cout << "PhoneBook is empty. Add contacts first." << std::endl;
			return;
		}

		// Display Header
		std::cout << std::setw(10) << "Index" << " | "
				  << std::setw(10) << "First Name" << " | "
				  << std::setw(10) << "Last Name" << " | "
				  << std::setw(10) << "Nickname" << std::endl;
		std::cout << "-----------|------------|------------|------------" << std::endl;

		// Display Contacts
		for (int i = 0; i < contactCount; ++i) {
			std::cout << std::setw(10) << i + 1 << " | ";
			printWithRules(contacts[i].getFirstName(), false);
			printWithRules(contacts[i].getLastName(), false);
			printWithRules(contacts[i].getNickName(), true);
		}

		// Prompt for Index to View Details
		int index;
		std::cout << "Enter the index of the contact to view details: ";
		if (!(std::cin >> index)) {
			std::cout << "Invalid input. Please enter a number." << std::endl;
			std::cin.clear();
			// Discard invalid input
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return;
		}

		// Clear the input buffer after reading the index
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// Validate Index
		if (index < 1 || index > contactCount) {
			std::cout << "Invalid index. Please enter a number between 1 and " << contactCount << "." << std::endl;
			return;
		}

		// Display Detailed Information
		const Contact& selected = contacts[index - 1];
		std::cout << "Contact Details:" << std::endl;
		std::cout << "First Name: " << selected.getFirstName() << std::endl;
		std::cout << "Last Name: " << selected.getLastName() << std::endl;
		std::cout << "Nickname: " << selected.getNickName() << std::endl;
		std::cout << "Phone Number: " << selected.getPhoneNumber() << std::endl;
	}
};

// Function to Add a Contact to the PhoneBook
void add_pb(PhoneBook* pb) {
	Contact newContact;
	std::string input;

	// Function to get non-empty input (simulated using a regular function)
	while (true) {
		std::cout << "Enter the first name of your contact: ";
		std::getline(std::cin, input);
		input = trim(input);
		if (!input.empty()) {
			newContact.setFirstName(input);
			break;
		}
		std::cout << "First name cannot be empty. Please try again." << std::endl;
	}

	while (true)
	{
		std::cout << "Enter the last name of your contact: ";
		std::getline(std::cin, input);
		input = trim(input);
		if (!input.empty()) {
			newContact.setLastName(input);
			break;
		}
		std::cout << "Last name cannot be empty. Please try again." << std::endl;
	}

	while (true)
	{
		std::cout << "Enter the nickname of your contact: ";
		std::getline(std::cin, input);
		input = trim(input);
		if (!input.empty()) {
			newContact.setNickName(input);
			break;
		}
		std::cout << "Nickname cannot be empty. Please try again." << std::endl;
	}

	// Phone number validation: ensure only digits
	while (true) {
		std::cout << "Enter the phone number of your contact: ";
		std::getline(std::cin, input);
		input = trim(input);
		if (!input.empty()) {
			bool valid = true;
			for (size_t j = 0; j < input.length(); ++j) {
				if (!isdigit(input[j])) {
					valid = false;
					break;
				}
			}
			if (valid) {
				newContact.setPhoneNumber(input);
				break;
			}
		}
		std::cout << "Invalid phone number. Please enter digits only." << std::endl;
	}

    while (true) {
        std::cout << "Enter the darkest secret of your contact: ";
        std::getline(std::cin, input);
        input = trim(input);
        if (!input.empty()) {
            newContact.setDarkestSecret(input);
            break;
        }
        std::cout << "Darkest secret cannot be empty. Please try again." << std::endl;
    }
	//add contact to phonebook
    pb->addContact(newContact);
}

// Function to Search and Display a Contact
void search_pb(PhoneBook* pb) {
	pb->searchContacts();
}

int main(){
	std::string command;
	PhoneBook phoneBook;

	std::cout << "hello hello hello!" << std::endl;

	while (true) 
	{
		std::cout << "Enter your command (ADD, SEARCH, EXIT)> ";
		std::getline(std::cin, command);

		// Handle EOF (e.g., Ctrl+D)
		if (std::cin.eof()) {
			std::cout << "\nEOF detected. Exiting." << std::endl;
			break;
		}

		// Trim and convert command to uppercase for case-insensitive comparison
		command = trim(command);
		command = toUpper(command);

		if (command == "ADD") {
			add_pb(&phoneBook);
		}
		else if (command == "SEARCH") {
			search_pb(&phoneBook);
		}
		else if (command == "EXIT") {
			std::cout << "Goodbye!" << std::endl;
			break;
		}
		else {
			std::cout << "Unknown command. Please enter ADD, SEARCH, or EXIT." << std::endl;
		}
	}

	return 0;
}
