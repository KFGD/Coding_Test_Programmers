#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;

	sort(strings.begin(), strings.end(), [&](const string& lhs, const string& rhs)
	{
		if (lhs[n] == rhs[n])
			return lhs < rhs;

		return lhs[n] < rhs[n];
	});

	answer.assign(strings.begin(), strings.end());

	return answer;
}