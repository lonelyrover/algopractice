#include <iostream>
#include <vector>
#include <set>
#include <string>

int main()
{
	int testCase;
	std::cin >> testCase;

	std::vector<std::multiset<std::string>> stringList;
	char input[1000+1] = { 0 };

	std::multiset<std::string> substrings;

	for (int i = 0; i < testCase; ++i)
	{		
		std::cin >> input;

		int j = 0;
		while (input[j])
		{
			std::string substring;
			substring.append(&input[j], 2);
			substrings.insert(substring);
			j += 2;
		}

		stringList.push_back(substrings);
		substrings.clear();
	}

	for (auto substrings : stringList)
	{
		std::multiset<std::string>::iterator itr = substrings.begin();
		while (itr != substrings.end())
		{
			std::cout << *itr++;
		}
		std::cout << std::endl;
	}
}