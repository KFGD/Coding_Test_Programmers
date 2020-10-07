#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	answer.resize(prices.size(), 0);

	deque<int> stack;
	stack.emplace_front(0);

	for (int i = 1; i < prices.size(); ++i)
	{
		if (prices[stack.front()] <= prices[i])
			stack.emplace_front(i);
		else
		{
			for (auto iter = stack.begin(); iter != stack.end(); )
			{
				if (prices[(*iter)] > prices[i])
				{
					answer[(*iter)] = i - (*iter);
					iter = stack.erase(iter);
				}
				else
					break;
			}
			stack.emplace_front(i);
		}
	}

	for (auto iter = stack.begin(); iter != stack.end(); ++iter)
		answer[(*iter)] = prices.size() - (*iter) - 1;


	return answer;
}