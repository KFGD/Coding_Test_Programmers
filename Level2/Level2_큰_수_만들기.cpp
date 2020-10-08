#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
	string answer = "";

	const int length = number.length() - k;
	int idx_max = 0;
	for (int i = 0; i < length; ++i)
	{
		char num_max = '0';
		const int remain = length - i;
		for (int j = idx_max; j < number.length() - remain + 1; ++j)
		{
			if (num_max < number[j])
			{
				num_max = number[j];
				idx_max = j;
			}
		}
		idx_max += 1;
		answer.push_back(num_max);
	}

	return answer;
}