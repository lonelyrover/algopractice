#include <iostream>
#include <vector>
#include <string>
#include <cstring>

int main()
{
	int testCase;
	std::cin >> testCase;

	int nth;
	char string[80 + 1] = { 0 };

	std::vector<std::string> outputs;

	for (int i = 0; i < testCase; ++i)
	{
		std::cin >> nth >> string;

		--nth;

		const size_t len = std::strlen(string);
		for (unsigned int i = nth; i < len; ++i)
		{
			string[i] = string[i + 1];
		}

		outputs.push_back(string);
	}

	int i = 0;
	for (auto output : outputs)
	{
		std::cout << ++i << " " << output << std::endl;
	}
}