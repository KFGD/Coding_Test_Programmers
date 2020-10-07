#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	size_t curIdx = 0;
	for (auto skill_tree : skill_trees)
	{
		bool bSucceed = true;
		curIdx = 0;
		for (int i = 0; i < skill_tree.size(); ++i)
		{
			const size_t n = skill.find(skill_tree[i], curIdx);

			if (string::npos == n)
				continue;
			else
			{
				if (curIdx == n)
				{
					curIdx += 1;
					continue;
				}
				else
				{
					bSucceed = false;
					break;
				}
			}
		}
		if (bSucceed)
		{
			answer += 1;
			cout << skill_tree << endl;
		}
	}

	return answer;
}