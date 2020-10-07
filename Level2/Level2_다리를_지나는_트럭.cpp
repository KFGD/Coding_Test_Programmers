#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = -1;

	int remainingLoad = weight;

	queue<int> weightPertime;

	for (auto iter = truck_weights.begin(); iter != truck_weights.end(); )
	{
		++answer;
		weightPertime.push(0);

		if (answer >= bridge_length)
		{
			remainingLoad += weightPertime.front();
			weightPertime.pop();
		}

		if (remainingLoad >= (*iter))
		{
			remainingLoad -= (*iter);
			weightPertime.back() += (*iter);
			++iter;
		}
	}

	answer += (bridge_length + 1);

	return answer;
}