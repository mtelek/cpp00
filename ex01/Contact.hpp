/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:58:47 by mtelek            #+#    #+#             */
/*   Updated: 2025/01/12 15:30:37 by mtelek           ###   ########.fr       */
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
		~Contact();
		void setDetails(const std::string &firstName, const std::string &lastName,
			const std::string &nickname, const std::string &phoneNumber, const std::string  &darkestSsecret);
		
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickname() const;
};

#endif
