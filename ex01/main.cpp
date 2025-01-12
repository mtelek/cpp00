/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:05:59 by mtelek            #+#    #+#             */
/*   Updated: 2025/01/12 15:28:21 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
 
bool is_valid_number(const std::string &str)
{
	size_t start = 0;
	size_t i;
	
	if (str[0] == '+')
	{
		if (str.size() == 1)
			return (false);
		start = 1;
	}
	for (i = start; i < str.size(); ++i)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return (true);
}

std::string getting_input(std::string input)
{
	if (!(std::cin >> input))
	{
		std::cout << "\nExiting program due to EOF.\n";
		exit(1);
	}
	return (input);
}

void execute_add(PhoneBook &phoneBook)
{
	std::string fName, lName, nName, phNumber, dSecret;
	
    std::cout << "Enter first name: ";
	fName = getting_input(fName);
	std::cout << "Enter last name: ";
	lName = getting_input(lName);
	std::cout << "Enter nickname: ";
	nName = getting_input(nName);
	std::cout << "Enter phone number: ";
	phNumber = getting_input(phNumber);
	while (is_valid_number(phNumber) == false)
	{
		std::cout << "Invalid phone number, please try again: ";
		phNumber = getting_input(phNumber);
	}
	std::cout << "Enter darkest secret: ";
	dSecret = getting_input(dSecret);
	phoneBook.addContact(fName, lName, nName, phNumber, dSecret);
}

void display_spec_contact(PhoneBook &phoneBook, int index)
{
    set_first_two_lines();
    Contact contact = phoneBook.getContact(index - 1);
	
    std::cout << std::setw(COLUMN_WIDTH) << std::right << index << "|"
              << std::setw(COLUMN_WIDTH) << std::right << formatText(contact.getFirstName(), COLUMN_WIDTH) << "|"
              << std::setw(COLUMN_WIDTH) << std::right << formatText(contact.getLastName(), COLUMN_WIDTH) << "|"
              << std::setw(COLUMN_WIDTH) << std::right << formatText(contact.getNickname(), COLUMN_WIDTH) << "\n";
}

void execute_search(PhoneBook &phoneBook)
{
	int index;
	
    phoneBook.displayContacts();
	std::cout << "Enter index number: ";
	std::string input = getting_input("");
	std::stringstream ss(input);
	ss >> index;
	while (ss.fail() || index < 1 || index > MAX_CONTACTS || 
           phoneBook.getContact(index - 1).getFirstName().empty())
	{
		std::cout << "Invalid index number, please try again: ";
        input = getting_input("");
        ss.clear();
        ss.str(input);
        ss >> index;
    }
	display_spec_contact(phoneBook, index);
}

int main()
{
	PhoneBook phoneBook;
	std::string cmd;

	while(1)
	{
		std::cout << "Enter a command: ";
		cmd = getting_input(cmd);
		if (cmd =="ADD")
			execute_add(phoneBook);
		else if (cmd == "SEARCH")
			execute_search(phoneBook);
		else if (cmd == "EXIT")
			break;
		else
			std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT.\n";
	}
	return (0);
}
