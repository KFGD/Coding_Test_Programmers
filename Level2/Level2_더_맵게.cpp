#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>> queue;
	for (auto value : scoville)
		queue.push(value);

	while (1 < queue.size() && K > queue.top())
	{
		const int a = queue.top();
		queue.pop();

		const int b = queue.top();
		queue.pop();

		const int newScovile = a + b * 2;
		queue.emplace(newScovile);

		++answer;
	}

	if (K > queue.top())
		return -1;

	return answer;
}