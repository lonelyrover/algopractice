#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

void increaseCount(std::map<int, int>& count, int number)
{
	auto element = count.find(number);
	if (element == count.end())
		count.insert(std::map<int, int>::value_type(number, 1));
	else
		++element->second;
}

int getMinCount(std::map<int, int>& count)
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
		increaseCount(countX, x);
		increaseCount(countY, y);

		std::cin >> x >> y;
		increaseCount(countX, x);
		increaseCount(countY, y);

		std::cin >> x >> y;
		increaseCount(countX, x);
		increaseCount(countY, y);

		resultCoords.push_back(std::pair<int, int>(getMinCount(countX), getMinCount(countY)));

		countX.clear();
		countY.clear();
	}

	for (auto coord : resultCoords)
	{
		std::cout << coord.first << " " << coord.second << std::endl;
	}
}