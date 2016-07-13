//https://www.reddit.com/r/dailyprogrammer/comments/4so25w/20160713_challenge_275_intermediate_splurthian/

#include <iostream>       // std::cout
#include <string>         // std::string
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>


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

void findAllPreferredNames(std::vector<std::string> elements) {
	std::vector<std::string> symbols;
	std::string symbol;

	for (std::vector<std::string>::iterator iter = elements.begin(); iter != elements.end(); ++iter)
	{
		std::cout << *iter;
		for (unsigned int i = 0; i < iter->size() - 1; i++)
		{
			for (unsigned int j = i + 1; j < iter->size(); j++)
			{
				symbol = (*iter)[i];
				symbol += (*iter)[j]; //combine the symbols into one string
				if (!(std::find(symbols.begin(), symbols.end(), symbol) != symbols.end()))//check if it is already in the list
				{
					symbols.push_back(symbol); //throw it on the vector
					symbol[0] = toupper(symbol[0]);
					std::cout << ": ";
					std::cout << symbol<< std::endl;
					goto loopbreak;
				}
				else if (i == (*iter).size()-2 && j == (*iter).size() -1){
					symbol = ": No Valid Symbol";
					symbols.push_back(symbol);
					std::cout << symbol << std::endl;		
				}// Do nothing if it finds it in the list already

			}
		}
	loopbreak:;
	}
	std::cout << symbols.size() << std::endl;
}
int main() {
	std::string elementName, symbolName;
	//std::cin >> elementName;
	//std::cin >> symbolName;
	std::vector<std::string> ElementArray;
	std::string line;
	std::ifstream ElementNames("ElementNames.txt");
	while (std::getline(ElementNames, line))
	{
		ElementArray.push_back(line);
	}
	findAllPreferredNames(ElementArray);

	
	//isValidName(elementName, symbolName);
	//findValidName(elementName);
	return 0;
}

