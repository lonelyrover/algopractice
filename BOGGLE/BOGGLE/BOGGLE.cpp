#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>

std::vector<std::pair<int, int>> neighbor;

bool search(char(&board)[5][5], std::string& keyword, int x, int y, size_t index, std::vector<char>& searched)
{
	if (keyword.size() == index || x < 0 || x >= 5 || y < 0 || y >= 5)
	{
		return false;
	}

	if (board[x][y] == keyword.at(index))
	{
		searched.at(index) = board[x][y];

		for (auto coord : neighbor)
		{
			if (search(board, keyword, x + coord.first, y + coord.second, index + 1, searched))
			{
				return true;
			}
			else
			{
				if (keyword.size() == index+1)
				{
					if (keyword.compare(&searched[0]) == 0)
					{
						return true;
					}
				}
			}
		}
	}

	return false;
}

void exhaustiveSearch(char (&board)[5][5], std::map<std::string, bool>& dictionary)
{
	for (auto& input : dictionary)
	{
		size_t len = input.first.size();
		std::string keyword = input.first;
		std::vector<char> searched(keyword.size()+1);

		size_t index = 0;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (search(board, keyword, i, j, index, searched))
				{
					input.second = true;
					i = j = 5;
				}
			}
		}
	}
}

int main()
{
	neighbor.push_back(std::make_pair(-1, -1));
	neighbor.push_back(std::make_pair(-1, 0));
	neighbor.push_back(std::make_pair(-1, 1));
	neighbor.push_back(std::make_pair(0, 1));
	neighbor.push_back(std::make_pair(1, 1));
	neighbor.push_back(std::make_pair(1, 0));
	neighbor.push_back(std::make_pair(1, -1));
	neighbor.push_back(std::make_pair(0, -1));

	int testCase;
	std::cin >> testCase;

	char board[5][5] = { 0 }, input[5 + 1] = { 0 };
	size_t sizeColumn = sizeof(board[0]) / sizeof(board[0][0]);
	size_t sizeRow = sizeof(board) / sizeColumn / sizeof(board[0][0]);

	for (int i = 0; i < testCase; ++i)
	{
		for (size_t j = 0; j < sizeRow; ++j)
		{
			std::cin >> input;
			size_t k = 0;
			while (input[k])
			{
				board[j][k] = input[k];
				++k;
			}
		}
	}

	size_t sizeDict;
	std::cin >> sizeDict;
	char inputDict[10 + 1] = { 0 };

	std::map<std::string, bool> dictionary;

	for (size_t i = 0; i < sizeDict; ++i)
	{
		std::cin >> inputDict;
		dictionary.insert(std::make_pair(inputDict, false));
		std::memset(inputDict, 0, sizeof(inputDict));
	}

	exhaustiveSearch(board, dictionary);

	for (auto output : dictionary)
	{
		std::cout << std::endl << output.first << " " << (output.second == true ? "YES" : "NO") << std::endl;
	}
}