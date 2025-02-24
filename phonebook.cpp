/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oabdelka <oabdelka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:48:59 by oabdelka          #+#    #+#             */
/*   Updated: 2025/02/17 19:34:30 by oabdelka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>

// Contact Class
class Contact{
	public:
		std::string fname;
		std::string lname;
		std::string nname;
		std::string pnum;
};

// print_with_rules Function
void	print_with_rules(const std::string &str, bool isLastField)
{
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9) << ".";
	}
	else
	{
		// Right-align the string within a 10-character width
		std::cout << std::setw(10) << str;
	}
	if (!isLastField)
		std::cout << " | ";
	else
		std::cout << std::endl;
}

// PhoneBook Class
class PhoneBook{
	public:
		Contact c[8];
	private:
		int i;
	public:
		void	ini_index()
		{
			i = 0;
		}
		void	add(Contact nc)
		{
			if (i == 8)
				i = 0;
			c[i] = nc;
			i++;
		}
		void	search(int	in)
		{
			if (in < 0 || in > 7)
			{
				std::cout << "Invalid index" << std::endl;
				return ;
			}
			if (!c[in].fname.empty())
			{
				std::cout << in << " | ";
				print_with_rules(c[in].fname, false);
				print_with_rules(c[in].lname, false);
				print_with_rules(c[in].nname, true);
			}
			else
				std::cout << "Invalid index" << std::endl;
		}
};

// Function to add a contact to the phonebook
void add_pb(PhoneBook *pb)
{
    Contact nc;
    
    std::cout << "Enter the first name of your contact: ";
    std::getline(std::cin, nc.fname);
    std::cout << "Enter the last name of your contact: ";
    std::getline(std::cin, nc.lname);
    std::cout << "Enter the nickname of your contact: ";
    std::getline(std::cin, nc.nname);
    std::cout << "Enter the phone number of your contact: ";
    std::getline(std::cin, nc.pnum);    
    pb->add(nc);
}

// Function to search and display a contact
void search_pb(PhoneBook *pb)
{
    int in;

    std::cout << "Enter the index you want to search for: ";
    if (!(std::cin >> in))
    {
        std::cout << "Invalid input. Please enter a number." << std::endl;
        std::cin.clear();
        // Discard invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    pb->search(in);
    // Discard the remaining input after reading the index
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(){
	std::string str;
	PhoneBook pb;

	std::cout << "hello hello hello" << std::endl;
	pb.ini_index();
	do{
		std::cout << "Enter your command (ADD, SEARCH, EXIT)> ";
		std::getline(std::cin, str);
		if (str == "ADD")
			add_pb(&pb);
		else if (str == "SEARCH")
			search_pb(&pb);
		else if (str == "EXIT")
			break ;
		else
			std::cout << "Unknown command. Please enter ADD, SEARCH, or EXIT." << std::endl;
	}while (str != "EXIT");
	return 0;
}
