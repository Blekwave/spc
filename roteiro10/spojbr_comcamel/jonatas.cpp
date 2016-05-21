#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int const ZERO_ASCII_CODE = 48;

void defineInterpretations(std::string expression);
void readExpression(std::string expression, std::vector<long long int> &numbers, std::vector<char> &operations);
void defineMaxInterpretation(std::vector<long long int> numbers, std::vector<char> operations);
void defineMinInterpretation(std::vector<long long int> numbers, std::vector<char> operations);

int main()  {
	
	int N;
	std::string expression;

	std::cin >> N;
	std::cin.ignore();
	
	while(N--)  {

		std::getline(std::cin, expression);
		defineInterpretations(expression);
	}

	return 0;
}

void defineInterpretations(std::string expression)  {
	
	std::vector<long long int> numbers;
	std::vector<char> operations;

	readExpression(expression, numbers, operations);

	defineMaxInterpretation(numbers, operations);
	defineMinInterpretation(numbers, operations);
}

void readExpression(std::string expression, std::vector<long long int> &numbers, std::vector<char> &operations)  {
		
	char currentValue,
		 lastValue;
	bool lastWasNumber = false;
	long long int number;

	for(int i = 0; i < expression.size(); i++)  {
		currentValue = expression[i];
		if(currentValue == '+' || currentValue == '*')  {
			operations.push_back(currentValue);
			if(lastWasNumber)  {
				numbers.push_back((int)lastValue - ZERO_ASCII_CODE);
				lastWasNumber = false;
			}
		}
		else  {
			if(lastWasNumber)  {
				number = (int)currentValue - ZERO_ASCII_CODE;
				number += ((int)lastValue - ZERO_ASCII_CODE) * 10;
				numbers.push_back(number);
				lastWasNumber = false;
			}
			else  {
				if(i == expression.size() - 1)  {
					numbers.push_back((int)currentValue - ZERO_ASCII_CODE);
				} 
				else  {
					lastValue = currentValue;
					lastWasNumber = true;
				}
			}
		}
	}
}

void defineMaxInterpretation(std::vector<long long int> numbers, std::vector<char> operations)  {
	
	std::vector<long long int> simplifiedExpression;
	long long int result = 1;

	for(int i = 0; i < operations.size(); i++)  {
		if(operations[i] == '+')
			numbers[i + 1] += numbers[i];
	}

	for(int i = 0; i < operations.size(); i++)  {
		if(operations[i] == '*')
			simplifiedExpression.push_back(numbers[i]);
	}
	simplifiedExpression.push_back(numbers[numbers.size() - 1]);

	for(int i = 0; i < simplifiedExpression.size(); i++)  {
		result *= simplifiedExpression[i];
	}

	std::cout << "The maximum and minimum are " << result;
}

void defineMinInterpretation(std::vector<long long int> numbers, std::vector<char> operations)  {

	std::vector<long long int> simplifiedExpression;
	long long int result = 0;

	for(int i = 0; i < operations.size(); i++)  {
		if(operations[i] == '*')
			numbers[i + 1] *= numbers[i];
	}

	for(int i = 0; i < operations.size(); i++)  {
		if(operations[i] == '+')
			simplifiedExpression.push_back(numbers[i]);
	}
	simplifiedExpression.push_back(numbers[numbers.size() - 1]);

	for(int i = 0; i < simplifiedExpression.size(); i++)  {
		result += simplifiedExpression[i];
	}

	std::cout << " and " << result << ".\n";
}
