#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
	string answer = "";

	vector<string> numstrings;
	for (int num : numbers)
		numstrings.emplace_back(to_string(num));

	sort(numstrings.begin(), numstrings.end(),
		[](const string& lhs, const string& rhs)
	{
		return lhs + rhs > rhs + lhs;
	}
	);

	for (auto str : numstrings)
		answer.append(str);

	if ('0' == answer.front())
		return "0";

	return answer;
}