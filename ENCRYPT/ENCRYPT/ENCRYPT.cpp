#include <iostream>
#include <vector>
#include <string>
#include <cassert>

int main()
{
	int testCase;
	std::cin >> testCase;

	char input[100 + 1] = { 0 };

	std::vector<std::string> outputs;
	for (int i = 0; i < testCase; ++i)
	{
		std::string first, second;

		std::cin >> input;
		int j = 0;
		while (input[j])
		{
			if ((j & 0x1) == 0x1)
				second.append(1, input[j]);
			else
				first.append(1, input[j]);
			++j;
		}

		outputs.push_back(first + second);
	}

	for (auto output : outputs)
	{
		std::cout << output << std::endl;
	}
}