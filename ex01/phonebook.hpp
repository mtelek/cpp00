/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:45:53 by mtelek            #+#    #+#             */
/*   Updated: 2024/12/29 21:14:54 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <sstream>
#include <cctype>

#define COLUMN_WIDTH 10
#define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact contacts[MAX_CONTACTS];
		int nextIndex;

	public:
		PhoneBook();
		
		void addContact(const std::string &firstName, const std::string &lastName,
			const std::string &nickname, const std::string &phoneNumber, const std::string &darkestSecret);
		Contact getContact(int index) const;
		int getNextIndex() const;
		void displayContacts() const;
	
};

std::string	formatText(const std::string &text, int width);
void		set_first_two_lines();

#endif