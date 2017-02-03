// recursion_practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

void combination1(int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			for (int k = j + 1; k < n; ++k)
				for (int l = k + 1; l < n; ++l)
					std::cout << i << " " << j << " " << k << " " << l << std::endl;
}

void pick(int n, std::vector<int>& picked, int toPick)
{
	if (toPick == 0)
	{
		for (int n : picked)
		{
			std::cout << n << " ";
		}

		std::cout << std::endl;
	}

	int smallest = picked.empty() ? 0 : picked.back() + 1;

	for (int next = smallest; next < n; ++next)
	{
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

void combination2(int n)
{
	std::vector<int> picked;
	pick(n, picked, n-1);
}

int main()
{
	combination1(5);
	std::cout << "-------------------------------------------" << std::endl;
	combination2(5);
    return 0;
}

