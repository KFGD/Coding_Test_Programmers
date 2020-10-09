#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int matrix[20001][20001] = { 0, };

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;

	for (int i = 0; i < edge.size(); ++i)
	{
		matrix[edge[i][0]][edge[i][1]] = 1;
		matrix[edge[i][1]][edge[i][0]] = 1;
	}

	vector<bool> visitList;
	visitList.resize(20001, false);

	queue<int> queue_node;
	visitList[1] = true;
	queue_node.push(1);

	vector<int> disList;
	disList.resize(20001, 0);

	while (!queue_node.empty())
	{
		const int curNode = queue_node.front();
		queue_node.pop();

		for (int i = 0; i < 20001; ++i)
		{
			if (0 == matrix[curNode][i])
				continue;
			if (true == visitList[i])
				continue;
			visitList[i] = true;
			disList[i] = disList[curNode] + 1;
			queue_node.push(i);
		}
	}

	const int dis_max = *max_element(disList.begin(), disList.end());
	answer = count(disList.begin(), disList.end(), dis_max);
	return answer;
}