#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	string answer = "";

	const int monthDay[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int curDay = 4;

	for (int i = 0; i < (a - 1); ++i)
		curDay += monthDay[i];

	curDay += b;

	const char* strDay[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
	const int maxDay = 7;

	const int index = curDay % maxDay;
	answer = strDay[index];

	return answer;
}