#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void fun(const int color, const int x, const int y, const int m, const int n, vector<vector<int>>& picture, int& area)
{
	if (0 > x || 0 > y || m == y || n == x)
		return;

	if (0 == picture[y][x])
		return;

	if (color != picture[y][x])
		return;

	area += 1;
	picture[y][x] = 0;

	fun(color, x, y - 1, m, n, picture, area);
	fun(color, x, y + 1, m, n, picture, area);
	fun(color, x - 1, y, m, n, picture, area);
	fun(color, x + 1, y, m, n, picture, area);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	vector<int> areaList;
	for (int y = 0; y < m; ++y)
	{
		for (int x = 0; x < n; ++x)
		{
			if (0 == picture[y][x])
				continue;
			int area = 0;
			fun(picture[y][x], x, y, m, n, picture, area);
			areaList.emplace_back(area);
		}
	}

	number_of_area = areaList.size();
	max_size_of_one_area = *max_element(areaList.begin(), areaList.end());

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}
