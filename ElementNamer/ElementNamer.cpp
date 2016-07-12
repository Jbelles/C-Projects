//https://www.reddit.com/r/dailyprogrammer/comments/4savyr/20160711_challenge_275_easy_splurthian_chemistry/
//bonus 1 and 2 as well.

#include <iostream>       // std::cout
#include <string>         // std::string
#include <vector>
#include <algorithm>

void isValidName(std::string ele, std::string sym) {
	signed short index = ele.find(sym[0]);
	if (index != std::string::npos) { //if the first letter of the given symbol name is present
		if (index < ele.size() && ele.substr(index + 1, ele.size()).find(sym[1]) != std::string::npos)//if the second letter of the symbol name is present in the remaining substring
		{
			std::cout << "Valid." << std::endl;
		}
		else {
			std::cout << "not a valid symbol name" << std::endl;
		}
	}
	else
	{
		std::cout << "not a valid symbol name" << std::endl;
	}
}

void findValidName(std::string ele) {
	std::string symbol;
	std::vector<std::string> combinations; //using a vector to store our string combinations
	for (unsigned int i = 0; i < ele.size()-1; i++) 
	{
		for (unsigned int j = i + 1; j < ele.size(); j++)
		{
			symbol = ele[i];
			symbol += ele[j]; //combine the symbols into one string
			combinations.push_back(symbol); //throw it on the vector

		}
	}
	std::sort(combinations.begin(), combinations.end()); //alphabetize
	combinations.erase(std::unique(combinations.begin(), combinations.end()), combinations.end()); //remove duplicates
	std::cout << "All combinations" << std::endl;
	for (std::vector<std::string>::iterator iter = combinations.begin(); iter != combinations.end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
	std::cout << "Alphabetically First: " + combinations.front() << std::endl;
	std::cout << "Number of combinations: ";
	std::cout << combinations.size() << std::endl;
}

int main() {
	std::string elementName, symbolName;
	std::cin >> elementName;
	std::cin >> symbolName;
	
	isValidName(elementName, symbolName);
	findValidName(elementName);
	return 0;
}

