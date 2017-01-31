#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>

std::map<std::string, int> stringToNumber;
std::map<int, std::string> numberToString;

int getNumberByString(char* stringNumber)
{
	for (auto stn : stringToNumber)
	{
		char input[26] = { 0 };
		int i = 0;
		while (stringNumber[i]) {
			++input[stringNumber[i] - 'a'];
			++i;
		}

		for (auto c : stn.first)
			--input[c - 'a'];

		for (i = 0; i < sizeof(input); ++i)
		{
			if (input[i] != '\0')
			{
				break;
			}
		}

		if (i == sizeof(input))
			return stn.second;
	}

	return -1;
}

int operate(int operand1, char oper, int operand2)
{
	if (oper == '+')
		return operand1 + operand2;
	else if (oper == '-')
		return operand1 - operand2;
	else if (oper == '*')
		return operand1 * operand2;

	return -1;
}

int main()
{
	stringToNumber.insert(std::make_pair("zero", 0));
	stringToNumber.insert(std::make_pair("one", 1));
	stringToNumber.insert(std::make_pair("two", 2));
	stringToNumber.insert(std::make_pair("three", 3));
	stringToNumber.insert(std::make_pair("four", 4));
	stringToNumber.insert(std::make_pair("five", 5));
	stringToNumber.insert(std::make_pair("six", 6));
	stringToNumber.insert(std::make_pair("seven", 7));
	stringToNumber.insert(std::make_pair("eight", 8));
	stringToNumber.insert(std::make_pair("nine", 9));
	stringToNumber.insert(std::make_pair("ten", 10));

	numberToString.insert(std::make_pair(0, "zero"));
	numberToString.insert(std::make_pair(1, "one"));
	numberToString.insert(std::make_pair(2, "two"));
	numberToString.insert(std::make_pair(3, "three"));
	numberToString.insert(std::make_pair(4, "four"));
	numberToString.insert(std::make_pair(5, "five"));
	numberToString.insert(std::make_pair(6, "six"));
	numberToString.insert(std::make_pair(7, "seven"));
	numberToString.insert(std::make_pair(8, "eight"));
	numberToString.insert(std::make_pair(9, "nine"));
	numberToString.insert(std::make_pair(10, "ten"));

	int testCase;
	std::cin >> testCase;

	std::vector<std::string> outputs;
	for (int t = 0; t < testCase; ++t)
	{
		char operand1[5 + 1] = { 0 }, oper[1 + 1] = { 0 }, operand2[5 + 1] = { 0 }, equal[1 + 1] = { 0 }, result[10 + 1] = { 0 };

		std::cin >> operand1 >> oper >> operand2 >> equal >> result;

		if (std::strlen(operand1) > 5 || std::strlen(operand2) > 5)
		{
			outputs.push_back("No");
			continue;
		}

		int numOperand1 = getNumberByString(operand1);
		if (numOperand1 < 0)
		{
			outputs.push_back("No");
			continue;
		}
		
		int numOperand2 = getNumberByString(operand2);
		if (numOperand2 < 0)
		{
			outputs.push_back("No");
			continue;
		}
		
		int numResult = getNumberByString(result);
		if (numResult < 0)
		{
			outputs.push_back("No");
			continue;
		}
		
		int numResult2 = operate(numOperand1, oper[0], numOperand2);
		if (numResult2 < 0)
		{
			outputs.push_back("No");
			continue;
		}

		if (numResult2 > 10 || numResult2 < 0 || numResult != numResult2)
		{
			outputs.push_back("No");
			continue;
		}

		outputs.push_back("Yes");
	}

	for (const auto output : outputs)
	{
		std::cout << output << std::endl;
	}
}