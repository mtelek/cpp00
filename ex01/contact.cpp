/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:10:13 by mtelek            #+#    #+#             */
/*   Updated: 2024/12/29 20:33:19 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact() : _firstName(""), _lastName(""), _phoneNumber("")
{}

void Contact::setDetails(const std::string &firstName, const std::string &lastName,
	const std::string &nickname, const std::string &phoneNumber, const std::string  &darkestSecret)
{
	_firstName = firstName;
	_lastName = lastName;
	_nickname = nickname;
	_phoneNumber = phoneNumber;
	_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const
{
	return (_firstName);
}

std::string Contact::getLastName() const
{
	return (_lastName);
}

std::string Contact::getNickname() const
{
	return (_nickname);
}
