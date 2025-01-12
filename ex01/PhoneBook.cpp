/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:39:12 by mtelek            #+#    #+#             */
/*   Updated: 2025/01/12 15:30:11 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : nextIndex(0) {}

PhoneBook::~PhoneBook() {}

Contact PhoneBook::getContact(int index) const
{
    return (contacts[index]);
}

int PhoneBook::getNextIndex() const
{
    return (nextIndex);
}

void PhoneBook::addContact(const std::string& firstName, const std::string& lastName,
	const std::string &nickname, const std::string& phoneNumber, const std::string &darkestSecret)
{
    contacts[nextIndex].setDetails(firstName, lastName, nickname, phoneNumber, darkestSecret);
    nextIndex = (nextIndex + 1) % MAX_CONTACTS;
}

std::string formatText(const std::string &text, int width)
{
    if (text.length() > static_cast<size_t>(width))
	{
        return (text.substr(0, width - 1) + ".");
    }
    return (text);
}

void	set_first_two_lines()
{
	int i;
	
	std::cout << std::setw(COLUMN_WIDTH) << std::right << "Index" << "|"
		<< std::setw(COLUMN_WIDTH) << std::right << "First Name" << "|"
		<< std::setw(COLUMN_WIDTH) << std::right << "Last Name" << "|"
		<< std::setw(COLUMN_WIDTH) << std::right << "Nickname" << "\n";

	for (i = 0; i < 4 * (COLUMN_WIDTH + 1) - 1; ++i)
		std::cout << "-";
	std::cout << "\n";
	
}

void PhoneBook::displayContacts() const
{
	int i;

	set_first_two_lines();	
	for (i = 0; i < MAX_CONTACTS; ++i)
	{
		if (!contacts[i].getFirstName().empty())
		{
			std::cout << std::setw(COLUMN_WIDTH) << std::right << (i + 1) << "|"
				<< std::setw(COLUMN_WIDTH) << std::right << formatText(contacts[i].getFirstName(), COLUMN_WIDTH) << "|"
				<< std::setw(COLUMN_WIDTH) << std::right << formatText(contacts[i].getLastName(), COLUMN_WIDTH) << "|"
				<< std::setw(COLUMN_WIDTH) << std::right << formatText(contacts[i].getNickname(), COLUMN_WIDTH) << "\n";
		}
	}
}
