#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(int n) {
	string answer = "";

	while (n >= 3)
	{
		answer.insert(answer.begin(), to_string(n % 3)[0]);
		n /= 3;
	}
	answer.insert(answer.begin(), to_string(n)[0]);

	for (int i = 0; i < answer.length(); ++i)
	{
		if ('0' == answer[i])
		{
			answer[i] = '4';
			switch (answer[i - 1])
			{
			case '1':
				answer[i - 1] = '0';
				break;
			case '2':
				answer[i - 1] = '1';
				break;
			case '4':
				answer[i - 1] = '2';
				break;
			}
			if ('0' == answer[i - 1])
				i = 0;
		}
	}

	auto iter = answer.begin();
	while ('0' == (*iter))
		iter = answer.erase(iter);


	return answer;
}