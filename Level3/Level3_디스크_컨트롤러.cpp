#include <string>
#include <vector>
#include <list>

using namespace std;

int solution(vector<vector<int>> jobs) {
	int answer = 0;

	list<int> minLeadtimeIdxList;
	for (int i = 0; i < jobs.size(); ++i)
		minLeadtimeIdxList.emplace_back(i);

	minLeadtimeIdxList.sort([&](const int lhs, const int rhs) {
		return jobs[lhs][1] < jobs[rhs][1];
	});

	int curTime = 0;
	auto iter = minLeadtimeIdxList.begin();
	while (!minLeadtimeIdxList.empty())
	{
		const vector<int>& selectedJob = jobs[(*iter)];
		if (curTime < selectedJob[0])
			++iter;
		else
		{
			const int finishTime = curTime + selectedJob[1];

			answer += finishTime - selectedJob[0];

			minLeadtimeIdxList.erase(iter);
			iter = minLeadtimeIdxList.begin();

			curTime = finishTime;
		}

		if (iter == minLeadtimeIdxList.end())
		{
			++curTime;
			iter = minLeadtimeIdxList.begin();
		}
	}

	answer /= jobs.size();

	return answer;
}