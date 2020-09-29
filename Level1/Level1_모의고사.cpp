#include <string>
#include <vector>

using namespace std;

namespace Level1_모의고사
{

vector<int> solution(vector<int> answers) {
	vector<int> answer;

	vector<vector<int>> solvePattern =
	{
		{ 1, 2, 3, 4, 5 },
		{ 2, 1, 2, 3, 2, 4, 2, 5 },
		{ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }
	};

	vector<int> resultList;
	resultList.resize(3, 0);

	int maximumResult = 0;
	for (int solverIdx = 0; solverIdx < 3; ++solverIdx)
	{
		int patternIdx = 0;
		for (int answer : answers)
		{
			if (answer == solvePattern[solverIdx][patternIdx])
				++resultList[solverIdx];

			++patternIdx;
			if (patternIdx == solvePattern[solverIdx].size())
				patternIdx = 0;
		}

		if (maximumResult < resultList[solverIdx])
			maximumResult = resultList[solverIdx];
	}

	for (int solverIdx = 0; solverIdx < 3; ++solverIdx)
	{
		if (maximumResult == resultList[solverIdx])
			answer.emplace_back(solverIdx + 1);
	}

	return answer;
}

}