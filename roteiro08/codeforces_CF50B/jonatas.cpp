#include <iostream>
#include <string>
#include <map>

int main()  {
	std::string inputString;
	long long int numberOfPairs = 0;
	std::map<char,long long int> charMap;
	std::getline(std::cin, inputString);
	
	for(int i = 0; i < inputString.size(); i++)  {
		charMap[inputString[i]]++;
	}

	for(auto q : charMap) {
		numberOfPairs += q.second * q.second;
	} 

	std::cout << numberOfPairs;

	return 0;
}
