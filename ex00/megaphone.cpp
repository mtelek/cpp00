/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:20:09 by mtelek            #+#    #+#             */
/*   Updated: 2024/12/28 14:06:35 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
	char *arg;
	int i;
	
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (i = 1; i < argc; i++)
		{
			arg = argv[i];
			while (*arg)
			{
				std::cout << (char)std::toupper(*arg);
				++arg;
			}
			std::cout << " ";
		}
	}
	std::cout << "\n";
	return (0);
}
