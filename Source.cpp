#include<iostream>
#include<fstream>

bool primary(long long n);

int main()
{
	std::ofstream of{ "n,n-2 are primary.txt" };
	long long n{}, m{}, cnt{}, N{}, dist{};
	std::cout << "n , N , cnt" << std::endl;
	std::cin >> n >> N >> cnt;
	m = n - 2;
	while (n < N)
	{
		if (primary(n) && primary(m))
		{
			cnt++;
			dist = n - dist;
			std::cout << n << " , " << m << "  counter : " << cnt << "  distance : " << dist << std::endl;
			of << n << " , " << m << "  counter : " << cnt << "  distance : " << dist << std::endl;
			dist = n;
		}
		n++;
		m++;
	}
	of.close();
	return 0;
}

bool primary(long long n)
{
	if (n == 1)
		return false;
	for (long long i{ 2 }; i*i <= n; i++)
	{
		if (n%i == 0)
			return false;
	}
	return true;
}