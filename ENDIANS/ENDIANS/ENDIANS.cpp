// ENDIANS.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>
#include <cassert>

// https://algospot.com/judge/problem/read/ENDIANS

void swap(char *xp, char *yp)
{
	if (xp == yp)
		return;
	*xp = *xp + *yp;
	*yp = *xp - *yp;
	*xp = *xp - *yp;
}

int main()
{
	unsigned int count, number;
	std::cin >> count;
	assert(count >= 1 && count <= 10000);

	std::vector<unsigned int> numbers;
	for (unsigned int i = 0; i < count; ++i)
	{
		std::cin >> number;
		char* bytePointer = reinterpret_cast<char*>(&number);

		swap(&bytePointer[0], &bytePointer[3]);
		swap(&bytePointer[1], &bytePointer[2]);

		numbers.push_back(number);
	}

	for (unsigned int n : numbers)
	{
		std::cout << n << std::endl;
	}

    return 0;
}
