/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:58:47 by mtelek            #+#    #+#             */
/*   Updated: 2024/12/29 20:31:43 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		std::string _phoneNumber;
		std::string _darkestSecret;
		
	public:
		Contact();
		void setDetails(const std::string &firstName, const std::string &lastName,
			const std::string &nickname, const std::string &phoneNumber, const std::string  &darkestSsecret);
		
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
};

#endif