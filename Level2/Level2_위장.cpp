#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;

	unordered_map<string, int> clothesMap;
	for (auto cloth : clothes)
	{
		auto iter = clothesMap.find(cloth[1]);

		if (iter == clothesMap.end())
		{
			clothesMap.emplace(cloth[1], 1);
		}
		else
			++(iter->second);
	}

	for (auto parts : clothesMap)
		answer *= (parts.second + 1);

	answer -= 1;

	return answer;
}