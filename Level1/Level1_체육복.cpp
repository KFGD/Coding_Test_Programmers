#include <string>
#include <array>
#include <vector>

using namespace std;

namespace Level1_체육복
{

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	for (int& lostIdx : lost)
		lostIdx -= 1;

	for (int& reserveIdx : reserve)
		reserveIdx -= 1;

	vector<array<bool, 3>> infoList;
	infoList.resize(n, { false, true, false });

	for (auto lostIdx : lost)
		infoList[lostIdx][1] = false;

	for (auto iter = reserve.begin(); iter != reserve.end(); )
	{
		const int reserveIdx = *iter;
		if (!infoList[reserveIdx][1])
		{
			infoList[reserveIdx][1] = true;
			iter = reserve.erase(iter);
		}
		else
		{
			if (0 <= reserveIdx - 1)
				infoList[reserveIdx - 1][2] = true;
			if (n > reserveIdx + 1)
				infoList[reserveIdx + 1][0] = true;
			++iter;
		}
	}

	bool bChange = true;
	while(bChange)
	{
		bChange = false;
		for (int i = 0; i < infoList.size(); ++i)
		{
			array<bool, 3>& info = infoList[i];
			if (info[1])
				continue;

			if(info[0] && info[2])
				continue;

			if (info[0])
			{
				info[1] = true;
				info[0] = false;
				const int idx = i - 2;
				if (0 <= idx)
					infoList[idx][2] = false;
				bChange = true;
			}
			else if (info[2])
			{
				info[1] = true;
				info[2] = false;
				const int idx = i + 2;
				if (n > idx)
					infoList[idx][0] = false;
				bChange = true;
			}
		}
	}

	for (int i = 0; i < infoList.size(); ++i)
	{
		array<bool, 3>& info = infoList[i];

		if (info[1])
			continue;

		if (info[0])
		{
			info[1] = true;
			info[0] = false;
			const int idx = i - 2;
			if (0 <= idx)
				infoList[idx][2] = false;
		}
		else if (info[2])
		{
			info[1] = true;
			info[2] = false;
			const int idx = i + 2;
			if (n > idx)
				infoList[idx][0] = false;
		}
	}

	for (auto info : infoList)
	{
		if (info[1])
			answer += 1;
	}
	

	return answer;
}

}