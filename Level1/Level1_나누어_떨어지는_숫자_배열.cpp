#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
	vector<int> answer;

	for (int i = 0; i < arr.size(); ++i)
	{
		const int value = (arr[i] % divisor);
		if (0 == value)
			answer.emplace_back(arr[i]);
		
	}

	sort(answer.begin(), answer.end());

	if (0 == answer.size())
		answer.emplace_back(-1);

	return answer;
}