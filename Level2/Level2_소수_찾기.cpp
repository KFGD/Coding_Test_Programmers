#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;

bool isPrime(int num)
{
	if (0 == num || 1 == num)
		return false;

	for (int i = 2; (i * i) <= num; ++i)
	{
		if (0 == (num % i))
			return false;
	}

	return true;
}

int solution(string numbers) {
	int answer = 0;

	vector<int> indexList;
	indexList.reserve(numbers.size());
	for (int i = 0; i < numbers.size(); ++i)
		indexList.emplace_back(i);

	vector<vector<int>> permutationList;
	for (int r = 1; r <= indexList.size(); ++r)
	{
		do
		{
			vector<int> permutation;
			permutation.reserve(r);
			for (int i = 0; i < r; ++i)
				permutation.emplace_back(indexList[i]);

			permutationList.emplace_back(permutation);
		} while (next_permutation(indexList.begin(), indexList.end()));
	}

	set<int> primeNumSet;

	string test;
	test.reserve(numbers.size());
	for (auto idxList : permutationList)
	{
		test.resize(numbers.size(), '\0');
		for (int i = 0; i < idxList.size(); ++i)
			test[i] = numbers[idxList[i]];

		const int num = atoi(test.c_str());
		if (isPrime(num))
			primeNumSet.emplace(num);
	}

	answer = primeNumSet.size();

	return answer;
}