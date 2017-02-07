#include <map>
#include <iostream>
#include <cassert>

int fib_bf(int n)
{
	if (n == 0 || n == 1)
		return n;
	else
		return fib_bf(n-1) + fib_bf(n-2);
}

std::map<int, int> memoization;

int fib_dp(int n)
{
	auto itr = memoization.find(n);
	if (itr != memoization.end())
	{
		return itr->second;
	}

	if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		int r = fib_dp(n - 1) + fib_dp(n - 2);
		memoization.insert(std::make_pair(n, r));
		return r;
	}
}

int main()
{
	std::cout << fib_bf(10) << std::endl;
	std::cout << fib_dp(10) << std::endl;

}