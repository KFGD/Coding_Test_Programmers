#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;

	int curValue = -1;

	for (int i = 0; i < arr.size(); ++i)
	{
		if (curValue != arr[i])
		{
			curValue = arr[i];
			answer.emplace_back(curValue);
		}
	}

	return answer;
}