#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

const int BILL_50 = 50;
const int BILL_10 = 10;
const int BILL_5 = 5;
const int BILL_1 = 1;
const int NUMBER_OF_BILLS = 4;

void selectMoneyBills(int V, std::vector<int> values, int testCounter);

int main()  {
	std::vector<int> values(NUMBER_OF_BILLS);
	int V, 
		testCounter = 1;

	while(true)  {
		std::cin >> V;
		if(V == 0)
			break;
		for(int i = 0; i < NUMBER_OF_BILLS; i++)
			values[i] = 0;
		selectMoneyBills(V, values, testCounter);
		testCounter++;
	}
	return 0;
}

void selectMoneyBills(int V, std::vector<int> values, int testCounter)  {
	while(V >= BILL_50)  {
		values[0]++;
		V -= BILL_50;
	}
	while(V >= BILL_10)  {
		values[1]++;
		V -= BILL_10;
	}
	while(V >= BILL_5)  {
		values[2]++;
		V -= BILL_5;
	}
	while(V >= BILL_1)  {
		values[3]++;
		V -= BILL_1;
	}
	std::cout << "Teste " << testCounter << "\n";
	for(int i = 0; i <  NUMBER_OF_BILLS; i++)  {
		std::cout << values[i] << " ";
	}
	std::cout << "\n\n";
}
