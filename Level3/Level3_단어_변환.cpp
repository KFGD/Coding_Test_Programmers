#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	words.insert(words.begin(), begin);
	auto iter_target = find(words.begin(), words.end(), target);
	if (words.end() == iter_target)
		return 0;

	const int target_index = distance(words.begin(), iter_target);
	const int length = words[0].length();
	int matrix[52][52] = { 0, };
	for (int i = 0; i < words.size(); ++i)
	{
		for (int j = 0; j < words.size(); ++j)
		{
			if (i == j)
				continue;

			int diff = 0;
			for (int k = 0; k < length; ++k)
			{
				if (words[i][k] != words[j][k])
					diff += 1;
			}
			if (diff < 2)
			{
				matrix[i][j] = 1;
				matrix[j][i] = 1;
			}
		}
	}

	vector<int> distList;
	distList.resize(words.size(), 0);

	vector<bool> visitList;
	visitList.resize(words.size(), false);

	queue<int> queue_node;
	queue_node.push(0);
	visitList[0] = true;

	while (!queue_node.empty())
	{
		const int curIndex = queue_node.front();
		queue_node.pop();

		for (int i = 0; i < words.size(); ++i)
		{
			if (0 == matrix[curIndex][i])
				continue;
			if (true == visitList[i])
				continue;
			visitList[i] = true;
			distList[i] = distList[curIndex] + 1;
			queue_node.push(i);
		}

		if (0 != distList[target_index])
			break;
	}

	answer = distList[target_index];

	return answer;
}