#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

void insert(std::map<int, int>& count, int number)
{
	auto element = count.find(number);
	if (element == count.end())
		count.insert(std::map<int, int>::value_type(number, 0));
	else
		++element->second;
}

int getMin(std::map<int, int>& count)
{
	int minValue = count.begin()->first, minCount = count.begin()->second;
	for (auto element : count)
	{
		if (element.second < minCount) {
			minValue = element.first;
			minCount = element.second;
		}
	}

	return minValue;
}

int main()
{
	int testCase, x, y;
	std::cin >> testCase;

	std::map<int, int> countX, countY;
	std::vector<std::pair<int, int>> resultCoords;

	for (int i = 0; i < testCase; ++i)
	{
		std::cin >> x >> y;
		insert(countX, x);
		insert(countY, y);

		std::cin >> x >> y;
		insert(countX, x);
		insert(countY, y);

		std::cin >> x >> y;
		insert(countX, x);
		insert(countY, y);

		resultCoords.push_back(std::pair<int, int>(getMin(countX), getMin(countY)));

		countX.clear();
		countY.clear();
	}

	for (auto coord : resultCoords)
	{
		std::cout << coord.first << " " << coord.second << std::endl;
	}
}