#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>

void buildSearchTable(std::map<std::string, char>& referenceTable, std::map<char, std::map<char, char>>& searchTable)
{
	for (auto referenceItr : referenceTable)
	{
		searchTable[referenceItr.first.at(0)][referenceItr.first.at(1)] = referenceItr.second;
	}
}

int main()
{
	std::map<std::string, char> referenceTable;
	referenceTable.insert(std::make_pair("20", ' '));
	referenceTable.insert(std::make_pair("21", '!'));
	referenceTable.insert(std::make_pair("24", '$'));
	referenceTable.insert(std::make_pair("25", '%'));
	referenceTable.insert(std::make_pair("28", '('));
	referenceTable.insert(std::make_pair("29", ')'));
	referenceTable.insert(std::make_pair("2a", '*'));

	std::map<char, std::map<char, char>> searchTable;

	buildSearchTable(referenceTable, searchTable);

	int testCase;
	std::cin >> testCase;

	std::vector<std::string> outputs;

	char input[80 + 1] = { 0 }, output[80 + 1] = {0};
	for (int i = 0; i < testCase; ++i)
	{
		std::cin >> input;

		int j = 0, k = 0;
		while (input[j] != 0)
		{
			if (input[j] == '%')
			{
				auto itr = searchTable.find(input[j + 1]);
				if (itr != searchTable.end())
				{
					auto secondItr = itr->second.find(input[j + 2]);
					if (secondItr != itr->second.end())
					{
						output[k] = secondItr->second;
						j += 2;
					}
				}
			}
			else
			{
				output[k] = input[j];
			}

			++j;
			++k;
		}

		outputs.push_back(output);
		std::memset(output, 0, sizeof(output));
	}

	for (auto output : outputs)
	{
		std::cout << output << std::endl;
	}
}