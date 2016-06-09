// A solução desse primeiramente calcula os números de Fibonnaci até o 44º, que é o maior número garantido pela entrada. 
// Após isso, o programa lê a sequência de números e a string da entrada. Utilizando o método dado pelo problema, cada 
// caractere da entrada é lido e seu índice na sequência de Fibonnaci é encontrado. Ao encontrar esse valor, temos a 
// a posição do caractere na string de saída, ele é então colocado na posição e isso é realizado para todos os caracteres
// até que temos a string de saída pronta e ela é impressa na console. 

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

int const QTD_FIBONACCI_NUMBERS = 45;
int const MAX_CYPHER_SIZE = 100;

std::vector<int> fillFibonacciVector(int qtd_numbers);
void decodeText(std::vector<int> inputNumbers, std::vector<int> fibonacciNumbers, std::string cypherText);
int getFibonacciIndex(int number, std::vector<int> fibonacciNumbers);

int main()  {

	int T, N, input;
	std::vector<int> inputNumbers;
	std::vector<int> fibonacciNumbers(QTD_FIBONACCI_NUMBERS);
	std::string cypherText;

	fibonacciNumbers = fillFibonacciVector(QTD_FIBONACCI_NUMBERS);

	std::cin >> T;

	while(T--)  {

		std::cin >> N;
		
		while(N--)  {
			std::cin >> input;
			inputNumbers.push_back(input);
		}

		std::cin.ignore();
		std::getline(std::cin, cypherText);
		decodeText(inputNumbers, fibonacciNumbers, cypherText);
		std::cout << "\n";
		inputNumbers.clear();
	}
	
	return 0;
}

std::vector<int> fillFibonacciVector(int qtd_numbers)  {
	
	int first = 1,
		second = 1,
		next;
	std::vector<int> fibonacciNumbers;

	for(int i = 1; i < qtd_numbers+1; i++)  {

		if(i <= 1) 
			next = i;
		else  {
			next = first + second;
			first = second;
			second = next;
		}

		fibonacciNumbers.push_back(next);
	}

	return fibonacciNumbers;
}

void decodeText(std::vector<int> inputNumbers, std::vector<int> fibonacciNumbers, std::string cypherText)  {

	char output[MAX_CYPHER_SIZE],
		 character;
	int fibonacciIndex = 0,
		maxFibonacciIndex = 0,
		lastValidIndex = 0;
	bool usedFibonacciNumbers[QTD_FIBONACCI_NUMBERS];
	
	for(int i = 0; i < QTD_FIBONACCI_NUMBERS; i++)
		usedFibonacciNumbers[i] = false;

	for(int i = 0; i < inputNumbers.size(); i++)  {

		fibonacciIndex = getFibonacciIndex(inputNumbers[i], fibonacciNumbers);
		usedFibonacciNumbers[fibonacciIndex] = true; 

		if(fibonacciIndex > maxFibonacciIndex)
			maxFibonacciIndex = fibonacciIndex;

		for(int j = lastValidIndex; j < cypherText.size(); j++)  {
			if((int)cypherText[j] >= 65 && (int)cypherText[j] <= 90)  {
				character = cypherText[j];
				lastValidIndex = j+1;
				break;
			}
		}

		output[fibonacciIndex] = character;
	}

	for(int i = 0; i < maxFibonacciIndex + 1; i++)  {
		if(!usedFibonacciNumbers[i])
			output[i] = (char)32;
	}

	for(int i = 0; i < maxFibonacciIndex + 1; i++)  {
		std::cout<<output[i];
	}
}

int getFibonacciIndex(int number, std::vector<int> fibonacciNumbers)  {
	
	for(int i = 0; i < QTD_FIBONACCI_NUMBERS; i++)  {
		if(number == fibonacciNumbers[i])
			return i;
	}
	return 0;
}
