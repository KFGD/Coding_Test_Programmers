#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;

	const int N = board.size();

	vector<int> curIndexList;
	curIndexList.resize(N, N);

	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (0 != board[i][j])
				curIndexList[j] = i;

		}
	}

	stack<int> bucket;
	for (auto move : moves)
	{
		move -= 1;
		int& curIndex = curIndexList[move];

		if (N == curIndex)
			continue;

		if (bucket.empty())
			bucket.push(board[curIndex][move]);
		else
		{
			if (board[curIndex][move] == bucket.top())
			{
				bucket.pop();
				answer += 2;
			}
			else
				bucket.push(board[curIndex][move]);
		}

		board[curIndex][move] = 0;
		curIndex += 1;
	}

	return answer;
}