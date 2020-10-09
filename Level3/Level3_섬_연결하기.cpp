#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int find_parent(const int idx, vector<int>& parentList)
{
	if (idx == parentList[idx])
		return idx;
	return parentList[idx] = find_parent(parentList[idx], parentList);
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	vector<int> parentList;
	parentList.resize(n, 0);
	for (int i = 0; i < n; ++i)
		parentList[i] = i;

	sort(costs.begin(), costs.end(), [](const vector<int>& lhs, const vector<int>& rhs)
	{
		return lhs[2] < rhs[2];
	});

	for (int i = 0; i < costs.size(); ++i)
	{
		const int start_node = find_parent(costs[i][0], parentList);
		const int end_node = find_parent(costs[i][1], parentList);
		const int cost = costs[i][2];

		if (start_node != end_node)
		{
			parentList[start_node] = end_node;
			answer += cost;
		}
	}

	return answer;
}