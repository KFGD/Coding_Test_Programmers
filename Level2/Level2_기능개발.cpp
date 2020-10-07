#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int size = progresses.size();

	int cursor = 0;
	int time = 0;
	while (cursor < size)
	{
		int release = 0;
		while (100 <= (progresses[cursor] + speeds[cursor] * time))
		{
			++release;
			++cursor;
			if (cursor >= size)
				break;
		}

		if (0 != release)
			answer.emplace_back(release);
		++time;
	}

	return answer;
}